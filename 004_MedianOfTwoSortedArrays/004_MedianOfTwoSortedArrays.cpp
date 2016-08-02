/*************************************************************************
	> File Name: 004_MedianOfTwoSortedArrays.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug  2 10:27:13 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;
        while(i != nums1.size() && j != nums2.size()){
            if(nums1[i] < nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i != nums1.size()){
            result.push_back(nums1[i]);
            i++;
        }
        while(j != nums2.size()){
            result.push_back(nums2[j]);
            j++;
        }
        int total = nums1.size() + nums2.size();
                
        if(total % 2 != 0){
            return (double)result[total/2];
        }else{
            return ((double)result[total/2 - 1] + result[total/2])/2;
        }
    }
};

int main(){
    Solution newSolution;
    int num1[4] = {1,3,5,7};
    int num2[0] = {};
    vector<int> nums1(num1, num1 + 4);
    vector<int> nums2(num2, num2);

    cout << newSolution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
