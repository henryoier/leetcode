/*************************************************************************
	> File Name: 273_IntegerToEnglishWords.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep 30 09:58:30 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string pos[4] = {"", "Thousand", "Million","Billion"};
        string digit[10] = {"", "One", "Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string teenDigit[10] = {"Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tensDigit[10] = {"", "","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        int nowPos = 0;
        string result = "";
        while(num > 0){
            int current = num % 1000;
            num = num / 1000;
            
            string currRes;
            int a = current / 100;
            int b = current / 10 % 10;
            int c = current % 10;
            
            if(b * 10 + c >= 10 && b * 10 + c <= 19){
                currRes = teenDigit[b * c + 10 - 10] + currRes;
            } else if(b == 0 && c != 0){
                currRes = digit[c] + currRes;
            } else if(c == 0 && b != 0){
                currRes = tensDigit[b] + currRes;
            } else if(b != 0 && c != 0){
                currRes = tensDigit[b] + " " + digit[c] + currRes;
            } else {
            }
            
            if(a > 0){
                if(currRes != "")
                    currRes = digit[a] + " Hundred " + currRes;
                else
                    currRes = digit[a] + " Hundred";
            }
            if(result != "")
                if(currRes != "")
                    result = currRes + " " + pos[nowPos] + " " + result;
                else
                    {}
            else
                if(nowPos == 0)
                    result = currRes;
                else
                    if(currRes != "")
                        result = currRes + " " + pos[nowPos];
                    else
                        {}
            nowPos++;
        }
        return result;
    }
};

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string pos[4] = {"", "Thousand", "Million","Billion"};
        string digit[10] = {"", "One", "Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string teenDigit[10] = {"Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string tensDigit[10] = {"", "","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        int nowPos = 0;
        string result = "";
        while(num > 0){
            int current = num % 1000;
            num = num / 1000;
            
            string currRes;
            int a = current / 100;
            int b = current / 10 % 10;
            int c = current % 10;
            
            if(b * 10 + c >= 10 && b * 10 + c <= 19){
                currRes = teenDigit[b * c + 10 - 10] + currRes;
            } else {
                currRes = tensDigit[b] + " " + digit[c] + currRes;
            }
            
            if(a > 0)
                currRes = digit[a] + " Hundred " + currRes;
            
            for(int i = 0; i < currRes.length(); i++)
                if((currRes[i] == ' ' && i == currRes.length() - 1)||(currRes[i] == ' ' && currRes[i + 1] == ' '))
                    currRes.erase(currRes.begin() + i);
            
            if(currRes != "")
                result = currRes + " " + pos[nowPos] + " " + result;
            nowPos++;
        }
        
        for(int i = 0; i < result.length();)
            if((result[i] == ' ' && (i + 1 == result.length() || i == 0))||(result[i] == ' ' && result[i + 1] == ' '))
                result.erase(result.begin() + i);
            else
                i++;
                
        return result;
    }
};
