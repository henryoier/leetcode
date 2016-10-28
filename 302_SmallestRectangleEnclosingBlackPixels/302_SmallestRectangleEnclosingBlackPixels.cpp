/*************************************************************************
	> File Name: 302_SmallestRectangleEnclosingBlackPixels.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 28 14:34:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        return (bSearch(image, x , image.size() - 1, false, false) - bSearch(image, 0, x, false, true) + 1) *
                    (bSearch(image, y , image[0].size() - 1, true, false) - bSearch(image, 0, y, true, true) + 1);
    }
private:
    int bSearch(vector<vector<char>>& image, int head, int tail, bool vertical, bool findMin){
        while(head <= tail){
            int mid = (tail - head) / 2 + head; 
            bool find = false;
            if(vertical){
                for(int i = 0; i < image.size(); i++){
                    if(image[i][mid] == '1'){
                        if(findMin)
                            tail = mid - 1;
                        else
                            head = mid + 1;
                        find = true;
                        break;
                    }
                }
                if(!find)
                    if(findMin)
                        head = mid + 1;
                    else
                        tail = mid - 1;
                else {}
            } else {
                for(int i = 0; i < image[0].size(); i++){
                    if(image[mid][i] == '1'){
                        if(findMin)
                            tail = mid - 1;
                        else
                            head = mid + 1;
                        find = true;
                        break;
                    }
                }
                if(!find)
                    if(findMin)
                        head = mid + 1;
                    else
                        tail = mid - 1;
                else {}
            }
        }
        cout << head << ' ' << tail << endl;
        if(findMin)
            return head;
        else
            return tail;
    }
};
