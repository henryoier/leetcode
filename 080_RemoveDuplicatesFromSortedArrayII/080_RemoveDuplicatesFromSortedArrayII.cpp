/*************************************************************************
	> File Name: 080_RemoveDuplicatesFromSortedArrayII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Sep 15 14:13:47 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        int last = INT_MAX;
        int count = 0;
        
        for(auto i = nums.begin();i != nums.end(); ++i){
            if(*i == last){
                if(count == 1){
                    nums.erase(i);
                    i--;
                }
                else{
                    count++;
                }
            } else{
                last=*i;
                count = 0;
            }
        }
        
        return nums.size();
    }
};

int main() {
    return 0;
}
