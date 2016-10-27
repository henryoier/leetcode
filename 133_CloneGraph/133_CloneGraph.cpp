/*************************************************************************
	> File Name: 133_CloneGraph.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Wed Oct 26 20:30:32 2016
 ************************************************************************/

#include<iostream>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr)
            return nullptr;
        unordered_map<int, UndirectedGraphNode*> searched;
        
        return graphNode(node, searched);
    }
    
private:
    UndirectedGraphNode *graphNode(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &searched){
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        for(int i = 0; i < node->neighbors.size(); i++)
            newNode->neighbors.push_back(node->neighbors[i]);
        
        searched.insert({newNode->label, newNode});
        
        for(int i = 0; i < newNode->neighbors.size(); i++){
            auto pos = searched.find(newNode->neighbors[i]->label); 
            if(pos != searched.end())
                newNode->neighbors[i] = pos->second;
            else
                newNode->neighbors[i] = graphNode(newNode->neighbors[i], searched);
        }
        return newNode;
    }
};
