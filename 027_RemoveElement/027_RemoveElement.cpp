/*************************************************************************
	> File Name: 027_RemoveElement.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 10 18:25:05 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main(){
    int arr[4] = {3, 2, 2, 4};
    vector<int> nums(arr, arr + 4);

    Solution newSolution;
    cout << newSolution.removeElement(nums, 3);

    return 0;
}
