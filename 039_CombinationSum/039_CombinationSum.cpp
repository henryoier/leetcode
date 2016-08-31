/*************************************************************************
	> File Name: 039_CombinationSum.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug 30 22:57:36 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        for(auto i = candidates.begin(); i != candidates.end(); i++){
            if(target > *i) {
                vector<vector<int>> temp;
                temp = combinationSum(candidates, target - *i);
                vector<vector<int>> temp2;
                if(!temp.empty())
                    for(int j = 0; j < temp.size(); j++){
                        vector<int> temp3 = temp[j];
                        temp3.push_back(*i);
                        sort(temp3.begin(), temp3.end());
                        temp2.push_back(temp3);
                    }
                result.insert(result.end(), temp2.begin(), temp2.end());
            } 
            if(target == *i) {
                vector<int> temp;
                temp.push_back(*i);
                result.push_back(temp);
            }
        }
        
        sort(result.begin(), result.end());
        vector<vector<int>>::iterator end_unique = unique(result.begin(), result.end());
        result.erase(end_unique, result.end());
        return result;
    }
};

int main() {

}
