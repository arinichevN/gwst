#ifndef MODEL_CHANNEL_H
#define MODEL_CHANNEL_H

#include "SerialThread.h"
#include "SlaveGetCommand.h"
#include "SlaveSetCommand.h"
#include "SlaveIntervalGetCommand.h"

#define CH_SLEEP_BEFORE_READ_SLAVE NANOSLEEP(0,100000000);

typedef struct {
   int id;
   SlaveIntervalGetCommandList igcmd_list;
   SlaveGetCommandList gcmd_list;
   SlaveGetCommandList tgcmd_list;
   SlaveSetCommandList scmd_list;
   struct sthread_st *thread;
   int max_retry;
   int retry;
   int state;
   Mutex mutex;
} Channel;
DEC_LIST(Channel)

typedef struct channelptr_st ChannelPtr;
struct channelptr_st{
	Channel *item;
	struct channelptr_st *next;
};
DEC_LIST(ChannelPtr)
DEC_LLIST(ChannelPtr)

extern void channel_resetData(Channel *item);
extern int channel_control(Channel *item, int fd);
extern SlaveGetCommand *channel_getIntervalGetCmd(Channel *channel, const char *cmd);
extern SlaveGetCommand *channel_getGetCmd(Channel *channel, const char *cmd);
extern SlaveGetCommand *channel_getTextGetCmd(Channel *channel, const char *cmd);
extern SlaveSetCommand *channel_getSetCmd(Channel *channel, const char *cmd);
extern int channel_slaveToClient (Channel *channel, char *pack_str, int tcp_fd);
extern int channel_slaveToClientText (Channel *channel, char *pack_str, int tcp_fd);
extern int channel_sendRawDataToSlave (Channel *channel, char *pack_str);
extern int channelList_init ( ChannelList *list, int max_retry, const char *config_path, const char *get_dir, const char *iget_dir, const char *tget_dir, const char *set_dir, const char *file_type  ) ;
#endif 