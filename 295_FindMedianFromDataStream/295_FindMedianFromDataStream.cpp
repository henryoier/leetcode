/*************************************************************************
	> File Name: 295_FindMedianFromDataStream.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 21:38:47 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(data.empty()){
            iter = data.insert(num);
        } else {
            if(data.size() % 2 == 0){
                if(num < *iter)
                    data.insert(num);
                else{
                    data.insert(num);
                    iter++;
                }
            } else {
                if(num < *iter){
                    data.insert(num);
                    iter--;
                } else 
                    data.insert(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(data.size() % 2 == 0)
            return (double)(*iter + *next(iter))/2;
        else
            return *iter;
    }
private:
    multiset<int> data;
    multiset<int>::iterator iter;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
