//
// Created by wjw on 2024/3/14.
//
#include <iostream>
#include "log.h"
#include <ctime>
using std::cout;
using std::endl;
using namespace WebServer::Log;
int main()
{
    int t=clock();
    int si=0;
    while(clock()-t<=1000)
    {
        LOG_DEBUG("这是第%d次操作",si++);
    }
}

