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
        int total_gas = 0, total_cost = 0; // 全局总油量和总耗油量
        int current_tank = 0, start = 0;   // 当前油箱油量、候选起点
        
        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_tank += gas[i] - cost[i]; // 累计当前起点的剩余油量
            
            // 若当前起点无法到达下一个加油站，更新起点为下一个
            if (current_tank < 0) {
                start = i + 1;
                current_tank = 0;
            }
        }
        
        // 总油量足够时返回起点，否则返回-1
        return total_gas >= total_cost ? start : -1;
    }
};
// @lc code=end

