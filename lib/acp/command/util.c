#include "util.h"

#define STR_IS(V) strcmp(command_str, V) == 0

int acp_commandStrToEnum(const char *command_str) {
	if(STR_IS("CMD_GATEWAY_RESET")) return CMD_GATEWAY_RESET;
	else if(STR_IS("CMD_GATEWAY_PRINT")) return CMD_GATEWAY_PRINT;
	else if(STR_IS("CMD_APP_GET_ID")) return CMD_APP_GET_ID;
	else if(STR_IS("CMD_AOID_GET_FIRST")) return CMD_AOID_GET_FIRST;
	else if(STR_IS("CMD_AOID_GET_NEXT")) return CMD_AOID_GET_NEXT;
	else if(STR_IS("CMD_AOID_GET_ACP_COMMAND_SUPPORTED_FIST")) return CMD_AOID_GET_ACP_COMMAND_SUPPORTED_FIRST;
	else if(STR_IS("CMD_AOID_GET_ACP_COMMAND_SUPPORTED_NEXT")) return CMD_AOID_GET_ACP_COMMAND_SUPPORTED_NEXT;
	else if(STR_IS("CMD_AOID_SET_RAM_VALUE")) return CMD_AOID_SET_RAM_VALUE;
	else if(STR_IS("CMD_AOID_SET_NVRAM_VALUE")) return CMD_AOID_SET_NVRAM_VALUE;
	else if(STR_IS("CMD_AOID_GET_RAM_VALUE")) return CMD_AOID_GET_RAM_VALUE;
	else if(STR_IS("CMD_AOID_GET_NVRAM_VALUE")) return CMD_AOID_GET_NVRAM_VALUE;
	else if(STR_IS("CMD_AOID_DELETE")) return CMD_AOID_DELETE;
	else if(STR_IS("CMD_AOID_ADD")) return CMD_AOID_ADD;
	else if(STR_IS("CMD_AOID_START")) return CMD_AOID_START;
	else if(STR_IS("CMD_AOID_STOP")) return CMD_AOID_STOP;
	else if(STR_IS("CMD_AOID_RESET")) return CMD_AOID_RESET;
	
	else if(STR_IS("CMD_NOID_GET_FIRST")) return CMD_NOID_GET_FIRST;
	else if(STR_IS("CMD_NOID_GET_NEXT")) return CMD_NOID_GET_NEXT;
	else if(STR_IS("CMD_NOID_GET_ACP_COMMAND_SUPPORTED_FIRST")) return CMD_NOID_GET_ACP_COMMAND_SUPPORTED_FIRST;
	else if(STR_IS("CMD_NOID_GET_ACP_COMMAND_SUPPORTED_NEXT")) return CMD_NOID_GET_ACP_COMMAND_SUPPORTED_NEXT;
	
	else if(STR_IS("CMD_NOID_GET_EXISTS")) return CMD_NOID_GET_EXISTS;
	else if(STR_IS("CMD_NOID_GET_FTS")) return CMD_NOID_GET_FTS;
	else if(STR_IS("CMD_NOID_GET_STATE")) return CMD_NOID_GET_STATE;
	else if(STR_IS("CMD_NOID_GET_ERROR")) return CMD_NOID_GET_ERROR;
	else if(STR_IS("CMD_NOID_GET_DEVICE_KIND")) return CMD_NOID_GET_DEVICE_KIND;

	else if(STR_IS("CMD_NOID_START")) return CMD_NOID_START;
	else if(STR_IS("CMD_NOID_STOP")) return CMD_NOID_STOP;
	else if(STR_IS("CMD_NOID_RESET")) return CMD_NOID_RESET;
	else if(STR_IS("CMD_NOID_SET_GOAL")) return CMD_NOID_SET_GOAL;
	else if(STR_IS("CMD_NOID_SET_TEXT")) return CMD_NOID_SET_TEXT;
	else if(STR_IS("CMD_NOID_SET_TEXT_BLINK")) return CMD_NOID_SET_TEXT_BLINK;
	return CMD_NONE;
}

#undef STR_IS