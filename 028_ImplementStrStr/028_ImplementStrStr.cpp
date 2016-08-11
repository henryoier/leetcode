/*************************************************************************
	> File Name: 028_ImplementStrStr.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Aug 10 18:31:24 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        while(index + needle.size() <= haystack.size()){
            bool check = true;
            for(int i = 0; i < needle.size(); i++ ){
                if(haystack[index + i] != needle[i]){
                    check = false;
                    break;
                }
            }
            if(check)
                return index;
            else
                index++;
        }
        return -1;
    }
};

int main(){
    Solution newSolution;

    cout << newSolution.strStr("bacvscsvzSasefsvs","scsv") << endl;
    return 0;
}
