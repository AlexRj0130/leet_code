#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        init(s, p); 
        vector<int> res;
        // 定位起始位置
        if (!findNextStaPos(s, 0)) {
            return res;
        }

        // 双指针遍历字符串 s
        while (right < s.size()) {
            auto rightChar = s[right];
            if (charTargetCount[char2Index(rightChar)] == 0) {
                if (!findNextStaPos(s, right)) {
                    return res;
                }
                continue;
            } else {
                ++charCurCount[char2Index(rightChar)];
                ++curCount;
                while (charCurCount[char2Index(rightChar)] > charTargetCount[char2Index(rightChar)]) {
                    moveLeft(s);
                }
            }

            if (curCount >= totalCount) {
                res.push_back(left + 1);
                moveLeft(s); 
            }
            ++right;
        }

        return res;
    }
private:
    void moveLeft(const string &s) {
        ++left;
        auto leftChar = s[left]; 
        --charCurCount[char2Index(leftChar)];
        --curCount;
    }

    bool findNextStaPos(const string &s, int sta) {
        curCount = 0;
        charCurCount = vector<int>(26, 0);

        while (sta < s.size()) {
            if (charTargetCount[char2Index(s[sta])] > 0) {
                left = sta - 1;
                right = sta;
                return true;
            }
            ++sta;
        }
        return false;
    }

    int char2Index(char ch) {
        return ch - 'a';
    }

    void init(const string &s, const string &p) {
        charTargetCount = vector<int>(26, 0);
        totalCount = 0;

        charCurCount = vector<int>(26, 0);
        curCount = 0;

        for (auto ch : p) {
            ++charTargetCount[char2Index(ch)];
            ++totalCount;
        }
    }
private:
    vector<int> charTargetCount;
    int totalCount;

    vector<int> charCurCount;
    int curCount;

    int left = -1, right = 0;
};
// @lc code=end

int main() {
    string s = "acdcaeccde", p = "c";
    Solution sol;
    auto res = sol.findAnagrams(s, p);
    return 0;
}
