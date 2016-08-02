/*************************************************************************
	> File Name: 007_ReverseInteger.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug  2 21:25:47 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        bool negative = false;
        if(x < 0){
            x = 0 - x;
            negative = true;
        }

        while(x>0){
            result = result * 10 + x % 10;
            x = x/10;
        }
        if(result > INT_MAX)
            return 0;
        if(negative) 
            return 0 - result;
        else
            return result;
    }
};

int main(){
    int x;
    cin >> x;
    
    Solution newSolution;
    cout << newSolution.reverse(x) <<endl;
    return 0;
}
