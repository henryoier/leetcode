/*************************************************************************
	> File Name: 053_MaximumSubarray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 19:44:31 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int max = INT_MIN;
        for(auto i = nums.begin(); i != nums.end(); i++ ){
            curr += *i;
            if(curr > max)
                max = curr;
            if(curr < 0)
                curr = 0;
        }
        return max;
    }
};

int main(){
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution newSolution;
    vector<int> nums(arr, arr + 9);

    cout << newSolution.maxSubArray(nums) << endl;

    return 0;
}
