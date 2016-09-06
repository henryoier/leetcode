/*************************************************************************
	> File Name: 071_SimplifyPath.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Tue Sep  6 16:50:26 2016
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string now;
        vector<string> wholePath;

        int current = 0;
        wholePath.push_back("/");

        while(path.length() != 0){
            path = path.substr(1);
            int next = path.find('/');
            if(next != -1){
                now = path.substr(0, next);
                path = path.substr(next);
            } else {
                now = path;
                path = "";
            }
            

            if(now == ".")
                continue;
            else if(now == "..")
                if(current == 0)
                    continue;
                else
                    current--;
            else if(now == "")
                continue;
            else{
                    current++;
                    if(current == wholePath.size())
                        wholePath.push_back('/' + now);    
                    else
                        wholePath[current] = '/' + now;
                }

        }
        string result;
        for(int i = 1; i <= current; i++)
            result = result + wholePath[i];  
        if(current == 0)
            return "/";
        else
            return result;    
    }
};

int main() {
    Solution newSolution;
    cout << newSolution.simplifyPath("/home/a/b/../..////") << endl;
    return 0; 
}
