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
        vector<vector<string>> result;  // 存储所有符合条件的分割方案
        vector<string> path;            // 存储当前分割路径
        backtrack(s, 0, path, result);  // 从索引0开始回溯
        return result;
    }
private:
    // 回溯函数：start表示当前处理的起始索引，path是当前分割路径，result是最终结果
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        // 终止条件：起始索引到达字符串末尾，说明当前路径是有效分割
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        // 枚举从start开始的所有可能分割点
        for (int i = start; i < s.size(); ++i) {
            // 判断子串s[start..i]是否为回文串
            if (isPalindrome(s, start, i)) {
                // 若是回文串，加入当前路径
                path.push_back(s.substr(start, i - start + 1));
                // 递归处理剩余部分（i+1开始）
                backtrack(s, i + 1, path, result);
                // 回溯：移除当前子串，尝试下一个分割点
                path.pop_back();
            }
        }
    }

    // 双指针法判断子串s[left..right]是否为回文串
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

