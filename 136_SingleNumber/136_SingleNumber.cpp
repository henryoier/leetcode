/*************************************************************************
	> File Name: 136_SingleNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 00:15:16 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> result;
        for(auto i:nums){
            if(result.find(i) == result.end())
                result.insert(i);
            else
                result.erase(i);
        }
        return *result.begin();
    }
};

int main() {
    return 0;
}
