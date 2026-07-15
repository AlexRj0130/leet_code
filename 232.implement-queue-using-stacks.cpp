#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {
        sPush = stack<int>();
        sPop = stack<int>();
    }
    
    void push(int x) {
        while (!sPop.empty()) {
            sPush.push(sPop.top());
            sPop.pop();
        }
        sPush.push(x);
    }
    
    int pop() {
        while (!sPush.empty()) {
            sPop.push(sPush.top());
            sPush.pop();
        }
        int res = sPop.top();
        sPop.pop();
        return res;
    }
    
    int peek() {
         while (!sPush.empty()) {
            sPop.push(sPush.top());
            sPush.pop();
        }
        int res = sPop.top();
        return res;
    }
    
    bool empty() {
        return sPush.empty() && sPop.empty();
    }
private:
    stack<int> sPush;
    stack<int> sPop;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

