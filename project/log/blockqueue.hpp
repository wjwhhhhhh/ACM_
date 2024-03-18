//
// Created by wjw on 2024/2/28.
//

#ifndef WEBSERVER_BLOCKQUEUE_HPP
#define WEBSERVER_BLOCKQUEUE_HPP

#include <mutex>
#include <condition_variable>
#include <deque>
#include <cassert>
#include <string>

namespace WebServer {
    namespace BlockQueue {
        template<typename T = int>
        class BlockQueue {
        public:
           explicit BlockQueue(int MaxQueue=1000);
           ~BlockQueue();
           bool full() ;
           bool empty();
           void close();
           bool push_back(const std::string &val);
           bool pop_front(std::string &val);
           bool pop_front(std::string &val,int timeout);
        private:
            bool is_close;
            int MaxQueue;
            std::deque<T> que;
            std::mutex mutex;
            std::condition_variable writer;
        };

        template<typename T>
        void BlockQueue<T>::close() {
            writer.notify_all();
            while(que.size()!=0)
            is_close=true;
        }

        template<typename T>
        bool BlockQueue<T>::pop_front(std::string &val, int timeout) {
            std::unique_lock<std::mutex> lock(mutex);
            while(que.size<=0)
            {
                if(writer.wait_for(lock, std::chrono::seconds(timeout))
                   == std::cv_status::timeout)
                {
                    exit(1);
                };
            }
            val=que.front();
            que.pop_front();
            return true;
        }

        template<typename T>
        bool BlockQueue<T>::pop_front(std::string &val) {
            std::unique_lock<std::mutex> lock(mutex);
            while(que.size()<=0)
            {
                if(is_close)return false;
                writer.wait(lock);
            }
            val=que.front();
            que.pop_front();
            return true;
        }

        template<typename T>
        bool BlockQueue<T>::push_back(const std::string &val) {
            {
                std::lock_guard<std::mutex> mul(mutex);
                if (que.size() < MaxQueue) {
                    writer.notify_all();
                    que.push_back(val);
                    return true;
                }
            }
            writer.notify_all();
            return false;
        }

        template<typename T>
        bool BlockQueue<T>::full() {
            std::lock_guard<std::mutex> mul(mutex);
            return que.full();
        }

        template<typename T>
        BlockQueue<T>::~BlockQueue() {
            close();
            return ;
        }

        template<typename T>
        bool BlockQueue<T>::empty()  {
            std::lock_guard<std::mutex> mul(mutex);
            return que.empty();
        }

        template<typename T>
        BlockQueue<T>::BlockQueue(int MaxQueue) {
            is_close = false;
            std::lock_guard<std::mutex> mul(mutex);
            this->MaxQueue=MaxQueue;
            return ;
        }

    }
}
#endif //WEBSERVER_BLOCKQUEUE_HPP
