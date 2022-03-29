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
 * @Date         : 2022-03-25 10:27:06
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-25 10:57:01
 * @FilePath     : /My_Cpp_test/Practice/模板与STL/STL_map_se.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string name[] = {"张三", "李四", "王二"};
    double salary[] = {1000, 1200, 1100};
    map<string, double> sal;
    map<string, double>::iterator p;

    for (size_t i = 0; i < 3; i++) {
        sal.insert(make_pair(name[i], salary[i]));
    }

    sal["Jay"] = 1500;
    sal["tom"] = 1600;

    for (p = sal.begin(); p != sal.end(); p++) {
        cout << p->first << "\t" << p->second << endl;
    }

    string person;
    cout << "请输入查找人员的名字: ";
    cin >> person;
    int flag = 1;

    for (p = sal.begin(); p != sal.end(); p++) {
        if (p->first == person) {
            cout << p->second << endl;
            flag = 0;
        }
    }

    if (flag) {
        cout << "没查到对应的结果！" << endl;
    }

	cout << "请输入待删除的人员名字：";
	cin >> person;
	map<string, double>::iterator it;
	it = sal.find(person);
	if(it != sal.end()) {
		cout << "查找成功："<< (*it).first<<":"<< (*it).second<<endl;
		sal.erase(it);
		cout << "删除成功"<<endl;
	}

	cout << "删除后的结果为 "<< endl;
	for(p=sal.begin(); p!=sal.end();p++)
		cout << p->first << p->second << endl;

    return 0;
}