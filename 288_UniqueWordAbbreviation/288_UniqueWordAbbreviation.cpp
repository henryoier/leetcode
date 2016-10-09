/*************************************************************************
	> File Name: 288_UniqueWordAbbreviation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct  9 14:52:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto i:dictionary){
            string cur = getAbbr(i);
            abbr[cur].insert(i);
        }       
    }

    bool isUnique(string word) {
        string curAbbr = getAbbr(word);
        if(!abbr.count(curAbbr) || (abbr[curAbbr].size() == 1 && abbr[curAbbr].count(word)))
            return true;
        else 
            return false;
    }
private:
    unordered_map<string, unordered_set<string>> abbr;
    
    string getAbbr(string a){
        if(a.length() < 3)
            return a;
        else 
            return a[0] + to_string(a.length() - 2) + a[a.length() - 1];
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
