/*************************************************************************
	> File Name: 046_Permutations.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 22:34:05 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int path[nums.size()];
        bool used[nums.size()];
        fill(used, used + nums.size(), false);

        dfs(0, nums, result, path, used);

        return result;
    }

private:
    void dfs(int depth, vector<int> nums, vector<vector<int>>& result, int path[], bool used[]){
        if(depth == nums.size()){
            vector<int> temp(path, path + nums.size());
            result.push_back(temp);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                path[depth] = nums[i];
                used[i] = true;
                
                dfs(depth + 1, nums, result, path, used);

                used[i] = false;
            }
        }
        return;
    }
};

int main() {
    Solution newSolution;
    int arr[5] = {5, 4, 3, 2, 1};
    vector<int> nums(arr, arr + 5);

    vector<vector<int>> result = newSolution.permute(nums);

    for(int i = 0; i < result.size(); i++){
        vector<int> temp = result[i];
        for(int j = 0; j < temp.size(); j++)
            cout << temp[j] << ' ';
        cout << endl;
    }
    return 0;
}
