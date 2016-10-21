/*************************************************************************
	> File Name: 393_UTF-8Validation.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Oct 21 13:24:52 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.empty())
            return true;
            
        int header = data[0];  
        int length = getLength(header);
        
        if(length > data.size() || length == 1)
            return false;
        data.erase(data.begin());
        
        if(length == 0)
            return validUtf8(data);
            
        for(int i = 0; i < length - 1; i++)
            if(!checkLegal(data[0]))
                return false;
            else
                data.erase(data.begin());
        
        return validUtf8(data);
    }
private:
    int getLength(int header){
        int result = 0;
        for(int i = 7; i >= 0; i--){
            if(header / (1 << i) % 2 == 1)
                result++;
            else
                break;
        }
        return result;
    }
    
    bool checkLegal(int header){
        return header / (1 << 6) == 2;
    }
};
