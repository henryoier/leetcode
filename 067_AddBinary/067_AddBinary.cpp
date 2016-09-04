/*************************************************************************
	> File Name: 067_AddBinary.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Sep  4 19:16:56 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if(a.length() < b.length())
            swap(a, b);

        int len = a.length(), len2 = b.length();

        int carry = 0;

        for(int i = 0; i < len; i++){
            if(i < len2){
                int now = a[i] + b[i] - 2 * '0' + carry;
                carry = now > 1;
                a[i] = now % 2 + '0';
            } else {
                int now = a[i] - '0' + carry;
                carry = now > 1;
                a[i] = now % 2 + '0';
            }
        }
        
        if(carry > 0)
            a = a + '1';

        reverse(a.begin(), a.end());

        return a;
    }
};

int main() {
    Solution newSolution;

    cout << newSolution.addBinary("1","1011") << endl;

    return 0;
}
