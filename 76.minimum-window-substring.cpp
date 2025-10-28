#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        } 

        vector<int> target(256, 0);
        for (int i = 0; i < t.size(); ++i) {
            target[t[i]] = target[t[i]] + 1;
        }


        int left = 0, right = 0;
        vector<int> recordTimes(256, 0); // 因为不要求顺序，所以记录各个字符已经出现的次数即可
        int remain = t.size(); // 用来记录出现的总次数。

        string res = "";
        int minLen = s.size() + 1;

        while (right < s.size()) {
            while (remain > 0 && right < s.size()) {
                auto charRight = s[right];
                if (target[charRight] > 0) { // 出现了目标字符
                    recordTimes[charRight] += 1; // 记录目标字符出现的次数
                    // 如果目标字符出现的次数尚未达到要求，则每出现一次，总数减去一次
                    if (recordTimes[charRight] <= target[charRight]) {
                        remain -= 1;
                    }
                    // 同步调整左侧窗口：立即去除首部出现的多余的目标字符
                    while (target[s[left]] == 0 // 不在目标集合中的字符
                        || (recordTimes[s[left]]) > target[s[left]]) // 出现次数大于要求的
                    { 
                        if (recordTimes[s[left]] > 0) {
                            recordTimes[s[left]] -= 1; 
                        }
                        ++left;
                    }
                }
                ++right;
            }

            if (remain != 0 || left >= s.size()) { // 遍历到结尾，也没有凑齐所有字符
                break;
            }

            // 提取目标字符串
            if (right - left < minLen) {
                minLen = right - left;
                res = s.substr(left, minLen);
            }

            // 移动左侧窗口
            // 说明：left指向的字符是最小满足条件，移除后，即不满足条件，从而开启下一轮循环。
            recordTimes[s[left]] -= 1; 
            ++left;
            remain += 1;
        }

        return res;
    }
};
// @lc code=end

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution sol;
    auto res = sol.minWindow(s, t);

    cout << "res = " << res << endl;
    return 0;
}
