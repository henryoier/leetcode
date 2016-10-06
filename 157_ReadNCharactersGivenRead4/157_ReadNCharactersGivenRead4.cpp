/*************************************************************************
	> File Name: 157_ReadNCharactersGivenRead4.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Thu Oct  6 19:35:15 2016
 ************************************************************************/

#include<iostream>

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        int target = 4;
        while(total < n){
            if(total + target <= n){
                int last = read4(buf + total);
                if(last < target)
                    return total + last;
                else
                    total = total + target;
            } else {
                target = n - total;
                int last = read4(buf + total);
                if(last < target)
                    return total + last;
                else
                    return total + target;
            }
        }
        return total;
    }
};
