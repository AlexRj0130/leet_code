#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    MinStack() {
        valStack = stack<int>();
        minValStack = stack<int>();
    }
    
    void push(int val) {
        valStack.push(val);
        minValStack.push(minValStack.empty() ? val : (minValStack.top() < val ? minValStack.top() : val));
    }
    
    void pop() {
        valStack.pop();
        minValStack.pop();
    }
    
    int top() {
        return valStack.top();
    }
    
    int getMin() {
        return minValStack.top();
    }
private:
    stack<int> valStack;
    stack<int> minValStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

