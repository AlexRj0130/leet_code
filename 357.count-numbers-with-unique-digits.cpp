#include <vector>
#include <array>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // return countHelp(n);
        // return countHelpFromRecord(n);
        return countHelpFromCompute(n);
    }
private: 
    int countHelpFromCompute(int n) {
        if (n <= 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        } else if (n == 2) {
            return 91;
        }

        int total = 91;

        int start = 3;
        int remain = 8;
        int tmp = 81;
        while (start <= n) {
            tmp = tmp * remain;
            total += tmp;
            start += 1;
            remain -= 1;
        }

        return total;
    }

    int countHelpFromRecord(int n) {
        array<int, 9> record{1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851};
        return record[n];
    }

    int countHelp(int n) {
        if (n <= 0) {
            return 1;
        } 

        int x = 1;
        while (n > 0) {
            x *= 10;
            --n;
        }

        int count = 0;
        for (int i = 0; i < x; ++i) {
            array<bool, 10> record;
            record.fill(false);

            int tmp = i;
            bool tmpCheck = true;
            while (tmp > 0) {
                auto flag = (tmp % 10);
                if (record[flag]) {
                    tmpCheck = false;
                    break;
                }
                record[flag] = true;
                tmp /= 10;
            }

            if (tmpCheck) {
                ++count;
            }
        }

        return count;
    }
};
// @lc code=end

int main() {
    Solution sol;
    cout << "res 0 = " << sol.countNumbersWithUniqueDigits(0) << endl;
    cout << "res 1 = " << sol.countNumbersWithUniqueDigits(1) << endl;
    cout << "res 2 = " << sol.countNumbersWithUniqueDigits(2) << endl;
    cout << "res 3 = " << sol.countNumbersWithUniqueDigits(3) << endl;
    cout << "res 4 = " << sol.countNumbersWithUniqueDigits(4) << endl;
    cout << "res 5 = " << sol.countNumbersWithUniqueDigits(5) << endl;
    cout << "res 6 = " << sol.countNumbersWithUniqueDigits(6) << endl;
    cout << "res 7 = " << sol.countNumbersWithUniqueDigits(7) << endl;
    cout << "res 8 = " << sol.countNumbersWithUniqueDigits(8) << endl;
    return 0;
}

