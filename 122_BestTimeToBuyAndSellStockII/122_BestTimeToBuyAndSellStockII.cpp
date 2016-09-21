/*************************************************************************
	> File Name: 122_BestTimeToBuyAndSellStockII.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Sep 21 00:31:24 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
            
        int buyPoint = INT_MAX;
        int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            if(i == 0 && prices[i + 1] > prices[i])
                buyPoint = prices[i];
                
            if(i > 0 && i < prices.size() - 1 && prices[i+1] > prices[i] && prices[i - 1] >= prices[i])
                buyPoint = prices[i];
            
            if(i == prices.size() - 1 && prices[i] > prices[i - 1])
                maxProfit += prices[i] - buyPoint;
                    
            if(i > 0 && i < prices.size() - 1 && prices[i+1] <= prices[i] && prices[i - 1] < prices[i])
                maxProfit += prices[i] - buyPoint;
        }
    
        return maxProfit;
    }
};

int main() {
    return 0;
}
