/*************************************************************************
	> File Name: 090_SubsetsII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 25 20:12:45 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = subsets(nums, 0);
        
        sort(result.begin(), result.end());
        vector<vector<int>>::iterator is_unique = unique(result.begin(), result.end());
        result.erase(is_unique, result.end());
        
        return result;
    }
private:
    vector<vector<int>> subsets(vector<int>& nums, int index){
        if(index == nums.size())
            return vector<vector<int>>(1, vector<int>());
            
        vector<vector<int>> temp = subsets(nums, index + 1);
        vector<vector<int>> result = temp;
        
        for(int i = 0; i < temp.size(); i++){
            temp[i].insert(temp[i].begin(), nums[index]);
            sort(temp[i].begin(), temp[i].end());
        }
        result.insert(result.begin(), temp.begin(), temp.end());
        
        return result;
    }
};
