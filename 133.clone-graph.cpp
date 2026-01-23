#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // 边界条件：空节点直接返回空
        if (node == nullptr) return nullptr;
        
        // 若该节点已克隆，直接返回克隆节点（避免重复创建+死循环）
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }
        
        // 1. 克隆当前节点（仅复制值，邻接列表先空）
        Node* cloneNode = new Node(node->val);
        // 2. 记录映射（必须先记录，否则递归邻居时会重复创建）
        cloneMap[node] = cloneNode;
        
        // 3. 递归克隆所有邻居，并添加到克隆节点的邻接列表
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }

private:
    // 哈希表：原节点 -> 克隆节点，避免重复克隆
    unordered_map<Node*, Node*> cloneMap;
};
// @lc code=end

int main() {


    return 0;
}