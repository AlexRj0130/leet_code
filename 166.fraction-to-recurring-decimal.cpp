#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        } 

        long long llNumerator = numerator;
        long long llDenominator = denominator;
        int signFlag = false;
        if (llNumerator > 0 && llDenominator < 0) {
            signFlag = true;
        } else if (llNumerator < 0 && llDenominator > 0) {
            signFlag = true;
        }
        llNumerator = llNumerator >= 0 ? llNumerator : (0-llNumerator);
        llDenominator = llDenominator >= 0 ? llDenominator : (0-llDenominator);

        vector<pair<int, int>> vec;
        unordered_set<int> uSet;
        bool repeatFlag = false;
        long long repeatVal = 0;

        long long intVal = llNumerator < llDenominator ? 0 : llNumerator / llDenominator;
        llNumerator = llNumerator % llDenominator;
        llNumerator *= 10;
        while (repeatFlag == false && llNumerator != 0) {
            if (llNumerator >= llDenominator) {
                if (uSet.contains(llNumerator)) {
                    repeatFlag = true;
                    repeatVal = llNumerator;
                    break;
                }
                vec.push_back({llNumerator, llNumerator / llDenominator});
                uSet.insert(llNumerator);
                llNumerator %= llDenominator;
            } else {
                vec.push_back({llNumerator, 0});
                uSet.insert(llNumerator);
            }
            llNumerator *= 10;
        }

        string res;
        if (signFlag) {
            res += "-";
        }
        res += to_string(intVal);

        if (vec.size() > 0) {
            res += ".";
        }

        for (auto & item : vec) {
            if (repeatFlag && item.first == repeatVal) {
                res += "(";
            }
            res += to_string(item.second);
        }

        if (repeatFlag) {
            res += ")";
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    sol.fractionToDecimal(-2147483648, 1);
    return 0;
}

