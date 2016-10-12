/*************************************************************************
	> File Name: 211_AddAndSearchWord.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 00:01:20 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class TrieNode{
public:
    bool is_word;
    TrieNode* children[26];
    
    TrieNode(){
        is_word = false;
        fill(children, children + 26, nullptr);
    }
};
    
class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    
    bool dfs(string word, TrieNode* root){
        if(word.empty())
            return root->is_word;
        
        if(word[0] == '.'){
            for(int idx = 0; idx < 26; idx++)
                if(root->children[idx])
                    if(dfs(word.substr(1), root->children[idx]))
                        return true;
            return false;
        } else {
            int idx = word[0] - 'a'; 
            if(!root->children[idx])
                return false;
            else
                return dfs(word.substr(1), root->children[idx]);
        }   
    }
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->children[idx])
                cur = cur -> children[idx];
            else{
                cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            }
        }   
        cur->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, root); 
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
