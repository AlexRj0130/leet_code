#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {};
        } 

        vector<string> res;
        backTrace(0, 0, "", n, res);
        return res;
    }
private:
    void backTrace(int left, int right, string record, const int n, vector<string> &res) {
        if (left >= n && right >= n) {
            res.push_back(record);
            return;
        }

        if (left < n) {
            backTrace(left + 1, right, record + '(', n, res);
        }

        if (right < left) {
            backTrace(left, right + 1, record + ')', n, res);
        }
    }
};

// @lc code=end

int main() {
    Solution sol;
    auto res = sol.generateParenthesis(4);
    for_each(res.begin(), res.end(), [](const string &item){
        cout << item << endl;
    });

    return 0;
}

