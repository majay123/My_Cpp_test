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
 * @Date         : 2022-04-01 10:04:30
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:22:42
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/cpulpuls11_singleton.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <atomic>
#include <climits>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
// c++11版本之后的跨平台实现
class singleton
{
  private:
    singleton() {}

    static mutex lock_;
    static atomic <singleton *> p;

  public:
    singleton *instance();
};

mutex singleton::lock_;
atomic<singleton *> singleton::p;

/*
* std::atomic_thread_fence(std::memory_order_acquire);
* std::atomic_thread_fence(std::memory_order_release);
* 这两句话可以保证他们之间的语句不会发生乱序执行。
*/
singleton * singleton::instance()
{
    singleton *tmp = p.load(memory_order_relaxed);
    atomic_thread_fence(memory_order_acquire);
    if(tmp == nullptr) {
        lock_guard<mutex> guard(lock_);
        tmp = p.load(memory_order_relaxed);
        if(tmp == nullptr) {
            tmp = new singleton();
            atomic_thread_fence(memory_order_relaxed);
            p.store(tmp, memory_order_relaxed);
        }
    }
    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}