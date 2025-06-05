#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() <= 0) {
            return true;
        } 

        if (wordDict.size() <= 0) {
            return false;
        }

        init(s, wordDict);

        for (int i = 1; i <= s.size(); ++i) {
            if (mWordSet.contains(s.substr(0, i))) {
                mDpVec[i] = true;
                continue;
            }

            bool findFlag = false;
            for (int j = 1; j < i; ++j) {
                if (mDpVec[j] && mWordSet.contains(s.substr(j, i - j))) {
                    findFlag = true;
                    break;
                }
            }
            mDpVec[i] = findFlag;
        }

        return mDpVec[s.size()];
    }
private:
    void init(const string &s, const vector<string> &wordDict) {
        mSize = s.size() + 1;
        mDpVec = vector<bool>(mSize, false);

        for (const auto &word: wordDict) {
            mWordSet.insert(word);
        }

        mDpVec[0] = true;
        mDpVec[1] = mWordSet.contains(s.substr(0, 1));
    }
private:
    unordered_set<string> mWordSet;
    int mSize{0};
    vector<bool> mDpVec;
};
// @lc code=end

