#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        rowSize = matrix.size();
        if (rowSize == 0) {
            return {};
        }
        if (rowSize == 1) {
            return matrix[0];
        }
        colSize = matrix[0].size();

        flag = vector<vector<bool>>(rowSize, vector<bool>(colSize, false));
        right(matrix, 0, 0);

        return res;
    }
private:
    bool right(const vector<vector<int>>& matrix, int i, int j) {
        if (isIndexInValid(i,j) || flag[i][j]) {
            return false;
        }

        int s = j;
        for (; s < colSize && !flag[i][s]; ++s) {
            res.push_back(matrix[i][s]);
            flag[i][s] = true;
        }

        return down(matrix, i + 1, s-1);
    }

    bool down(const vector<vector<int>>& matrix, int i, int j) {
        if (isIndexInValid(i,j) || flag[i][j]) {
            return false;
        }

        int s = i;
        for (; s < rowSize&& !flag[s][j]; ++s) {
            res.push_back(matrix[s][j]);
            flag[s][j] = true;
        }

        return left(matrix, s-1, j-1); 
    }

    bool left(const vector<vector<int>>& matrix, int i, int j) {
        if (isIndexInValid(i,j) || flag[i][j]) {
            return false;
        }

        int s = j;
        for (; s >= 0 && !flag[i][s]; --s) {
            res.push_back(matrix[i][s]);
            flag[i][s] = true;
        }

        return up(matrix, i-1, s+1);
    }

    bool up(const vector<vector<int>>& matrix, int i, int j) {
        if (isIndexInValid(i,j) || flag[i][j]) {
            return false;
        }

        int s = i;
        for (; s >= 0 && !flag[s][j]; --s) {
            res.push_back(matrix[s][j]);
            flag[s][j] = true;
        }

        return right(matrix, s+1, j+1);  
    }

    bool isIndexInValid(int i, int j) {
        return !(i >= 0 && i < rowSize && j >= 0 && j < colSize); 
    }

private:
    int rowSize, colSize;
    vector<vector<bool>> flag; 
    vector<int> res;
};
// @lc code=end

