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
 * @Date         : 2022-04-01 09:58:42
 * @LastEditors  : MCD
 * @LastEditTime : 2022-04-01 10:20:11
 * @FilePath     : /My_Cpp_test/Practice/design_pattern/singleton/dcl_singleton.cpp
 * @Description  : 第二次检查是必要，因为就像我们刚刚看到的，很有可能另一个线程偶然在第一次检查之后，获得锁成功之前初始化p。
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

/**
 * @brief 还是有漏洞存在的
 * 原因是：内存读写的乱序执行(编译器问题)。
 * 
 */
using namespace std;

class singleton
{
  private:
    singleton() {}

    static singleton *p;
    static mutex lock_;

  public:
    singleton *instance();

    // 实现一个内嵌垃圾回收
    class CGarbo
    {
      public:
        ~CGarbo()
        {
            if (singleton::p)
                delete singleton::p;
        }
    };

    static CGarbo CGarbo; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
};

singleton *singleton::p = nullptr;
singleton *singleton::instance()
{
    if (p == nullptr) {
        lock_guard<mutex> guard(lock_);
        if (p == nullptr)
            // p = new singleton();
            // 分配能够存储singleton对象的内存；
            // 在被分配的内存中构造一个singleton对象；
            // 让p指向这块被分配的内存。
            p = new singleton();
            // 可能会认为这三个步骤是按顺序执行的，但实际上只能确定步骤1是最先执行的，步骤2，3却不一定。问题就出现在这
    }
    return p;
}

int main(int argc, char const *argv[])
{

    return 0;
}