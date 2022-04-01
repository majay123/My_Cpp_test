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
 * @Date         : 2022-04-01 09:56:38
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:18:23
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/hungrysingleton.cpp
 * @Description  : 饿汉:单例类定义的时候就进行了实例化
 * 当然这个是线程安全的
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

using namespace std;

class singleton
{
  private:
    singleton() {}
    static singleton *p;

  public:
    static singleton *instance();
};

singleton *singleton::p = new singleton();
singleton *singleton::instance()
{
    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}