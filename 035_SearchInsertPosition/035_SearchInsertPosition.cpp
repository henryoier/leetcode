/*************************************************************************
	> File Name: 035_SearchInsertPosition.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Aug 28 23:32:21 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);    
    }

private:
    int binarySearch(const vector<int> nums, int target, int head, int tail){
        int mid = (head + tail) / 2 + 1;
        
        if(head == tail)
            if(nums[head] >= target)
                return head;
            else
                return head + 1;
        
        if(target >= nums[mid])
            return binarySearch(nums, target, mid, tail);
        else
            return binarySearch(nums, target, head, mid - 1);
    }
};

int main(){
    int arr[4]= {1, 3, 5, 6};
    vector<int> nums(arr, arr + 4);
    Solution newSolution;
    cout << newSolution.searchInsert(nums, 4) << endl;

    return 0;
}
