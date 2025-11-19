#include <vector>

using namespace std;
/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() <= 1 || n <= 0) {
            return tasks.size();
        }

        init(tasks);

        int res = 0;
        int resInterval;
        char resCh;
        while (peekOneTask(n, resInterval, resCh)) {
            res += (resInterval);
        }

        return res;
    }
private:
    void init(const vector<char>& tasks) {
        taskCount = vector<int>(26, 0);
        taskInterval = vector<int>(26, 0);
        
        for (auto ch : tasks) {
            ++taskCount[ch - 'A'];
        }
    }

    bool peekOneTask(int interval, int &resInterval, char &resCh) {
        bool flag = false;
        for (int i = 0; i < taskInterval.size(); ++i) {
            if (taskCount[i] <= 0) {
                continue;
            }

            if (flag == false) {
                resInterval = taskInterval[i];
                resCh = 'A' + i;
                flag = true;
                continue;
            }

            if (taskInterval[i] < resInterval) {
                resInterval = taskInterval[i];
                resCh = 'A' + i; 
            } else if (taskInterval[i] == resInterval) {
                if (taskCount[i] > taskCount[resCh - 'A']) {
                    resCh = 'A' + i;
                }
            }
        }

        if (!flag) {
            return flag;
        }

        resInterval += 1;

        taskCount[resCh - 'A'] -= 1;
        for (int i = 0; i < taskInterval.size(); ++i) {
            if (i == resCh - 'A') {
                taskInterval[i] = interval;
            } else {
                if (taskInterval[i] >= resInterval) {
                    taskInterval[i] -= resInterval;
                } else {
                    taskInterval[i] = 0; 
                }
            }
        }

        return flag;
    }
private:
    vector<int> taskCount; 
    vector<int> taskInterval;
};
// @lc code=end

