/*************************************************************************
	> File Name: 034_SearchForARange.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Aug 28 14:55:09 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1); 
    }

private:
    vector<int> binarySearch(const vector<int> nums, int target, int head, int tail){
        //cout << head << ' ' << tail << endl;
        vector<int> result;
        
        if(head > tail){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        if(nums[head] == nums[tail]){
            if(nums[head] == target){
                result.push_back(head);
                result.push_back(tail);
                return result;
            } else {
                result.push_back(-1);
                result.push_back(-1);
                return result;
            }
        }
        
        int mid = (head + tail) / 2;
        if(target > nums[mid])
            return binarySearch(nums, target, mid + 1, tail);
        if(target < nums[mid])
            return binarySearch(nums, target, head, mid - 1);
        
        vector<int> resultLeft = binarySearch(nums, target, head, mid - 1);
        vector<int> resultRight = binarySearch(nums, target, mid + 1, tail);
        if(resultLeft[0] == -1)
            result.push_back(mid);
        else
            result.push_back(resultLeft[0]);

        if(resultRight[1] == -1)
            result.push_back(mid);
        else
            result.push_back(resultRight[1]);
        return result; 
    }
};

int main(){
    Solution newSolution;
    int arr[6] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(arr, arr + 6);
    vector<int> result = newSolution.searchRange(nums, 6);
    cout << '[' << result[0] << ',' << result[1] << ']' << endl;
    return 0;
}
