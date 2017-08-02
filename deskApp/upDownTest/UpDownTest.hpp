/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UpDownTest.hpp
 * Author: thanh
 *
 * Created on August 2, 2017, 11:36 AM
 */

#ifndef UPDOWNTEST_HPP
#define UPDOWNTEST_HPP
#include "ZMQ/ZmqRequester.hpp"
#include "TIMER/Timer.hpp"
#include"SmartDesk/Desk.hpp"
#define  DESK  "ipc:///tmp/desk_control:9999"

class UpDownTest{
public:
    void Init();
    unsigned char tx[20];
    unsigned char len = 0;
    bool state = false;
    ZmqRequester mReq;
    Timer runTimer;
    virtual ~UpDownTest();
    UpDownTest();
    void moveUp();
    void moveDown();
private:
protected:
};


#endif /* UPDOWNTEST_HPP */

