#include <iostream>

/* Abstract Class Communicator */

/* Class UdpCommunicator from Communicator */

/* Class TcpCommunicator from Communicator */

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