/*************************************************************************
	> File Name: 128_LongestConsecutiveSequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 22 13:38:21 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        
        for(auto i:nums){
            hash.insert({i, false});
        }
        
        int max = 0;
        
        for(auto i:nums){
            if(hash[i])
                continue;
            else {
                int count = 0;
                int j = i;
                while(hash.find(j) != hash.end()){
                    count++;
                    hash[j] = true;
                    if(j == INT_MAX)
                        break;
                    else
                        j++;
                }
                
                j = i;
                while(hash.find(j) != hash.end()){
                    count++;
                    hash[j] = true;
                    if(j == INT_MIN)
                        break;
                    else
                        j--;
                }    
                count--;
                if(count > max)
                    max = count;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}
