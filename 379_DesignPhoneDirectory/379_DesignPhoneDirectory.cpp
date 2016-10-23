/*************************************************************************
	> File Name: 379_DesignPhoneDirectory.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 17:39:42 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        maxN = maxNumbers;
        legal.resize(maxN, true);
        numbers.resize(maxN);
        iota(numbers.begin(), numbers.end(), 0);       
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(cur == maxN)
            return -1;
        else{
            legal[numbers[cur]] = false;
            return numbers[cur++];
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return legal[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(!legal[number]){
            legal[number] = true;
            numbers[--cur] = number;
        }
    }
private:
    vector<bool> legal;
    vector<int> numbers;  
    int cur = 0;
    int maxN;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
