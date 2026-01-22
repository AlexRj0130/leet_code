#include <vector>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        // 1. DP 预处理：dp[i][j] 表示 s[i..j] 是否为回文串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 先处理长度为1的子串（i==j）
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // 处理长度>=2的子串（按子串长度从小到大遍历）
        for (int len = 2; len <= n; ++len) {  // len 表示子串长度
            for (int i = 0; i + len <= n; ++i) {  // i 是子串起始索引
                int j = i + len - 1;  // j 是子串结束索引
                if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
            }
        }

        // 2. 基于DP数组的回溯
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, dp, path, result);
        return result;
    }
private:
    // 回溯函数：直接使用dp数组判断回文，无需重复计算
    void backtrack(const string& s, int start, const vector<vector<bool>>& dp,
                   vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            // 直接查表，O(1) 判断 s[start..i] 是否为回文
            if (dp[start][i]) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, dp, path, result);
                path.pop_back();  // 回溯
            }
        }
    }
};
// @lc code=end

