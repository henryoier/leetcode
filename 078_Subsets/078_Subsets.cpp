/*************************************************************************
	> File Name: 078_Subsets.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep  7 13:27:34 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int path[n];

        for(int i = 0; i <= nums.size(); i++){
            dfs(n, i, 0, 0, path, nums, result);
        }

        return result;
    }
private:
    void dfs(int n, int k, int chosen, int depth, int path[], vector<int> nums, vector<vector<int>>& result){
        if(chosen == k){
            vector<int> temp;
            
            for(int i = 0; i < chosen; i++)
                temp.push_back(path[i]);
            result.push_back(temp);
            
            return;
        }

        if(n - depth == k - chosen){
            path[chosen] = nums[depth];
            dfs(n, k, chosen + 1, depth + 1, path, nums, result);
        } else {
            path[chosen] = nums[depth];
            dfs(n, k, chosen + 1, depth + 1, path, nums, result);
            dfs(n, k, chosen, depth + 1, path, nums, result);
        }
    }
};

int main() {
    return 0;
}
