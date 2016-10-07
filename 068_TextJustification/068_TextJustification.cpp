/*************************************************************************
	> File Name: 068_TextJustification.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 20:52:46 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        if(words.empty())
            return result;
            
        int start = 0;
        while(start < words.size()){
            int cur = start;
            int len = 0;
            while(cur < words.size() && len + words[cur].length() <= maxWidth){
                len += words[cur].length() + 1;
                cur++;
            }
            len = len - (cur - start);
            int space = 0; 
            int addOn = 0;
            
            if(cur - start != 1){
                space = (maxWidth - len) / (cur - start - 1);
                addOn = (maxWidth - len) % (cur - start - 1);
            }
         
            string line;
            if(cur == words.size() || cur - 1 == start){
                for(int i = start; i < cur - 1; i++)
                    line = line + words[i] + ' ';
                line = line + words[cur - 1];
                for(int j = line.length(); j < maxWidth; j++)
                    line = line + ' ';
            } else{
                    for(int i = start; i < cur - 1; i++){
                        line = line + words[i];
                        for(int j = 0; j < space; j++)
                            line = line + ' ';
                        if(addOn > 0){
                            line = line + ' ';
                            addOn--;
                        }
                    }
                    line = line + words[cur - 1];
            }
            result.push_back(line);
            if(cur == words.size())
                break;
            else
                start = cur;
        }
        
        return result;
    }
};
