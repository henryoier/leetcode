/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto i : nestedList)
            nest.push_back(i);
        
        while(!nest.empty() && !nest.front().isInteger()){
            vector<NestedInteger> now = nest.front().getList();
            nest.pop_front();
            for(int i = now.size() - 1; i >= 0; i--)
                nest.push_front(now[i]);
        }
    }

    int next() {
        int result = nest.front().getInteger();
        nest.pop_front();
        
        while(!nest.empty() && !nest.front().isInteger()){
            vector<NestedInteger> now = nest.front().getList();
            nest.pop_front();
            for(int i = now.size() - 1; i >= 0; i--)
                nest.push_front(now[i]);
        }

        return result;
    }

    bool hasNext() {
        return !nest.empty(); 
    }
private:
    deque<NestedInteger> nest;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        return s.top().first++->getInteger();
    }

    bool hasNext() {
        while (s.size()) {
            vector<NestedInteger>::iterator current = s.top().first;
            vector<NestedInteger>::iterator end = s.top().second;
            if (current == end) {
                s.pop();
            } else {
                if (current->isInteger())
                    return true;
                else {
                    s.top().first++;
                    if (current->getList().begin() != current->getList().end())
                        s.push(make_pair(current->getList().begin(), current->getList().end()));
                }
            }
        }
        return false;
    }
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

