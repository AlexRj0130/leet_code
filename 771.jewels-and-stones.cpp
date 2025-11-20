#include <string>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> ch2count; 

        for (auto ch : stones) {
            ++ch2count[ch];
        }

        int res = 0;
        for (auto ch : jewels) {
            res += ch2count[ch];
        }

        return res;
    }
};
// @lc code=end

