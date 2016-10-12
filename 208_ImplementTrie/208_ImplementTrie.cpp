/*************************************************************************
	> File Name: 208_ImplementTrie.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Oct 11 23:45:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool is_word;
    TrieNode* children[26];
    
    TrieNode(){
        is_word = false;
        fill(children, children + 26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(now->children[idx])
                now = now->children[idx];
            else{
                now->children[idx] = new TrieNode();
                now = now->children[idx];
            }
        }
        now->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(!now->children[idx])
                return false;
            else
                now = now->children[idx];
        }
        return now->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *now = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(!now->children[idx])
                return false;
            else
                now = now->children[idx];
        }
        return true;   
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
