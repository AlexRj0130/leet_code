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
        vector<string> splitExpr = splitExpression(expression); 

        vector<vector<string>> postOrderExpr; 
        dfsToPostOrder(splitExpr, 0, {}, {}, postOrderExpr);

        vector<int> res;
        for (const auto &expr : postOrderExpr) {
            auto resItem = calculatePostOrder(expr);
            res.push_back(resItem);
        }
        return res;
    }
private:
    int calculatePostOrder(const vector<string> &expr) {
        vector<string> vStack;
        for (const auto &item : expr) {
            if (!isOperator(item)) {
                vStack.push_back(item);
            } else {
                auto b = vStack.back();
                vStack.pop_back();
                auto a = vStack.back();
                vStack.pop_back();
                vStack.push_back(calculateHelp(a, b, item));
            }
        }
        return stoi(vStack[0]);
    }

    string calculateHelp(const string &a, const string &b, const string &op) {
        int aInt = stoi(a);
        int bInt = stoi(b);
        int res = 0;
        if (op == "+") {
            res = aInt + bInt; 
        } else if (op == "-") {
            res = aInt - bInt;
        } else if (op == "*") {
            res = aInt * bInt;
        } else {
            res = 0;
        }
        return to_string(res);
    }

    void dfsToPostOrder(const vector<string> &expr, int depth, vector<string> trace, vector<string> opStack, vector<vector<string>> &res) {
        if (depth >= expr.size()) {
            while (!opStack.empty()) {
                trace.push_back(opStack.back());
                opStack.pop_back();
            }
            res.push_back(trace);
            return;
        }

        const auto &item = expr[depth];
        if (!isOperator(item)) {
            trace.push_back(item);
            dfsToPostOrder(expr, depth + 1, trace, opStack, res);
        } else {
            int opStackSize = opStack.size();
            for (int i = 0; i <= opStackSize; ++i) {
                opStack.push_back(item);
                dfsToPostOrder(expr, depth + 1, trace, opStack, res);
                opStack.pop_back();

                if (!opStack.empty()) {
                    trace.push_back(opStack.back());
                    opStack.pop_back();
                }
            }
        }
    }

    bool isOperator(const string &val) {
        return val == "+" || val == "-" || val == "*";
    }

    vector<string> splitExpression(const string &expr) {
        vector<string> res;
        
        string numTmp = "";
        for (auto item : expr) {
            if (isspace(item)) {
                if (numTmp.size() > 0) {
                    res.push_back(numTmp);
                    numTmp = "";
                }
                continue;
            } else if (isdigit(item)) {
                numTmp += item;
            } else if (item == '+' || item == '-' || item == '*') {
                if (numTmp.size() > 0) {
                    res.push_back(numTmp);
                    numTmp = "";
                } 
                res.push_back(string("") + item);
            }
        }
        if (numTmp.size() > 0) {
            res.push_back(numTmp);
            numTmp = "";
        }

        return res;
    }
};
// @lc code=end

int main() {
    string expr = "2-1-1";
    Solution sol;
    sol.diffWaysToCompute(expr);
    return 0;
}