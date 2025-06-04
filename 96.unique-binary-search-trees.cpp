#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return n;
        }

        return countTree(1, n);
    }
private:
    int countTree(int start, int end) {
        if (start >= end) {
            return 1;
        }

        int res = 0;
        for (int mid = start; mid <= end; ++mid) {
            int resLeft = 1, resRight = 1;
            if (mid != start) {
                resLeft = countTreeWithMap(start, mid - 1);
            }
            if (mid != end) {
                resRight = countTreeWithMap(mid + 1, end);
            }
            res += (resLeft * resRight);
        }
        return res;
    }
    int countTreeWithMap(int start, int end) {
        int key = start * 1000 + end;
        if (countMap.contains(key)) {
            return countMap[key];
        }

        auto val = countTree(start, end);
        countMap.insert({key, val});
        return val;
    }
private:
    unordered_map<int, int> countMap;
};
// @lc code=end

