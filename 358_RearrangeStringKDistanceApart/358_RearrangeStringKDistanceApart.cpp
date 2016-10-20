/*************************************************************************
	> File Name: 358_RearrangeStringKDistanceApart.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 20 00:27:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        vector<pair<char, int>> order;
        map<char, int> count;
        
        for(auto s:str)
            count[s]++;
        for(auto s:count)
            order.push_back(pair<char, int>(s.first, s.second));
            
        sort(order.begin(), order.end(), [=](pair<char, int> a, pair<char, int>b){
           return a.second > b.second; 
        });  
        
        string result;
        vector<int> last(26, -1);
        while(!order.empty()){
            int cur = 0;
            while(last[order[cur].first - 'a'] != -1 && last[order[cur].first - 'a'] + k > result.length() && cur < order.size())
                cur++;
            if(cur == order.size())
                return "";
                
            last[order[cur].first - 'a'] = result.length();
            result += order[cur].first;
            
            if(order[cur].second == 1)
                order.erase(order.begin() + cur);
            else{
                order[cur].second -= 1;
                while(cur < order.size() - 1 && (order[cur].second < order[cur + 1].second || (order[cur].first > order[cur + 1].first && order[cur].second == order[cur + 1].second))){
                    swap(order[cur], order[cur + 1]);
                    cur++;
                }
            }
        }
        return result;
    }
};
