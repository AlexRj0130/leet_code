#include <vector>
#include <array>
#include <limits>

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
        
    }
    
    void push(int val) {
        auto preMin = getMin(); 
        auto curMin = val <= preMin ? val : preMin;
        mStackData.push_back({val, curMin});
    }
    
    void pop() {
        mStackData.pop_back(); 
    }
    
    int top() {
        if (mStackData.empty()) {
            return std::numeric_limits<int>::max();
        } 

        return mStackData.back()[0];
    }
    
    int getMin() {
        if (mStackData.empty()) {
            return std::numeric_limits<int>::max();
        }
        return mStackData.back()[1];
    }
private:
    vector<std::array<int, 2>> mStackData;
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

