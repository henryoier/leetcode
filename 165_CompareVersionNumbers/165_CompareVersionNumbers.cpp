/*************************************************************************
	> File Name: 165_CompareVersionNumbers.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep 25 23:11:26 2016
 ************************************************************************/

#include<iostream>

using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(!version1.empty() && !version2.empty()){
            int index1 = version1.find('.'), index2 = version2.find('.');
            if(index1 == string::npos)
                index1 = version1.size();
                
            if(index2 == string::npos)
                index2 = version2.size();   
            
            int version1_now = atoi(version1.substr(0, index1).c_str()), version2_now = atoi(version2.substr(0, index2).c_str());
            if(version1_now > version2_now)
                return 1;
            if(version1_now < version2_now)
                return -1;

            if(index1 != version1.size())
                version1 = version1.substr(index1 + 1);
            else
                version1 = version1.substr(index1);
                
            if(index2 != version2.size())
                version2 = version2.substr(index2 + 1);
            else
                version2 = version2.substr(index2);   
        }     
        if(!version1.empty()){
            while(!version1.empty()){
                int index = version1.find('.');
                
                if(index == string::npos)
                    index = version1.size();
                int version1_now = atoi(version1.substr(0, index).c_str());
                
                if(version1_now > 0)
                    return 1;
                    
                if(index != version1.size())
                    version1 = version1.substr(index + 1);
                else
                    version1 = version1.substr(index);
            }
        }
        if(!version2.empty()){
            while(!version2.empty()){
                int index = version2.find('.');
                
                if(index == string::npos)
                    index = version2.size();
                int version2_now = atoi(version2.substr(0, index).c_str());
                
                if(version2_now > 0)
                    return -1;
                    
                if(index != version2.size())
                    version2 = version2.substr(index + 1);
                else
                    version2 = version2.substr(index);
            }
        }
            
        return 0;    
    }
};
