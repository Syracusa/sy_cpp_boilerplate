#ifndef DATASTORE_H
#define DATASTORE_H

#include "net.h"



class DataStore
{

};

class DataStoreReqMsgBuilder
{

};

class DataStoreReqMsgHandler
{

};

class DataStoreRespMsgBuilder
{

};

class DataStoreRespMsgHandler
{

};

class DataStoreServer
{

  public:
    DataStore datastore;
    DataStoreReqMsgBuilder msgBuilder;
    DataStoreRespMsgHandler msgHandler;
    NetServer server;
    void mainloop();
};

class DataStoreClient
{
  public:
  DataStoreRespMsgBuilder msgBuilder;
  DataStoreReqMsgHandler msgHandler;

};

#endif