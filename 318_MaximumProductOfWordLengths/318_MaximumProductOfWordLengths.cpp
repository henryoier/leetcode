/*************************************************************************
	> File Name: 318_MaximumProductOfWordLengths.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 21:43:00 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() < 2)
            return 0;
        priority_queue<int> s;
        vector<int> count(words.size(), 0);
        
        for(int i = 0; i < words.size(); i++){
            unordered_set<char> *hash = new unordered_set<char>();
            for(auto j:words[i]){
                if(hash->find(j) == hash->end()){
                    count[i] |= (1 << (j - 'a'));
                    hash->insert(j);
                }
            }
            delete hash;
        }
        
        for(int i = 0; i < words.size() - 1; i++)
            for(int j = i + 1; j < words.size(); j++)
                if((count[i] & count[j]) == 0){
                    //cout << i << ' ' << j;
                    s.push(words[i].length() * words[j].length());
                }
            
        if(s.empty())
            return 0;
        else
            return s.top();
    }
}; 

class Solution {
    public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int result = 0;
        for (int i=0; i<words.size(); ++i) {
            for (char c : words[i])
                mask[i] |= 1 << (c - 'a');
            for (int j=0; j<i; ++j)
                if (!(mask[i] & mask[j]))
                    result = max(result, int(words[i].size() * words[j].size()));    
        }
        return result;    
    }
};
