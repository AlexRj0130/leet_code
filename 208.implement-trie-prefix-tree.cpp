#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
struct TrieNode {
    char curChar;
    bool isEnd;
    vector<TrieNode*> index;
    TrieNode() : TrieNode(0, true) {}
    TrieNode(char curChar, bool isEnd) : curChar(curChar), isEnd(isEnd) {
        index = vector<TrieNode*>('z' - 'a' + 1, nullptr);
    }
    bool hasIndex(char indexChar) {
        return index[indexChar - 'a'] != nullptr;
    }

    TrieNode * getIndex(char indexChar) {
        if (!hasIndex(indexChar)) {
            return nullptr;
        }
        return index[indexChar - 'a']; 
    }

    TrieNode * setIndex(char indexChar, bool isEnd) {
        if (hasIndex(indexChar)) {
            return getIndex(indexChar);
        }

        index[indexChar - 'a'] = new TrieNode(indexChar, isEnd);
        return getIndex(indexChar);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        insertHelper(word, 0, root);
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root); 
    }
    
    bool startsWith(string prefix) {
        return startWithHelper(prefix, 0, root); 
    }
private:
    void insertHelper(const string &word, int index, TrieNode *node) {
        if (word.size() <= 0 || index < 0 || index >= word.size()) {
            return;
        }

        char curChar = word[index];
        bool isEnd = (index == word.size() - 1);

        if (node->hasIndex(curChar)) {
            auto indexNode = node->getIndex(curChar);
            insertHelper(word, index + 1, indexNode);
            if (isEnd) {
                indexNode->isEnd = true;
            }
        } else {
            auto indexNode = node->setIndex(curChar, isEnd);
            insertHelper(word, index + 1, indexNode);
        }
    }

    bool searchHelper(const string &word, int index, TrieNode *node) {
        if (word.size() <= 0 || index < 0 || index >= word.size()) {
            return true;
        }

        char curChar = word[index];
        bool isEnd = (index == word.size() - 1); 

        if (!node->hasIndex(curChar)) {
            return false;
        } else {
            auto indexNode = node->getIndex(curChar);
            if (!isEnd) {
                return searchHelper(word, index + 1, indexNode);
            } else {
                return indexNode->isEnd;
            }
        }
    }

    bool startWithHelper(const string &word, int index, TrieNode *node) {
        if (word.size() <= 0 || index < 0 || index >= word.size()) {
            return true;
        } 

        char curChar = word[index];
        if (!node->hasIndex(curChar)) {
            return false;
        } else {
            auto indexNode = node->getIndex(curChar);
            return startWithHelper(word, index + 1, indexNode);
        }  
    }

private:
    TrieNode * root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << ", " << trie.search("app") << endl; 
    cout << trie.startsWith("apple") << ", " << trie.startsWith("app") << endl; 
    trie.insert("app");
    cout << trie.search("apple") << ", " << trie.search("app") << endl; 
    cout << trie.startsWith("apple") << ", " << trie.startsWith("app") << endl; 
    return 0;
}

