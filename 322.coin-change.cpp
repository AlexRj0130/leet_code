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
        if (amount < 0) {
            return -1;
        } else if (amount == 0) {
            return 0;
        }

        vector<int> dp(amount + 1, -1);
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] > amount) { // 将无用的硬币直接过滤掉。
                continue;
            }
            dp[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            if (dp[i] > 0) {
                continue;
            }

            int resTmp = -1;
            for (int j = 0; j < coins.size(); ++j) {
                int preIndex = i - coins[j];
                if (preIndex < 0) { // 将无用的组合直接过滤掉。
                    continue;
                }

                int minTmp = dp[preIndex];
                if (minTmp <= 0) { // 将状态数组中不存在记录的数据直接过滤掉。
                    continue;
                }

                if (resTmp <= 0) { // 更新状态数组。
                    resTmp = minTmp + 1;
                } else {
                    resTmp = min(resTmp, minTmp + 1);
                }
            }

            dp[i] = resTmp;
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