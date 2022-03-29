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
 * @Date         : 2022-03-29 13:12:50
 * @LastEditors  : MCD
 * @LastEditTime : 2022-03-29 13:44:04
 * @FilePath     : /My_Cpp_test/Practice/并发编程/1.3_runtime.cpp
 * @Description  : 
 * 
 * ******************************************
 */

#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

using namespace std;

//使得每个线程具有最小数目的元素以避免过多的线程开销
template <typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = accumulate(first, last, result);   //累加求和
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    unsigned int const length = distance(first, last);

    if (!length)
        return init;

    unsigned int const min_per_thread = 255;
    unsigned int const max_threads = (length - 1 + min_per_thread) / min_per_thread;
    cout << "max_threads = " << max_threads << endl;

    unsigned int const hardware_threads = thread::hardware_concurrency();
    cout << "hardware_threads = " << hardware_threads << endl;

    unsigned int const num_threads = min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    cout << "num_threads = " << num_threads << endl;

    unsigned int const block_size = length / num_threads;
    cout << "block_size = " << block_size << endl;

    vector<T> result(num_threads);
    vector<thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned int i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        advance(block_end, block_size);
        threads[i] = thread(accumulate_block<Iterator, T>(), block_start, block_end, ref(result[i]));
        block_start = block_end;
    }

    accumulate_block<Iterator, T>()(block_start, last, result[num_threads - 1]);
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
    // for(auto & th:threads)
    //     th.join();

    return accumulate(result.begin(), result.end(), init);
}

int main(int argc, char const *argv[])
{
    vector<int> v{ 3, 4, 5, 6 };
    int res = 0;
    cout << v.size() << endl;
    cout << parallel_accumulate(v.begin(), v.end(), res);
    return 0;
}