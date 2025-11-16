#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        } 

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() <= 0) {
            return nullptr;
        } 

        int index = 0;
        return deserializeHelper(data, index);
    }
private:
    TreeNode *deserializeHelper(const string &data, int &index) {
        if (index >= data.size()) {
            return nullptr;
        }

        while (index < data.size() && data[index] == ',') {
            ++index;
        }

        if (data[index] == '#') {
            ++index;
            return nullptr;
        }

        int num = 0;
        int sign = 1;
        if (data[index] == '-') {
            sign = -1;
            ++index;
        }

        while (index < data.size() && isdigit(data[index])) {
            num = num * 10 + data[index] - '0';
            ++index;
        }

        num *= sign;

        auto leftNode = deserializeHelper(data, index);
        auto rightNode = deserializeHelper(data, index);

        auto node = new TreeNode(num);
        node->left = leftNode;
        node->right = rightNode;

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

int main() {
    auto root = new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3,
            new TreeNode(4),
            new TreeNode(5)));
    
    Codec codec;
    auto serRes = codec.serialize(root);
    auto desRes = codec.deserialize(serRes);

    return 0;
}