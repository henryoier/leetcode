/*************************************************************************
	> File Name: 011_ContainerWithMostWater.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug  3 16:31:19 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size()-1; i++)
            for(int j = i + 1; j < height.size(); j++)
                if(min(height[i], height[j]) * (j - i) > max)
                    max = min(height[i], height[j]) * (j - i);
        return max;
    }
};
*/
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size() - 1; i++){
            int maxDist = 0;
            for(int j = height.size() - 1; j > i; j--)
                if(height[j] >= height[i]){
                    maxDist = j - i;
                    break;
                }
            if(maxDist * height[i] > max)
                max = maxDist * height[i];
        }
        
        for(int i = height.size() - 1; i > 1; i--){
            int maxDist = 0;
            for(int j = 0; j < i; j++)
                if(height[j] >= height[i]){
                    maxDist = i - j;
                    break;
                }
            if(maxDist * height[i] > max)
                max = maxDist * height[i];
        }
        return max;
    }
};
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int result = INT_MIN;
        while (start < end) {
            int area = min(height[end], height[start]) * (end - start);
            result = max(result, area);
            if (height[start] <= height[end]) {
                start++;
            } else {
                end--; 
            }
        }
        return result;
    }
};

int main(){
    int h[4] = {1,2,3,4};
    vector<int> height(h, h + 4);
    Solution newSolution;

    cout << newSolution.maxArea(height) << endl;
    return 0;
}
