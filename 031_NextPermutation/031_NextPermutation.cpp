/*************************************************************************
	> File Name: 031_NextPermutation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Aug 27 10:51:56 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(isDecendent(nums, 0 , nums.size() - 1)){
            sort(nums.begin(), nums.end());
            return;
        }
        for(auto first = nums.end() - 2; first >= nums.begin(); first--){
            for(auto last = nums.end() - 1; last != first; last--){
                if(*last > *first){
                    swap(*last, *first);
                    sort(first + 1, nums.end());
                    return;
                }
            }
        } 
    }
private:
    bool isDecendent(const vector<int> nums, int head, int tail) {
        if(head == tail)
            return true;

        if(nums[head] < nums[head + 1])
            return false;
        else
            return isDecendent(nums, head + 1, tail);
    }
};

int main(){
    int arr[1] = {4};
    vector<int> nums(arr, arr + 1);

    Solution newSolution;
    newSolution.nextPermutation(nums);

    for(auto i = nums.begin(); i != nums.end(); i++)
        cout << *i << ' ';

    return 0;
}
