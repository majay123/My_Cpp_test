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
 * @Date         : 2022-03-30 15:15:35
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-31 12:53:50
 * @FilePath     : /My_Cpp_test/Practice/smart_ptr/unique_ptr.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

#include "shape.h"

using namespace std;

template <typename T>
class my_unique_ptr
{
  public:
    explicit my_unique_ptr(
        T *ptr = nullptr) noexcept : ptr_(ptr) {}

    ~my_unique_ptr() noexcept
    {
        delete ptr_;
    }

    T &operator*() const noexcept { return *ptr_; }
    T *operator->() const noexcept { return ptr_; }
    operator bool() const noexcept { return ptr_; }

    T *get() const noexcept { return ptr_; }

    my_unique_ptr(my_unique_ptr &&other) noexcept
    {
        cout << "move ctor" << endl;
        ptr_ = other.release();
    }

    template <typename U>
    my_unique_ptr(my_unique_ptr<U> &&other) noexcept
    {
        cout << "U move ctor" << endl;
        ptr_ = other.release();
    }

    // copy and swap  始终只有一个对象有管理这块空间的权限
    my_unique_ptr &operator=(my_unique_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    // 原来的指针释放所有权
    T *release() noexcept
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(my_unique_ptr &rhs) noexcept
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);   // 转移指针所有权
    }

  private:
    T *ptr_;
};

template<typename T>
void swap(my_unique_ptr<T> &lhs, my_unique_ptr<T> &rhs) noexcept {
    lhs.swap(rhs);
}

// 利用多态 上转 如果返回值为shape,会存在对象切片问题。
shape *create_shape(shape_type type)
{
    switch (type) {
    case shape_type::circle:
        return new circle();
    case shape_type::triangle:
        return new triangle();
    case shape_type::rectangle:
        return new rectangle();
    }
    return nullptr;
}


int main(int argc, char const *argv[])
{
    my_unique_ptr<shape> ptr1{create_shape(shape_type::circle)};
    // my_unique_ptr<shape> ptr2_2{ptr1};        // error 
    my_unique_ptr<shape> ptr2_2{std::move(ptr1)};    // ok
    if (ptr2_2.get() != nullptr && ptr1.get() == nullptr)
        ptr2_2.get()->print();

    my_unique_ptr<shape> ptr3{create_shape(shape_type::rectangle)};
//    ptr1 = ptr3;    // error
    ptr3 = std::move(ptr1); // ok
//    my_unique_ptr<circle> cl{create_shape(shape_type::circle)};  // error 因为create_shape返回的是shape 不能基类转子类
    my_unique_ptr<circle> cl{new circle()};
    my_unique_ptr<shape> ptr5(std::move(cl));  // ok unique<circle>转unique<circle>


    return 0;
}