/*************************************************************************
	> File Name: 406_QueueReconstructionByHeight.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 12 21:34:28 2016
 ************************************************************************/

#include<iostream>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        vector<pair<int, pair<int, int>>> queue;
        
        for(auto i : people){
            queue.push_back(pair<int, pair<int, int>>(i.second, i));
        }
        
        sort(queue.begin(), queue.end(), comp);
        
        while(!queue.empty()){
            pair<int,int> cur = queue.begin()->second;
            queue.erase(queue.begin());
            
            result.push_back(cur);
            for(int i = 0;i < queue.size(); i++)
                if(cur.first >= queue[i].second.first){
                    queue[i].first--;
                    int j = i;
                    while(j > 0 && (queue[j].first < queue[j - 1].first || (queue[j].first == queue[j - 1].first && queue[j].second.first < queue[j - 1].second.first))){
                            swap(queue[j], queue[j - 1]);
                            j--;
                    }
                }
                
            
        }
        return result;
    }
private:
    struct compare{
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b){
            if(a.first < b.first || (a.first == b.first && a.second.first < b.second.first))
                return true;
            else
                return false;
        }
    } comp;
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        sort(people.begin(), people.end(), comp);
        
        for(auto i:people)
            result.insert(result.begin() + i.second, i);
        return result;
    }
private:
    struct compare{
        bool operator()(pair<int, int> a, pair<int, int>b){
            if(a.first > b.first || (a.first == b.first && a.second < b.second))
                return true;
            else
                return false;
        }
    } comp;
};
