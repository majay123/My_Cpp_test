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
 * @Date         : 2022-03-25 14:01:06
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 15:32:13
 * @FilePath     : /My_Cpp_test/Practice/文件与流/文件与流2.cpp
 * @Description  : 用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
 * 
 * ******************************************
 */

#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
// 1
#if 0
    fstream ioFile;

    ioFile.open("./a.txt", ios::out);
    ioFile << "zsan"
           << " " << 76 << " " << 98 << " " << 67 << endl;
    ioFile << "lisi"
           << " " << 89 << " " << 70 << " " << 60 << endl;
    ioFile << "wangshi"
           << " " << 91 << " " << 88 << " " << 77 << endl;
    ioFile << "huanger"
           << " " << 62 << " " << 81 << " " << 75 << endl;
    ioFile << "liuliu"
           << " " << 90 << " " << 78 << " " << 57 << endl;
    ioFile.close();

    ioFile.open("./a.txt", ios::in | ios::binary);
    char name[10];
    int chinese, math, computer;
    cout << "姓名\t"
         << "英语\t"
         << "数学\t"
         << "计算机\t"
         << "总分" << endl;
    ioFile >> name;
    while (!ioFile.eof()) {
        ioFile >> chinese >> math >> computer;
        cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
        ioFile >> name;
    }
    ioFile.close();
#endif

    // 2
    char ch;
    ofstream out("./test.txt", ios::out | ios::binary);
    for (int i = 0; i < 90; i++) {
        out.put('\n');
        out.put(i);
        out.put(' ');
    }
    out.close();

    ifstream in("./test.txt", ios::in | ios::binary);
    cout << "out file " << endl;
    while (in.get(ch))
        cout << ch;
    cout << '\n'<< endl;
    in.close();

    return 0;
}
