g`""`class Solution {
public:
    void reverseWords(string &s) {
        if(s.length() == 0)
            return;

        string t("");
        int p = s.length() - 1;
        int last = s.length();
        while(p >= 0){
            if(s[p] == ' ')
                if(p == last - 1){
                    last--;
                    p--;
                } else{
                    if(t == "")
                        t = s.substr(p + 1, last - p - 1);
                    else 
                        t = t + ' ' + s.substr(p + 1, last - p - 1);
                    last = p;
                    p--;
                }
            else
                p--;
        }
        if(last != 0)
            if(t == "")
                t = s.substr(0, last);
            else
                t = t + ' ' + s.substr(0, last);
        s = t;
    }
};

int main() {
    Solution newSolution;
    string s = "the sky is blue";
    
    newSolution.reverseWords(s);

    cout << s << endl;
    return 0;
}
