#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) {
            return {};
        } 

        vector<int> res{0, 1};
        for (int i = 1; i < n; ++i) {
            appendAndSetBit(res, i);
        }

        return res;
    }
private:
    void appendAndSetBit(vector<int> &vec, int pos) {
        int srcSize = vec.size();
        int newSize = 2 * srcSize;

        vec.resize(newSize);

        for (int i = 1; i <= srcSize; ++i) {
            vec[newSize - i] = setBit(vec[i-1], pos);
        }
    }

    int setBit(int val, int pos) {
        return val | (1 << pos);
    }
};
// @lc code=end

