/*************************************************************************
	> File Name: 045_JumpGameII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 14:13:19 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, last = 0, curr = 0, max = 0;
        if(nums.size() == 1)
            return 0;
            
        for(int i = 0; i < nums.size(); i++){
            if(i > last){
                step++;
                last = max;
            }
            curr = i + nums[i];
            if(curr >= nums.size() - 1) 
                return step + 1;
            else
                if(curr > max)
                    max = curr;
                else {}
        }
        return step;
    }
};

int main(){
    Solution newSolution;
    int arr[15] = {3,2,1,4,5,6,7,8,3,2,1,5,6,2,1};
    vector<int> nums(arr, arr + 15);

    cout << newSolution.jump(nums) << endl;

    return 0;
}
