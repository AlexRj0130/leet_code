#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] > b[0]) {
                return true;
            } else if (a[0] < b[0]) {
                return false;
            } else {
                return a[1] < b[1];
            }
        });

        vector<vector<int>> res;
        for (auto &item : people) {
            if (res.size() <= 0) {
                res.push_back(item);
                continue;
            }

            res.insert(res.begin() + item[1], item);
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> people{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}; 
    Solution sol; 
    sol.reconstructQueue(people);
    return 0;
}