#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int size = citations.size();
        vector<int> count(size + 1, 0); 

        // 统计引用次数为 item 的论文的数量, 下标为引用次数，值为论文数量
        for (auto item : citations) {
            if (item >= size) {
                ++count[size];
            } else {
                ++count[item];
            }
        }

        int sum = 0;
        for (int i = size; i >= 0; --i) {
            sum += count[i];
            if (sum >= i) {
                return i;
            }
        }

        return 0;
    }
};
// @lc code=end

