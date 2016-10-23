/*************************************************************************
	> File Name: 227_BasicCalculatorII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Sun Oct 23 10:47:56 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        istringstream in(s);
        
        stack<int> nums;
        stack<char> opts;
        int num;
        char opt;
        
        while(in >> num){
            if(!opts.empty() && (opts.top() == '*' || opts.top() == '/')){
                int numA = nums.top();
                nums.pop();
                if(opts.top() == '*')
                    nums.push(numA * num);
                else
                    nums.push(numA / num);
                opts.pop();
            } else nums.push(num);
            if(in >> opt)
                opts.push(opt);
            else
                break;
        }
        
        stack<int> nums2;
        stack<char> opts2;
        while(!nums.empty()){
            cout << nums.top();
            nums2.push(nums.top());
            nums.pop();
        }
        while(!opts.empty()){
            opts2.push(opts.top());
            opts.pop();
        }
        
        while(!opts2.empty()){
            int a = nums2.top();
            nums2.pop();
            int b = nums2.top();
            nums2.pop();
            
            if(opts2.top() == '-')
                nums2.push(a - b);
            else
                nums2.push(a + b);
            opts2.pop();
        }
        
        return nums2.top();
    }
};
