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
 * @LastEditTime : 2022-03-25 12:44:18
 * @FilePath     : /My_Cpp_test/Practice/异常处理/异常处理1.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "1--before try block..." << endl;
    try {
        cout << "2--inside try block..." << endl;
        // throw (char *)"test";
        throw 20;
        cout << "3--After throw..." << endl;
    } catch (int i) {
        cout << "4--in catch block1 ... exception..errcode is.." << i << endl;
    } catch (char *s) {
        cout << "5--in catch block2 ... exception..errcode is.."<< s << endl;
    }
    cout << "6--after catch..." << endl;

    return 0;
}