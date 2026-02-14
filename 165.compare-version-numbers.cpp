#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.empty() && version2.empty()) {
            return 0;
        } 

        auto v1 = stringToIntVec(version1), v2 = stringToIntVec(version2);
        auto v1Size = v1.size(), v2Size = v2.size();
        for (int i = 0; i < v1Size || i < v2Size; ++i) {
            int val1 = i < v1Size ? v1[i] : 0;
            int val2 = i < v2Size ? v2[i] : 0;

            if (val1 == val2) {
                continue;
            } else if (val1 < val2) {
                return -1;
            } else {
                return 1;
            }
        }

        return 0;
    }
private:
    vector<int> stringToIntVec(const string &str) {
        istringstream iss(str);
        vector<int> res;
        string token;

        while (std::getline(iss, token, '.')) {
            res.push_back(std::stoi(token));
        }
        return res;
    }
};
// @lc code=end

