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
 * @Date         : 2022-04-01 10:11:09
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:24:05
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/barrier_singleton.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;


// method 1 operator new + placement new
//singleton *instance() {
//    if (p == nullptr) {
//        lock_guard<mutex> guard(lock_);
//        if (p == nullptr) {
//            singleton *tmp = static_cast<singleton *>(operator new(sizeof(singleton)));
//            new(p)singleton();
//            p = tmp;
//        }
//    }
//    return p;
//}

// method 2
// lwsync是POWERPC提供的barrier指令。
#define barrier() __asm__ volatile ("lwsync")

class singleton
{
  private:
    singleton() {}

    static singleton *p;
    static mutex lock_;

  public:
    singleton *instance();
};

singleton *singleton::p = nullptr;

singleton *singleton::instance()
{
    if (p == nullptr) {
        lock_guard<mutex> guard(lock_);
        barrier();
        if(p == nullptr)
            // memory barrier。强迫CPU执行的时候按照1、2、3的步骤来运行。
            // 分配能够存储singleton对象的内存；
            // 在被分配的内存中构造一个singleton对象；
            // 让p指向这块被分配的内存。
            p = new singleton();
    }
    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}