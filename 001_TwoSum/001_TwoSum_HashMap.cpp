/*************************************************************************
	> File Name: 001_TwoSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Jul 20 22:56:52 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        vector<int> result;
        unordered_map<int, int>::iterator pos;

        for(int i = 0; i < nums.size(); i++)
            hash_map[nums[i]] = i;

        for(int i = 0; i < nums.size() - 1; i++){
            int gap = target - nums[i];
            pos = hash_map.find(gap);
            if(pos != hash_map.end() && hash_map[gap] > i){
                result.push_back(i);
                result.push_back(hash_map[gap]);
                return result;
            }
        }
        return result; 
    }
};

int main(){
    int n, target,number;
    vector<int> nums;
    vector<int> result;

    cin >> n >> target;
    for(int i = 0; i < n; i++){
        cin >> number;
        nums.push_back(number);
    }

    Solution newSolution;
    result = newSolution.twoSum(nums, target);
    
    cout << result[0] << ' ' << result[1] << endl;

    return 0;
}    
