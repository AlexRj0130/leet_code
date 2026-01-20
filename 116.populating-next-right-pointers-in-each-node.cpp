#include <cstdlib>

/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        connectFar(root->left, root->right);
        return root;
    }
private:
    void connectFar(Node *left, Node *right) {
        if (left == nullptr || right == nullptr) {
            return;
        }

        left->next = right;
        connectFar(left->right, right->left);
        connectFar(left->left, left->right);
        connectFar(right->left, right->right);
    }
};
// @lc code=end

int main() {
    auto root = new Node(-1, 
        new Node(0, 
            new Node(2,
                new Node(6),
                new Node(7),
                nullptr
            ),
            new Node(3,
                new Node(8),
                new Node(9),
                nullptr
            ),
            nullptr
        ),
        new Node(1,
            new Node(4,
                new Node(10),
                new Node(11),
                nullptr
            ),
            new Node(5,
                new Node(12),
                new Node(13),
                nullptr
            ),
            nullptr
        ),
        nullptr
    );

    Solution sol;
    sol.connect(root);

    return 0;
}