/*************************************************************************
	> File Name: 015_3Sum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Aug  5 15:15:25 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; 
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> hashMap;
        for(int i = 0; i<nums.size(); i++)
            hashMap[nums[i]] = i;

        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < nums.size() -1; j++){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int target = 0 - nums[i] - nums[j];
                if(target < nums[j])
                    break;
                if(hashMap[target] > j){
                    vector<int> tempResult;
                    tempResult.push_back(nums[i]);
                    tempResult.push_back(nums[j]);
                    tempResult.push_back(target);
                    result.push_back(tempResult);
                } 
            }    
        }
        sort(result.begin(), result.end());
        vector<vector<int>>::iterator iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
};


int main(){
    int number[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> nums(number, number + 100);
    
    Solution newSolution;
    vector<vector<int>> result = newSolution.threeSum(nums);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
