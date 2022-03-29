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
 * @Date         : 2022-03-25 12:38:16
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 13:51:21
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理9.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;
class BasicException
{
  public:
    virtual string Where() { return "BasicException..."; }
};
class FileSysException : public BasicException
{
  public:
    virtual string Where() { return "FileSysException..."; }
};
class FileNotFound : public FileSysException
{
  public:
    virtual string Where() { return "FileNotFound..."; }
};
class DiskNotFound : public FileSysException
{
  public:
    virtual string Where() { return "DiskNotFound..."; }
};


int main(int argc, char const *argv[])
{
    try {
        //        .....  //程序代码
        DiskNotFound err;
        throw &err;
    } catch (BasicException *p) {
        cout << p->Where() << endl;
    }
}
