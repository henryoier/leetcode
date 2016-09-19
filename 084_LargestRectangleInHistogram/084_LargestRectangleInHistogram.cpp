/*************************************************************************
	> File Name: 084_LargestRectangleInHistogram.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 18 21:43:59 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
    public:
    int largestRectangleArea(vector<int>& heights) {
                stack<int> s;
                heights.push_back(0);
                int result = 0;
                
        for(int i = 0; i < heights.size();){
            if(s.empty() || heights[i] > heights[s.top()]){
                                s.push(i++);
                            
            } else {
                                int tmp = s.top();
                                s.pop();
                                result = max(result, heights[tmp] * (s.empty()?i:i - s.top() - 1));
                            
            }
                    
        }
                return result;
            
    }

};

int main() {

    return 0;
}
