/*************************************************************************
	> File Name: 006_ZigZagConversion.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Aug  2 18:43:53 2016
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() == 0)
            return "";

        if (numRows == 1)
            return s;
        int width = (s.length() / (numRows + numRows - 2) + 1) * (numRows - 1);
        char **pattern = new char*[numRows];
        
        for(int i = 0; i<numRows;i++)
            pattern[i] = new char[width];

        for(int i = 0; i < numRows; i++)
            for(int j = 0; j < width; j++)
                pattern[i][j] = '#';
        
        int x = 0,y = 0;
        bool zig = true;
        int maxlength = 0;
        for(int i = 0; i < s.length(); i++){
            pattern[x][y] = s[i];
            if(zig){
                x++;
                if(x == (numRows - 1)){
                    zig = false;
                }
            }else{
                x--;
                y++;
                if(y>maxlength){ 
                    maxlength = y;
                }
                if(x == 0){
                    zig = true;
                }
            }
        }
        string ans = "";
        for(int x = 0; x < numRows; x++){
            for(int y = 0; y <= maxlength; y++){
                if(pattern[x][y] != '#')
                    ans = ans + pattern[x][y];
            }
            cout << endl;
        }

        return ans;
    }
};

int main(){
    string s = "twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd";
    int numRows = 4;
    
    Solution newSolution;
    cout << newSolution.convert(s, numRows) << endl;
    return 0;
}
