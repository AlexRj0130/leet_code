#include <vector>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> toLearn;
        vector<int> preLearnCount(numCourses, 0);
        map<int, vector<int>> preToNext;

        for (const auto & item : prerequisites) {
            auto pre = item[1], cur = item[0];
            ++preLearnCount[cur];
            if (preToNext.contains(pre)) {
                preToNext[pre].push_back(cur);
            } else {
                preToNext.insert({pre, {cur}});
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            int count = preLearnCount[i];
            if (count > 0) {
                continue;
            }
            toLearn.push_back(i);
        }

        int learnedCount = 0;
        vector<int> res;
        while (!toLearn.empty()) {
            int learned = toLearn.back();
            toLearn.pop_back();
            ++learnedCount;
            res.push_back(learned);

            const auto &nextList =  preToNext[learned];
            for (const auto next : nextList) {
                if (preLearnCount[next] > 0) {
                    --preLearnCount[next];
                    if (preLearnCount[next] == 0) {
                        toLearn.push_back(next);
                    }
                }
            }
        }

        return learnedCount == numCourses ? res : vector<int>{};
    }
};
// @lc code=end

