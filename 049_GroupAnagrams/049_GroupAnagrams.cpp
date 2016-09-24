/*************************************************************************
	> File Name: 049_GroupAnagrams.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 23:45:29 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<pair<string, string>> anagram;
        
        for(auto i:strs){
            string temp = i;
            sort(temp.begin(), temp.end());
            anagram.push_back(pair<string, string>(i, temp));
        }
        sort(anagram.begin(), anagram.end(), [=] (pair<string, string> p1, pair<string, string> p2){
           return p1.second < p2.second; 
        });
        
        string last;
        for(auto i = anagram.begin(); i != anagram.end(); i++){
            if(i == anagram.begin()){
                last = i->second;
                result.push_back(vector<string>(1, i->first));
            } else {
                if(i->second != last){
                    last = i->second;
                    result.push_back(vector<string>(1, i->first));
                } else {
                    result[result.size() - 1].push_back(i->first);
                }
            }
        }
        
        return result;
    }
};

int main() {
    string arr [6] = {"ape", "and", "cat", "ate", "nat", "bat"};
    vector<string> strs(arr, arr + 3);
    Solution newSolution;
    
    vector<vector<string>> result = newSolution.groupAnagrams(strs);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
