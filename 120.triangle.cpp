#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int tSize = triangle.size(); 
        if (tSize <= 0) {
            return 0;
        }

        vector<int> res(tSize, 0);
        for (int i = 0; i < tSize; ++i) {
            res[i] = triangle[tSize - 1][i];
            for (int j = i - 1, k = tSize - 2; j >= 0 && k>= 0; --j, --k) {
                int val = triangle[k][j];
                res[j] = min(val + res[j + 1], val + res[j]);
            }
        }

        return res[0];
    }
};
// @lc code=end

int main() {
    vector<vector<int>> data;
    data.push_back({2});
    data.push_back({3, 4});
    data.push_back({6, 5, 7});
    data.push_back({4, 1, 8, 3});
    
    Solution sol;
    auto res = sol.minimumTotal(data);
    return 0;
}
