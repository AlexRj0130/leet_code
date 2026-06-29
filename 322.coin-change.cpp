#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0 || coins.size() <= 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }

        vector<int> dp(amount + 1, -1);
        for (auto item : coins) {
            if (item > amount) {
                continue;
            }
            dp[item] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] == 1) {
                continue;
            }

            int tmpMin = -1;
            for (auto coin : coins) {
                int remain = i - coin;
                if (remain <= 0) {
                    continue;
                }

                if (dp[remain] < 0) {
                    continue;
                }

                tmpMin = tmpMin == -1 ? dp[remain] + 1 : min(tmpMin, dp[remain] + 1);
            }
            dp[i] = tmpMin;
        }

        return dp[amount];
    }
private:
};
// @lc code=end

int main() {
    vector<int> coins = {2};
    int amount = 1;

    Solution sol;
    auto res = sol.coinChange(coins, amount);
    cout << "res = " << res << endl; 

    return 0;
}