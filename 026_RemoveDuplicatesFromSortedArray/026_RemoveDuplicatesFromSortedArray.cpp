/*************************************************************************
	> File Name: 026_RemoveDuplicatesFromSortedArray.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 10 00:03:16 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator end_unique = unique(nums.begin(), nums.end());
        nums.erase(end_unique, nums.end());        
        
        return nums.size();
    }
};

int main(){
    int arr[10] = {1,2,4,4,5,6,7,8,9,9};
    vector<int> vec(arr, arr + 10);
    Solution newSolution;
    
    cout << newSolution.removeDuplicates(vec);
    return 0;
}
