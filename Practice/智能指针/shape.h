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
 * @Date         : 2022-03-31 09:12:58
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-31 09:17:43
 * @FilePath     : /My_Cpp_test/Practice/smart_ptr/shape.h
 * @Description  : 
 * 
 * ******************************************
 */

#ifndef SHAPE
#define SHAPE
#include <iostream>
using namespace std;

enum class shape_type {
    circle,
    triangle,
    rectangle,
};


class shape {
public:
    shape() { cout << "shape" << endl; }

    virtual void print() {
        cout << "I am shape" << endl;
    }

    virtual ~shape() {}
};

class circle : public shape {
public:
    circle() { cout << "circle" << endl; }

    void print() {
        cout << "I am circle" << endl;
    }
};

class triangle : public shape {
public:
    triangle() { cout << "triangle" << endl; }

    void print() {
        cout << "I am triangle" << endl;
    }
};

class rectangle : public shape {
public:
    rectangle() { cout << "rectangle" << endl; }

    void print() {
        cout << "I am rectangle" << endl;
    }
};





#endif