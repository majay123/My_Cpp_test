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
 * @Date         : 2022-04-01 09:54:28
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:15:28
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/iazysingleton.cpp
 * @Description  : 懒汉:第一次用到类实例的时候才会去实例化，上述就是懒汉实现
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

/**
 * @brief 这个代码只适合在单线程下，当多线程时，是不安全的。
 * 考虑两个线程同时首次调用instance方法且同时检测到p是nullptr，
 * 则两个线程会同时构造一个实例给p，这将违反了单例的准则。
 * 
 */

using namespace std;

class singleton
{
  private:
    singleton() {}
    static singleton *p;

  public:
    static singleton *instance();
};

singleton *singleton::p = nullptr;

singleton *singleton::instance()
{
    if(p == nullptr)
        p = new singleton;

    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}