/*************************************************************************
	> File Name: 038_CountAndSay.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug 30 22:39:01 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else
            return convert(countAndSay(n - 1));
    }

private:
    string convert(string last){
        char ch = last[0];
        int count = 1;
        string result = "";

        for(int i = 1; i < last.size(); i++){
            if(last[i] == ch) {
                count++;
            }   
            else{
                result = result + (char)(count + '0') + ch;
                ch = last[i];
                count = 1;
            }
        }
        result = result + (char)(count + '0') + ch;
        return result;
    }
};

int main(){
    Solution newSolution;
    cout << newSolution.countAndSay(5) << endl;

    return 0;
}
