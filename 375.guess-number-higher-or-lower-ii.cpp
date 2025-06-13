#include <vector>
#include <iostream>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        return tab(n);
    }

private:
    int tab(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int s = n; s >= 1; s--) {
            for (int e = s + 1; e <= n; e++) {
                int ans = INT_MAX;
                for (int i = s; i <= e; i++) {
                    ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                }
                dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }

    int faildResult(int n) {
        mDpVec = vector<vector<int>>(n+2, vector<int>(n+2, 0));
        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                int dpTmp = std::numeric_limits<int>::max();
                for (int k = i; k <= j; ++k) {
                    int leftSum = k > i ? mDpVec[i][k - 1] : 0;
                    int rightSum = k < j ? mDpVec[k + 1][j] : 0;
                    dpTmp = min(dpTmp, k + max(leftSum, rightSum));
                }
                mDpVec[i][j] = dpTmp;
            }
        }

        return mDpVec[1][n];
    }

    int treeMethod(int n) {
        mDpVec = vector<vector<int>>(n+2, vector<int>(n+2, 0)); 
        for (int i = 0; i <= n; ++i) {
            mDpVec[i][i] = i;
        }

        for (int i = n; i >= 1; --i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int k= i; k <= j; ++k) {
                    int leftSum = k > i ? mDpVec[i][k - 1] : 0;
                    int rightSum = k < j ? mDpVec[k + 1][j] : 0;
                    mDpVec[i][j] = max(mDpVec[i][j],  leftSum + rightSum); 
                }
            }
        }

        return (1 + n) * n / 2 - mDpVec[1][n];
    }

private:
    vector<vector<int>> mDpVec;
};
// @lc code=end

int main() {
    Solution sol;
    cout << sol.getMoneyAmount(3) << endl;
    return 0;
}

