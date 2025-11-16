#include <string>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        if (s.size() <= 0) {
            return "";
        } 

        stack<string> numStack;
        stack<string> itemStack;

        string numStr, itemStr;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                numStr += s[i];
            } else if (islower(s[i])) {
                itemStr += s[i];
            } else if (s[i] == '[') {
                numStack.push(numStr);
                itemStack.push(itemStr);
                numStr = "";
                itemStr = "";
            } else if (s[i] == ']') {
                auto preNumStr = numStack.top();
                auto preItem = itemStack.top();
                numStack.pop();
                itemStack.pop();
                
                auto preNum = stoi(preNumStr);
                while (preNum > 0) {
                    preItem += itemStr;
                    --preNum;
                }
                itemStr = preItem;
            }
        }

        return itemStr;
    }
};
// @lc code=end

int main() {
    string str = "3[a2[c]]";
    Solution sol;

    return 0;
}