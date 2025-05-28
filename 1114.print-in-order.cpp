#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock, [&]{return state == 0;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 1;
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock, [&]{return state == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx); 
        cv.wait(lock, [&]{return state == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lock.unlock();
        cv.notify_all();
    }
private:
    int state{0};
    std::mutex mtx;
    std::condition_variable cv;
};
// @lc code=end

