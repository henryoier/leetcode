###Leetcode Review
####001_TwoSum   
**Main Algo:** using unordered_map  
**Corner Case:** target = 2 * nums[i]  
**Core Codes:**  

####002_AddTwoNumbers 
**Main Algo:** LinkedList  
**Corner Case:** 9->9 + 1  

####003_LongestSubstringWithoutRepeatingCharacters  
**Main Algo:** Greedy, similar to two pointers.  
**Cornere Case:** "", "pppp"  
**Core Codes:**  

```c++
int last[ASCII_MAX];
int start = 0, maxLen = 0;
fill(last, last + ASCII_MAX, -1);

for(int i = 0; i < s.size(); i++){
    if(last[s[i]] >= start){
        if(i - start > maxLen)
            maxLen = i - start;
        start = last[s[i]] + 1;
    }
    last[s[i]] = i;
}
if(s.size() - start > maxLen)
    maxLen = s.size() - start;
return maxLen;
```

####004_MedianOfTwoSortedArrays 1Y  

####005_LongestPalindromicSubstring
**Main Algo:** 

* Enum all mids(odd and even are differnt), find the length, DP, O(n^2).  
* **Manacher’s Algorithm O(n)**

####006_ZigZagCoversion
**Main Algo:** Math  
**Corner Case:** s = "", numRows = 1  
**Core Codes:**  

```c++
for(int i = 0; i < s.size(); i++){
    int p = i % (2 * numRows - 2);
    if(p < numRows){
        row[p] += s[i];
    } else {
        row[2 * numRows - 2 - p] += s[i]; // think about the graph of the function.
    }
}
```  

####007_ReverseInteger  
**Corner Case:** Overload

####008_StringToInteger
**Corner Case:**

* WhiteSpaces at the beginning
* ‘+’ and ‘-’
* conversion breaks when there is a character which is not a number. 
* overload of MAX_INT and MIN_INT.  

####009_PalindromeNumber
**Corner Case:**

* All negative numbers are not palindromes.
* Ignore white spaces.

####010_RegularExpressionMatching  
**Main Algo:**

* Recursion,
* DP, compress the space complexity   

**Corner Case:**  

* P's end contians redundant *s.

**Core Codes:**

```c++
if(s_pos == s.length()) {
	 // Remove redundant *s
	 while((p_pos + 1 < p.length() && p[p_pos + 1] == '*'))
        p_pos += 2;
    return p_pos == p.length();
} 
if(p_pos == p.length())
    return s_pos == s.length();
    
if(p[p_pos] == '.' || s[s_pos] == p[p_pos]) // currently matched
    if(p_pos + 1 < p.length() && p[p_pos + 1] == '*')
        return match(s, p, s_pos + 1, p_pos) || match(s, p, s_pos, p_pos + 2);
    else 
        return match(s, p, s_pos + 1, p_pos + 1);
else 
    if(p_pos + 1 < p.length() && p[p_pos + 1] == '*')
        return match(s, p, s_pos, p_pos + 2);
    else 
        return false;
```

```c++
//DP with space compression
for(int i = 1; i <= n; i++){
    f[i % 2][0] = false; // Must write this
    for(int j = 1; j <= m; j++)
        if(p[j - 1] == '*')
            f[i % 2][j] = f[i % 2][j - 2] || (f[(i + 1) % 2][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        else
            if(p[j - 1] == '.' || (s[i - 1] == p[j - 1]))
                f[i % 2][j] = f[(i + 1)%2][j - 1];
            else
                f[i % 2][j] = false;
}
```
####011_ContainerWithMostWater   
**Main Algo:** Greedy, from the outside to inside, the height was determined by the lower buck. So we always choose the higher one to be remained. Since the distance is decreasing.  
**Core codes**

```C++
while (start < end) {
    int area = min(height[end], height[start]) * (end - start);
    result = max(result, area);
    if (height[start] <= height[end]) {
        start++;
    } else {
        end--; 
    }
}
```
 
####012\_IntegerToRoman && 013_RomanToInteger
**Main Algo:** There are only two types of digits, IX (X minus I) or else(Add all letters together).  

####014_LongestCommonPrefix  

####015_3Sum  
**Main Algo:** 

* Hashmap O(n^2), we have to sort first. And it will TLE if do not pass the same numbers. **Here why hashmap works with dups existing?**
* Use three pointers. O(n^(k - 1))

**Core Codes:**

```c++
// Three pointers.
sort(nums.begin(), nums.end());
for(int i = 0; i < nums.size() - 2; i++){
    if(i > 0 && nums[i] == nums[i - 1])
        continue;
    int j = i + 1, k = nums.size() - 1;
    while(j < k){
        if(nums[i] + nums[j] + nums[k] < 0){
            j++;
            while(j < k && nums[j] == nums[j - 1])
                j++;
        } else if (nums[i] + nums[j] + nums[k] > 0){
            k--;
            while(j < k && nums[k] == nums[k + 1])
                k--;
        } else {
            result.push_back(vector<int>({nums[i], nums[j], nums[k]}));
            k--;
            while(j < k && nums[k] == nums[k + 1])
                k--;
        }
    }
}
```

####016_3SumClosest 
**Main Algo:** Three pointers.  
**Core Codes:** 

```c++
sort(nums.begin(), nums.end());        
for(auto i = nums.begin(); i != prev(nums.end(), 2); i++){
    auto j = next(i);
    auto k = prev(nums.end());
    
    while(j < k){
        int sum = *i + *j + *k;
        int gap = abs(target - sum);
        if(gap < min_gap){
            min_gap = gap;
            min_sum = sum;
        }
        if(sum < target) j++;
        else k--;
    }
}
```

####017_LetterCombinationOfAPhoneNumber  
**Main Algo:** Typical DFS  

####018_4Sum
**Main Algo:** Four pointers  

####019_RemoveNthNodeFromEndOfList 1Y  
**Main Algo:** The best way to solve this problem is to set two pointer at the begining. The first one go n steps first and then they go together until the first on goes to the end.  
**Corner Cases:** empty list, or remove the head node.
**Core Codes:**  

```c++
ListNode* now = head;

if(now == NULL)
    return now;

int tempN = n;
while(tempN > 1){
    now = now->next;
    tempN--;
}

if(now->next == nullptr)
    return head->next;
    
ListNode* newHead = head;
ListNode* last;
while(now->next != nullptr){
    last = newHead;
    newHead = newHead->next;
    now = now->next;
}
last->next = newHead->next;
return head;
``` 

####020_ValidParentheses
**Main Algo:** Use a stack to pair the brackets and pop, once the current right bracket can not be paired to the top of the stack it goes wrong.    
  
####021\_MergeTwoSortedLists && 023_MergeKSortedLists 
**Main Algo:** Using a priority_queue, O(nlogk).  
**Core Codes:**  

```c++
auto cmp = [](ListNode* l1, ListNode* l2){
    return l1->val > l2->val;
};
priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > heap(cmp);

for(auto i:lists)
    if(i != nullptr)
        heap.push(i);
if(heap.empty())
    return nullptr;

ListNode *head = heap.top();
ListNode *now = head;
if(heap.top()->next != nullptr)
    heap.push(heap.top()->next);
heap.pop();

while(!heap.empty()){
    now->next = heap.top();
    now = now->next;
    if(heap.top()->next != nullptr)
        heap.push(heap.top()->next);
    heap.pop();
}
now->next = nullptr;
return head;
```
####022_GenerateParentheses  
**Main Algo:** The parentheses follow the rule that if the unpaired left ones are zero, you couldn’t put a right one. Besides, if n * 2 - pos == leftn, then you can only put right ones.  
**Core codes:** 

```c++
if(leftn == 0){
    resultChar[pos] = '(';
    getParenthesis(n, pos + 1, leftn + 1, resultChar, result);
} else {
    if(n * 2 - pos > leftn){
        resultChar[pos] = '(';
        getParenthesis(n, pos + 1, leftn + 1, resultChar, result);

        resultChar[pos] = ')';
        getParenthesis(n, pos + 1, leftn - 1, resultChar, result);
    } else {
        resultChar[pos] = ')';
        getParenthesis(n, pos + 1, leftn - 1, resultChar, result);
    }
}  
```

####024\_SwapNodesInPairs && 025_ReverseNodesInKGroup
**Main Algo:** Record the current position, when it is larger than n/k * k, it shouldn't be reversed.  
**Core Codes:** 

```c++
ListNode *newNode;
newNode = reverse(head->next, k, order + 1, n);
    
if(order % k == 0 || order > n/k * k){
    head->next = newNode;
    return head;
} else {
    ListNode* now = newNode;
    int t = order;
    while((t + 1) % k != 0){
        now = now->next;
        t++;
    }
    head->next = now->next;
    now->next = head;
    return newNode;
}
```
 
####026_RemoveDuplicatesFromSortedArray
**Core Codes:**  

```c++
return distance(nums.begin(), unique(nums.begin(), nums.end()));
``` 

####027_RemoveElement
**Mail Algo:** Move all non-val value to the begining of the array.  
**Core Codes:**  

```c++
int index = 0;
for(int i = 0; i < nums.size(); i++){
    if(nums[i] != val){
        nums[index++] = nums[i];
    }
}
return index;
```

####028_ImplementStrStr()

####029_DivideTwoIntegers  
**Mail Algo:** The divisor can be doubled every time to accelerate.   **Corner Cases:** overload situation  
**Core Codes:**

```c++
if (!divisor || (dividend == INT_MIN && divisor == -1))
    return INT_MAX;
int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
long dvd = labs(dividend);
long dvs = labs(divisor);
int res = 0;
while (dvd >= dvs) { 
    long temp = dvs, multiple = 1;
    while (dvd >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
    }
    dvd -= temp;
    res += multiple;
}
return sign == 1 ? res : -res; 
```
####030_SubstringWithConcatenationOfAllWords
**Main Algo:** An important condition--all words are the same length. 
**Core Codes:**

```c++
for(auto word:words)
    expected[word]++;

for(int i = 0; i + n * len <= s.length(); i++){
    unordered_map<string, int> seen;
    int j = i;
    int count = 0;
    while(true){
        string now = s.substr(j, len);
        if(expected.find(now) == expected.end() || seen[now] == expected[now])
            break;
        else{
            count++;
            seen[now]++;
            j += len;
        }
    }
    if(count == n)
        result.push_back(i);
}
```
 
####031_NextPermutation
**Core Codes:**

```c++
for(auto first = nums.end() - 2; first >= nums.begin(); first--){  
	for(auto last = nums.end() - 1; last != first; last--){  
    	if(*last > *first){  
			swap(*last, *first);  
    		sort(first + 1, nums.end());  
    		return;  
		}  
	}  
}  
```

####032_LongestValidParentheses
**Corner Cases:** "(()" we have to apply this algorithm twice.  
**Core Codes:**

```c++
for(int pos = 0; pos < s.length(); pos++ ){  
	if(s[pos] == '(')  
		unpair++;  
	else  
		if(unpair == 0)  
			lastPos = pos;  
		else{  
			unpair--;  
			if(unpair == 0)  
				if(pos - lastPos > max)  
					max = pos - lastPos;  
		}  
}  
```

####033\_SearchInRotatedSortedArrayI && 081_SearchInRotatedSortedArrayII
**Main Algo:** Binary Search with different conditions. In the later problem, the difference is that once mid == tail, tail--.  
**Core Codes:**

```c++
while(head < tail){
    int mid = (head + tail) / 2;
    if(nums[mid] > nums[tail])f
        if(target >= nums[head] && target <= nums[mid])
            tail = mid;
        else
            head = mid + 1;
    else if(nums[mid] < nums[tail])
        if(target > nums[mid] && target <= nums[tail])
            head = mid + 1;
        else
            tail = mid;
    else
        tail--;
}
``` 

####034_SearchForARange
**Main Algo:** Binary search to find the lower and upper bounds.
**Core Codes:**

```c++
// lower_bound & upper_bound
std::vector<int>::iterator low=std::lower_bound (nums.begin(), nums.end(), target);
    if(*low != target) return result;
    std::vector<int>::iterator up= std::upper_bound (low, nums.end(), target) -1;
    result[0] = low - nums.begin();
    result[1] = up - nums.begin();

// Binary search twice
int head = 0, tail = nums.size();
while(head < tail){
    int mid = (head + tail) / 2;
    if(nums[mid] >= target)
        tail = mid;
    else
        head = mid + 1;
}
if(nums[head] != target) // check if there is a range
    return result;
result[0] = head;

head = 0, tail = nums.size();
while(head < tail){
    int mid = (head + tail) / 2;
    if(nums[mid] <= target)
        head = mid + 1;
    else
        tail = mid;
}
result[1] = tail - 1;
```

####035_SearchInsertPosition  
**Main Algo:** Binary Search  
  
####036\_ValidSudoku && 037_SudokuSolver
**Main Algo:** DFS  

####038_CountAndSay  

####039\_CombinationSum && 040_CombinationSum II
**Main Algo:** Recursion, sort the candidates first.   
For combinationII, we can not choose the same candidates more than once. And finally we have to remove duplicate answers.  
**Core Codes:**

```c++
if(target == 0)
    return vector<vector<int>>(1, vector<int>());
    
if(start == candidates.size() || candidates[start] > target)
    return result;

result = findComb(candidates, start, target - candidates[start]);
for(int i = 0; i < result.size(); i++)
    result[i].insert(result[i].begin(), candidates[start]);
vector<vector<int>> temp = findComb(candidates, start + 1, target);
result.insert(result.end(), temp.begin(), temp.end());
        
``` 

####041_FirstMissingPositive
```c++
//Interval solution
for(auto i = nums.begin(); i != nums.end(); i++){  
    if(*i <= 0)  
        continue;  

    for(int j = 0; j < result.size(); j++){  
        if(*i >= result[j].first && *i <= result[j].second){  
            pair<int, int> left, right;  
            left = make_pair(result[j].first, *i - 1);  
            right = make_pair(*i + 1, result[j].second);  
            result.erase(result.begin() + j);  
            if(left.first <= left.second)  
                result.insert(result.begin() + j++, left);  
            if(right.first <= right.second)  
                result.insert(result.begin() + j, right);  
            break;  
        }  
    }  
}  
    
// O(1) space.
int i, n = nums.size();
for(i=0; i<n; i++){
    while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
        swap(nums[i], nums[nums[i]-1]);
}
    
int j=1;
for(j=1; j<=n; j++)
    if(nums[j-1]!=j)
        break;
        
return j;
```

####042_TrappingRainWater 2Y  
**Main Algo:**  

* Find the left most height and right most height at each point, the result will be sum (min(left[i], right[i]) - height[i])
* From the outest two bars go inside to the 

**Core Codes:**

```c++
// Find left and right most.
for(int i = 0; i < n; i++){
    if(i == 0){
        left[i] = height[i];
        right[n - i - 1] = height[n - i - 1];
    } else {
        if(height[i] <= left[i - 1])
            left[i] = left[i - 1];
        else
            left[i] = height[i];
        if(height[n - i - 1] <= right[n - i])
            right[n - i - 1] = right[n - i];
        else
            right[n - i - 1] = height[n - i - 1];
    }
}

// From outside to inside
int trap(vector<int>& height) {
    auto l = height.begin(), r = height.end() - 1;
    int level = 0, water = 0;
    while (l != r + 1) {
        int lower = *l < *r ? *l++ : *r--;
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}
```

####043_MultiplyStrings 2Y  
**Corner Cases:** One of the factor is 0.  
**Core Codes:**

```c++
for(int i = 0; i < num1.size(); i++){
    for(int j = 0; j < num2.size(); j++){
        mulResult[i + j] += n1[i] * n2[j] % 10;
        mulResult[i + j + 1] += n1[i] * n2[j] / 10;
    }
}

for(int i  = 0; i < length - 1; i++){
    if(mulResult[i] > 9) {
        mulResult[i + 1] += mulResult[i] / 10;
        mulResult[i] = mulResult[i] % 10 ; 
    }
}
```
####044_WildcardMatching
**Core Codes:**

```c++
//DP similar to regex expression matching
for(int i = 1; i <= n; i++){
    f[i % 2][0] = false;
    for(int j = 1; j <= m; j++)
        if(p[j - 1] == '*'){
            f[i % 2][j] = f[i % 2][j - 1] || f[(i + 1) % 2][j];
        } else if(p[j - 1] == '?' || s[i - 1] == p[j - 1])
            f[i % 2][j] = f[(i + 1) % 2][j - 1];
        else
            f[i % 2][j] = false;
}
```  

####046\_Permutations and 047_PermutationsII
**Main Algo:** 

* Dfs could solve, for permutation II, we have to cut edges. 
* Next permutation function.  

**Core Codes:**

```c++
sort(nums.begin(), nums.end());

do{
    result.push_back(nums);
} while(next_permutation(nums.begin(), nums.end()));
```

####048_RotateImage
**Main Algo:** Rotate in place, since it's a square matrix.    
**Core Codes:**

```c++
while(start < end){
    for(int i = 0; i < end - start; i++){
        int mid = matrix[start][start + i];
        matrix[start][start + i] = matrix[end - i][start];
        matrix[end - i][start] = matrix[end][end - i];
        matrix[end][end - i] = matrix[start + i][end];
        matrix[start + i][end] = mid;
    }
    start++;
    end--;
}
```

####049_GroupAnagrams
**Main Algo:** Use a unordered_map to map the sorted version to the orginal string. Other wise it would TLE. 
**Core Codes:**

```c++
for(auto k : strs){
    string a = k;
    sort(a.begin(), a.end());
    s[a].push_back(k);
}
```

####050_Pow(x, n)
**Main Algo:** Split n to n / 2.  
**Corner Cases:** n = 0, n < 0  
**Core Codes:**  

```c++
double myPow(double x, int n) {
    if(n < 0)
        return 1.0 / power(x, -n); // deal with n < 0
    else
        return power(x, n);
}

double power(double x, long n){
    if(n == 0)
        return 1.0;
        
    double half = power(x, n / 2);

    if(n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}
```

####051\_N-Queens && 052_N-QueensII  
**Main Algo:** Typical DFS  
**Core Codes:** 

```c++
// Bit operation.
void solve(int row, int ld, int rd) {
    if (row == lim) { // have placed row queens
        ans ++;  // we have a solution
        return;
    }
    int pos = lim & (~(row | ld | rd)); // valid positions
    while (pos != 0) {
        int p = pos & (-pos); // rightmost position
        pos -= p; // have tried this
        solve(row + p, (ld + p) << 1, (rd + p) >> 1);
    }
}
 
int totalNQueens(int n) {
    ans = 0;
    lim = (1 << n) - 1;
    solve(0, 0, 0);
    return ans;
}  
```
 
####053_MaximumSubarray
**Main Algo:** Greedy, when current sum is less than 0, let it be 0.   

####054\_SpiralMatrix && 059_SpiralMatrixII
**Main Algo:** Move towards four directions. Each time when the next step is illegal, change the direction.  
**Core Codes:**

```c++ 
vector<vector<int>> result(n, vector<int>(n, 0));
int direc[5] = {0, 1, 0, -1, 0};

int x = 0, y = 0, d = 0;
for(int i = 1; i <= n * n; i++){
    result[x][y] = i;
    if(x + direc[d] == n || x + direc[d] < 0 || y + direc[d + 1] == n || y + direc[d + 1] < 0 || result[x + direc[d]][y + direc[d + 1]] != 0)
        d = (d + 1) % 4;
    x += direc[d];
    y += direc[d + 1];
}
    return result;  
```

####055\_JumpGame && 045_JumpGameII
**Main Algo:** For jump game II, it's similar to BFS, but we could use a greedy algorithm.  
**Core Codes:**

```c++
for(int i = 0; i < nums.size(); i++){
    if(i > last){ // out of the range of step
        step++;
        last = max;
    }
    
    if(i == nums.size() - 1) // arrive the end
        return step;
        
    if(i + nums[i] > max) // find the range of the next step
        max = i + nums[i];
}
```

####056\_MergeIntervals && 057_InsertIntervals
**Main Algo:** All can be solved by sort by the starts, and insert them to the answer one by one.  
**Core Codes:**

```c++
sort(intervals.begin(), intervals.end(), [=](const Interval a, const Interval b){
    return a.start < b.start;
});

vector<Interval> result;

for(auto i : intervals)
    if(result.empty() || i.start > result.back().end)
        result.push_back(i);
    else
        result.back().end = max(result.back().end, i.end);

return result;
``` 

####058_LengthOfLastWord
**Main Algo:** The best way is to use stringstream. 
**Corner Cases:** If do not use stringstream, we need to consiter multiple spaces and a space at the end of the input string.   
**Core Codes:**

```c++
istringstream in(s);
string last = "";
while(in >> last);
return last.length();
```
####060_PermutationSquence
**Main Algo:** If we simply calculate the next permutation it would TLE. This problem is a math problem, where k determines which of the candidate we could choose.  
**Core Codes:**

```c++
string cand = "123456789"; 
string result(n, '0');
for(int i = 0; i < n; i++){
    int cur = (k - 1) / fac(n - i - 1); // Choose the current digit.
    k = (k - 1) % fac(n - i - 1) + 1; // Calculate the remaining.
    cout << i << cur << k << cand[cur] << endl;
    result[i] = cand[cur];
    cand.erase(cur, 1);
}
```
####061_RotateList
**Main Algo:** We circle the list first, and find the newHead to split.  
**Core Codes:**

```c++
int len=1; // number of nodes
ListNode *newH, *tail;
newH=tail=head;
    
// get the number of nodes in the list
while(tail->next){
    tail = tail->next;
    len++;
}
tail->next = head; // circle the link

if(k %= len){
    for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
}
newH = tail->next; 
tail->next = NULL;
return newH;
```
 
####062\_UniquePaths && 063_UniquePathsII && 064_MinimumPathSum
**Main Algo:** DP  
**Core Codes:**

```c++
f[1][1] = !obstacleGrid[0][0];
    
for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
        if(i == 1 && j == 1)
            continue;
        else if(obstacleGrid[i - 1][j - 1] == 1)
            f[i][j] = 0;
        else
            f[i][j] = f[i - 1][j] + f[i][j - 1];

```

####065_ValidNumber
Can contain only 1 e, right should be pure number.
For fraction, right should not contain '-' or '+'  


####066_PlusOne 
####067_AddBinary  

####068_TextJustification 
Mind the details. 

####069_Sqrt(x)
**Main Algo:** Binary Search  
**Corner Cases:**Overflow when compare mid * mid <= x, so we have to compare mid and x / mid.  
**Core Codes:** 

```c++
long head = 0, tail = x;
while(head < tail){
    int mid = (head + tail + 1) / 2;
    if(mid  > (double)x / mid)
        tail = mid - 1;
    else
        head = mid;
}
```   

####070_ClimbingStaris
**Main Algo:** DP
 
####071_SimplifyPath
**Main Algo:** Using istringstream to split the path, use a stack to record the whole path.  
**Corner Cases:** "///", "/../"
**Core Codes:**

```c++
stack<string> dir;
istringstream in(path);

string cur;
while(getline(in, cur, '/')){
    if(cur.empty() || cur == "." || (cur == ".." && dir.empty()))
        continue;
    if(cur == "..")
        dir.pop();
    else
        dir.push('/' + cur);
}
```

####072_EditDistance 
**Main Algo:** DP  
**Core Codes:**

```c++
f[0][0] = 0;
for(int i = 1; i <= m; i++)
    f[i][0] = i;
for(int j = 1; j <= n; j++)
    f[0][j] = j;

for(int i = 0; i <= m; i++)
    for(int j = 0; j <= n; j++)
        if(word1[i - 1] == word2[j - 1])
            f[i][j] = f[i - 1][j - 1];
        else
            f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
```
####073_SetMatrixZeroes
**Main Algo:** To do it in-place, we use the first row and first column to help us to record whether to delete this column or this row. At first we have to find out whether to delete the first row or first column.  
**Core Codes:**

```c++
if(matrix.empty()) return ;
int rowSize = matrix.size(), colSize = matrix[0].size();
bool firstRow = false, firstCol = false;
for(int c = 0; c < colSize; ++c) if(matrix[0][c] == 0) firstRow = true;
for(int r = 0; r < rowSize; ++r) if(matrix[r][0] == 0) firstCol = true;
for(int r = 1; r < rowSize; ++r)
    for(int c = 1; c < colSize; ++c)
        if(matrix[r][c] == 0) matrix[0][c] = matrix[r][0] = 0;
for(int c = 1; c < colSize; ++c) 
    if(matrix[0][c] == 0)
        for(int r = 1; r < rowSize; ++r)
            matrix[r][c] = 0;
for(int r = 1; r < rowSize; ++r) 
    if(matrix[r][0] == 0)
        for(int c = 1; c < colSize; ++c)
            matrix[r][c] = 0;
if(firstRow) for(int c = 0; c < colSize; ++c) matrix[0][c] = 0;
if(firstCol) for(int r = 0; r < rowSize; ++r) matrix[r][0] = 0;
```

####074_SearchA2DMatrix
**Main Algo:** We start from the top-right most position. Every time if the element is smaller than target, we move down to the next row; if it is larger than target, we move to the left column.  
**Core Codes:**

```c++
int x = 0, y = matrix[0].size() - 1;
while(x < matrix.size() && y >= 0){
    if(matrix[x][y] < target)
        x++;
    else if(matrix[x][y] > target)
        y--;
    else
        return true;
}
```

####075_SortColors
**Main Algo:** Count the numbers each color. Or do it in the way below.  
**Core Codes:**

```c++
vector<int> colors(k);
for (int i = 0; i < nums.size; i++) {
    int current = k, num = nums[i];
    while (--current >= num)
        nums[colors[current]++] = current;
}
```  
 
####077_Combinations
**Main Algo:** DFS  
**Core Codes:**

```c++
if(depth == k) {
    result.push_back(path);
    return;
}

for(int i = last + 1; i <= n; i++){ // keep it in asendant order
    path.push_back(i);
    dfs(depth + 1, i, n, k, path, result);
    path.pop_back();
}
```  

####078\_Subsets && 090_SubsetsII
**Main Algo:** For each number we have two distinct choice, choose or not. In subsetsII, we have to sort the nums first to ensure the answers are in asendant order and have to remove the duplicate results at the end.  
**Core Codes:**

```c++
vector<vector<int>> result(1, vector<int>());
for(int i = 0; i < nums.size(); i++){
    vector<vector<int>> temp = result;
    for(auto& k:temp)
        k.push_back(nums[i]);
    result.insert(result.end(), temp.begin(), temp.end());
}
```

079_WordSearch dfs  

####080_RemoveDuplicatesfromSortedArrayII

**Core Codes:**
```c++
int i = 0;
for (int n : nums)
    if (i < 2 || n > nums[i-2])
        nums[i++] = n;
return i;
```

####082_RemoveDuplicatesfromSortedListII && 083_RemoveDuplicatesfromSortedListI
**Core Codes:** A dummy node will sometimes help.
**Core Codes:**

```c++
ListNode *dummy = new ListNode(-1);
dummy->next = head;
ListNode *last = dummy;

while(last->next != nullptr && last->next->next != nullptr)
    if(last->next->val == last->next->next->val){
        int same = last->next->val;
        while(last->next != nullptr && last->next->val == same)
            last->next = last->next->next;
    } else{
        last = last->next;
    }
return dummy->next;
```

084_LargestRectangleInHistogram  

####086_PartitionList
**Main Algo:** Recursively we got the PartitionedList of the next node, and decide where to insert the current node.
**Core Codes:**

```c++
if(head->val < x){
    head->next = partition(head->next, x);
    return head;
} else{
    ListNode* dummy = new ListNode(-1);
    dummy->next = partition(head->next, x);
    ListNode* last = dummy, *now = dummy->next;
    while(head->val >= x && now != nullptr && now->val < x){
        last = now;
        now = now->next;
    }
    last->next = head;
    head->next = now;
    return dummy->next;
}
```

####088_MergeSortedArray
**Core Codes:**

```c++
int ia = m - 1, ib = n - 1, icur = m + n - 1;while(ia >= 0 && ib >= 0) {
    A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];}while(ib >= 0) {    A[icur--] = B[ib--];  }
```

####089_GrayCode
**Main Algo:** For a n bit gray code, the first 2^(n - 1) and last 2^(n - 1) are symmetric except the highest digit, for the former one is zero, and for the later one is 1.
**Core Codes:**

```c++
if(n == 0)
    return vector<int>(1, 0);

vector<int> result1;
result1 = grayCode(n - 1);
vector<int> result = result1;
for(int i = result1.size() - 1; i >=0; i--)
    result.push_back((1 << (n - 1)) + result1[i]);
```

####091_DecodeWays
**Main Algo:** DP
**Corner Cases:** s[i - 1] == '0'  
**Core Codes:**  

```c++
for(int i = 0; i < s.length(); i++){
    if(i == 0){
        if(s[0] != '0')
            f[i] = 1;
        else
            f[i] = 0;
    } else if (i == 1){
        if(s[i] != '0')
            f[i] = f[i - 1];
        if(stoi(s.substr(i - 1, 2)) <= 26 && s[i - 1] != '0')
            f[i] += 1;
    } else {
        if(s[i] != '0')
            f[i] = f[i - 1];
        if(stoi(s.substr(i - 1, 2)) <= 26 && s[i - 1] != '0')
            f[i] += f[i - 2];
    }
}
```

####092_ReverseLinkedListII
**Main Algo:** Recursion, return the result of the next node.
**Core Codes:**

```c++
if(count < m){
    head->next = reverse(head->next, count + 1, m ,n);
    return head;
} else if(count == n){
    return head;
} else {
    ListNode* newHead = reverse(head->next, count + 1, m, n);
    int nowCount = count + 1; 
    ListNode* now = newHead;
    while(nowCount != n){
        now = now->next;
        nowCount++;
    }
    head->next = now->next;
    now->next = head;
    
    return newHead;
}
```

####093_ValidIPAddress
**Core Codes:**

```c++
if(s.empty())
    return;

for(int i = 1; i <= min((int)s.length(), 3); i++){
    string now = s.substr(0, i);
    // Illegal conditions, multiple 0's or larger than 255
    if(i == 3 && now > "255" || (i != 1 && s[0] == '0')) 
        break;
    num[pos] = now;
    dfs(pos + 1, num, s.substr(i), result);
}
```

####095\_UniqueBinarySearchTreeII && 096_UniqueBinarySearchTrees
**Main Algo:** Divide and conquer, recursion or DP all work.  
**Core Codes:**

```c++
//UniqueBinarySearchTreeI
f[0] = 1;
f[1] = 1;
for(int i = 2; i<= n; i++)
    for(int root = 1; root <= i; root++){
        f[i] += f[root - 1] * f[i - root];
    }
    
//UniqueBinarySearchTreeII
if(begin > end){
    result.push_back(nullptr);
    return result;
}
if(begin == end){
    TreeNode *newRoot = new TreeNode(begin);
    result.push_back(newRoot);
    return result;
}

for(int root = begin; root <= end; root++){
    vector<TreeNode*> left_nodes = genTree(begin, root - 1);
    vector<TreeNode*> right_nodes = genTree(root + 1, end);
    for(auto i = left_nodes.begin(); i != left_nodes.end(); ++i)
        for(auto j = right_nodes.begin(); j != right_nodes.end(); ++j){
            TreeNode *newRoot = new TreeNode(root);
            newRoot->left = *i;
            newRoot->right = *j;
            result.push_back(newRoot);
        }
}
```

####097_InterleavingString
**Main Algo:** DP, if use recursion, it would TLE.  
**Core Codes:**

```c++
for(int i = 1; i <= n; i++)
    f[i][0] = s1[i - 1] == s3[i - 1]?f[i - 1][0]:false;
for(int j = 1; j <=m; j++)
    f[0][j] = s2[j - 1] == s3[j - 1]?f[0][j - 1]:false;
    
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
            f[i][j] = f[i - 1][j] || f[i][j - 1];
        else if (s1[i - 1] == s3[i + j - 1])
                f[i][j] = f[i - 1][j];
        else if (s2[j - 1] == s3[i + j - 1])
                f[i][j] = f[i][j - 1];
        else f[i][j] = false;
```
 

####098_ValidateBinarySearchTree  
**Main Algo:** Check if the right-most node of the left subtree is smaller than the root and the left-most node of the right subtree is larger than the root.  
**Core Codes:**

```c++
if(root->left == nullptr)
    leftResult = true;
else{
    TreeNode *now = root->left;
    while(now->right != nullptr)
        now = now->right;
    leftResult = now->val < root->val;
}

if(root->right == nullptr)
    rightResult = true;
else{
    TreeNode *now = root->right;
    while(now->left != nullptr)
        now = now->left;
    rightResult = now->val > root->val;
}

return leftResult && rightResult && isValidBST(root->left) && isValidBST(root->right);
``` 

####099_RecoverBinarySearchTree

####100\_SameTree && 101_SymmetricTree
**Main Algo:** Recursion  

####102\_BinaryTreeLevelOrderTraversal && 103_BinaryTreeZigzagLevelOrderTraversal 1Y  
**Main Algo:** DFS or BFS, for Zigzag Order, when the level is odd, insert the node to the begining other wise push_back the node.  

####104_MaximumDepthOfBinaryTree
**Main Algo:** Recursion   

107_BinaryTreeLevelOrderTraversalII 1Y  

108_ConvertSortedArrayToBinarySearchTree 1Y  

109_ConvertSortedListToBinarySearchTree 1Y  

110_BalancedBinaryTree 1Y  

111_MinimumDepthOfBinaryTree 2Y  
1WA a leaf node is a node whose left and right children are all nullptr  

112_PathSum 1Y  
Pay attention to leaf node.  

113_PathSumII 2Y  
If use vector to store the path, remember to erase the item whenever at the end of the function  

114_FlattenBinaryTreeToLinkedList 2Y  
1WA forgot to delete the left child of root  

115_DistinctSubsequence 1Y  
DP  

116_PopulatingNextRightPointerInEachNode 3Y  
1WA Didn't consider the left node or the only root  
2WA Didn't consider root has no next  

117_PopulatingNextRightPointerInEachNode Multi WA  
BFS use queue.  

118_PascalsTriangle 1Y  
Pay attention to returning a new vector, we do not have to add new because once we do that we will return a pointer  

119_PascalsTriangleII 2Y  
1WA At first I want to use the formula to calculate, but it would overload when I was calculating the factor.So i just sum up from the last row.  

120_Triangle 2Y  
When j is 0 or i, there is only one way.  

121_BestTimeToBuyAndSellStock 2y  
The lowest point coult be equal to one of its neightbor so the condition should be >= and<=  

122_BestTimeToBuyAndSellStockII 1Y  
if(i == 0 && prices[i + 1] > prices[i])  
    buyPoint = prices[i];                              

if(i > 0 && i < prices.size() - 1 && prices[i+1] > prices[i] && prices[i - 1] >= prices[i])  
    buyPoint = prices[i];  

if(i == prices.size() - 1 && prices[i] > prices[i - 1])  
    maxProfit += prices[i] - buyPoint;  

if(i > 0 && i < prices.size() - 1 && prices[i+1] <= prices[i] && prices[i - 1] < prices[i])  
    maxProfit += prices[i] - buyPoint;  

125_ValidPalindrome 2Y  
1TLE used recursive function  

129_SumRootToLeafNumbers 1Y  
If use a char to initialize a string, use string(int, char);  

105_ConstructBinaryTreeFromPreorderAndInorderTraversal 3Y  
1 MLE Since every time we passed two new vectors so the memory limits were exceeded  
2 WA If we use the head and end pointer, find function would be dificult because it return a iterator.  

106_ConstructBinaryTreeFromInorderAndPostorderTraversal 1Y  
Similar to the previous problem.  

136_SingleNumber 1Y  
Use unordeded_set  
A better way is to use XOR  

137_SingleNumberII 1Y  
Use unordered_map  
A better way is to count for every bit and mod 3  

##2016.9.22  
128_LongestConsecutiveSequence 1Y  
Use unordered_map to record if it has appeared.  

131_PalindromePartitioning 2Y  
Typo, should insert s.substr(0, i) at the end of partition(s.substr(i));  

139_WordBreak 3Y  
1 Naive dfs TLE  
2 Sorted the length of words in decent order and then dfs TLE  
3 DP  

140_WordBreakII 1Y  
The same DP as the previous one, pay attention that when you use for(auto i:vector) you cannot change the value of vectors buy changing i  

141_LinkedListCycle 1Y  
Slower and O(n) space by using unordered_set  
Faster and O(1) space by using two pointers in different speeds  

142_LinkedListCycle 1Y  
The same as the previous problem, for the faster method, when the speed 2 meed speed 1, make a new speed1 from head, they will meet at the begining of the cycle.  

143_ReorderList 1Y  
If not in_place use a vector to do it.  
If in_place, find the middle of the linkedlist and reverse the later half, and finally merge.  
ListNode* reverse(ListNode *head) {  
    if (head == nullptr || head->next == nullptr) return head;  

    ListNode *prev = head;  
    for (ListNode *curr = head->next, *next = curr->next; curr;  
        prev = curr, curr = next, next = next ? next->next : nullptr) {  
            curr->next = prev;  
    }  

    head->next = nullptr;  
    return prev;      
}  

144_BinaryTreePreorderTraversal 1Y  
Use stack to perform preorder traversal.  

145_BinaryTreePostorderTraversal 1Y  
Push the root, right, left in order, once the kids were pushed, the root could be poped the next time.  

151_ReverseWordsInAString 3Y  
1 WA when result is empty, used t = s.substr()  
2 WA at the end when last is zero, don't have to add anything.  

152_MaximumProductArray 3Y  
Greedy.  
1 WA the if else structure is not clear  
2 WA Since there will be negative product, need calculate twice for order and reversed.  

155_MinStack 2Y  
1 TLE  
2 Keep a min and refresh it to reduce time cost  

153_FindMinimumInRotatedSortedArray 1Y  
Binary search  

154_FindMinimumInRotatedSortedArray 2Y  
1WA The last could be the same as the first one.  

160_IntersectionOfTwoLinkedLists 1Y  
First time I used undered_set, O(n) time complexity and O(n) space \\  
Then I used two pointer to find the length difference, then start at the same length begin point. O(n) Time complexity and O(1) space

162_FindPeakElement 2Y

099_RecoverBinarySearchTree 2Y
1WA Forget to consider leaf node
There are three types  
1, two nodes are from left and right subtree  
2, both come from left subtree  
3, both come from right subtree  

165_CompareVersionNumbers 2Y
1WA Forgot 1.0 vs 1 this condition

167_TwoSumII
Using binary search.  

## 2016.9.26
168_ExcelSheetColumnTitle 1Y  

169_MajorityElement 1Y  
Used hash map  

171_ExcelSheetColumnNumber 1Y  

174_DungeonGame 1Y  
DP my favourite  

189_RotateArray 1Y  

190_ReverseBits 2Y  
1WA n >> 1 is not the same as n = n / 2  

191_NumberOf1Bits 1Y  

198_HouseRobber 1Y  
DP  

199_BinaryTreeRightSideView 2Y
1WA Forgot to consider that the left subtree might be higher than the right subtree  

200_NumberOfIslands 2Y  
1 Use a bool vector to record would TLE  

201_BitwiseANDOfNumbersRange Good One  

202_HappyNumber 1Y
Do not forget to insert into hash set  

203_RemoveLinkedListElements 2Y  
1 WA Forgot to consider remove all elements, it will be dead-loop  

205_IsomorphicStrings 1Y  

## 2016.9.27  
206_ReverseLinkedList 1Y  
Solved recursively

209_MinimunSizeSubarraySum 2Y  
1 WA Mistunderstood subarray, used minheap,
2Y Used two pointers.  

215_KthLargestElementInAnArray 1Y  
min_heap using priority queue  

216_CombinationSumII 2Y
DFS 1WA didn't request a good range  

179_LargestNumber Good one
Use sort function, rewrite the compare part  

217_ContainsDuplicate 1Y
Use unordered_set  

####218_TheSkylineProblem  
**Main Algo:** 
Use a max_heap to store the maximum height, we when meet the left wall, we insert and check if the max_height changed; for the right wall, we delete it and check if the max_height changed.  
**Corner Cases:**
The corner cases all about how to sort the points.

* For left wall with same x, we made higher y first;
* For right wall with same x, we made lower y first;
* For left and right walls with same x, we made left first.  

**Core Codes:** 

```c++
for(p : buildings){
    points.push_back(make_pair(p[0], -p[2])); 
    //We made the left wall's height to be negative, thus we could solve the sorting problem mentioned above.
    points.push_back(make_pair(p[1], p[2]));
}
sort(points.begin(), points.end());

multiset<int> max_heap = {0};
int top = 0;
for(p : points){
    if(p.second < 0){
        max_heap.insert(-p.second);
    } else {
        max_heap.erase(max_heap.find(p.second));
    }
    
    if(*max_heap.rbegin() != top){
        result.push_back(make_pair(p.first, top = *max_heap.rbegin()));
    }
}
``` 

219_ContainsDuplicateII 2Y  
1 WA instead of s.erase(s.begin()) it's better to erase the exact number  
Use a maximized size set

##2016.9.28  
221_MaximalSquare 2Y  
f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1;  

225_ImplementStackUsingQueues 1Y
Using a queue will be dumb  

226_InvertBinaryTree 1Y  

405_ConvertANumberToHex 1Y  

404_SumOfLeftLeaves 2Y  
Recursively solve the problem, could use stack?  

402_RemoveKDigits 1Y  
Find the first one that is larger than the one after it.  

401_BinaryWatch 2Y  
Forgot to consider when hour or second overloaded.  

401_BinaryWatch 2Y  
Forgot to consider when hour or second overloaded.  

401_BinaryWatch 2Y  
Forgot to consider when hour or second overloaded.  

401_BinaryWatch 2Y  
Forgot to consider when hour or second overloaded.  

400_NthDigit 2Y  
When calculating the pow, it might overload  

228_SummaryRanges 2Y  
Pay attention to the final element of the array, it has several oprations to do.  

230_KthSmallestElementInABST 2Y
It's worthwhile to write three traversals iteratively  

231_PowerOfTwo 1Y  
Using bit operation.  

232_ImplementQueueUsingStacks 1Y  
Used two stacks  

234_PalindromeLinkedList 1Y  
Used vector, took O(n) time and O(n) space.  

235_LowestCommonAncestorOfABinarySearchTree 1Y

236_LowestCommonAncestorOfABinarySearchTree 2Y  
At first I used the same method as the previous problem that to find where the two nodes are. It's almost TLE. Then I just recursive used the function, to check the return value of left and right subtree.  

237_DeleteNodeInALinkedList 2Y  
You can not let the current node to be nullptr, instead, let the next pointed to a nulltpr  

237_DeleteNodeInALinkedList 2Y  
You can not let the current node to be nullptr, instead, let the next pointed to a nulltpr  

238_ProductOfArrayExceptSelf  1Y  
Pay attention to the number of zeros  

239_SlidingWindowMaximum 3Y  
I used map(set cannot hold same items), a better way is to use deque(Monotonic Queue)  

241_DifferentWaysToAddParentheses 1Y *
DP  

242_ValidAnagram 1Y  
I used sort, but the fastest way is to count the frequencies of all letters, O(n).  

257_BinaryTreePaths 1Y  
Recursively find the paths.  

258_AddDigits 2Y  
Since f(n) % 9 = f(n - 1) % 9 + 1  

260_SingleNumberIII  
The most common way is to use unordered_set, but using bit operation costs only O(1) space.  

263_UglyNumber 1Y  

264_UglyNumberII 3Y  
The ugly number was generated from 2,3,5, and for each number, the nth smallest is number * ugly[n - 1]; Then we can choose from the three candidates.  

268_MissingNumber 2Y  
Solved it with O(1) space.  
A better way is to use bit operation  

273_IntegerToEnglishWords 3Y  
Pay attention to empty string, and spaces(we could remove them at the end).  

274_HIndex 1Y

275_HIndexII 2Y  
Use binary search to reduce the time complexity.  

278_FirstBadVersion 1Y  
Binary search  

279_PerfectSquare 1Y  
DP  

283_MoveZeroes 1Y  

289_GameOfLife 2Y  
Use one bit to store the new state.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

290_WordPattern 2Y  
Since it's bijection, check both side.  

292_NimGame 2Y  
At first I tried to use dp, but actually if you can let the other one face n*4 everytime you can always win.  
So if at first you are not n*4, you will win.  

295_FindMedianFromDataStream 1Y  
Use multiset  

299_BullsAndCows 1Y  
Remember to remove the two element no matter it's bull or cow  

300_LongestIncreasingSubsequence 1Y   
Simple DP, There will be O(nlongn) solution.  

303_RangeSumQuery-Immutable 1Y  
Use an array to store the sum.  

304_RangeSumQuery2D-Immutable 1Y  
The same as the previous problem.  

306_AdditiveNumber 3Y  
Enum all possible num[0] and num[1], pay attention to overload and zero condition.  

398_RandomPickIndex 2Y  
1 MLE  
2 Copied from the forum. O(n) pick time, but the same space as num.  

397_IntegerReplacement 2Y  
At first I tried to used DP, to reduce redundant computing, but a high cost of memory.  
Then I changed it to recursive function, and mind the overload of n.  

396_RotateFunction 2Y  
1 TLE It's easy to think of a O(n^2) solution but will TLE.
2 Actually everytime when we shift the array, the sum can be calculated directly.  

395_LongestSubstringWithAtLeastKRepeatingCharacter 3Y  
Recursively solve this problem, use a count array to reduce count the times of a character every time.  

394_DecodeString 1Y  
Recursively solve it.  

392_IsSubsequence 2Y  
1 MLE and TLE DP
2 Search every char of s in t.  

390_EliminationGame 2Y  
Record the start, end, interval and direction, used recursive functions  

389_FindTheDifference 1Y  
Sort the two strings and then compare.  

387_FirstUniqueCharacterInAString 1Y  
For every string, find if exists after it, if found continue.  

386_LexicographicalNumbers 3Y  
Used dfs and bfs, then I realized only 10 new can be generated.  

383_RansomNote 1Y
Count all numbers in note and magazines.  

382_LinkedListRandomNode 1Y  
Random number mod n  

307_RangeSumQuery-Mutable 3Y  
Used BIT  

287_FindTheDuplicateNumber 3Y  
If duplicates exist, there would be a circle.  

377_CombinationSumIV 2Y  
At first I used recursive function, then I change to dp  

376_WiggleSubsequence 3Y  
At first I used DP which past but with high time cost. Then I used greedy algorithm, that when incresing, we only consider the bigger, and it's the same in decresing conditions. We only need to know how many peak or valley it has.  

374_GuessNumberHigherOrLower 1Y  
Binary search.  

220_ContainsDuplicateIII 3Y  
Using multiset  

380 & 381 InsertDeleteGetRandomO(1)
Using set and multiset.  

318_MaximumProductOfWordLengths 2Y  
Use binary to encode.  

319_BulbSwitcher 2Y  
Two ways, find the pattern or prove that only with odd number of factors will be on finally.  

322_CoinChange 1Y  
BFS Slower  
DP Faster  

326_PowerOfThree 2Y  
If n is power of three then log10(n) / log10(3) is an integer.  

371_SumOfTwoIntegers 2Y  
Using bit operation.  

328_OddEvenLinkedList 2Y

367_ValidPerfectSquare 2Y  
Using binary search, mind overload.  

313_SuperUglyNumber 2Y  
For each prime, the ith smalllest it can generate is f[i - 1] * itself.  

409_LongestPalindrome 2Y  
The longest consisit of even * evenN + (odd - 1) * oddN + 1(middle)  

373_FindKPairsWithSmallestSums 2Y  
Similar to SuperUglyNumber  

342_PowerOfFour 1Y  
Continue using log10(num) / log10(a)  

037_SudokuSolver 2Y  
Fixed a bug, that I didn't set board[i][j] to be '.'  

344_ReverseString 1Y  

345_ReverseVowelsOfAString 1Y  

349_IntersectionOfTwoArrays 1Y  

350_IntersectionOfTwoArraysII 1Y  

204_CountPrimes 2Y  
Use small prime to delete non-prime, need high space  

156_BinaryTreeUpsideDown 1Y  
Return the root of the left subtree, and then find until right end and then insert root.  

130_SurroundedRegions  2Y  
DFS, find all illegal regions rather than legal  

134_GasStation 2Y  
Find the beginnings of non-negative serires, and check if it can cover the whole circle.  

338_CountingBits 1Y  
f[n] = f[n - lower_bound(2^n)] + 1  

347_TopKFrequentElements 2Y  
Used unordered_map to count and priority queue to store and ranking.  

343_IntegerBreak 1Y  
DP, f[n] = max(max(k, f[k]) * max(n - k, f[n - k]), f[n]) (for k = 1 to n - 1)  

147_InsertionSortList 1Y  

148_SortList 2Y  
Mergesort, an optimization is to count the number of nodes at first.  

149_MaxPointsOnALine 3Y  
My solution enumerates all pairs and check others which is a O(n^3). A better way is to enumerate all points and check all others with different slopes. Then add the same points as the original one.  

150_EvaluateReversePolishNotation 1Y  
Use a stack to store the number, when then token is a opt, implement the calculation.  

157_ReadNCharactersGivenRead4 2Y   

159_LongestSubstringWithAtMostTwoDistinctCharacters 2Y  
Keep two pointers, when legal, tail++, otherwise head ++.  

173_BinarySearchTreeIterator 2Y  
When initializing, push all the left node into stack, before poping, push the right sun and all its left nodes.  

161_OneEditDistance 2Y  
If there is a difference in the string, and used four ways to change , still different, return false, if no difference in the string, the length has 1 difference, return true, else return false.  

163_MissingRanges 3Y  
Should consider empty condition and need to consider overload conditions.  

124_BinaryTreeMaximumPathSum 3Y  
Recursively solve it, whether include root or do not include root.  

170_TwoSumII-DataStructureDesign 2Y  
Used an unordered_map to implement it  

186_ReverseWordsInAStringII 1Y  
An in place way is to reverse the whole string and then reverse individual words.  

293_FlipGame 1Y  

243_ShortestWordDistance 2Y  
The fastest way is to record last pos of word1 and word2, when looping calculate the minDist.  

243_ShortestWordDistance 2Y  
The fastest way is to record last pos of word1 and word2, when looping calculate the minDist. O(n)  

244_ShortestWordDistanceII 1Y  
Used a map to store each indexes, an optimization is to use two pointers to find the min distance.  

245_ShortestWordDistanceIII 2Y  
Similart to 243  

246_StrobogrammaticNumber 1Y  

247_StrobogrammaticNumber 1Y  
Take care that the first number could not be 0.  

249_GroupShiftedStrings 2Y  
Be more careful.  

250_CountUnivalSubtrees 1Y  
Return if it is a unival substree, and if the root is , total++  

251_Flatten2DVector 1Y  
Two pointers to record row and column, pay attention to empty rows.  

252_MeetingRooms 1Y  
Sort with start time, compare the neighbors whether there is any overlap.  

253_MeetingRoomsII 1Y  
The same as the previous one, sort with the start time, when multiple rooms available, choose the one with closest time.  

254_FactorCombinations 1Y  
In order to reduce duplicates, we add an arg to record the last nubmer we used and starts from it.  

256_PaintHouse 1Y  
Simple DP  

265_PaintHouseII 1Y  
DP, but only record the two minimun costs.  

270_ClosestBinarySearchTreeValue 1Y  
Return the value of left or right (decided by the root val), and compare with root;  

266_PalindromePermutation 1Y  
Permutation means a reorder of existing words.  

271_EncodeAndDecodeStrings 2Y  
I added "sq39" to separate the strings, payattention that there could be a empty string.  

276_PaintFence 1Y  
DP, f[0] = k, f[1] = k * k, f[n] = (k - 1) * (f[n - 1] + f[n - 2]);  

277_FindTheCelebrity 2Y  
Find the people who know nobody, and check if everyone else know him.  

280_WiggleSort 1Y  
Sort, then insert the end to the front.  

285_InOrderSuccessorInBST 2Y  
If the val is smaller than BST, and with no right nodes in left substree, the successor will be the root.  

286_WallsAndGates 1Y  
dfs, take care that control no loop  

415_AddStrings 1Y  
High accuracy add operation.  

416_PartitionEqualSubsetSum 1Y  
Calculate the sum first, and then used a unordered_set to record then possible sums of subsets.  

288_UniqueWordAbbreviation 2Y  
Use a unordered_set to store the words that has the same abbreviation. Unique means no existing abbr || only one has the abbr and it's the same as this word.  

296_BestMeetingPoint 2Y  
Naive search O(m * n) will TLE.  
For Manhattan Distance, the row and column could be considered separately.  

298_BinaryTreeLongestConsecutiveSequence 1Y  
Design a new function return the consecutive length until this root, and refresh a global maxLength.  

311_SparseMatrixMultiplication 2Y  
Use map to store each row and each column that has non-zero element.  

320_GeneralizedAbbreviation 1Y  
Recursive function.  

323_NumberOfConnectedComponentsInAnUndirectedGraph 2Y  
Union find.  

346_MovingAverageFromDataStream 1Y  

348_DesignTic-Tac-Toe 1Y  
Use map to store the count of row, col, diag.  

408_ValidWordAbbreviation 2Y  

325_MaximumSizeSubarraySumEqualsK 1Y  
Use a unordered_map to store the earliest index that has the sum.  

366_FindLeavesOfBinaryTree 1Y  

369_PlusOneLinkedList 1Y  

356_LineReflection 3Y  
Remove duplicates first, sort by x, start from the median. Pay attention that the y could be different for the same x.  

360_SortTransformedArray 2Y  
Pay attention to a == 0, b == 0 conditions.  

361_BombEnemy 3Y  
Naive search O(mnmax(m, n)) would TLE, keep four arrays count the number of enemies that can be kill at that point, O(mn).  

207_CourseSchedule 2Y  
Toplogic sort, decide whether there is a loop or not by the final number of courses that was selected.  

210_CourseScheduleII 1Y  
Similar to the previous problem.  

269_AlienDictionary 3Y Good one.  
Top logic sort, but pay attention to duplicate orders. and pay attention to the final output.  

208_ImplementTrie 2Y  

211_AddAndSearchWord 1Y  
Used trie tree.  

339_NestedListWeightSum 1Y  

360_NestedListWeightSumII 2Y  
Use a pair th record depth and number, and then find the maximum depth to calculate the sum.  

362_DesignHitCounter 2Y  
Used a queue but pay attention to empty condition.  

281_Zigzag Iterator 2Y  
Used a queue, can handle multiple vectors.  

359_LoggerRateLimiter 1Y  
Since we have to check all the valid pre-logs, so we used a vector rather than queue.  

233_RectangleArea 1Y  
Mind the overload and overlap.  

406_QueueReconstructionByHeight 1Y  
I used toplogic sort, a better way is to sort by height first and sort by number of higher ones second. Insert them after the number of higher ones.  

164_MaximumGap 3Y  
Using bucket sort. PigeonHole Theory.  

213_HouseRobberII 3Y  
DP, same as HouseRobber, pay attention that (i - 1) % n could be negative.  

399_EvaluateDivision 1Y  
BFS to find all paths.  

334_IncreasingTripletSubsequence 1Y  
Use two interger to record the first two increasing, and substitute them if a new one is smalller than any of it.  

132_PalindromePartitioningII 3Y  
O(n^2) DP  

417_PacificAtlanticWaterFlow 2Y  
Floodfill, pay attention that if not using reference might MLE.  

187_RepeaatedDNASequences 2Y  
Using unordered_map to count the time.  

337_HouseRobberIII 2Y  
DP in tree, use unordered_set to record the result we have calculated.  

297_SerializeAndDeserializeBinaryTree 3Y  
Used pre-order traversal.  

259_3SumSmaller 2Y  
Use 3 pointers.  

412_FizzBuzz 1Y  

422_ValidWordSquare 2Y  
Take care that if might not be symmetric.  

135_Candy 3Y  
At first I used toplogic sort buy actually it can be solved by simplely scan the array twice in two direction.
if(ratings[i] > ratings[i-1])
    candy[i] = max(candy[i], candy[i - 1] + 1);
if(ratings[i] > ratings[i + 1]) the same.  

391_PerfectRectangle 3Y  
The perfectRectangle Should obey two rules. 1. Area sum is equal to max rectangle. 2. except the four outer points. other points must appear twice.  

310_MinimumHeightTrees 3Y  
The problem could be solved in two ways. 1. find the longest path 2. delete all leaf nodes until there are only one or two.  

365_WaterAndJugProblem 2Y  
We could get 0 to x + y, gcd(x, y) to be the step.  

370_RangeAddition 3Y  
num[i[0]] += i[2]  
num[i[1] + 1] -= i[2]  

then num[i] += num[i - 1]  

358_RearrangeStringKDistanceApart 1Y  
Greedy, choose the char with most remaining.  

291_WordPatternII 3Y  
DFS, pruning by sum(count[char] * len of pattern char) <= str.length()

351_AndroidUnlockPatterns 3Y  
DFS, since the keyboard is symetric, we only need 1,2,5 to be calculated.  

419_BattleshipsInABoard 2Y  
DFS, floodfill, check if it is legal at the end.  

393_UTF8-Validation 2Y  
Pay attention to the length of 1's in header is 1(Invalid).  

403_FrogJump 3Y  
DP, record all last steps that can reach stone[i].  

227_BasicCalculatorII 2Y  
Used istringstream and stack.  

414_ThirdMaximumNumber 1Y  
Used priority_queue to implement. It can also be solved by using a set.  

368_LargestDivisibleSubset 3Y  
DP, record the path.  

384_ShuffleAnArray  
Using Fisher_Yates shuffle.  

439_TernaryExpressionParser  1Y  

379_DesignPhoneDirectory 3Y  
Used a int vector and a bool vector.
When releasing, numbers[--cur] = number;  

438_FindAllAnagramsInAString  2Y  
Use the most naive to compare would exceed the time. When changing the index, only 1 char would change.  

388_LongestAbsoluteFilePath 2Y  
Used the istringstream and getline function to split \n.  

133_CloneGraph 3Y  
Using a map to store those cloned nodes.  

138_CopyListWithRandomPointer 1Y  
Similar to clone graph.  

421_MaximumXOROfTwoNumbersInAnArray 1Y  
Using trie tree. Pay attention, (1 << i) & n > 0 means get the ith binary number.

308_RangeSumQuery2D-Mutable 2Y  
2D Bit.  

340_LongestSubstringWithAtMostKDistinctCharacters 1Y  
Used two pointers.  

353_DesignSnakeGame 2Y  

331_VerifyPreorderSerializationOfABinaryTree 1Y  

354_RussianDollEnvelopes 3Y  
Similar to LIS. Using lower_bound(logN).  

302_SmallestRectangleEnclosingBlackPixels 3Y  
Using binary search.  

423_ReconstructOriginalDigitsFromEnglish 2Y  
I used dfs (with pruing), but the best way is to count some important letters.  
class Solution {
    public:
    string originalDigits(string s) {
        vector<int> a(10, 0);
        vector<int> alpha(128, 0);
        for (char c : s)
            alpha[c]++;
        a[0] = alpha['z'];
        a[2] = alpha['w'];
        a[4] = alpha['u'];
        a[6] = alpha['x'];
        a[8] = alpha['g'];
        a[3] = alpha['h'] - a[8];
        a[5] = alpha['f'] - a[4];
        a[7] = alpha['v'] - a[5];
        a[1] = alpha['o'] - a[0] - a[2] - a[4];
        a[9] = alpha['i'] - a[5] - a[6] - a[8];

        string ans;
        for (int i = 0; i < 10; i++) {
            if (a[i] > 0)
                ans += string(a[i], '0' + i);
        }
        return ans;    
    }
};

222_CountCompleteTreeNodes 1Y  
By calculating the depth of right subtree and the whole tree, we could find if the left tree is complete.  
Thus,
if(height(root->right) == h - 1)
    return (1 << (h - 1)) + countNodes(root->right);
else
    return (1 << (h - 2)) + countNodes(root->left);  

330_PatchingArray 2Y  
It's important to see that when [1, n] is can be got, if there is an i <= n + 1, [1, n + i] is achievable.  

440_KthSmallestInLexicographicalOrder 3Y  
Good problem.  

301_RemoveInvalidParentheses 1Y  
BFS, use unordered_set to remove dup.  

240_SearchA2DMatrixII 2Y  
At first I used binary search. Another O(m + n) way is search the right-up most element, if smaller, target could not be at that col, if larger. target could not be at that row.

435_Non-OverlappingIntervals 2Y  
Sort the intervals with start first. When a new intervals have no overlap with the last one, add it . else, refresh the end point by comparing the current end with the new one.  

317_ShortestDistanceFromAllBuildings 3Y  
BFS from all buildings, find the place with minimum sum of distances.  

044_WildcardMatching 2Y  
DP with round array.  

436_FindRightInterval 2Y  
Using upper bound.  

struct compare{
    int compValue(const Interval& a){
        return a.start;
    }
    int compValue(const int a){
        return a;
    }

    template<typename T1, typename T2>
    bool operator()(T1 const t1, T2 const t2){
        return compValue(t1) <= compValue(t2);
    }
}comp;

357_CountNumberWithUniqueDigits 2Y  
Simply sum 9 * 9 * 8 * ... * (9 - i + 2) and add 1 for the zero.

312_BurstBalloons 3Y  
DP, find the maximum in the interval of [start, end], enum the last one to blow, f[start][end] = max(f[start][k - 1]+ f[k + 1][end] + nums[k] * nums[start - 1]*nums[end + 1]);  

255_VerifyPreorderSequenceInBinarySearchTree 1Y  
Using a stack to do the same operation as preorder traversal, the false condition happen when the right subtree has a number that is bigger than the root. So we have to record the root.  

332_ReconstructItinerary 3Y  
DFS. When using multiset, pay attention to erase() which erase all items with the key. And we need to record all cities out to do the for loop.  

261_GraphValidTree 2Y  
Actually is to find if there is a curcuit in the graph. Using Union-Find, BFS, DFS, which fasest to slowest.  

352_DataStreamAsDisjointIntervals 2Y  
Using lower_bound.  

126_WordLadderII 3Y  
BFS, delete the word after every layer.  

127_WordLadder 1Y  
Erase a word once we push it into the queue.  

341_FlattenNestedListIterator 3Y  
Using deque. Stack.(*)

437_PathSumIII 1Y  
DP on a tree. Record all possible sums with this root.  

305_NumberOfIslandsII 2Y  
Using union-find. But pay attention that find all differnt sets at first and then union them.  

447_NumberOfBoomerangs 2Y  
Search all possible head point, with different dists, for each dists, add dist * (dist - 1)  

441_ArrangingCoins 1Y  
Mathemetical problem. Solve a inequality.  

####314_BinaryTreeVerticalOrderTraversal 1Y  
**Main Algo:** BFS, the left and right's pos is only one distance with the root  
**Corner Case:** root == nullptr  
**Core Code:**  

```c++  
while(!q.empty()){  
    TreeNode *curNode = q.front().first;  
    int curPos = q.front().second;  
    
    q.pop();
    vertical[curPos].push_back(curNode->val);
    
    if(curNode->left != nullptr)
        q.push(make_pair(curNode->left, curPos - 1));
    if(curNode->right != nullptr)
        q.push(make_pair(curNode->right, curPos + 1));
}
```