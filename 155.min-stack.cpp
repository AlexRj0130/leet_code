#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
struct MinStackElement {
    int val;
    int minVal;
    MinStackElement(int val, int minVal) : val(val), minVal(minVal) {} 
};

class MinStack {
public:
    MinStack() {
        minStack = {}; 
    }
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push(MinStackElement(val, val));
        } else {
            auto preMin = getMin();
            minStack.push(MinStackElement(val, min(val, preMin)));
        }
    }
    
    void pop() {
        minStack.pop(); 
    }
    
    int top() {
        return minStack.top().val; 
    }
    
    int getMin() {
        return minStack.top().minVal; 
    }
private:
    stack<MinStackElement> minStack;
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

