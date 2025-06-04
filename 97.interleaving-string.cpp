#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        init(s1, s2, s3);
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                mDpVec[i][j] = (mDpVec[i-1][j-1] && (canSumEqualTo(s1[i-1], s2[j-1], s3.substr(i+j-2, 2))))
                    || (mDpVec[i-1][j] && (s1[i-1] == s3[i+j-1]))
                    || (mDpVec[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }

        return mDpVec[mSize1-1][mSize2-1];
    }
private:
    bool canSumEqualTo(char c1, char c2, string s) {
        return (string({c1, c2}) == s || string({c2, c1}) == s);
    }

    void init(const string &s1, const string &s2, const string &s3) {
        mSize1 = s1.size() + 1;
        mSize2 = s2.size() + 1;
        mDpVec = vector<vector<bool>>(mSize1, vector<bool>(mSize2, false));

        mDpVec[0][0] = true;
        for (int i = 1; i <= s1.size() && i <= s3.size() && s1[i-1] == s3[i-1]; ++i) {
            mDpVec[i][0] = true;
        }
        for (int j = 1; j <= s2.size() && j <= s3.size() && s2[j-1] == s3[j-1]; ++j) {
            mDpVec[0][j] = true;
        }
    }
private:
    int mSize1{0};
    int mSize2{0};
    vector<vector<bool>> mDpVec;
};
// @lc code=end

int main() {
    Solution sol;
    auto res = sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;    
}

