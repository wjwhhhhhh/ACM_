//
// Created by wjw on 2024/3/2.
//

#ifndef WEBSERVER_BUFFER_H
#define WEBSERVER_BUFFER_H
#include<string>
#include <atomic>
#include <vector>
#include <sstream>

namespace WebServer {
    namespace Buffer {
        class Buffer
        {
        public:
            explicit Buffer(int Maxsize=126);
            ~Buffer();
            void append(char &val);
            void append(const char *val);
            void append(std::string &val);
            void append(std::string &&val);
            std::string GetString();
        private:
            int write;
            std::string buffer;
        };
    }
}
#endif //WEBSERVER_BUFFER_H
