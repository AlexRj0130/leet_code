#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res; 
        if (s.size() <= 10) {
            return res;
        } 

        unordered_map<string, int> countMap;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string subStr(s.begin() + i, s.begin() + i + 10);
            if (countMap.contains(subStr)) {
                ++countMap[subStr];
                continue;
            }
            countMap.insert({subStr, 1});
        }

        for (const auto &item : countMap) {
            if (item.second > 1) {
                res.push_back(item.first);
            }
        }

        return res;
    }
};
// @lc code=end

