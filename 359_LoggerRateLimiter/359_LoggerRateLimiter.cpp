/*************************************************************************
	> File Name: 359_LoggerRateLimiter.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 15:23:11 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!log.empty() && log[0].first + 9 < timestamp)
            log.erase(log.begin());
            
        for(auto i:log)
            if(i.second == message)
                return false;
                
        log.push_back(pair<int, string>(timestamp, message));
        return true;
    }
private:
    vector<pair<int, string>> log;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
