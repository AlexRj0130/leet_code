#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int citSize = citations.size(); 
        if (citSize <= 0) {
            return 0;
        }

        int res = 0;
        int sta = 0, end = citSize - 1;
        while (sta <= end) {
            int mid = (sta + end) / 2;
            if (isHIndex(citations[mid], mid, citSize)) {
                res = citSize - mid;
                end = mid - 1;
            } else {
                sta = mid + 1;
            }
        }
        return res;
    }
private:
    bool isHIndex(const int indexCit, const int index, const int total) {
        int count = total - index;
        return indexCit >= count;
    }
};
// @lc code=end

int main() {
    vector<int> vec = {11,15};
    Solution sol;
    sol.hIndex(vec);
    return 0;
}