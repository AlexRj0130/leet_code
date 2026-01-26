#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int totalTank = 0, res = 0;

        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            totalTank += gas[i] - cost[i];

            if (totalTank < 0) {
                res = i + 1;
                totalTank = 0;
            }
        }

        return totalGas >= totalCost ? res : -1;
    }
};
// @lc code=end

