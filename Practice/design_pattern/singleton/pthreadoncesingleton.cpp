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
 * @Date         : 2022-04-01 09:46:25
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 09:50:32
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/pthreadoncesingleton.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <sys/param.h>
#include <thread>

using namespace std;

/**
 * @brief class singleton
 *
 */
class singleton
{
  private:
    singleton();                       // 私有构造函数，不允许使用者自己生成对象
    singleton(const singleton &other); //

    // 要写成静态方法的原因：类成员函数隐含传递this指针（第一个参数）
    static void init()
    {
        p = new singleton;
    }

    static pthread_once_t ponce_;
    static singleton *p;

  public:
    singleton *instance()
    {
        // init函数只会执行一次
        pthread_once(&ponce_, &singleton::init);
        return p;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}