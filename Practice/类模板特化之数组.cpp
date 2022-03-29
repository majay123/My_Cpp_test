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
 * @Date         : 2022-03-28 15:31:40
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 09:17:40
 * @FilePath     : /My_Cpp_test/Practice/类模板特化之数组.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

#define MAXSIZE (5)
template <class T>

class Array
{
  public:
    Array()
    {
        memset(array, 0, sizeof(array));
    }

    T &operator[](int i);
    void Sort();

  private:
    T array[MAXSIZE];
};

template <class T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i > MAXSIZE - 1) {
        cout << "Error : array index out of range" << endl;
        exit(0);
    }
    return array[i];
}

template <class T>
void Array<T>::Sort()
{
    int p, j;

    for (int i = 0; i < MAXSIZE - 1; i++) {
        p = i;
        for (j = i + 1; j < MAXSIZE; j++) {
            if (array[p] < array[j])
                p = j;
        }
        T t;
        t = array[i];
        array[i] = array[p];
        array[p] = t;
    }
}

template <>
void Array<char *>::Sort()
{
    int p, j;
    for (int i = 0; i < MAXSIZE - 1; i++) {
        p = i;
        for (j = i + 1; j < MAXSIZE; j++) {
            if (strcmp(array[p], array[j]) < 0)
                p = j;
        }
        char *t = array[i];
        array[i] = array[p];
        array[p] = t;
    }
}

int main(int argc, char const *argv[])
{
    Array<int> a1;
    Array<char *> b1;

    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 2;
    a1[3] = 103;
    a1[4] = 93;

    a1.Sort();
    for (size_t i = 0; i < MAXSIZE; i++) {
        cout << a1[i] << "\t";
    }
    cout << endl;

    b1[0] = "x1";
    b1[1] = "ya";
    b1[2] = "x1";
    b1[3] = "be";
    b1[4] = "bc";
    b1.Sort();
    for (int i = 0; i < 5; i++)
        cout << b1[i] << "\t";
    cout << endl;
    return 0;
}