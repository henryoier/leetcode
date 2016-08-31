/*************************************************************************
	> File Name: FirstMissingPositive.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug 30 23:51:33 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<utility>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<pair<int, int>> result;
        pair<int, int> init = make_pair(1, INT_MAX);
        result.push_back(init);

        for(auto i = nums.begin(); i != nums.end(); i++){
            if(*i <= 0)
                continue;
            
            for(int j = 0; j < result.size(); j++){
                if(*i >= result[j].first && *i <= result[j].second){
                    pair<int, int> left, right;
                    left = make_pair(result[j].first, *i - 1);
                    right = make_pair(*i + 1, result[j].second);
                    result.erase(result.begin() + j);
                    if(left.first <= left.second)
                        result.insert(result.begin() + j++, left);
                    if(right.first <= right.second)
                        result.insert(result.begin() + j, right);
                    break;
                }
            }
        }
        return result[0].first;
    }
};

int main(){
    Solution newSolution;
    int arr[5] = {3, 4, -1, 1, 0};
    vector<int> nums(arr, arr + 5);

    cout << newSolution.firstMissingPositive(nums) << endl;

    return 0;
}
