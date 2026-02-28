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

        sort(strNums.begin(), strNums.end(), cmp);

        string res;
        for (const auto &item : strNums) {
            res.append(item);
        }
        
        if (res.length() > 0 && res[0] == '0') {
            return "0";
        }
        
        return res;
    }
private:
    static bool cmp(string a, string b) {
         if (a.length() == b.length()) {
                return a > b;
            }

            bool flag = false;

            if (a.length() < b.length()) {
                swap(a, b);
                flag = true;
            }

            string aLeft = a.substr(0, b.length());
            string aRight = a.substr(b.length(), a.length() - b.length());
            
            if (aLeft != b) {
                return !flag ? aLeft > b : aLeft < b;
            }

            return !flag ? cmp(aRight, b) : cmp (b, aRight);
    }
};
// @lc code=end

