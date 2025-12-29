#include <string>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "/";
        } 

        vector<string> vStr;
        string word;
        for (int index = 0; index <= path.size(); ++index) {
            if (index == path.size()) {
                checkAndResetWord(word, vStr); 
                break;
            }

            auto ch = path[index];
            if (ch == '/') {
                checkAndResetWord(word, vStr);
            } else {
                word += ch;
            }
        }

        string res;
        for (const auto &item : vStr) {
            res += (string("/") + item);
        }

        return res.empty() ? "/" : res;
    }
private:
    void checkAndResetWord(string &word, vector<string> &vStr) {
        do {
            if (word.empty()) {
                break;
            }

            if (word == ".") {
                break;
            }

            if (word == "..") {
                if (vStr.size() > 0) {
                    vStr.pop_back();
                }
                break;
            }

            vStr.push_back(word);
        } while (false);
        
        word = "";
    }
};
// @lc code=end

