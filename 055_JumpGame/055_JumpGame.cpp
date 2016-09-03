/*************************************************************************
	> File Name: 055_JumpGame.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 20:32:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > max)
                return false;
            if(i + nums[i] > max)
                max = i + nums[i];
            if(max >= nums.size() - 1)
                return true;
        }
        return false;    
    }
};

int main() {
    Solution newSolution;
    int arr[5] = {2,3,1,1,4};
    vector<int> nums(arr, arr + 5);

    cout << newSolution.canJump(nums) << endl;

    return 0;
}
