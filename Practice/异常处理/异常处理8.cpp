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
 * @LastEditTime : 2022-03-25 13:50:34
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理8.cpp
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
    char *Where()
    {
        return (char *)"BasicException...";
    }
};

class FileSysException : public BasicException
{
  public:
    char *Where()
    {
        return (char *)"FileSysException...";
    }
};

class FileNotFound : public FileSysException
{
  public:
    char *Where() { return (char *)"FileNotFound..."; }
};

class DiskNotFound : public FileSysException
{
  public:
    char *Where() { return (char *)"DiskNotFound..."; }
};

int main(int argc, char const *argv[])
{
    try {
        // TODO
        throw FileSysException();
    } catch (DiskNotFound p) {
        cout << p.Where() << endl;
    } catch (FileNotFound p) {
        cout << p.Where() << endl;
    } catch (FileSysException p) {
        cout << p.Where() << endl;
    } catch (BasicException p) {
        cout << p.Where() << endl;
    }

    try {
        // TODO
        throw DiskNotFound();
    } catch (BasicException p) {
        cout << p.Where() << endl;
    } catch (FileSysException p) {
        cout << p.Where() << endl;
    } catch (DiskNotFound p) {
        cout << p.Where() << endl;
    } catch (FileNotFound p) {
        cout << p.Where() << endl;
    }

    return 0;
}