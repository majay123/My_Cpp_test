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
 * @LastEditTime : 2022-03-31 14:18:18
 * @FilePath     : /My_Cpp_test/Practice/smart_ptr/shared_ptr.cpp
 * @Description  :
 *
 * ******************************************
 */

#include <climits>
#include <iostream>
#include <thread>

#include "shape.h"

using namespace std;

class shared_count
{
  public:
    shared_count() : count_(1) {}

    // 增加计数
    void add_count()
    {
        count_++;
    }

    long reduce_count()
    {
        return --count_;
    }

    //获得计数
    long get_count()
    {
        return count_;
    }

  private:
    long count_;
};

template <typename T>
class my_shared_ptr
{
  public:
    explicit my_shared_ptr(T *ptr = nullptr) noexcept : ptr_(ptr)
    {
        if (ptr)
            shared_count_ = new shared_count();
    }

    // 实现强制转换需要的构造函数
    template <typename U>
    my_shared_ptr(const my_shared_ptr<U> &other, T *ptr) noexcept
    {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    ~my_shared_ptr() noexcept
    {
        // 最后一个my_shared_ptr再去删除对象与共享计数
        // ptr_不为空且此时共享计数减为0的时候,再去删除
        if (ptr_ && !shared_count_->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }

    T &operator*() const noexcept { return *ptr_; }
    T *operator->() const noexcept { return ptr_; }
    operator bool() const noexcept { return ptr_; }
    T *get() const noexcept { return ptr_; }

    // 带模板的拷贝与移动构造函数 模板的各个实例间并不天然就有 friend 关系，因而不能互访私有成员 ptr_ 和 shared_count_。
    // 需要下面显示声明
    template <typename U>
    friend class my_shared_ptr;

    template <typename U>
    my_shared_ptr(const my_shared_ptr<U> &other) noexcept
    {
        cout << "调用了带模板的拷贝构造!" << endl;
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    template <typename U>
    my_shared_ptr(my_shared_ptr<U> &&other) noexcept
    {
        cout << "调用了带模板的移动构造!" << endl;
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
            other.shared_count_ = nullptr;
        }
    }

    // copy and swap  始终只有一个对象有管理这块空间的权限
    my_shared_ptr &operator=(my_shared_ptr rhs) noexcept
    {
        rhs.swap(*this);
        return *this;
    }

    void swap(my_shared_ptr &rhs) noexcept
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    long use_count() const noexcept
    {
        if (ptr_)
            return shared_count_->get_count();
        else
            return 0;
    }

  private:
    T *ptr_;
    shared_count *shared_count_;
};

template <typename T>
void swap(my_shared_ptr<T> &lhs, my_shared_ptr<T> &rhs) noexcept
{
    lhs.swap(rhs);
}

// 转型类型操作符
/*  转换类型操作符              作用
 * const_cast       去掉类型的const或volatile属性
 * static_cast      无条件转换，静态类型转换
 * dynamic_cast     又提阿健转换，动态类型转换，运行时检查类型安全（转换失败返回NULL）
 * reinterpret_cast 仅重新解释类型，但是没有进行二次进制转换
 */

// dynamic_cast
// 向上转换就是一个派生类转换成基类指针,等价于static_cast;
// 向下转换就是一个基类指针转换成派生类指针,因为基类指针可能实际指向基类对象也可能是派生类对象,
// 如果是基类对象.转换成派生类是可能出错的,因为对象并没有派生类方法.
// dynamic_cast具有类型检查的功能，比static_cast更安全
template <typename T, typename U>
my_shared_ptr<T> dynamic_pointer_cast(const my_shared_ptr<U> &other) noexcept
{
    T *ptr = dynamic_cast<T *>(other.get());
    return my_shared_ptr<T>(other, ptr);
}

// static_cast
// 基类和子类之间的转换:其中子类指针转换为父类指针是安全的，但父类指针转换为子类指针是不安全的（基类和子类之间的动态类型转换建议用dynamic_cast）。
// 基本数据类型转换，enum，struct，int，char，float等。static_cast不能进行无关类型（如非基类和子类）指针之间的转换
// 把任何类型的表达式转换成void类型
// static_cast不能去掉类型的const、volatile属性（用const_cast）
template <typename T, typename U>
my_shared_ptr<T> static_pointer_cast(const my_shared_ptr<U> &other) noexcept
{
    T *ptr = static_cast<T *>(other.get());
    return my_shared_ptr<T>(other, ptr);
}

// const_cast
// 目标类型只能是指针或者引用
template <typename T, typename U>
my_shared_ptr<T> const_pointer_cast(const my_shared_ptr<U> &other) noexcept
{
    T *ptr = const_cast<T *>(other.get());
    return my_shared_ptr<T>(other, ptr);
}

// reinterpret_cast
// 转换的类型必须是一个指针，应用、算术类型、函数指针或者成员指针
// 在比特级别上进行转换，可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值）。但不能将非32bit的实例转成指针。
// 最普通的用途就是在函数指针类型之间进行转换。
// 很难保证移植性。
template <typename T, typename U>
my_shared_ptr<T> reinterpret_pointer_cast(const my_shared_ptr<U> &other)
{
    T *ptr = reinterpret_cast<T *>(other.get());
    return my_shared_ptr<T>(other, ptr);
}

int main(int argc, char const *argv[])
{
    my_shared_ptr<circle> ptr1(new circle);
    cout << "use count of ptr1 is " << ptr1.use_count() << endl;

    my_shared_ptr<shape> ptr2, ptr3;
    cout << "use count of ptr2 was " << ptr2.use_count() << endl;
    ptr2 = ptr1;                                                  // my_shared_ptr<circle>隐式转换shared_ptr<shape> 调用带模板的拷贝构造
    cout << "use count of ptr2 was " << ptr2.use_count() << endl; // count + 1
    cout << "=============================" << endl;

    ptr3 = ptr1;
    cout << "此时3个my_shared_ptr指向同一个资源" << endl;
    cout << "use count of ptr1 is now " << ptr1.use_count() << endl;
    cout << "use count of ptr2 is now " << ptr2.use_count() << endl;
    cout << "use count of ptr3 is now " << ptr3.use_count() << endl;

    if (ptr1)
        cout << "\nptr1  is not empty" << endl;
    cout << "=============================" << endl;

    // 会先调用赋值函数,由编译器决定调用的是拷贝构造还是移动构造,造出一个新的临时对象出来,临时对象会在跳出作用域后被析构掉。
    // 在析构函数中,会先判断该临时对象的是否指向资源,如果没有,析构结束。否则,对引用计数减1,判断引用计数是否为0,如果为0,删除共享引用计数指针,否则不操作。
    cout << "此时2个my_shared_ptr指向同一个资源" << endl;
    ptr2 = move(ptr1);
    if (!ptr1 && ptr2) {
        cout << "ptr1 move to ptr2" << endl;
        cout << "use count of ptr1 is now " << ptr1.use_count() << endl;
        cout << "use count of ptr2 is now " << ptr2.use_count() << endl;
        cout << "use count of ptr3 is now " << ptr3.use_count() << endl;
    }
    cout << "=============================" << endl;

    // shape* -> circle* 使用dynamic_cast转换后,指针为空.此时资源还是被dptr2拥有,dptr1为0
    my_shared_ptr<shape> dptr2(new shape);
    my_shared_ptr<circle> dptr1 = dynamic_pointer_cast<circle>(dptr2); // 基类转子类
    cout << "use count of dptr1 is now " << dptr1.use_count() << endl; // 0
    cout << "use count of dptr2 is now " << dptr2.use_count() << endl; // 1
    cout << "=============================" << endl;

    // circle* -> circle* 使用dynamic_cast转换后,指针不为空,此时资源被两者共同使用,引用计数为2
    my_shared_ptr<shape> dptr3(new circle);
    my_shared_ptr<circle> dptr1_1 = dynamic_pointer_cast<circle>(dptr3);   // 基类转子类
    cout << "use count of dptr1_1 is now " << dptr1_1.use_count() << endl; // 2
    cout << "use count of dptr3 is now " << dptr3.use_count() << endl;     // 2
    cout << "=============================" << endl;

    // circle* -> shape* 使用dynamic_cast转换后,指针不为空,此时资源被两者共同使用,引用计数为2
    my_shared_ptr<circle> dptr3_1(new circle);
    my_shared_ptr<shape> dptr2_1 = dynamic_pointer_cast<shape>(dptr3_1);   // 子类转基类 上行转换,安全！
    cout << "use count of dptr2_1 is now " << dptr2_1.use_count() << endl; // 2
    cout << "use count of dptr3_1 is now " << dptr3_1.use_count() << endl; // 2
    cout << "=============================" << endl;

    // shape* -> circle* 使用static_cast转换后,指针为空  与dynamic_cast相比,不安全
    my_shared_ptr<shape> sptr2(new shape);
    my_shared_ptr<circle> sptr1 = static_pointer_cast<circle>(sptr2);  // // 基类转子类
    cout << "use count of sptr1 is now " << sptr1.use_count() << endl; // 2
    cout << "use count of sptr2 is now " << sptr2.use_count() << endl; // 2
    cout << "=============================" << endl;

    // circle* -> circle* 使用dynamic_cast转换后,指针不为空,此时资源被两者共同使用,引用计数为2
    my_shared_ptr<shape> sptr3(new circle);
    my_shared_ptr<circle> sptr1_1 = dynamic_pointer_cast<circle>(sptr3);   // 基类转子类
    cout << "use count of sptr1_1 is now " << sptr1_1.use_count() << endl; // 2
    cout << "use count of sptr3 is now " << sptr3.use_count() << endl;     // 2
    cout << "=============================" << endl;

    // circle* -> circle* 使用static_cast转换后,指针不为空,此时资源被两者共同使用,引用计数为2 等价于dynamic_cast
    my_shared_ptr<circle> sptr3_1(new circle);
    my_shared_ptr<shape> sptr2_1 = static_pointer_cast<shape>(sptr3_1);    //子类转基类 上行转换,安全！
    cout << "use count of sptr2_1 is now " << sptr2_1.use_count() << endl; // 2
    cout << "use count of sptr3_1 is now " << sptr3_1.use_count() << endl; // 2
    cout << "=============================" << endl;

    my_shared_ptr<const int> constV(new int);
    my_shared_ptr<int> s = const_pointer_cast<int>(constV);
    *s = 100;
    int a = reinterpret_pointer_cast<int>(s);
    cout << a << endl;

    return 0;
}