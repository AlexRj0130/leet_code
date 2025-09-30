#include <string>

using namespace std;

/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() == 0) {
            return num2;
        }

        if (num2.size() == 0) {
            return num1;
        }

        string res;

        int remain = 0, i=num1.size() - 1,j=num2.size() - 1;
        while(i >= 0 || j >= 0 || remain > 0) {
            char c1 = i >= 0 ? num1[i] : '0';
            char c2 = j >= 0 ? num2[j] : '0';
            int v1 = c2i(c1);
            int v2 = c2i(c2);

            int tmp = v1 + v2 + remain;

            res = (i2c(tmp%10)) + res;
            remain = tmp/10;

            --i, --j;
        }

        return res;
    }

private:
    int c2i(char c) {
        return c - '0';
    }

    char i2c(int i) {
        return '0' + i;
    }
};
// @lc code=end

int main() {
    string num1 = "11", num2="123";

    Solution sol;

    sol.addStrings(num1, num2);

    return 0;
}

