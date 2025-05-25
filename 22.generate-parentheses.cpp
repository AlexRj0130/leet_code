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
        generate(0, 0, n, "", res); 
        return res;
    }
private:
    void generate(int nOpen, int nClose, int n, string subRes, vector<string> &res) {
        if (nOpen == n && nClose == n) {
            res.push_back(subRes);
            return;
        }

        if (nOpen < n) {
            generate(nOpen + 1, nClose, n, subRes + "(", res);
        }

        if (nClose < nOpen) {
            generate(nOpen, nClose + 1, n, subRes + ")", res);
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

