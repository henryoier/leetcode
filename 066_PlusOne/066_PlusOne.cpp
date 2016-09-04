/*************************************************************************
	> File Name: 066_PlusOne.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep  4 19:05:42 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        digits[0] += 1;
        
        for(int i = 0; i < digits.size(); i++){
            if(i == digits.size() - 1 && digits[i] > 9){
                digits[i] = 0;
                digits.push_back(1);
            }
            else
                if(digits[i] > 9) {
                    digits[i] = 0;
                    digits[i + 1] += 1;
                }   
                else
                    break;
        }
        reverse(digits.begin(), digits.end());

        return digits;
    }
};

int main() {
    int arr[5] = {9,9,8,9,9};
    vector<int> digits(arr, arr + 5);
    
    Solution newSolution;
    vector<int> result = newSolution.plusOne(digits);
 
    for(auto i = result.begin(); i != result.end(); i++)
        cout << *i;

    return 0;
}
