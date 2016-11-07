class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> parent(m * n, -1);
        vector<int> res;
        
        int pos[5]{1,0,-1,0,1};
        int result = 0;
        
        for(auto i:positions){
            int x = i.first;
            int y = i.second;

            parent[x * n + y] = x * n + y;
            result++;
            
            unordered_set<int> count;
            count.clear();
            for(int j = 0; j < 4; j++){
                if(x + pos[j] >= m || x + pos[j] < 0 || y + pos[j + 1] >= n || y + pos[j + 1] < 0)
                    continue;
                    
                int curPos = (x + pos[j]) * n + y + pos[j + 1];
                    
                if(parent[curPos] >= 0){
                    while(parent[curPos] != curPos){
                        curPos = parent[curPos] = parent[parent[curPos]];
                    }
                    count.insert(parent[curPos]);
                }
            }
            result -= count.size();
            res.push_back(result);
            
            for(auto i:count)
                parent[i] = x * n + y;
        }
        
        return res;
    }
};
