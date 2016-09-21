/*************************************************************************
	> File Name: 119_PascalsTriangleII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep 20 23:42:54 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == -1)
            return result;
            
        vector<int> last = getRow(rowIndex - 1);
        for(int i = 0; i <= last.size(); i++)
            if(i == 0 || i == last.size())
                result.push_back(1);
            else
                result.push_back(last[i] + last[i - 1]);
                
        return result;
    }
};

int main() {
    return 0;
}
