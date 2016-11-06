class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.erase(beginWord);

        queue<string> q;
        q.push(beginWord);
        int step = 0;

        while(!q.empty()){
            step++;
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cur = q.front();
                q.pop();
                for(int j = 0; j < cur.size(); j++){
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == cur[j])
                            continue;
                        string n = cur;
                        n[j] = c;
                        if(n == endWord){
                            return step + 1;
                        } else if(wordList.count(n)){
                            q.push(n);
                            wordList.erase(n);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
