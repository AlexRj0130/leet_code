#include <string>
#include <stack>

using namespace std;

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        stack<string> strStack; 
        string word;
        for (int i = 0; i < s.size(); ++i) {
            auto ch = s[i];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
                word += ch;
                continue;
            }

            if (!word.empty()) {
                strStack.push(word);
                word = "";
            }
        }

        if (!word.empty()) {
            strStack.push(word);
            word = "";
        }

        string res;
        while (!strStack.empty()) {
            auto item = strStack.top();
            strStack.pop();
            if (res.empty()) {
                res = item;
            } else {
                res += ' ';
                res += item;
            }
        }

        return res;
    }
};
// @lc code=end

