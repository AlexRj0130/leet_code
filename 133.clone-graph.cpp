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
        if (node == nullptr) {
            return nullptr;
        } 

        unordered_map<int, Node*> nodeMap;
        unordered_set<int> nodeSet;

        bfsToCopyNode(node, nodeMap);
        return bfsToConnectNode(node, nodeMap, nodeSet);
    }

private:
    void bfsToCopyNode(Node* node, unordered_map<int, Node*> &nodeMap) {
        if (node == nullptr) {
            return;
        }

        if (nodeMap.contains(node->val)) {
            return;
        }

        nodeMap[node->val] = new Node(node->val);
        for (auto pNode : node->neighbors) {
            bfsToCopyNode(pNode, nodeMap);
        }
    }

    Node * bfsToConnectNode(Node* node, const unordered_map<int, Node*> &nodeMap, unordered_set<int> &nodeSet) {
        if (node == nullptr || nodeSet.contains(node->val)) {
            return nullptr;
        }

        auto res = nodeMap.at(node->val);
        if (res == nullptr) {
            return nullptr;
        }
        
        nodeSet.insert(node->val);
        for (auto pNode : node->neighbors) {
            if (pNode == nullptr || nodeMap.at(pNode->val) == nullptr) {
                continue;
            }
            res->neighbors.push_back(nodeMap.at(pNode->val));
        }

        for (auto pNode : node->neighbors) {
            auto subRes = bfsToConnectNode(pNode, nodeMap, nodeSet);
        } 

        return res;
    }
};
// @lc code=end

int main() {


    return 0;
}