/*************************************************************************
	> File Name: 381_InsertDeleteGetRandomO1-DuplicateAllowed.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Mon Oct  3 17:03:13 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        size = 0;     
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        size++;
        if(s.find(val) == s.end()){
            s.insert(val);
            return true;
        } else {
            s.insert(val);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto idx = s.find(val);
        if(idx == s.end())
            return false;
        else{
            size--;
            s.erase(idx);
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        auto idx = next(s.begin(), rand() % size);
        return *idx;
    }
    
private:
    multiset<int> s;
    int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
