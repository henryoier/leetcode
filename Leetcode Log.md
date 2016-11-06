#Leetcode Log  
   
##2016.7.23   
001_TwoSum 2Y  
     Given a series of numbers and a target. The problems requires to get the index of the two numbers whose sum is the target.  
     Not much to say, two-layer-loop to enumerate all conditions and terminate when ever there is a solution. The time complexity is O(n^2)。  
     At the first time when I submitted my solution, I didn’t write “return XXX” at the end of the function. Though I passed the test on my computer, but got an compilation error on leetcode because under some circumstances there will be no return value even if the problem told us there must be exactly one solution. The same error may happen if we don't write a return line after “else”.  
  
     By using unordered map we could reduce the time complexity of find the position to O(1), thus the total complexity can be reduced to O(n).(Detailed in code)  
  
##2016.8.2  
002_AddTwoNumbers 1Y  
Review the basic operation of list and pointer.  
  
004_MedianOfTwoSortedArrays 1Y  
  
005_LongestPalindromicSubstring 1Y  
  
006_ZigZagCoversion 3Y  
1st WA forget to consider empty string && forget to consider when numRows == 1.  
2st Memory Exceeded didn’t calculate the size of the pattern array.  
Watch out the initialization of 2-D arrays. We can not do it dynamically.  
  
007_ReverseInteger 2Y  
1st WA forget to consider when reversed, the result could be larger than MAX_INT.  
  
008_StringToInteger Too Many Was  
Consider WhiteSpaces at the beginning.Consider ‘+’ and ‘-’, and the conversion break when there is a character which is not a number. Finally you have to consider the overload of MAX_INT and MIN_INT.  
  
##2016.8.3  
009_PalindromeNumber 2Y  
Forget to consider negative number and all negative numbers are not palindrome.  
  
011_ContainerWithMostWater   
1 and 2 TLE Search all conditions, O(n^2).  
Greedy algorithm. The area was related to the lower one. So just start from the beginning and the end. It’s of no use that we change the higher one’s index closer to the lower one because the area will only decrease. Thus each time we just need to change the index of the lower one. And we can assure that once the two indexes become the same we have already find the maximum area.  
  
##2016.8.4  
010_RegularExpressionMatching  
Recursively solve the problem  
First, consider p[p_index + 1] is ‘*’;  
Then consider where there is a ‘.’ or s and p has the same character at their indexes.  
  
##2016.8.5  
012_IntegerToRoman 1Y  
  
013_RomanToInteger 1Y  
There are only two types of digits, IX (X minus I) or else(Add all together).  
  
014_LongestCommonPrefix 1Y  
  
015_3Sum 3Y  
1 TLE Search O(n^3)  
2 TLE Hashmap O(n^2)  
3Y Passed the same numbers. Then accepted.  
  
017_LetterCombinationOfAPhoneNumber 1Y  
Typical DFS  
  
019_RemoveNthNodeFromEndOfList 1Y  
The best way to solve this problem is to set two pointer at the begining. The first one go n steps first and then they go together while the first on goes to the end.  
  
020_ValidParentheses 1Y  
Use a stack to pair the brackets.  
  
021_MergeTwoSortedLists 1Y  
  
##2016.8.6  
023_MergeKSortedLists 1Y  
Use MergeTwoSortedLists n times.  
  
##2016.8.9  
022_GenerateParentheses nWA  
The parentheses follow the rule that if the unpaired left ones are zero, you couldn’t put a right one. Besides, if n * 2 - pos == leftn, then you can only put right ones.  
  
##2016.8.10  
026_RemoveDuplicatesFromSortedArray 1Y  
027_RemoveElement 1Y  
  
##2016.8.11  
028_ImplementStrStr() 1Y  
003_LongestSubstringWithoutRepeatingCharacters 2Y  
1 TLE Binary Search  
2 Greedy Algorithm  
  
024_SwapNodesInPairs 1Y  
  
##2016.8.27  
031_NextPermutation 2Y  
for(auto first = nums.end() - 2; first >= nums.begin(); first--){  
for(auto last = nums.end() - 1; last != first; last--){  
                	if(*last > *first){  
                    		swap(*last, *first);  
                    		sort(first + 1, nums.end());  
                    		return;  
    		}  
            	}  
}  
  

32_LongestValidParentheses 1TLE 2Y  
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
use this method twice.  
  
##2016.8.28  
029_DivideTwoIntegers  
The divisor can be doubled every time to accelerate. Besides, mind the overload situation  
Example Code:  
  
  
  
034_SearchForARange  
Binary search, if(nums[head] == num[tail]) return [head, tail] or [-1, -1] for pruning.  
  
035_SearchInsertPosition  
Binary search  
int binarySearch(const vector<int> nums, int target, int head, int tail){  
        int mid = (head + tail) / 2 + 1;  
          
        if(head == tail)  
            if(nums[head] >= target)  
                return head;  
            else  
                return head + 1;  
          
        if(target >= nums[mid])  
            return binarySearch(nums, target, mid, tail);  
        else  
            return binarySearch(nums, target, head, mid - 1);  
    }  
  
036_ValidSudoku 1Y  
  
##2016.8.30  
038_CountAndSay 1Y  
  
039_CombinationSum 2Y  
1 WA didn't sort the result and remove the duplicates  
  
sort(result.begin(), result.end());  
vector<vector<int>>::iterator end_unique = unique(result.begin(), result.end());  
result.erase(end_unique, result.end());  
  
040_CombinationSumII 2Y  
1 TLE use the method in previous problem, erase the item you selected everytime in candidates.  
2Y DFS  
  
041_FirstMissingPositive 1Y  
int firstMissingPositive(vector<int>& nums) {  
        vector<pair<int, int>> result;  
        pair<int, int> init = make_pair(1, INT_MAX);  
        result.push_back(init);  
  
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
        return result[0].first;      
    }  
  
042_TrappingRainWater 2Y  
1 WA Forgot when size is 0, couldn’t initialize.  
while(last < height.size() - 1){  
            int i;  
            for(i = last + 1; i < height.size(); i++){  
                if(height[i] >= lastHeight)  
                    if(lastHeight == 0){  
                        lastHeight = height[i];  
                        last = i;  
                    } else {  
                        for(int j = last + 1; j < i; j++){  
                            result += lastHeight - height[j];  
                        }  
                        last = i;  
                        lastHeight = height[last];  
                        break;  
                    }  
                else  
                    continue;  
            }  
   
            if(i == height.size()){  
                lastHeight--;  
            }  
        }  
  
##2016.8.31  
  
043_MultiplyStrings 2Y  
Similar to high accuracy multiplication. Cannot directly use char array or string because their ranges are from [-127, 128]  
  
045_JumpGameII 3Y  
1 TLE DP   
2 TLE Refined DP  
3 Greedy Algorithm  
int step = 0, last = 0, curr = 0, max = 0;  
        if(nums.size() == 1)  
            return 0;  
              
        for(int i = 0; i < nums.size(); i++){  
            if(i > last){  
                step++;  
                last = max;  
            }  
            curr = i + nums[i];  
            if(curr >= nums.size() - 1)   
                return step + 1;  
            else  
                if(curr > max)  
                    max = curr;  
                else {}  
        }  
        return step;  
  
046_Permutations 1Y  
dfs could solve  
  
047_PermutationsII 2Y  
dfs TLE, but it can be passed by pruning.  
Otherwise we can use next_permutation function.  
  
  
##2016.9.1  
050_pow(x, n) 2Y  
divide and conquer, mind overload condition.  
  
051_N-Queens 1Y  
052_N-QueensII 1Y  
dfs  
  
##2016.9.2  
053_MaximumSubarray 2Y  
Greedy, when current sum is lower than 0, let it be 0.   
  
054_SpiralMatrix 1Y  
Mind all possible conditions.  
  
058_LengthOfLastWord 3Y  
Forgot to consider the space could be at the end and there could be multiple spaces.  
  
059_SpiralMatrixII 1Y  
If the parameter should be 2-D array, better use like f[x*m + y], where f is a m x n matrix;   
  
##2016.9.3  
062_UniquePaths 1Y  
063_UniquePathsII 1Y  
dp  
  
##2016.9.4  
064_MinimumPathSum 1Y  
dp  
  
060_PermutationSquence 2Y  
1 TLE One by one  
2 recursion  
  
066_PlusOne 1Y  
  
067_AddBinary 1Y  
  
069_Sqrt(x) 2Y  
1 WA Overflow when compare i * i <= x;   
  
070_ClimbingStaris 1Y  
DP  
  
##2016.9.6  
056_MergeIntervals  
for(int i = 0; i < intervals.size() - 1; i++)  
      for(int j = i + 1; j < intervals.size(); j++)  
             if(!(intervals[i].start > intervals[j].end) && !(intervals[i].end < intervals[j].start)){   
//Overlapped  
                        Interval a = intervals[i], b = intervals[j];  
                        Interval newInterval(min(a.start, b.start), max(a.end, b.end));  
  
                        intervals.erase(intervals.begin() + j);  
                        intervals.erase(intervals.begin() + i);  
                        intervals.insert(intervals.begin() + i, newInterval);  
                        j = i;   //Until convergent  
                    }  
 return intervals;       
  
057_InsertInterval 2Y  
1 WA didn't do it recursively  
for(auto i = intervals.begin(); i != intervals.end(); i++){  
            if(newInterval.end < i->start){  
                intervals.insert(i, newInterval);  
                return intervals;  
            } else if(newInterval.start > i->end){  
                continue;  
            } else {  
                newInterval.start = min(newInterval.start, i->start);  
                newInterval.end = max(newInterval.end, i->end);  
                intervals.erase(i);  
                return insert(intervals, newInterval);  
            }  
        }  
        intervals.insert(intervals.end(), newInterval);  
        return intervals;   
    }  
  
071_SimplifyPath 3Y  
  
072_EditDistance 2Y  
1 WA wrong border conditions.  
  
073_SetMatrixZeroes 1Y  
  
075_SortColors 1Y  
  
##2016.9.7  
077_Combinations 1Y  
dfs  
  
078_Subsets 1Y  
dfs  
  
##2016.9.8 – 9.18  
079_WordSearch dfs  
  
084_LargestRectangleInHistogram  
  
091_DecodeWays dp  
  
095_UniqueBinarySearchTreeII 2Y  
Forgot the empty result.  
  
096_UniqueBinarySearchTrees 2Y  
Forgot to set the array to be all 0;  
  
097_InterleavingString 2Y  
1 TLE use recursive function would TLE  
2Y mind the boundary conditions  
  
098_ValidateBinarySearchTree 2y  
1WA A valid binary search tree is that the maximum of the left subtree is smaller than the val of root and the minimum of the right is bigger than the val of root.  
  
100_SameTree 1Y  
  
101_SymmetricTree 1Y  
  
102_BinaryTreeLevelOrderTraversal 1Y  
  
103_BinaryTreeZigzagLevelOrderTraversal 1Y  
  
##2016.9.20  
104_MaximumDepthOfBinaryTree 1Y  
  
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

048_RotateImage 1Y

049_GroupAnagram 1Y
Redefined sort function

## 2016.9.24
061_RotateList 1Y

074_SearchA2DMatrix 2Y
A good template for binary search

086_PartitionList 3Y
1WA Insert head in front (all are greater or equal)
2WA typo

## 2016.9.25
089_GrayCode 1Y
pay attention that << >> has low priority   
  
090_SubsetsII 2Y  
The array may contain duplicates, so we have to sort every condition  

092_ReverseLinkedListII 1Y
Mistype n into m

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
  
025_ReverseNodesInK-Group  3Y  
When doing recursion, record the order.  
  
033_SearchInRotatedSortedArray 3Y  
BinarySearch, divide the problem into several conditions  
  
016_3SumClosest 2Y  
Use three pointers.  
  
018_4Sum 3Y  
  
081_SearchInRotatedSortedArrayII 2Y  
Similar to previous problem, the difference is that once head == tail, tail-- until different.
  
030_SubstringWithConcatenationOfAllWords 3Y  
Missed an important condition that all words are the same length.  
  
065_ValidNumber 3Y  
Can contain only 1 e, right should be pure number.
For fraction, right should not contain '-' or '+'  
  
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
  
068_TextJustification 3Y  
Mind the details.  
  
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
  

