#ifndef ACP_TCP_SERVER_H
#define ACP_TCP_SERVER_H

#include "../../../timef.h"
#include "../../../dstructure.h"
#include "../../../app.h"
#include "../main.h"
#include "connection/list.h"
#include "serve_function.h"

typedef int(*AcptsServeFunction)(int, const char *);

typedef struct {
	AcptsConnectionLList connections;
	int fd;
	size_t conn_num_max;
	int (*serve_function) (int, const char *);
	Thread thread;
} Acpts;


extern Acpts *acpts_newBegin(int port, size_t conn_num_max, AcptsServeFunction serve_function);

extern void acpts_terminate(Acpts *self);

extern void acpts_free(Acpts **pself);
#endif
