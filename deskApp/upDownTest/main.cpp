/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thanh
 *
 * Created on August 2, 2017, 11:20 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <stddef.h>
#include <cstdlib>
#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

#include <termios.h>
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <signal.h>
#include <unistd.h>    /* UNIX standard function definitions */
#include <assert.h>
#include<time.h>
#include "UpDownTest.hpp"
using namespace std;

/*
 * 
 */
uint16_t count = 0;
UpDownTest mTest;
int main(int argc, char** argv) {
    
    mTest.Init();
    struct timespec tim,tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 500*1000*1000; // 500ms
    int major, minor, patch;
    zmq_version (&major, &minor, &patch); 
    printf ("Current ØMQ version is %d.%d.%d\n", major, minor, patch);
    
    while(1){    
        
        nanosleep(&tim , &tim2);

    }
    return 0;
}

