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
 * @Date         : 2022-03-29 10:12:08
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 10:56:05
 * @FilePath     : /My_Cpp_test/Practice/并发编程/1.2_ownership.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <cassert>
#include <climits>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;

void some_function() {}
void some_other_function() {}

// std::thread不支持拷贝语义。
// std::thread支持移动语义。

// scoped_thread实例
void do_something(int i)
{
    cout << i << " " << endl;
}

struct func {
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (unsigned int j = 0; j < 1000000; j++) {
            do_something(i);
        }
    }
};

class scoped_thread
{
    thread t;

  public:
    explicit scoped_thread(thread t_) : t(move(t_))
    {
        if (!t.joinable())
            throw logic_error("scoped_thread No");
    }

    ~scoped_thread() {
        t.join();
    }

    scoped_thread(scoped_thread const &) = delete;
    scoped_thread &operator=(scoped_thread const &) = delete;
};

void do_work(unsigned int id) {
    cout << "hello thread : " << id << endl;
}

void f()
{
    vector<thread> threads;
    for(unsigned int i = 0; i < 20; ++i){ 
        threads.push_back(thread(do_work, i)); // 产生线程
    }

    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));

}

int main(int argc, char const *argv[])
{
    f();
    
    return 0;
}