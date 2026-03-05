#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        } 

        vector<bool> vec(n, true);
        vec[0] = vec[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (vec[i] == false) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                vec[j] = false;
            }
        }

        int res = 0;
        for (auto flag : vec) {
            res += (flag ? 1 : 0);
        }
        return res;
    }
};
// @lc code=end

