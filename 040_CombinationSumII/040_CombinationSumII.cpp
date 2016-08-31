/*************************************************************************
	> File Name: 040_CombinationSumII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug 30 23:24:01 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int nums[candidates.size()];

        sort(candidates.begin(), candidates.end());
        
        dfs(0, nums, candidates, target, 0, result);
        
        sort(result.begin(), result.end());
        vector<vector<int>>::iterator end_unique = unique(result.begin(), result.end());
        result.erase(end_unique, result.end());
        return result;
    }
    
private:
    void dfs(int depth, int nums[], vector<int> candidates, int target, int lastPos, vector<vector<int>>& result){
        if(target == 0){
            vector<int> temp;
            for(int i = 0; i < depth; i++)
                temp.push_back(nums[i]);
            result.push_back(temp);
        }
        
        if(lastPos == candidates.size() || candidates[lastPos] > target)
            return;

        for(int i = lastPos; i < candidates.size(); i++){
            if(candidates[i] <= target){
                nums[depth] = candidates[i];
                dfs(depth + 1, nums, candidates, target - candidates[i], i + 1, result);
            }
        }
    }
};

int main() {
    return 0;
}
