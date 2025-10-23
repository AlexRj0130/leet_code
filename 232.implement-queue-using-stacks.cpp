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
        inStack = stack<int>(); 
        outStack = stack<int>(); 
    }
    
    void push(int x) {
        while(!outStack.empty()) {
            inStack.push(outStack.top());
            outStack.pop();
        }
        inStack.push(x);
    }
    
    int pop() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }

        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    int peek() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        } 
        return outStack.top();
    }
    
    bool empty() {
        return inStack.empty() && outStack.empty(); 
    }
private:
    stack<int> inStack;
    stack<int> outStack;
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

