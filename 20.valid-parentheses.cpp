#include <string>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        } 

        stack<char> stackVal;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    stackVal.push(s[i]);
                    continue;
                case '[':
                    stackVal.push(s[i]);
                    continue;
                case '{':
                    stackVal.push(s[i]);
                    continue;
                case ')':
                    if (stackVal.empty() || stackVal.top() != '(') {
                        return false;
                    }
                    stackVal.pop();
                    continue;
                case ']':
                    if (stackVal.empty() || stackVal.top() != '[') {
                        return false;
                    }
                    stackVal.pop();
                    continue;
                case '}':
                    if (stackVal.empty() || stackVal.top() != '{') {
                        return false;
                    }
                    stackVal.pop();
                    continue;
                default:
                    return false;
            }
        }

        return stackVal.empty();
    }
};
// @lc code=end

