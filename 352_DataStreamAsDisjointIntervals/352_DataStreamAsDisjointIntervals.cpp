/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval cur(val, val);
        if(list.empty()){
            list.push_back(cur);
            return;
        }
  
        auto l = lower_bound(list.begin(), list.end(), cur, comp);
        
        if(l == list.end()){
            if(prev(l)->end + 1 == cur.start){
                prev(l)->end = cur.end;
            } else{ 
                if(cur.start > prev(l)->end){
                    list.push_back(cur);
                } else {}
            }
        } else if(l == list.begin()){
            if(l->start - 1 == cur.end){
                l->start = cur.start;
            } else {
                if(cur.end < l->start){
                    list.insert(list.begin(), cur);
                } else {}
            }
        } else {
            if(prev(l)->end + 1 == cur.start && l->start - 1 == cur.end){
                prev(l)->end = l->end;
                list.erase(l);
            } else if(prev(l)->end + 1 == cur.start){
                prev(l)->end = cur.end;
            } else if(l->start - 1 == cur.end){
                l->start = cur.start;
            } else if(cur.end < l->start){
                list.insert(l, cur);
            }
        }
    }
    
    vector<Interval> getIntervals() {
        return list;
    }
private:
    struct compare{
        bool operator()(Interval a, Interval b){
            return a.end < b.start;
        }
    } comp;
    vector<Interval> list;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
