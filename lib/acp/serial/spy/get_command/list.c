#include "list.h"

//int acpsygcLList_begin(AcpsyIDLListm *self){
	//LLIST_RESET(self)
	//if(!mutex_init(&self->mutex)) {
		//return 0;
	//}
	//return 1;
//}

//int acpsygcLList_add(AcpsyGetCommandLList *self, AcpsyGetCommand *item, size_t items_max_count) {
	//if(self->length >= items_max_count) {
		//printde("can not add item to list: list length (%zu) limit (%zu) \n", self->length, items_max_count);
		//return 0;
	//}
	//if(self->top == NULL) {
		//mutex_lock(&self->mutex);
		//self->top = item;
		//mutex_unlock(&self->mutex);
	//} else {
		//mutex_lock(&self->last->mutex);
		//self->last->next = item;
		//mutex_unlock(&self->last->mutex);
	//}
	//self->last = item;
	//self->length++;
	//return 1;
//}

//void acpsygcLList_free(AcpsyGetCommandLList *self){
	//AcpsyGetCommand *item = self->top, *temp;
	//while(item != NULL) {
		//temp = item;
		//item = item->next;
		//acpsygc_free(temp);
	//}
	//self->top = NULL;
	//self->last = NULL;
	//self->length = 0;
	//mutex_free(&self->mutex);
//}

int acpsygcList_begin(AcpsyGetCommandList *self){
	LIST_RESET(self)
	return 1;
}

int acpsygcList_add(AcpsyGetCommandList *self, int command, struct timespec timeout, size_t items_max_count) {
	if(self->length >= items_max_count) {
		printde("\tcan not add item to list: list length (%zu) limit (%zu) \n", self->length, items_max_count);
		return 0;
	}
	if(self->length == self->max_length){
		size_t new_length = self->length + ACPSY_GET_COMMAND_LIST_ALLOC_BLOCK_LENGTH;
		LIST_RESIZE(self, new_length)
		if(self->max_length != new_length){
			putsde("\tget commands list realloc failed\n");
			return 0;
		}
	}
	if(acpsygc_begin(&self->items[self->length], command, timeout)){
		self->length++;
		return 1;
	}
	return 0;
}

void acpsygcList_free(AcpsyGetCommandList *self){
	for (size_t i = 0; i < self->length; i++){
		acpsygc_free(&self->items[i]);
	}
	LIST_FREE(self)
}
