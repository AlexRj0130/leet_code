#include <vector>
#include <limits>

using namespace std;

/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } 

        init(prices);

        int res = 0;
        for (int i = 2; i <= prices.size(); ++i) {
            auto price = prices[i - 1];
            mDpHold[i] = max(mDpHold[i - 1], mDpNotHold[i - 1] - price);
            mDpNotHold[i] = max(mDpNotHold[i - 1], mDpCool[i - 1]);
            mDpCool[i] = mDpHold[i - 1] + price;
            res = max({mDpHold[i], mDpNotHold[i], mDpCool[i]});
        }

        return res;
    }
private:
    void init(const vector<int>& prices) {
        mSize = prices.size();
        mDpHold = vector<int>(mSize + 1, 0);
        mDpNotHold = vector<int>(mSize + 1, 0);
        mDpCool = vector<int>(mSize + 1, 0);
        
        mDpHold[1] = 0 - prices[0];
        mDpNotHold[1] = 0;
        mDpCool[1] = 0;
    }

private:
    vector<int> mDpHold;
    vector<int> mDpNotHold;
    vector<int> mDpCool;
    int mSize{0};
};
// @lc code=end

int main() {
    vector<int> data({1,2,3,0,2});
    Solution sol;
    auto res = sol.maxProfit(data);
    return 0;
}

