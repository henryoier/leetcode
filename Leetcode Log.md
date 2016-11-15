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

####004_MedianOfTwoSortedArrays
**Main Algo:** Check the k/2 th element in both array(remaining). If nums1[k/2] < nums2[k/2], the first k/2 element must be in the first half part.  
**Core Codes:**

```c++
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int total = m + n;
    
    if(total % 2 == 1)
        return findMedian(nums1, 0, nums2, 0, total / 2 + 1);
    else
        return (findMedian(nums1, 0, nums2, 0, total/2) + findMedian(nums1, 0, nums2, 0, total/2+1)) / 2.0;
}

int findMedian(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k){
    if(start1 >= nums1.size())
        return nums2[start2 + k - 1];
    if(start2 >= nums2.size())
        return nums1[start1 + k - 1];
    if(k == 1)
        return min(nums1[start1], nums2[start2]);
        
    int mid1 = start1 + k/2 <= nums1.size()?nums1[start1 + k/2 - 1]:INT_MAX; // If one of the array's size is less than k/2
    int mid2 = start2 + k/2 <= nums2.size()?nums2[start2 + k/2 - 1]:INT_MAX;
    
    if(mid1 < mid2)
        return findMedian(nums1, start1 + k/2, nums2, start2, k - k/2);
    else
        return findMedian(nums1, start1, nums2, start2 + k/2, k - k/2);
}
```

####005_LongestPalindromicSubstring
**Main Algo:** 

* Enum all mids(odd and even are differnt), find the length, or DP, O(n^2).  
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

```c++
int myAtoi(string str) {
    // sign is to record +/- if any in str; num is the number value; pos is the progress position in str
    long sign = 1, num = 0, pos = 0;
    
    // skip initial spaces
    while (pos < str.length() && str[pos] == ' ') pos++;                        
    
    // extract sign if any
    if (pos < str.length() && (str[pos] == '+' || str[pos] == '-'))
        sign = str[pos++] == '-' ? -1 : 1;    
    
    // extract number if any, stop if num exceeds INT_MAX boundary
    while (pos < str.length() && isdigit(str[pos]) && num <= INT_MAX)
        num = num * 10 + (str[pos++] - '0');
    
    // make sure answer does not exceed int boundary
    return sign == 1 ? min(num, (long)INT_MAX) : max(-num, (long)INT_MIN);
}
```

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

```c++
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

####019_RemoveNthNodeFromEndOfList
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
####076_MinimumWindowSubstring
**Main Algo:** Sliding window with two pointers, once we expand the tail and find it cover the t string, we shrink the head.  
**Core Codes:**

```c++
string minWindow(string s, string t) {
    int minLength = INT_MAX, start = 0, min_start;
    int cur = 0;
    unordered_map<char, int> t_count;
    for(auto i:t) t_count[i]++;
    
    for(int i = 0; i < s.length(); i++){
        if(t_count[s[i]]-- > 0) cur++;
        
        while(cur == t.size()){
            if(i - start + 1 < minLength){
                minLength = i - start + 1;
                min_start = start;
            } 
            if(t_count[s[start++]]++ == 0) cur--;
        }
    }
    
    return minLength == INT_MAX?"":s.substr(min_start, minLength);
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

####079\_WordSearch && 212_WordSearchII
**Main Algo:** For WordSearchII, we build a trie tree using the words for search. DFS the board and push_back the index once we find one.  
**Corner Cases:** Since we can not go out of the board, so we check the next nodes's idx. For example board is [[a]], word is a.  
**Core Codes:**

```c++
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++)
            constructTrieTree(root, words[i], i);
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                dfs(i, j, root, board);
                
        vector<string> result;
        for(auto i:result_idx)
            result.push_back(words[i]);
            
        return result;
    }
private:
    struct TrieNode{
        TrieNode* next[26];
        int idx = -1;
        TrieNode(){
            fill(next, next + 26, nullptr);
        }
    };
    vector<int> result_idx;
    
    void dfs(int i, int j, TrieNode* root, vector<vector<char>>& board){
        if(board[i][j] == 0 || root->next[board[i][j] - 'a'] == nullptr)
            return;
            
        char cur = board[i][j];
        TrieNode *p = root->next[cur - 'a'];
        // we check if we can find a word by the end of this node.
        if(p->idx != -1){
            result_idx.push_back(p->idx);
            p->idx = -1;
        }
        
        board[i][j] = 0;
        if(i > 0) 
            dfs(i - 1, j, root->next[cur - 'a'], board);
        if(i < board.size() - 1) 
            dfs(i + 1, j, root->next[cur - 'a'], board);
        if(j > 0) 
            dfs(i, j - 1, root->next[cur - 'a'], board);
        if(j < board[0].size() - 1) 
            dfs(i, j + 1, root->next[cur - 'a'], board);
        board[i][j] = cur;
    }
    
    void constructTrieTree(TrieNode* root, string s, int i_idx){
        for(auto c:s){
            if(root->next[c - 'a'] == nullptr){
                root->next[c - 'a'] = new TrieNode();
                root = root->next[c - 'a'];
            } else root = root->next[c - 'a'];
        }
        root->idx = i_idx;
    }
};
```

####080_RemoveDuplicatesfromSortedArrayII
**Core Codes:**

```c++
int i = 0;
for (int n : nums)
    if (i < 2 || n > nums[i-2])
        nums[i++] = n;
return i;
```

####082\_RemoveDuplicatesfromSortedListII && 083_RemoveDuplicatesfromSortedListI
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

####084_LargestRectangleInHistogram
**Main Algo:** Keep an asendant stack, we push the current idx if the height is larger then the top one, and we pop one by one once the current index's height is smaller than the top. Each pop we could calculate the area of the top element by **height * (currentIdx - nextTop(if not then it's 0))** And at then end we push a height 0 to the end of the heights.  
**Core Codes:**

```c++
stack<int> s;
heights.push_back(0);

int maxArea = 0;
for(int i = 0; i < heights.size(); i++){
    if(s.empty() || heights[i] > heights[s.top()])
        s.push(i);
    else{
        while(!s.empty() && heights[s.top()] > heights[i]){
            int curIdx = s.top();
            s.pop();
            int curArea = heights[curIdx] * (s.empty()?i:(i - s.top() - 1));
            if(curArea > maxArea)
                maxArea = curArea;
        }
        s.push(i);
    }
}
```

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

####087_ScrambleString
**Main Algo:** We just enum all possible breaks(roots) and check if rotate(or not) can form the two string to be the same.  For recursion algorithm. In order to reduce redundant calculation, we use an unordered_map to store the results that we have calculated.  
**Core Codes:**

```c++
//DP version, faster
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        f[1][i][j] = (s1[i] == s2[j]);

for(int len = 2; len <= n; len++)
    for(int i = 0; i + len <= n; i++)
        for(int j = 0; j + len <= n; j++)
            for(int breakLen = 1; breakLen < len; breakLen++)
                if((f[breakLen][i][j] && f[len - breakLen][i + breakLen][j + breakLen]) || 
                    (f[breakLen][i][j + len - breakLen] && f[len - breakLen][i + breakLen][j])){
                        f[len][i][j] = true;
                        break;
                    }
                            
// Recursion with memory, slow.
unordered_map<string, bool> hash;
    
bool scramble(string& s1, int b1, int e1, string& s2, int b2, int e2){
    if(hash.count(to_string(b1) + '+' + to_string(e1) + '+' + to_string(b2) + '+' + to_string(e2)))
        return hash[to_string(b1) + '+' + to_string(e1) + '+' + to_string(b2) + '+' + to_string(e2)];
        
    if(s1.substr(b1, 1) == s2.substr(b2, 1))
        return true;

            
    for(int len = 1; b1 + len < e1; len++){
        if((scramble(s1, b1, b1 + len, s2, b2, b2 + len) && scramble(s1, b1 + len, e1, s2, b2 + len, e2)) ||
            (scramble(s1, b1, b1 + len, s2, e2 - len, e2) && scramble(s1, b1 + len, e1, s2, b2, e2 - len))){
                hash[to_string(b1) + '+' + to_string(e1) + '+' + to_string(b2) + '+' + to_string(e2)] = true;
                return true;
            }
    }
    hash[to_string(b1) + '+' + to_string(e1) + '+' + to_string(b2) + '+' + to_string(e2)] = false;
    return false;
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

####102\_BinaryTreeLevelOrderTraversal && 103_BinaryTreeZigzagLevelOrderTraversal && 107_BinaryTreeLevelOrderTraversalII
**Main Algo:** DFS or BFS, for Zigzag Order, when the level is odd, insert the node to the begining other wise push_back the node.  

####104_MaximumDepthOfBinaryTree
**Main Algo:** Recursion   

####105\_ConstructBinaryTreeFromPreorderAndInorderTraversal && 106_ConstructBinaryTreeFromInorderAndPostorderTraversal
**Core Codes:** 

```c++
// Iterator version for in&post order rebuild.
typedef vector<int>::iterator P;
    
TreeNode* build(P ibegin, P iend, P pbegin, P pend){
    if(ibegin == iend || pbegin == pend)
        return nullptr;
        
    auto cur = *prev(pend);
    TreeNode* root = new TreeNode(cur);
    auto mid = find(ibegin, iend, cur);
    auto dist = distance(ibegin, mid);
    root->left = build(ibegin, mid, pbegin, pbegin + dist);
    root->right = build(next(mid), iend, pbegin + dist, prev(pend));
    
    return root;
}
```

####108\_ConvertSortedArrayToBinarySearchTree && 109_ConvertSortedListToBinarySearchTree 1Y  
**Main Algo:** In order to keep the tree balance, we choose the middle element to be the root and construct left and right subtree recursively.  
**Core Codes:** 

```c++
TreeNode* sortedListToBST(ListNode* head) {
    if(head == nullptr)
        return nullptr;
    if(head->next == nullptr)
        return new TreeNode(head->val);
    
    int count = 0;
    ListNode *p = head;
    while(p != nullptr){
        count++;
        p = p->next;
    }
    
    count = count / 2;
    ListNode *pre, *now = head;
    for(int i = 0; i < count; i++){
        pre = now;
        now = now->next;
    }
    TreeNode *root = new TreeNode(now->val);
    pre->next = nullptr;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(now->next);
    
    return root;
}
```

####110\_BalancedBinaryTree && 111_MinimumDepthOfBinaryTree  
**Corner Cases:** If a node has only one child, the depth should depth(child) + 1.    
**Main Codes:**

```c++
if(root == nullptr)
    return 0;
if(root->left == nullptr && root->right == nullptr)
    return 1;
if(root->left == nullptr)
    return minDepth(root->right) + 1;
if(root->right == nullptr)
    return minDepth(root->left) + 1;
return min(minDepth(root->left), minDepth(root->right)) + 1;
```  

####112\_PathSum && 113_PathSumII
**Main Algo:** Recursion or DFS search. There could be identical paths since there could be nodes with the same vals.  
**Corner Cases:** Do not use (sum == 0 && root == nullptr) to judge. Since we can not guarantee it is generated by a leaf node and will make the same path be recorded twice.  
**Core Codes:**
   
```c++
vector<vector<int>> pathSum(TreeNode* root, int sum) {
vector<vector<int>> result;
if(root == nullptr)
    return result;
if(root->left == nullptr && root->right == nullptr && root->val == sum)
    return vector<vector<int>>(1, vector<int>(1, root->val));

vector<vector<int>> temp = pathSum(root->left, sum - root->val);
result.insert(result.end(), temp.begin(), temp.end());

temp = pathSum(root->right, sum - root->val);
result.insert(result.end(), temp.begin(), temp.end());

for(auto& k:result)
    k.insert(k.begin(), root->val);

return result;
}
```
####114_FlattenBinaryTreeToLinkedList
**Main Algo:** We insert the left subtree between root and right subtree, and left left node to be null, and then flatten right subtree(which has been changed since we insert left subtree here). This takes only O(1) space.  
**Core Codes:**

```c++
TreeNode *left = root->left;
root->left = nullptr;

if(left != nullptr){
    TreeNode *cur = left;
    while(cur->right != nullptr)
        cur = cur->right;
    cur->right = root->right;
    root->right = left;
}
flatten(root->right);
```  

####115_DistinctSubsequence
**Main Algo:** DP. if s[i - 1] equals t[j - 1]. Then we have two choices here, pair or not. So f[i][j] = f[i - 1][j - 1] + f[i - 1][j]; Otherwise f[i][j] can only be f[i - 1][j];  
**Core Codes:**

```c++
vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        
for(int i = 0; i <= m; i++)
    f[i][0] = 1;
    
for(int j = 1; j <= n; j++){
    for(int i = j; i <= m; i++){
        if(s[i - 1] == t[j - 1])
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        else
            f[i][j] = f[i - 1][j];
    }
}
return f[m][n];
```

####116\_PopulatingNextRightPointerInEachNode && 117_PopulatingNextRightPointerInEachNode Multi
**Main Algo:** For population problem 1, the tree is perfect, so we can just use the simple recursion to do that. In problem II, since there will be gaps, it's much easier to use BFS.  
**Core Codes:** 

```c++
// recursive solution for populatingI 
if (!r) return;
if (r->left) r->left->next = r->right;
if (r->right) r->right->next = (r->next)? r->next->left : NULL;
connect(r->left);
connect(r->right);

//BFS solution.
``` 

####118\_PascalsTriangle && 119_PascalsTriangleII
**Main Algo:** 

* Calculate row by row. 
* Math formula. Control overflow.

**Core Codes:**

```c++
// Row by row.
vector<int> last = getRow(rowIndex - 1);
for(int i = 0; i <= last.size(); i++)
    if(i == 0 || i == last.size())
        result.push_back(1);
    else
        result.push_back(last[i] + last[i - 1]);
        
// Math solution
vector<int> v(rowIndex+1);
uint m = rowIndex / 2;
v[0] = 1;
for (uint i = 1, k = rowIndex; i <= m; i++, k--) {
    v[i] = (unsigned long long)v[i-1] * k / i;
}
for (uint i = m+1, j = (rowIndex-1)/2; i <= rowIndex; i++, j--) {
    v[i] = v[j];
}
return v;
```

####120_Triangle
**Main Algo:** DP  
**Corner Cases:** n = 0    
**Core Codes:**

```c++
if(n == 0)
    return 0;

for(int i = 1; i < n; i++)
    for(int j = 0; j <= i; j++)
        if(j > 0 && j < i)
            triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
        else if(j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else
                triangle[i][j] += triangle[i - 1][j - 1];

return *min_element(triangle[n-1].begin(), triangle[n-1].end());
```


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

####124_BinaryTreeMaximumPathSum
**Main Algo:** DFS return the maximum path to the node, all we have to compare is the two maximum paths plus root or the result in the two subtrees.  
**Core Codes:**
```c++
public:
	int maxPathSum(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
            
        int a = dfs(root);
        
        return result;
    }
    
private:
	 int result = -INT_MIN;
    
    int dfs(TreeNode *root){
        if(root == nullptr) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(root->val + left + right > result)
            result = root->val + left + right;
            
        return max(max(left, right) + root->val, 0); 
    }
```

####125_ValidPalindrome
**Main Algo:** Compare head and tail, ignore cases and non-letters.  

####128_LongestConsecutiveSequence
**Main Algo:** Use an unordered_map to store the numbers and find all clusters. **Take care of overflows.**
**Core Codes:**

```c++
unordered_map<int, bool> hash;
for(auto i:nums) hash[i] = false;

int maxLength = 0;
for(auto i:nums){
    if(hash[i])
        continue;
    else {
        int count = 1;
        for(long j = i + 1; j <= INT_MAX && hash.count(j) && !hash[j]; j++){
            count++;
            hash[j] = true;
        }
        
        for(long j = i - 1; j >= INT_MIN && hash.count(j) && !hash[j]; j--){
            count++;
            hash[j] = true;
        }
        maxLength = max(maxLength, count);
    }
}
```

####129_SumRootToLeafNumbers
**Main Algo:** Simple recursion.   

####130_SurroundedRegions  
**Main Algo:** DFS, from all O's at the boundary, and find all adjacent O's change them into a new state. Finally we change all O's to X because they can not be reached(surrounded by Xs) and change the middle-state to Os.  
**Core Codes:**

```c++
void dfs(int i, int j, vector<vector<char>>& board){
    int direc[5] = {0, 1, 0, -1, 0};
    

    board[i][j] = '#';
    for(int d = 0; d < 4; d++){
        int i1 = i + direc[d], j1 = j + direc[d + 1];   
        if(i1 > 0 && i1 < board.size() - 1 && j1 > 0 && j1 < board[0].size() - 1 && board[i1][j1] == 'O')
            dfs(i1, j1, board);
    }
}
```

####131\_PalindromePartitionI && 132_PalindromePartitioningII 
**Core Codes:**

```c++
// PalindromePartitionI
for(int i = 1; i < s.length();i++){
    if(isPalindrome(s.substr(0, i))){
        vector<vector<string>> right = partition(s.substr(i));
            
        for(int j = 0; j < right.size(); j++) {
            right[j].insert(right[j].begin(), s.substr(0, i));
        }
        result.insert(result.end(), right.begin(), right.end());
    }
}

if(isPalindrome(s))
    result.push_back(vector<string>(1, s));

// PalindromePartitionII
vector<int> minCut(n, INT_MAX);
vector<vector<bool>> palin(n, vector<bool>(n, false));

minCut[0] = 0;
for(int end = 1; end < n; end++)
    for(int start = end; start >= 0; start--){
        if(s[start] == s[end] && (end - start < 2 || palin[start + 1][end - 1])){
            palin[start][end] = true;
            if(start == 0)
                minCut[end] = 0;
            else
                minCut[end] = min(minCut[end], minCut[start - 1] + 1); 
        }
    }
```
####133_CloneGraph
**Main Algo:** To reduce redundant clone, we use a unordered_map to store whether this label's node has been cloned or not.  
**Core Codes:**

```c++
UndirectedGraphNode *graphNode(UndirectedGraphNode *node, 
	unordered_map<int, UndirectedGraphNode*> &searched){
    if(searched.count(node->label))
        return searched[node->label];
        
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    for(int i = 0; i < node->neighbors.size(); i++)
        newNode->neighbors.push_back(node->neighbors[i]);
    
    searched[newNode->label] = newNode;
    
    for(int i = 0; i < newNode->neighbors.size(); i++)
        newNode->neighbors[i] = graphNode(newNode->neighbors[i], searched);
    
    return newNode;
}
```

####134_GasStation
**Main Algo:** The start station could be the position where remain[i] > 0 and remain[i - 1] < 0. Then we check all possible start stations to see if we could reach a circle.  
**Core Codes:**

```c++
vector<int> remain;
vector<int> start;
for(int i = 0; i < gas.size(); i++){
    remain.push_back(gas[i] - cost[i]);
    if(i != 0 && remain[i] >= 0 && remain[i - 1] < 0) //Only the start of positive remaining are added.
        start.push_back(i);
}
if(*remain.begin() >= 0 && *prev(remain.end()) < 0)
    start.push_back(0);
    
if(remain.size() == 1)
    if(remain[0] < 0)
        return -1;
    else
        return 0;
    
for(auto s:start){
    int i = s;
    int total = 0;
    while(true){
        total += remain[i];
        if(total < 0)
            break;
        else{
            i = (i + 1) % remain.size();
            if(i == s)
                return s;
        }
    }
}
return -1;
```

####135_Candy
**Main Algo:** Initially we assign all element to be the mininum 1, and we find from left to right and right to left to ensure that every point suffer the relation.  
**Core Codes:**

```c++
vector<int> candy(ratings.size(), 1); 
        
for(int i = 1; i < ratings.size(); i++)
    if(ratings[i] > ratings[i - 1])
        candy[i] = max(candy[i], candy[i - 1] + 1);
        
for(int i = ratings.size() - 2; i >= 0; i--)
    if(ratings[i] > ratings[i + 1])
        candy[i] = max(candy[i], candy[i + 1] + 1);

return accumulate(candy.begin(), candy.end(), 0);
```

####136\_SingleNumber && 137_SingleNumberII
**Main Algo** For problem I, xor even times will get 0. So we can just xor all elements. The result is the single number. For problem II, we count the digits of 1's in every bit, and we can get the result by mod 3.  
**Core Codes:**

```c++
//Xor Solution for SingleNumberI
return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());

//Count digits for SingleNubmerII
vector<int> count(32, 0);
        
for(auto n:nums){
    for(int i = 0; i < 32; i++)
        count[i] += (n >> i) & 1; 
        // Here we can not use (n & (1 << i)) > 0 since there are negative nubmers. 
}
    
int result = 0;
for(int i = 0; i < 32; i++)
    result += (count[i] % 3) << i;
```

####138_CopyListWithRandomPointer
**Main Algo:** Similar to clone graph.  
**Core Codes:**

```c++
RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == nullptr)
        return nullptr;
    if(hash.count(head->label))
        return hash[head->label];
        
    RandomListNode *newhead = new RandomListNode(head->label);
    hash[head->label] = newhead;
    
    newhead->next = copyRandomList(head->next);
    newhead->random = copyRandomList(head->random);
            
    return newhead;
}
```

139_WordBreak 3Y  
1 Naive dfs TLE  
2 Sorted the length of words in decent order and then dfs TLE  
3 DP  

140_WordBreakII 1Y  
The same DP as the previous one, pay attention that when you use for(auto i:vector) you cannot change the value of vectors buy changing i  

####141\_LinkedListCycle && 142_LinkedListCycleII
**Main Algo:** For problem II, set two speed pointers. Let the initial step to be a, the length of cycle is c, so the meeting point of two pointers is a + b, then we could see that (a + b) * 2 = a + b  + c. where c == a + b. Then we let a new pointer start from the head, and let slow move. The place they met is a distance from the head.  
**Core Codes:**  

```c++
// LinkedListCycle
ListNode *slow = head, *fast = head;
while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
        return true;
}

// LinkedListCycleII        
ListNode *slow = head, *fast = head;
while(fast->next != nullptr && fast->next->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        ListNode *newNode = head;
        while(slow != newNode){
            slow = slow->next;
            newNode = newNode->next;
        }
        return newNode;
    }
}
``` 

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

####146_LRUCache
**Core Codes:**

```c++
class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int value = -1;
        
        // Key exist and is valid.
        if(key2idx.count(key) && valid[key2idx[key]]){
        	  // Get the value and set the idx to be invalid.
            int cur_idx = key2idx[key];
            value = cache[cur_idx];
            valid[cur_idx] = false;
            
            // Insert the value to the back and change the index map
            cache.push_back(value);
            valid.push_back(true);
            key2idx[key] = cache.size() - 1;
            
            // Check if the least used index was modified.
            if(cur_idx == min_idx){
                while(!valid[min_idx])
                    min_idx++;    
            }
        }  
        return value;
    }
    
    void set(int key, int value) {
    	  // Key exist and is valid.
        if(key2idx.count(key) && valid[key2idx[key]]){
        	  // Set the index to be invalid.
            int cur_idx = key2idx[key];
            valid[cur_idx] = false;
            
            // Insert the value to the back and change the index map
            cache.push_back(value);
            valid.push_back(true);
            key2idx[key] = cache.size() - 1;
            
            // Check if the least use index was changed.
            if(cur_idx == min_idx){
                while(!valid[min_idx])
                    min_idx++;    
            }
        } else {
        	  // If the key does not exist, we have to insert a new key and value.
            cache.push_back(value);
            valid.push_back(true);
            key2idx[key] = cache.size() - 1;
            cur_load++;
			  
			  // Check if the current load exceeded the capacity, and change the least used index.
            if(cur_load > capacity){
                valid[min_idx++] = false;
                while(!valid[min_idx])
                    min_idx++;
            }
        }
    }
private:
    vector<int> cache;
    vector<bool> valid;
    unordered_map<int, int> key2idx;
    
    int capacity;
    int min_idx = 0;
    int cur_load = 0;
};
```

####147_InsertionSortList
**Main Algo:** Recursion.  
**Core Codes:**

```c++
ListNode *newHead = insertionSortList(head->next);

if(head->val < newHead->val){
    head->next = newHead;
    return head;
}
    
ListNode *now = newHead;
while(now->next != nullptr && head->val > now->next->val){
    now = now->next;
}
head->next = now->next;
now->next = head;
return newHead;
```

####148_SortList 
**Core Codes:**

```c++
ListNode* MergeSort(ListNode* head, int n){
    if(n == 1)
        return head;
        
    ListNode *now = head;
    int i;
    for(i = 0; i < (n - 1) / 2; i++)
        now = now->next;
    
    ListNode *right = MergeSort(now->next, n - i  - 1);
    now->next = nullptr;
    ListNode *left = MergeSort(head, i + 1);
    
    ListNode *newHead;
    if(left->val < right->val){
        newHead = left;
        left = left->next;
    } else{
        newHead = right;
        right = right->next;
    }
    
    now = newHead;
    while(right != nullptr && left != nullptr){
        if(left->val < right->val){
            now->next = left;
            now = now->next;
            left = left->next;
        } else {
            now->next = right;
            now = now->next;
            right = right->next;
        }
    }
    while(right != nullptr){
        now->next = right;
        now = now->next;
        right = right->next;
    }
    while(left != nullptr){
        now->next = left;
        now = now->next;
        left = left->next;
    }
    now->next = nullptr;
    return newHead;
}
```

####149_MaxPointsOnALine
**Main Algo:** For each points, calculate the how many points in each slope and plus the duplicate points.  
**Core Codes:** 

```c++
unordered_map<float,int> slopes;
int maxP = 0;
for(int j = points.size() - 1; j >= maxP; j--){
    slopes.clear();
    int dup = 1;
    for(int i = 0; i < j; i++)
        if(points[i].x == points[j].x)
            if(points[i].y == points[j].y)
                dup++;
            else
                slopes[INT_MAX]++;
        else
            slopes[(float)(points[j].y - points[i].y) / (points[j].x - points[i].x)]++;
    int m = 0;
    for(auto s:slopes)
        m = max(m, s.second);
    maxP = max(maxP, m + dup); 
}
```

####150_EvaluateReversePolishNotation
**Core Codes:**

```c++
tack<int> st;                          
// use stack to store candidate numbers
    
for (string token : tokens) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
        int b = st.top(); st.pop();     
        // merge top two numbers in stack
        st.top() = token == "+" ? st.top() + b : token == "-" ? st.top() - b : token == "*" ? st.top() * b : st.top() / b;
    } else {
        st.push(stoi(token));           
        // add candidates in stack
    }
}
    
return st.top();
```

####151\_ReverseWordsInAString && 186_ReverseWordsInAStringII
**Main Algo:** Using istringstream or reverse the whole string first and reverse the word one by one.
**Corner Cases:**Mind multiple spaces and the spaces at the begining and ending of the string.
**Core Codes:**

```c++
while(!s.empty() && s[0] == ' ')
    s.erase(0, 1);
reverse(s.begin(), s.end());
while(!s.empty() && s[0] == ' ')
    s.erase(0, 1);
   
for(int i = 0; i < (int)s.length() - 1;)
    if(s[i] == ' ' && s[i + 1] == ' ')
        s.erase(i + 1, 1);
    else
        i++;

int head = 0;
while(head < (int)s.length()){
    int idx = s.find(' ', head);
    if(idx == string::npos)
        idx = s.length();
 
    reverse(s.begin() + head, s.begin() + idx);
    if(idx != s.length())
        head = idx + 1;
    else
        head = idx;
}
```

####152_MaximumProductArray
**Core Codes:**

```c++
int maxN = INT_MIN, product = 1;
int len = nums.size();

for(int i = 0; i < len; i++) {
    maxN = max(product *= nums[i], maxN);
    if (nums[i] == 0) product = 1;
}

product = 1;
for(int i = len - 1; i >= 0; i--) {
    maxN = max(product *= nums[i], maxN);
    if (nums[i] == 0) product = 1;
}
```

####153\_FindMinimumInRotatedSortedArray && 154_FindMinimumInRotatedSortedArrayII

**Core Codes:** 

```c++
if(nums.empty())
    return 0;
int head = 0, tail = nums.size() - 1;
while(head < tail){
    int mid = (head + tail) / 2;
    if(nums[head] == nums[tail]){
        tail--;
    } else if(nums[head] < nums[tail]){
        tail = mid;
    } else
        if(nums[mid] < nums[head])
            tail = mid;
        else
            head = mid + 1;
}

return nums[head];
```

####155_MinStack 
**Main Algo:** Refresh the minimum after push and pop option.  
**Core Codes:**

```c++
void push(int x) {
    s.push_back(x);
    if(x < min)
        min = x;
}

void pop() {
    if(s[s.size() - 1] == min){
        s.erase(s.end() - 1);
        auto index = min_element(s.begin(), s.end());
        if(index == s.end())
            min = INT_MAX;
        else
            min = *index;
    }else {
        s.erase(s.end() - 1);
    }
}
```

####156_BinaryTreeUpsideDown
**Main Algo:** Return the root of the result upside down left subtree. Find it's right most left node, and add root and right node to it's left and right. Then return the root.  
**Core Codes:**

```c++
if(root == nullptr || root->left == nullptr)
    return root;
    
TreeNode* newNode = upsideDownBinaryTree(root->left);
TreeNode* now = newNode;
while(now->right != nullptr)
    now = now->right;
now->left = root->right;
root->left = nullptr;
root->right = nullptr;
now->right = root;

return newNode;
```
####159_LongestSubstringWithAtMostTwoDistinctCharacters
**Main Algo:** Two pointers, sliding window.  
**Core Codes:** 

```c++
while(tail < s.length()){
    if(hash.size() < 2){
        hash[s[tail]]++;
        tail++;
        if(tail - head > max)
            max = tail - head;
    } else {
        if(hash.count(s[tail])){
            hash[s[tail]]++;
            tail++;
            if(tail - head > max)
                max = tail - head;
        } else {
            while(hash[s[head]] != 1){
                hash[s[head]]--;
                head++;
            }
            hash.erase(s[head]);
            head++;
            hash.insert({s[tail], 1});
            tail++;
            if(tail - head > max)
                max = tail - head;
        }
    }
}
```

####160_IntersectionOfTwoLinkedLists
**Main Algo:** Let two pointers start from both heads, and when one reaches the end, it lead the same steps as the difference between the two list's length. Thus we put the pointer to the start of the other list, and so is the the other pointer. Finally they will meet at the intersection.  
**Core Codes:**

```c++
ListNode *cur1 = headA, *cur2 = headB;
while(cur1 != cur2){
    cur1 = cur1?cur1->next:headB;
    cur2 = cur2?cur2->next:headA;
}
return cur1;
```

####161_OneEditDistance 
**Main Algo:** Directly compare or DP.  
**Core Codes:**

```c++
for (int i = 0;i < min(s.size(), t.size());++i) {
    if (s[i] != t[i])  
        return s.substr(i + 1) == t.substr(i + 1) || 
        			s.substr(i + 1) == t.substr(i) || 
        				s.substr(i) == t.substr(i + 1);
}
return abs(int(s.size()) - int(t.size())) == 1;
```

####162_FindPeakElement

####163_MissingRanges
**Core Codes:**

```c++
if(nums.empty()){
    string s = to_string(lower);
    if(upper != lower){s += "->" + to_string(upper);}
    res.push_back(s);
    return res;
}

int n = nums.size();
for(int i = 0; i < n; ++i){
    if(nums[i] > lower){
        string s = to_string(lower);
        if(lower != nums[i] - 1){s +="->" + to_string(nums[i] - 1);}
        res.push_back(s);
    }
    lower = nums[i] + 1;
}

if(nums[n-1] != upper){
    string s = to_string(nums[n-1] + 1);
    if(nums[n-1] + 1 != upper) s += "->" + to_string(upper);
    res.push_back(s);
}
```

####164_MaximumGap
**Main Algo:** Bucket and pigon hole theory.  
**Core Codes:**  

```c++
if(nums.size() < 2)
    return 0;
int n = nums.size(), maxN = *max_element(nums.begin(), nums.end()), minN = *min_element(nums.begin(), nums.end());

if(maxN == minN)
    return 0;
    
int width = ceil((maxN - minN) * 1.0 / (n - 1));

vector<int> bucket_max(n, INT_MIN);
vector<int> bucket_min(n, INT_MAX);

for(auto n:nums){
    int idx = (n - minN) / width;
    bucket_max[idx] = max(bucket_max[idx], n);
    bucket_min[idx] = min(bucket_min[idx], n);
}

int cur_max = bucket_max[0], maxGap = 0;
for(int i = 1; i < n; i++){
    if(bucket_min[i] != INT_MAX && bucket_min[i] - cur_max > maxGap)
        maxGap = bucket_min[i] - cur_max;
    if(bucket_max[i] != INT_MIN)
        cur_max = bucket_max[i];
}

return maxGap;
```

####165_CompareVersionNumbers
**Corner Cases:** "01" = "1", "1.0.0" = "1"
**Core Codes:**

```c++
istringstream in1(version1), in2(version2);

for(;;){
    string v1 ,v2;
    if(getline(in1, v1, '.')){
        if(getline(in2, v2, '.')){
            if(stoi(v1) < stoi(v2))
                return -1;
            else if(stoi(v1) > stoi(v2))
                return 1;
            else
                continue;
        } else {
            if(stoi(v1) == 0)
                continue;
            else
                return 1;
        }
    } else {
        if(getline(in2, v2, '.'))
            if(stoi(v2) == 0)
                continue;
            else
                return -1;
        else
            return 0;
    }
}
return 0;
```

####167_TwoSumII
**Main Algo:** Two pointers.  
**Core Codes:**

```c++
int i = 0, j = numbers.size() - 1;
while(i < j){
    if(numbers[i] + numbers[j] == target)
        return vector<int>({i + 1, j + 1});
    if(numbers[i] + numbers[j] > target) j--;
    else i++;
}
return vector<int>();
```

####168 & 171_ExcelSheetColumnTitle
**Core Codes:**

```c++
// 168
string result;
while(n > 0){
    result = (char)((n - 1) % 26 + 'A') + result;
    n = (n - 1) / 26;
}
return result;

// 171
int result = 0;
for(auto i:s){
    result = result*26 + (i - 'A') + 1;
}
```

####169_MajorityElement
**Core Codes:**

```c++
// Bit count solution.
int result = 0;
for(int i = 0; i < 32; i++){
    int count = 0;
    for(auto n:nums)
        count += (n >> i) & 1;
    result += (count > nums.size() / 2) << i;
}
```
####170_Factorial Trailing Zeroes
**Main Algo:**
**Core Codes:**

```c++
return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
```

####173_BinarySearchTreeIterator
**Main Algo:** In order traversal.
**Core Codes:**

```c++
/** @return the next smallest number */
int next() {
    TreeNode* cur = s.top()->right;
    int result = s.top()->val;
    s.pop();
    while(cur != nullptr){
        s.push(cur);
        cur = cur->left;
    }
    return result;
}
```

####174_DungeonGame
**Main Algo:** DP
**Core Codes:**

```c++
for(int i = m - 1; i >= 0; i--)
    for(int j = n - 1; j >= 0; j--){
        if(i == m - 1 && j == n - 1){
            if(dungeon[i][j] < 0)
                f[i][j] = 1 - dungeon[i][j];
            else
                f[i][j] = 1;
        } else if(i == m - 1){
            f[i][j] = max(1, f[i][j + 1] - dungeon[i][j]);
        } else if(j == n - 1)
            f[i][j] = max(1, f[i + 1][j] - dungeon[i][j]);
        else
            f[i][j] = max(1, min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j]);
    }
```

####179_LargestNumber
**Corner Cases:** All are 0, return only 1 zero. 
**Core Codes:**

```c++
// The sort function
static bool compare(int a, int b){
    string sa = to_string(a);
    string sb = to_string(b);
    
    return sa + sb > sb + sa;
}
```

####187_RepeatedDNASequences
**Core Codes:**

```c++
vector<string> result;
unordered_map<string, int> hash;

for(int start = 0; start + 9 < s.length(); start++){
    string cur = s.substr(start, 10);
    if(hash[cur] == 1)
        result.push_back(cur);
    hash[cur]++;
}
```

####189_RotateArray
**Core Codes:**

```c++
// Insert the end k elements to the begin.
k = k % nums.size();
        
nums.insert(nums.begin(), nums.end() - k, nums.end());
nums.erase(nums.end() - k, nums.end());

// Reverse three times
k = k % nums.size();

reverse(nums.begin(), nums.end());
reverse(nums.begin(), nums.begin() + k);
reverse(nums.begin() + k, nums.end());

// Rotate function (std::)
k = k % nums.size();
std::rotate(nums.begin(), nums.end() - k, nums.end());
```  

####190_ReverseBits
**Core Code:**

```c++
uint32_t result = 0;
for(int i = 0; i < 32; i++)
	 // Take care of the order of operations.  
    result += (n >> i & 1) << (31 - i);
```

####191_NumberOf1Bits 1Y  
**Core Codes:**

```c++
int result = 0;
for(int i = 0; i < 32; i++)
    result += n >> i & 1;
```

####198_HouseRobber I & II
**Main Algo:** DP, but the states can be compressed. In problem II, since 0 and n-1 are adjacent, we just neet to find out two distinct conditions:0 to n - 2, and 1 to n - 1.
**Core Codes:**

```c++
// Code for house robber II, the robber function is the same as house robber I.
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0)
        return 0;
    if(n < 3)
        return *max_element(nums.begin(), nums.end());
    
    return max(robber(nums, 0, n - 1), robber(nums, 1, n));
}

int robber(vector<int>& nums, int start, int end) {
    int prev = 0, cur = 0;
    for(int i = start; i < end; i++){
        int temp = max(prev + nums[i], cur);
        prev = cur;
        cur = temp;
    }
    return cur;
}
``` 

####199_BinaryTreeRightSideView
**Corner Cases:** The left subtree is higher than right subtree. We could also use dfs and bfs.
**Core Codes:**

```c++
// Recursion
vector<int> resultLeft;
if(root->right != nullptr)
    result = rightSideView(root->right);
    
if(root->left != nullptr)
    resultLeft = rightSideView(root->left);

if(resultLeft.size() > result.size())
    result.insert(result.end(), resultLeft.end() - (resultLeft.size() - result.size()), resultLeft.end());

result.insert(result.begin(), root->val);

// BFS
queue<TreeNode*> q;
vector<int> result;

if(root == nullptr)
    return result;
    
q.push(root);
int depth = 0;

while(!q.empty()){
    int curWidth = q.size();
    result.push_back(0);
    for(int i = 0; i < curWidth; i++){
        TreeNode* cur = q.front();
        q.pop();
        result[depth] = cur->val;
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
    depth++;
}
```

####200_NumberOfIslands
**Main Algo:** Floodfill
**Core Codes:**

```c++
// Floodfill for problem I
void floodfill(vector<vector<char>>& grid, int i , int j){
    if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != '1')
        return;
        
    grid[i][j] = '0'; // If we do not want to use extra space.
    
    floodfill(grid, i + 1, j);
    floodfill(grid, i - 1, j);
    floodfill(grid, i, j + 1);
    floodfill(grid, i, j - 1);
}

// Union find for problem II
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
```

####201_BitwiseANDOfNumbersRange
**Main Algo:**
Suppose from 00101 to 01011, the critical points the the highest different digit - 00XXX to 01XXX which will include 00111 to 01000 and the answer is 00000, 

**Core Codes:**

```c++
while(n > m) n = n & (n - 1);
    return n;
   
int result = 0;
for(int i = 31; i >= 0; i--){
    if((m >> i & 1) != (n >> i & 1))
        break;
    else
        result += (m >> i & 1) << i;
}
return result;
```

####202_HappyNumber

####203_RemoveLinkedListElements
**Corner Cases:** [1], [1,1]
**Core Codes:**

```c++
ListNode *dummy = new ListNode(-1);
dummy->next = head;
ListNode* now = dummy;
while(now != nullptr && now->next != nullptr){
    while(now->next != nullptr && now->next->val == val)
        now->next = now->next->next;
    now = now->next;
}

return dummy->next;
```

####204_CountPrimes
**Core Codes:**

```c++
// Bitmap solution. Reduce space complexity.
int countPrimes(int n) {
    vector<int> f(n / 32 + 1, -1);

    int result = 0;

    for(int i = 2; i < n; i++){
        if(get(f, i)){
            result++;
            int k = i * 2;
            while(k < n){
                set(f, k);
                k += i;
            }
        }
    }

    return result;
}

void set(vector<int>& f, int pos){
    f[pos / 32] &= (-1 ^ (1 << pos % 32));
}
int get(vector<int>& f, int pos){
    return f[pos / 32] >> (pos % 32) & 1;
}
```

####205_IsomorphicStrings
**Main Algo:** Set up a bijection between the chars.  
**Core Codes:**

```c++
unordered_map<char, char> map1, map2;

for(int i = 0; i < s.length(); i++){
    if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
        map1.insert({s[i], t[i]});
        map2.insert({t[i], s[i]});
    } else if(map1[s[i]] == t[i] && map2[t[i]] == s[i]) {} 
        else return false;
}
```
 
####206_ReverseLinkedList 
**Core Codes:**

```c++
// Iteration
ListNode *prev = nullptr, *cur = head, *next = nullptr;
while(cur != nullptr){
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
}
return prev;
        
// Recursion
ListNode* newHead = reverseList(head->next);
        
ListNode* now = newHead;
while(now->next != nullptr) now = now->next;

now->next = head;
head->next = nullptr;

return newHead;
```

####207\_CourseSchedule I&II
**Main Algo:** Simple topologic sort
**Corner Cases:** The final course number is not equal to n
**Core Codes:**

```c++
vector<int> result;
vector<vector<int> > post(numCourses);
vector<int> indegree(numCourses);

for(auto i:prerequisites){
    post[i.second].push_back(i.first);
    indegree[i.first]++;
}

queue<int> q;
for(int i = 0; i < numCourses; i++)
    if(indegree[i] == 0)
        q.push(i);
        
while(!q.empty()){
    int cur = q.front();
    q.pop();
    result.push_back(cur);
    for(auto i:post[cur]){
        if(--indegree[i] == 0)
            q.push(i);
    }
}
```       

####208_ImplementTrie
**Core Codes**

```c++
class TrieNode {
public:
    // Initialize your data structure here.
    bool is_word;
    TrieNode* children[26];
    
    TrieNode(){
        is_word = false;
        fill(children, children + 26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.length(); i++){
            int idx = word[i] - 'a';
            if(now->children[idx])
                now = now->children[idx];
            else{
                now->children[idx] = new TrieNode();
                now = now->children[idx];
            }
        }
        now->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *now = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(!now->children[idx])
                return false;
            else
                now = now->children[idx];
        }
        return now->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *now = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(!now->children[idx])
                return false;
            else
                now = now->children[idx];
        }
        return true;   
    }

private:
    TrieNode* root;
};
```

####209_MinimunSizeSubarraySum
**Core Codes:**

```c++
// Using two pointers.
int head = 0, tail = 0, sum = 0, min = INT_MAX;
while(tail < nums.size()){
    sum += nums[tail++];
    if(sum >= s){
        while(sum - nums[head] >= s){
            sum -= nums[head];
            head++;
        }
        if(tail - head < min)
            min = tail - head;
    }
}
```

####211_AddAndSearchWord
**Main Algo:** Implement trie tree and dfs with '.'
**Core Codes:**

```c++
bool dfs(string word, TrieNode* root){
    if(word.empty())
        return root->is_word;
    
    if(word[0] == '.'){
        for(int idx = 0; idx < 26; idx++)
            if(root->children[idx])
                if(dfs(word.substr(1), root->children[idx]))
                    return true;
        return false;
    } else {
        int idx = word[0] - 'a'; 
        if(!root->children[idx])
            return false;
        else
            return dfs(word.substr(1), root->children[idx]);
    }   
}
```
**Follow Up:** How to reduce time complexity? Add . to the trie tree, which will increase space complexity.

####212_WordSearchII
**Main Algo:** Build a trie tree using the words for search. DFS the board and push_back the index once we find one.  
**Corner Cases:** Since we can not go out of the board, so we check the next nodes's idx. For example board is [[a]], word is a.
**Core Codes:**

```c++
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++)
            constructTrieTree(root, words[i], i);
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                dfs(i, j, root, board);
                
        vector<string> result;
        for(auto i:result_idx)
            result.push_back(words[i]);
            
        return result;
    }
private:
    struct TrieNode{
        TrieNode* next[26];
        int idx = -1;
        TrieNode(){
            fill(next, next + 26, nullptr);
        }
    };
    vector<int> result_idx;
    
    void dfs(int i, int j, TrieNode* root, vector<vector<char>>& board){
        if(board[i][j] == 0 || root->next[board[i][j] - 'a'] == nullptr)
            return;
            
        char cur = board[i][j];
        TrieNode *p = root->next[cur - 'a'];
        // we check if we can find a word by the end of this node.
        if(p->idx != -1){
            result_idx.push_back(p->idx);
            p->idx = -1;
        }
        
        board[i][j] = 0;
        if(i > 0) 
            dfs(i - 1, j, root->next[cur - 'a'], board);
        if(i < board.size() - 1) 
            dfs(i + 1, j, root->next[cur - 'a'], board);
        if(j > 0) 
            dfs(i, j - 1, root->next[cur - 'a'], board);
        if(j < board[0].size() - 1) 
            dfs(i, j + 1, root->next[cur - 'a'], board);
        board[i][j] = cur;
    }
    
    void constructTrieTree(TrieNode* root, string s, int i_idx){
        for(auto c:s){
            if(root->next[c - 'a'] == nullptr){
                root->next[c - 'a'] = new TrieNode();
                root = root->next[c - 'a'];
            } else root = root->next[c - 'a'];
        }
        root->idx = i_idx;
    }
};
```

####215_KthLargestElementInAnArray 
**Main Algo:**

```c++
// Implement nth_largest based on parition
int partition (vector<int>& nums, int left, int right) {
    swap(nums[left], nums[left + random() % (right - left + 1)]);   
    // randomly choose a pivot and put it on left position
    
    int pivot = nums[left], slow = left + 1, fast = left + 1;       
    // use two pointers to partition: slow and fast
    
    while (fast <= right) {
        if (pivot < nums[fast]) {
            swap(nums[slow++], nums[fast]);
        }
        fast++;
    }
    
    swap(nums[left], nums[--slow]);                                 
    // position pivot 
    return slow;                                                    
    // return pivot position
}
    
public:
int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    k--;
    
    while (l <= r) {                                
        int n = partition(nums, l, r);                              
        
        if (n == k) { return nums[n]; }
        if (n < k) { 
            l = n + 1; 
        } else {
            r = n - 1;
        }
    }
    return -1;
}

// Using nth_element function.
nth_element(nums.begin(), prev(nums.end(), k), nums.end(), less<int>());
return *prev(nums.end(), k);

nth_element(nums.begin(), next(nums.begin(), k - 1), nums.end(), greater<int>());

return nums[k - 1];
```

####216_CombinationSumIII
**Main Algo:** DFS
**Core Codes:**

```c++
vector<vector<int>> dfs(int last, int k, int n) {
    if(k == 0 && n != 0 || k*(19 - k)/2 < n)
        return vector<vector<int>>();
    if(k == 1)
        return vector<vector<int>>(1, vector<int>(1, n));
        
    vector<vector<int>> result;
    int i = last + 1;
    while((2 * i + k - 1) * k / 2 <= n){
    // To ensure there will be a solution.
        vector<vector<int>> temp =  dfs(i, k - 1, n - i);
        for(int j = 0; j < temp.size(); j++)
            temp[j].insert(temp[j].begin(), i);
        result.insert(result.end(), temp.begin(), temp.end());
        i++;
    }
    return result;
}
```

####217_ContainsDuplicate I & II & III
**Main Algo:** 

* I: Whether dup exist, using hashset.
* II: Dup exist with distant K? Keep a hashset with size k + 1, erase num[i - k - 1].
* III: In distance k with difference t? Keep a multiset with size k + 1, insert each new element and compare with it's prev and next.

**Core Codes:**

```c++
multiset<int> s;
if(k == 0 || t < 0)
    return false;
    
for(int i = 0; i < nums.size(); i++){
    if(s.empty())
        s.insert(nums[i]);
    else if(s.size() <= k){
        s.insert(nums[i]);
        auto idx = s.find(nums[i]);
        if((idx != s.begin() && *prev(idx) + t >= nums[i]) || (idx != prev(s.end()) && *next(idx) - t <= nums[i]))
            return true;
    } else {
        s.erase(s.find(nums[i - k - 1]));
        s.insert(nums[i]);
        auto idx = s.find(nums[i]);
        if((idx != s.begin() && *prev(idx) + t >= nums[i]) || (idx != prev(s.end()) && *next(idx) - t <= nums[i]))
            return true;
    }
}
return false;
```

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

####221_MaximalSquare
**Core Codes:** 

```c++
for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(matrix[i][j] == '1'){
            if(i == 0 || j == 0)
                f[i][j] = 1;
            else{
                f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
            }
            if(f[i][j] > max)
                    max = f[i][j];
            
        }
return max * max;
```

####222_CountCompleteTreeNodes
**Main Algo:** By calculating the depth of right subtree and the whole tree, we could find if the left tree is complete.  
**Core Codes:**

```c++
int countNodes(TreeNode* root) {
    int h = height(root);
    if(h == 0)
        return 0;
        
    if(height(root->right) == h - 1)
        return (1 << (h - 1)) + countNodes(root->right);
    else
        return (1 << (h - 2)) + countNodes(root->left);
}

int height(TreeNode* root){
    int result = 0;
    while(root != nullptr){
        result++;
        root = root->left;
    }
    return result;
}
```

####223_RectangleArea
**Core Codes:**

```c++
return ((long)D - B) * ((long)C - A) + 
			((long)H - F) * ((long)G - E) - 
				max(((long)min(C,G) - max(A, E)),(long)0) * 
					max(((long)min(D, H) - max(B, F)), (long)0);
```

####224

####225_ImplementStackUsingQueues
**Core Codes:**

```c++
// Removes the element on top of the stack.
void pop() {
    for(int i = 0; i < s.size(); i++){
        if(i < s.size() - 1)
            s.push(s.front());
        s.pop();
    }
}

// Get the top element.
int top() {
    int result;
    for(int i = 0; i < s.size(); i++){
        if(i == s.size() - 1)
            result = s.front();
        s.push(s.front());
        s.pop();
    }
    return result;
}
```

####226_InvertBinaryTree
**Core Codes:**

```c++
if(root == nullptr)
    return root;

root->left = invertTree(root->left);
root->right = invertTree(root->right);

swap(root->left, root->right);
return root;
```

####228_SummaryRanges
**Corner Cases:** Pay attention to the final element of the array.
**Core Codes:**

```c++
for(int i = 0; i < nums.size(); i++){
    if(i == 0){
        head = nums[i];
    } else if(i == nums.size() - 1){
        if(nums[i] - nums[i - 1] != 1){
            if(nums[i - 1] != head)
                result.push_back(to_string(head) + "->" + to_string(nums[i - 1]));
            else
                result.push_back(to_string(head));
            result.push_back(to_string(nums[i]));
        } else
            result.push_back(to_string(head) + "->" + to_string(nums[i]));
    } else if(nums[i] - nums[i - 1] != 1){
        if(nums[i - 1] != head)
            result.push_back(to_string(head) + "->" + to_string(nums[i - 1]));
        else
            result.push_back(to_string(head));
        head = nums[i];
    } else {}
}  
```

####230_KthSmallestElementInABST
**Core Codes:**

```c++
// Iterative inorder traversal
stack<TreeNode*> s;
s.push(root);
while(s.top()->left != nullptr)
    s.push(s.top()->left);
    
int counter = 0;
while(!s.empty()){
    TreeNode* cur = s.top();
    s.pop();
    counter++;
    if(counter == k)
        return cur->val;
    if(cur->right != nullptr){
        s.push(cur->right);
        while(s.top()->left != nullptr)
            s.push(s.top()->left);
    }
}
```

####232_ImplementQueueUsingStacks
**Core Codes:**

```c++
// Removes the element from in front of queue.
void pop(void) {
    while(s.size() != 1){
        cache.push(s.top());
        s.pop();
    }
    s.pop();
    while(cache.size() != 0){
        s.push(cache.top());
        cache.pop();
    }
}

// Get the front element.
int peek(void) {
    int res;
    while(s.size() != 1){
        cache.push(s.top());
        s.pop();
    }
    res = s.top();
    while(cache.size() != 0){
        s.push(cache.top());
        cache.pop();
    }
    return res;
}
```

####234_PalindromeLinkedList
**Core Codes:**

```c++
// Reverse the right half. O(n) time and O(1) space.
bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseList(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(head->val!=slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}
ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* next=NULL;
    while(head!=NULL){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
```

####235_LowestCommonAncestorOfABinarySearchTree
**Core Codes:**

```c++
if(p->val < root->val && q->val < root->val){
    return lowestCommonAncestor(root->left, p, q);
} else if(p->val > root->val && q->val > root->val){
    return lowestCommonAncestor(root->right, p, q);
} else return root;
```

####236_LowestCommonAncestorOfABinarySearchTree
**Main Algo:** Recursively use the function, to check the return value of left and right subtree.
**Core Codes:**

```c++
if(root == nullptr ||root == p || root == q)
    return root;
TreeNode *inLeft = lowestCommonAncestor(root->left, p, q);
TreeNode *inRight = lowestCommonAncestor(root->right, p, q);

if(inLeft == nullptr)
    return inRight;
else if(inRight == nullptr)
    return inLeft;
else 
    return root;
```

####237_DeleteNodeInALinkedList
**Core Codes:**

```c++
while(node->next != nullptr){
    if(node->next->next == nullptr){
        node->val = node->next->val;
        node->next = nullptr;
    } else {
        node->val = node->next->val;
        node = node->next;
    }
}
```

####238_ProductOfArrayExceptSelf
**Core Codes:**

```c++
// Left product and right products
for (int i = 0, j = nums.size() - 1, lp = 1, rp = 1; 
	i < nums.size(); lp *= nums[i++], rp *= nums[j--]) {
    ans[i] *= lp, ans[j] *= rp;             
    // update ans elements
}

// Count zeros. A optimization is to record the position of zero
vector<int> ans(nums.size(), 0);
int p = 1, zcnt = 0, zi = 0;                
// p is the current product; zcnt is zero count; zi is zero element index

for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
        zi = i;
        if (++zcnt > 1) { return ans; }     
        // if nums has more than 1 zeros, ans is all 0s
    } else {
        p *= nums[i];
    }
}
    
if (zcnt == 1) {                            
	 // if has one 0, the only non-zero element is on zi position
    ans[zi] = p;
} else {                                    
	 // meaning zcnt == 0
    for (int i = 0; i < nums.size(); i++) { ans[i] = p / nums[i]; }
}
return ans;
```
  
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
 

230_KthSmallestElementInABST 2Y
It's worthwhile to write three traversals iteratively  

231_PowerOfTwo 1Y  
Using bit operation.  

232_ImplementQueueUsingStacks 1Y  
Used two stacks  

234_PalindromeLinkedList 1Y  
Used vector, took O(n) time and O(n) space.  

237_DeleteNodeInALinkedList 2Y  
You can not let the current node to be nullptr, instead, let the next pointed to a nulltpr  

237_DeleteNodeInALinkedList 2Y  
You can not let the current node to be nullptr, instead, let the next pointed to a nulltpr  

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
At first I tried to use dp, but actually if you can let the other one face n4 everytime you can always win.  
So if at first you are not n4, you will win.  

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

134_GasStation 2Y  
Find the beginnings of non-negative serires, and check if it can cover the whole circle.  

338_CountingBits 1Y  
f[n] = f[n - lower_bound(2^n)] + 1  

347_TopKFrequentElements 2Y  
Used unordered_map to count and priority queue to store and ranking.  

343_IntegerBreak 1Y  
DP, f[n] = max(max(k, f[k]) * max(n - k, f[n - k]), f[n]) (for k = 1 to n - 1)  

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