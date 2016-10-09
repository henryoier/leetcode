/*************************************************************************
	> File Name: 271_EncodeAndDecodeStrings.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sat Oct  8 21:09:50 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        if(strs.empty())
            return s;
            
        for(int i = 0; i < strs.size(); i++)
            s += strs[i] + "sq39";
        
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        if(s.length() == 0)
            return result;
            
        while(s.length() != 0){
            int idx = s.find("sq39");
            
            result.push_back(s.substr(0, idx));
            s = s.substr(idx + 4);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
