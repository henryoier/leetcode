/*************************************************************************
	> File Name: 001_TwoSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Jul 20 22:56:52 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i = 0; i < nums.size() - 1; i++)
            for(int j = i + 1; j < nums.size(); j++)
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
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
