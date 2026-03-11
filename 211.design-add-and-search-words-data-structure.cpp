#include <vector>
#include <string>
#include <map>

using namespace std;

/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

struct PrefixTreeNode {
    bool isEnd; // 是否存在以该字符作为结尾的字符串。
    char ch; // 当前字符的值。
    map<char, PrefixTreeNode*> nodeMap; 
};

class WordDictionary {
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        addWordHelp(word, 0, &head);
    }
    
    bool search(string word) {
        return searchHelp(word, 0, &head);
    }
private:
    bool searchHelp(const string &word, int curIndex, PrefixTreeNode *preNode) {
        if (preNode == nullptr) {
            return false;
        }

        if (curIndex >= word.size()) {
            return preNode->isEnd;
        }

        auto targetCh = word[curIndex];
        if (targetCh == '.') {
            for (const auto &pair : preNode->nodeMap) {
                if (searchHelp(word, curIndex + 1, pair.second)) {
                    return true;
                }
            }
            return false;
        }
        auto pCurNode = preNode->nodeMap.find(targetCh);
        if (pCurNode != preNode->nodeMap.end() && searchHelp(word, curIndex + 1, (*pCurNode).second)) {
            return true;
        }
        auto pCurNodeGen = preNode->nodeMap.find('.');
        return (pCurNodeGen != preNode->nodeMap.end() && searchHelp(word, curIndex + 1, (*pCurNodeGen).second));
    }

    void addWordHelp(const string &word, int curIndex, PrefixTreeNode *preNode) {
        if (curIndex >= word.size() || preNode == nullptr) {
            return;
        }

        auto targetCh = word[curIndex];
        PrefixTreeNode *pCurNode = nullptr;
        if (preNode->nodeMap.contains(targetCh)) {
            pCurNode = preNode->nodeMap[targetCh];
        } else {
            pCurNode = new PrefixTreeNode();
            pCurNode->ch = targetCh;
            preNode->nodeMap.insert({targetCh, pCurNode});
        }

        if (curIndex == word.size() - 1) {
            pCurNode->isEnd = true;
        } else {
            addWordHelp(word, curIndex + 1, pCurNode);
        }
    }
private:
    PrefixTreeNode head;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

int main() {

    return 0;
}