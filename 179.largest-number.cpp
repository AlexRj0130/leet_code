#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums; 
        for (auto item : nums) {
            strNums.push_back(to_string(item));
        }

        auto cmp = [](const string &a, const string &b) {
            return a + b > b + a;
        };

        sort(strNums.begin(), strNums.end(), decltype(cmp)());

        string res;
        for (const auto &item : strNums) {
            res.append(item);
        }
        
        if (res.length() > 0 && res[0] == '0') {
            return "0";
        }

        return res;
    }
};
// @lc code=end

