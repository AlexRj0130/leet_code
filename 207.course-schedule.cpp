#include <vector>
#include <map>
#include <set>

using namespace std;

/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> zeroIn; // 存储所有入度为 0 的节点的 index
        vector<int> indexIn(numCourses, 0); // 存储所有节点当前的入度
        map<int, set<int>> preToIndex; // key 为节点的 index，val 为以该节点为前置条件的节点的集合
        
        // 初始化
        for (const auto &preItem : prerequisites) {
            ++indexIn[preItem[0]];
            if (preToIndex.contains(preItem[1])) {
                preToIndex[preItem[1]].insert(preItem[0]);
            } else {
                preToIndex.insert({preItem[1], {preItem[0]}});
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indexIn[i] != 0) {
                continue;
            }
            zeroIn.push_back(i);
        }

        // 拓扑排序
        while (zeroIn.size() > 0) {
            int lastZeroIn = zeroIn.back();
            zeroIn.pop_back();

            auto indexSet = preToIndex[lastZeroIn];
            for (const auto index : indexSet) {
                if (indexIn[index] <= 0) {
                    continue;
                }
                --indexIn[index];
                if (indexIn[index] == 0) {
                    zeroIn.push_back(index);
                }
            }
        }

        // 返回结果
        for (const auto count : indexIn) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

