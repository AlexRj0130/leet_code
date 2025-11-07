#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1) {
            return;
        }

        // 转置
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 水平翻转
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    
    Solution sol;
    sol.rotate(matrix);
    return 0;
}