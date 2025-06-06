#include <vector>
#include <algorithm>

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
        std::sort(coins.begin(), coins.end());
        init(coins, amount);
        for (int i = 1; i <= amount; ++i) {
            int tmp = amount + 1;
            for (const auto &c : coins) {
                if (i - c < 0) {
                    continue;
                } else if (i - c == 0) {
                    tmp = 1;
                    break;
                }

                if (mDpVec[i - c] < 0) {
                    continue;
                }

                tmp = min(tmp, mDpVec[i - c] + 1);
            }
            mDpVec[i] = tmp == amount + 1 ? -1 : tmp;
        }

        return mDpVec[amount];
    }
private:
    void init(const vector<int>& coins, const int amount) {
        mDpVec = vector<int>(amount + 1, 0);
    }
private:
    vector<int> mDpVec;
};
// @lc code=end

int main() {
    vector<int> data({1,2147483647});
    Solution sol;
    auto res = sol.coinChange(data, 2);

    return 0;
}

