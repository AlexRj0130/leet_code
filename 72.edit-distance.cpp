#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        init(word1, word2);
        for (int i = 1; i <= mSize1; ++i) {
            for (int j = 1; j <= mSize2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    mDpVec[i][j] = mDpVec[i-1][j-1];
                    continue;
                }

                mDpVec[i][j] = min(min(mDpVec[i-1][j-1], mDpVec[i-1][j]), mDpVec[i][j-1]) + 1;
            }
        }
        return mDpVec[mSize1][mSize2];
    }
private:
    void init(const string &word1, const string &word2) {
        mSize1 = word1.size();
        mSize2 = word2.size();

        mDpVec = vector<vector<int>>(mSize1 + 1, vector<int>(mSize2 + 1, 0));

        for (int i = 1; i <= mSize1; ++i) {
            mDpVec[i][0] = i;
        }

        for (int j = 1; j <= mSize2; ++j) {
            mDpVec[0][j] = j;
        }
    }

private:
    int mSize1{0};
    int mSize2{0};
    vector<vector<int>> mDpVec;
};
// @lc code=end

int main() {
    Solution sol;
    auto res = sol.minDistance("horse", "ros");
    return 0;
}

