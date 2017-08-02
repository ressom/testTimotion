/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "UpDownTest.hpp"
void UpDownTest::Init() {
    
    mReq.Init(DESK,this);
    mReq.bind();
    mReq.start();
    runTimer.Init(500000000L,40,this); // 20s
    runTimer.Start();
    state = true;
    moveUp();

}

void UpDownTest::moveUp() {
    tx[0] = 0xFF; // Start Byte 1
    tx[1] = 0xFF; // Start Byte 2
    tx[2] = 0x02; // length
    tx[3] = 0x03; //product id
    tx[4] = 0x03; // component id
    tx[5] = 0x02; // instruction
    tx[6] = ControlTableAddress.Up; // address
    tx[7] = 0x01; // param 1
    tx[8] = 0x01; // param 2
    tx[9] = 0x0F; // check sum
    tx[10] = 0xFA;// stop byte 1
    tx[11] = 0xFA;// stop byte 2
    len = 12;
    mReq.putBytes(tx,len);                
    printf("Set Desk Move Up\n");                
}

void UpDownTest::moveDown() {
    tx[0] = 0xFF; // Start Byte 1
    tx[1] = 0xFF; // Start Byte 2
    tx[2] = 0x02; // length
    tx[3] = 0x03; //product id
    tx[4] = 0x03; // component id
    tx[5] = 0x02; // instruction
    tx[6] = ControlTableAddress.Down; // address
    tx[7] = 0x01; // param 1
    tx[8] = 0x01; // param 2
    tx[9] = 0x10; // check sum
    tx[10] = 0xFA;// stop byte 1
    tx[11] = 0xFA;// stop byte 2
    len = 12;
    mReq.putBytes(tx,len); 
    printf("Set Desk Move Down\n");
}


UpDownTest::UpDownTest() {
    Init();

}

UpDownTest::~UpDownTest() {

}
int ZmqReqCallback(void *local_class, void *target_class){
    ZmqRequester *x = (ZmqRequester *)local_class;

    AutonomousCommFrame_Typedef obj;
    
    uint16_t data = AutonomousCommFrame_GetParamsFromArray(x->rx_buf,x->rx_buf_length);
    printf("Get data from %s, data: %d\n",DESK,data);
    return 0;
  
}
int TimerCallbackFcn(void * local_class_p, void *target_class_p){
    
    Timer *_timer  = (Timer *)local_class_p;
    UpDownTest *obj = (UpDownTest *)target_class_p;
    //_timer->Stop();
    if (obj->state == false) {
        obj->moveUp();
        
    }
    else {
        obj->moveDown();
    }
    obj->state = !obj->state;
    return 0;
}