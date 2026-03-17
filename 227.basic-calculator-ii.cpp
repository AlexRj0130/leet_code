#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        // 1.逐一读取各个数值和运算符，然后转后缀表达式。
        // 2.使用后缀表达式计算最终数值。 
        toPostOrder(s);
        
        vector<string> res;
        for (const auto & item : vecPost) {
            if (!isOp(item)) {
                res.push_back(item);
                continue;
            }

            auto b = res.back();
            res.pop_back();
            auto a = res.back();
            res.pop_back();

            auto resItem = calculateHelp(a, b, item);
            res.push_back(to_string(resItem));
        }
        return stoi(res.back());
    }
private:
    void toPostOrder(const string &s) {
        string numStrTmp;
        for (char c : s) {
            if (isspace(c)) {
                if (!numStrTmp.empty()) {
                    vecPost.push_back(numStrTmp);
                    numStrTmp = "";
                }
                continue;
            }

            if (isdigit(c)) {
                numStrTmp += c;
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (!numStrTmp.empty()) {
                    vecPost.push_back(numStrTmp);
                    numStrTmp = "";
                }
                pushOp(c);
            }
        }

        if (!numStrTmp.empty()) {
            vecPost.push_back(numStrTmp);
            numStrTmp = "";
        }        
        while (!vecOp.empty()) {
            auto op = vecOp.back();
            vecOp.pop_back();
            vecPost.push_back(op);
        }
    }

    void pushOp(char op) {
        string strOp;
        strOp += op;

        while (!opPriority(strOp)) {
            string op = vecOp.back();
            vecOp.pop_back();
            vecPost.push_back(op);
        }

        vecOp.push_back(strOp);
    }
    
    bool opPriority(string newOp) {
        if (vecOp.empty()) {
            return true;
        }

        auto topOp = vecOp.back();
        if (topOp == "*" || topOp == "/") {
            return false;
        } else if (newOp == "+" || newOp == "-") {
            return false;
        } 

        return true;
    } 

    int calculateHelp(string strA, string strB, string strOp) {
        char op = strOp[0];

        int a = stoi(strA);
        int b = stoi(strB);

        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }

        return 0;
    }

    bool isOp(string val) {
        return val == "+" || val == "-" || val == "*" || val == "/";
    }

    

private:
    vector<string> vecPost;
    vector<string> vecOp;
};
// @lc code=end


int main() {
    string exp = " 3/2 ";

    Solution sol;
    sol.calculate(exp);

    return 0;
}
