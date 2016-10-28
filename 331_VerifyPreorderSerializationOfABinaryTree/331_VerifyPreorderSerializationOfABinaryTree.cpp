/*************************************************************************
	> File Name: 331_VerifyPreorderSerializationOfABinaryTree.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct 27 20:33:39 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        cout << preorder<< endl;
        if(preorder.empty())
            return true;
        string newString = preorder;
        if(validPreorder(newString) && newString.empty())
            return true;
        else
            return false;
    }
    
private:
    bool validPreorder(string &s){
        if(s.empty())
            return false;
            
        if(s[0] == '#'){
            int idx = s.find(',');
            if(idx == string::npos)
                s = "";
            else
                s = s.substr(idx + 1);
            return true;
        }
        
        int idx = s.find(',');
        if(idx == string::npos)
            s = "";
        else
            s = s.substr(idx + 1);
                
        return validPreorder(s) && validPreorder(s);
    }
};
