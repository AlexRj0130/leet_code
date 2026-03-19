#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        auto expr = removeSpace(expression);

        vector<int> res;
        dfs(expr, res);
        return res;
    }
private:
    void dfs(const string &expression, vector<int> &res) {
        if (expression.size() <= 0) {
            return;
        }

        bool noOperator = true;
        for (int i = 0; i < expression.size(); ++i) {
            const auto ch = expression[i];
            if (isOperator(ch)) {
                noOperator = false;

                string leftExpr = expression.substr(0, i);
                vector<int> leftRes;
                dfs(leftExpr, leftRes);

                string rightExpr = expression.substr(i + 1, expression.size() - i - 1);
                vector<int> rightRes;
                dfs(rightExpr, rightRes);

                for (auto a : leftRes) {
                    for (auto b : rightRes) {
                        auto tmp = calculateHelp(a, b, ch);
                        res.push_back(tmp);
                    }
                }
            }
        }

        if (!noOperator) {
            return;
        }

        res.push_back(stoi(expression));
    }

    int calculateHelp(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
        }

        return 0;
    }

    string removeSpace(const string &expression) {
        string res;
        for (const auto &item : expression) {
            if (isspace(item)) {
                continue;
            }
            res += item;
        }
        return res;
    }

    bool isOperator(const char ch) {
        return ch == '+' || ch == '-' || ch == '*';
    }
};
// @lc code=end

int main() {
    string expr = "2-1-1";
    Solution sol;
    sol.diffWaysToCompute(expr);
    return 0;
}