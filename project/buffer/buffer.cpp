//
// Created by wjw on 2024/3/2.
//
#include <cassert>
#include <algorithm>
#include "buffer.h"
#include <iostream>
using std::string;
WebServer::Buffer::Buffer::Buffer(int Maxsize) {
    write=0;
    buffer.resize(Maxsize);
}

WebServer::Buffer::Buffer::~Buffer() {

}

void WebServer::Buffer::Buffer::append(char &val) {
    if(write == buffer.size())buffer.resize(2*buffer.size());
    buffer[write++] = val;
    return;
}

void WebServer::Buffer::Buffer::append(const char*val) {
    std::string tem(val);
    append(tem);
    return ;
}


void WebServer::Buffer::Buffer::append(std::string &val) {
    for(auto &c:val)
    append(c);
}

std::string WebServer::Buffer::Buffer::GetString() {
    string ans="";
    while(write>0)
    {
        write--;
        ans+=buffer[write];
    }
    std::reverse(ans.begin(),ans.end());
    return ans;
}

void WebServer::Buffer::Buffer::append(string &&val) {
    for(auto &c:val)
        append(c);
    return ;
}


