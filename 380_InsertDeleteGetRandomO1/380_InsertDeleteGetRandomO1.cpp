/*************************************************************************
	> File Name: 380_InsertDeleteGetRandomO1.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 17:01:31 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) != s.end())
            return false;
        else {
            s.insert(val);
            size++;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) == s.end()){
            return false;
        } else {
            s.erase(val);
            size--;
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % size;
        return *next(s.begin(), index);
    }
private:
    unordered_set<int> s;
    int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
