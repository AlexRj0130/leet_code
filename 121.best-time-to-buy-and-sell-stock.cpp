#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } 

        int maxRevenue = 0;
        int minIndex = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[minIndex] > prices[i - 1]) {
                minIndex = i - 1;
            }

            int revenue = prices[i] - prices[minIndex];
            maxRevenue = maxRevenue < revenue ?  revenue : maxRevenue;
        }

        return maxRevenue;
    }
};
// @lc code=end

int main() {

    auto v = vector<int>{3,3,5,0,0,3,1,4};

    Solution sol;
    sol.maxProfit(v);

    return 0;
}

