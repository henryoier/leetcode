/*************************************************************************
	> File Name: 003_LongestSubstringWithoutRepeatingCharacters.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Jul 26 16:43:09 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        
        int head = 1, tail = s.length();
        int midMax = 1;
        while(head < tail){       
            int mid = (head + tail + 1) / 2;
            int index = 0;
            bool unique = false;
            while(index + mid <= s.length()){ 
                if(checkUnique(s.substr(index, mid))){
                    unique = true;
                    break;
                } else index++;            
            }
            if(unique){
                if(mid > midMax)
                    midMax = mid;
                head = mid;
            } else {
                tail = mid - 1;
            }
        }
        return midMax;
    }

private:
    bool checkUnique(string str){
        sort(str.begin(), str.end());
        for(auto s = str.begin(); s < str.end() - 1; s++){
            if(*s == *(s+1))
                return false;
        } 
        return true;
    }
};*/

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int start = 0, maxLen = 0;
        fill(last, last + ASCII_MAX, -1);

        for(int i = 0; i < s.size(); i++){
            if(last[s[i]] >= start){
                if(i - start > maxLen)
                    maxLen = i - start;
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        if(s.size() - start > maxLen)
            maxLen = s.size() - start;
        return maxLen;
    }
};

int main(){

    Solution newSolution;
    string s;

    cin >> s;
    cout << newSolution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
