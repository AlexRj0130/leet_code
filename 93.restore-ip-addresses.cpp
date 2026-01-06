#include <vector>
#include <string>

using namespace std;

/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res; 
        vector<string> trace;
        dfs(s, 0, 0, res, trace);
        return res;
    }
private:
    void dfs(const string &s, const int depth, const int start, vector<string> &res, vector<string> &trace) {
        if (start > s.size() || depth > 4) {
            return;
        }

        if (start == s.size() && depth == 4) {
            res.push_back(vecStrToIP(trace));
            return;
        }

        int maxLen = 3;
        if (start < s.size() && s[start] == '0') {
            maxLen = 1;
        }

        for (int i = 1; i <= maxLen && (start + i - 1) < s.size(); ++i) {
            string sub = s.substr(start, i);
            int subI = stoi(sub);
            if (!(subI >= 0 && subI <= 255)) {
                continue;
            }
            
            trace.push_back(sub);
            dfs(s, depth + 1, start + i, res, trace);
            trace.pop_back();
        }
    }

    string vecStrToIP(const vector<string> &trace) {
        string res = "";
        for (int i = 0; i < trace.size(); ++i) {
            if (i == 0) {
                res = trace[i];
            } else {
                res = res + "." + trace[i];
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    string str = "25525511135";
    Solution sol;
    sol.restoreIpAddresses(str);
    return 0;
}