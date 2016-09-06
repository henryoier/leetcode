/*************************************************************************
	> File Name: 075_SortColors.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep  6 19:40:35 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0, c = 0;

        for(auto i = nums.begin(); i != nums.end(); i++)
            if(*i == 0)
                a++;
            else
                if(*i == 1)
                    b++;
                else
                    c++;

        for(auto i = nums.begin(); i != nums.end(); i++)
            if(a != 0){
                *i = 0;
                a--;
            } else if(b != 0){
                *i = 1;
                b--;
            } else {
                *i = 2;
            }
};

int main() {
    return 0;
}
