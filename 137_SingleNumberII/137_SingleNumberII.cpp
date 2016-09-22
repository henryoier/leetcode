/*************************************************************************
	> File Name: 137_SingleNumberII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 00:28:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto i:nums)
            if(map.find(i) == map.end())
                map.insert({i, 1});
            else
                map[i] += 1;
        
        for(auto i = map.begin(); i != map.end(); i++){
            if(i->second == 1)
                return i->first;
        }
        return 0;
    }
};

int main() {
    return 0;
}
