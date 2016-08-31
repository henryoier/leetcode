/*************************************************************************
	> File Name: 042_TrappingRainWater.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 31 00:31:37 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;
            
        int result = 0;
        int last = 0;
        int lastHeight = height[last];
        
        
        while(last < height.size() - 1){
            int i;
            for(i = last + 1; i < height.size(); i++){
                if(height[i] >= lastHeight)
                    if(lastHeight == 0){
                        lastHeight = height[i];
                        last = i;
                    } else {
                        for(int j = last + 1; j < i; j++){
                            result += lastHeight - height[j];
                        }
                        last = i;
                        lastHeight = height[last];
                        break;
                    }
                else
                    continue;
            }
 
            if(i == height.size()){
                lastHeight--;
            }
        }

        return result;   
    }
}; 

int main(){
    Solution newSolution;
    int arr[14] = {3,1,5,4,6,7,8,3,5,6,7,3,6,7};
    vector<int> height(arr, arr + 14);

    cout << newSolution.trap(height) << endl;
    return 0;
}
