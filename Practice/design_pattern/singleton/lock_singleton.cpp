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
 * @Date         : 2022-04-01 09:51:24
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:17:15
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/lock_singleton.cpp
 * @Description  : 没有线程安全问题，加了锁之后反而存在性能问题。
 * 性能非常低下，因为每次调用instance()都会加锁释放锁
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class singleton
{
  private:
    singleton() {}
    static singleton *p;
    static mutex lock_;

  public:
    static singleton *instance();
};

singleton *singleton::p = nullptr;

singleton *singleton::instance()
{
    lock_guard<mutex> guard(lock_);
    if(p == nullptr)
        p = new singleton();
    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}