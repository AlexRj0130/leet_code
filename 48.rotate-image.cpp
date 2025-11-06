#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 1) {
            return;
        } 

        int x = 0, y = 0;
        for (int pos = 0; pos < matrix.size() / 2; ++pos) {
            int size = matrix.size() - 2 * pos;
            int count = size - 1;
            while (count > 0) {
                rotateOneStep(matrix, pos, size);
                --count;
            }
        }
    }
private:
    void rotateOneStep(vector<vector<int>>& matrix, const int pos, const int size) {
        if (size <= 1) {
            return;
        }
        int tmp = matrix[pos][pos];

        int initX = pos, initY = pos;
        int count = (size - 1) * 4 - 1;
        while (count > 0) {
            int xNext = 0, yNext = 0;
            findNext(pos, size, initX, initY, xNext, yNext);
            matrix[initX][initY] = matrix[xNext][yNext];
            initX = xNext;
            initY = yNext;
            --count;
        }

        matrix[pos][pos + 1] = tmp;
    }
    void findNext(const int pos, const int size, const int x, const int y, int &xNext, int &yNext) {
        if (size <= 1) {
            xNext = x;
            yNext = y;
            return;
        }

        if (y == pos) {
            if (x == pos + size - 1) {
                xNext = x;
                yNext = y + 1;
            } else {
                xNext = x + 1;
                yNext = y;
            }
        } else if (x == pos + size - 1) {
            if (y == pos + size - 1) {
                xNext = x - 1;
                yNext = y;
            } else {
                xNext = x;
                yNext = y + 1;
            }
        } else if (y == pos + size - 1) {
            if (x == pos) {
                xNext = x;
                yNext = y - 1;
            } else {
                xNext = x - 1;
                yNext = y;
            }
        } else if (x == pos){
            if (y == pos) {
                xNext = x + 1;
                yNext = y;
            } else {
                xNext = x;
                yNext = y - 1;
            }
        }
    }
};
// @lc code=end

int main() {
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    
    Solution sol;
    sol.rotate(matrix);
    return 0;
}