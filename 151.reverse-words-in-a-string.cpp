#include <string>
#include <vector>

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
        string str;
        auto vStr = split(s);
        while (!vStr.empty()) {
            if (str.empty()) {
                str = vStr.back();
            } else {
                str += " ";
                str += vStr.back();
            }
            vStr.pop_back();
        }

        return str;
    }
private:
    vector<string> split(const string &s) {
        if (s.size() <= 0) {
            return {};
        }

        vector<string> res;
        string tmp;
        for (auto item : s) {
            if (isspace(item)) {
                if (!tmp.empty()) {
                    res.push_back(tmp);
                    tmp = "";
                }
            } else {
                tmp += item;
            }
        }
        
        if (!tmp.empty()) {
            res.push_back(tmp);
            tmp = "";
        }
        return res;
    }
};
// @lc code=end

