#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    int findFirstGreaterThan(const vector<int> &arr, int target) {
        if (arr.size() <= 0) {
            return -1;
        }

        int left = 0, right = arr.size() - 1;
        int result = -1;
        while (left < right) {
            int mid = (left + right) / 2;
            printf("left[%d] = %d, right[%d] = %d, mid[%d] = %d\n", left, arr[left], right, arr[right], mid, arr[mid]);
            if (arr[mid] <= target) {
                left = mid + 1; 
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9, 10}; // len = 13
    Solution sol;
    auto result = sol.findFirstGreaterThan(arr, 5);
    cout << "result = " << result << endl;
    return 0;
}