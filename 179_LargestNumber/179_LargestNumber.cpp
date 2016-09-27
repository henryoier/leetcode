/*************************************************************************
	> File Name: 179_LargestNumber.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 27 16:52:27 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        sort(nums.begin(), nums.end(), compare);
        for(auto i:nums){
            result += to_string(i);
        }
        if(result.length() == 0 || result[0] == '0')
            return "0";
        else
            return result;
    }
private:
    static bool compare(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        
        return sa + sb > sb + sa;
    }
};
