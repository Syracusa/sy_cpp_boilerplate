#include <iostream>

/* Abstract Class Communicator */

/* Class UdpCommunicator from Communicator */

/* Class TcpCommunicator from Communicator */


/*

main(){
 DataStoreServer serv = new DataStoreServer(new TcpServer);


}

class DataStore(){

  void handle_msg(){
    
  }
}

class DataStoreServer {
  public NetServer netServ;
  DataStoreReqMsgHandler hdl;
  
  constructor (Netserver serv) {
     netServ = serv;
     hdl = New hdl();
  }

  public work(){

  }
  while(1){
    bytearr data = netServ.recv();
    hdl.handle(data);
  }
}

Class TcpServer impl Netserver {

}

Class TcpClient impl NetClient {

}

Class NetServer{
  in_addr client_addr
  do_recv()
  do_send()
}

Class NetClient{
  in_addr server_addr
  do_recv()
  do_send()
}

Class DataStoreClient {
  NetClient cli;
  DataStoreReqMsgBuilder bld;
}

Class DataStoreServer {
  NetServer serv;
  DataStoreMsgHandler hdlr;
}

Class DataStoreMsgHandler

Class DataStoreReqMsg {
  u8 operation
  u8 dataid

  int bufsz
  int bufptr

  serialize()
  deserialize()
}

Class DataStoreReqMsg : DataSaveReq{
 u8* data

 serialize(){
  super.serialize().append(mydata)
 }
}

Class DataStoreReqMsg : DataLoadReq{
 no payload
 
}

Class DataStoreResMsg : DataStoreAck{
  u8 result;
}
 
*/

/*
Rc don't use checksum and stx etx but sc do.
 RawCommunicator impl Communicatable;
 SafeCommunicator impl Communicatable;

ICD1Msg use 2byte code 
ICD2Msg use 1byte code, 1byte UserID

EncryptReq : ICD1Msg
DecryptReq : ICD1Msg

DataSaveReq : ICD2Msg
DataLoadReq : ICD2Msg

Class ICD1Msg{
 u16 code
 u8* data
 pack()
 unpack()
}

Class ICD2Msg{
 u8 code
 u8 id
 u8* data
 pack
 unpack
}

class DataSaveReq : ICD2Msg
{
 construtor{
   super.code = MSGCODESAVEREQ
 }

}

class DataStoreServer{
  Netserver server;
}

DataStoresercer dss;
dss.new
dss.server = Tcpserver()
recvmsg()
process icd2


DataStore: Public 
DataEncryptor


Interface netserver{

}

TcpServer{
  Communicatable c;

  doAccept(){}
}

TcpClient{
  Communicatable c;

  doConnect(){}
  recvRoutine(){
Thread t;
t.start;
}

}

UdpServer{

}

UdpClient{

}





































 

*/