/*
 *
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 *
 *
 *
 * ************Copyright 2022 MCD************
 *
 * @version      :
 * @Company      : HOPE
 * @Author       : MCD
 * @Date         : 2022-04-01 09:44:06
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 13:39:38
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/producer_consumer.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>

using namespace std;

const int MAX_NUM = 10000;

class BounderBuffer
{
  public:
    BounderBuffer(size_t n)
    {
        array_.resize(n);
        start_pos_ = 0;
        end_pos_ = 0;
        pos_ = 0;
    }

    void Produce(int n)
    {
        {
            unique_lock<mutex> lock(mtx_);
            // wait for not full
            not_full_.wait(lock, [=, this] { return pos_ < array_.size(); });

            usleep(1000 * 200); // 400ms
            array_[end_pos_] = n;
            end_pos_ = (end_pos_ + 1) % array_.size();
            ++pos_;
            cout << "Produce pos: " << pos_ << endl;
            lock.unlock();
        } // auto unlock

        not_empty_.notify_one();
    }

    int Consume()
    {
        unique_lock<mutex> lock(mtx_);

        // wait for not empty
        not_empty_.wait(lock, [=, this] {return pos_ > 0; });

        usleep(1000 * 200); // 400ms
        int n = array_[start_pos_];
        start_pos_ = (start_pos_ + 1) % array_.size();
        --pos_;
        cout << "Consume pos: " << pos_ << endl;
        lock.unlock();

        not_full_.notify_one();

        return n;
    }

  private:
    vector<int> array_;
    size_t start_pos_;
    size_t end_pos_;
    size_t pos_;

    mutex mtx_;
    condition_variable not_full_;
    condition_variable not_empty_;
};

BounderBuffer bb(10);
mutex g_mtx;

void Producer()
{
    int n = 0;
    while (n < 5) {
        bb.Produce(n);
        cout << "Producer: " << n << endl;
        n++;
    }

    bb.Produce(-1);
}

void Consumer()
{
    thread::id thread_id = this_thread::get_id();
    int n = 0;
    do {
        n = bb.Consume();
        cout << "Consumer thread Id: " << thread_id << "======> " << n << endl;
    } while (-1 != n);

    bb.Produce(-1);
}

int main(int argc, char const *argv[])
{
    vector<thread> t;
    t.push_back(thread(&Producer));
    t.push_back(thread(&Consumer));
    t.push_back(thread(&Consumer));
    t.push_back(thread(&Consumer));

    for (auto &one : t) {
        one.join();
    }

    return 0;
}