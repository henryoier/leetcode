/*************************************************************************
	> File Name: 047_PermutationsII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 22:51:36 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(),nums.end());
        result.push_back(nums);

        while(!isDecendent(nums, 0 , nums.size() - 1)){
            bool find = false;
            for(auto first = nums.end() - 2; first >= nums.begin(); first--){
                for(auto last = nums.end() - 1; last != first; last--){
                    if(*last > *first){ 
                        swap(*last, *first);
                        sort(first + 1, nums.end());
                        vector<int> temp(nums);
                        result.push_back(temp);
                        find = true;
                        break;
                    }
                    if(find)
                        break;
                }
            }  
        }
        return result;
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

int main() {
    Solution newSolution;
    int arr[4] = {1,2,2,1};
    vector<int> nums(arr, arr + 4);

    vector<vector<int> > result = newSolution.permuteUnique(nums);
    cout << endl;
    for(int i = 0; i < result.size(); i++){
        vector<int> temp = result[i];
        for(int j = 0; j < temp.size(); j++)
            cout << temp[j] << ' ';
        cout << endl;
    }

    return 0;
}


