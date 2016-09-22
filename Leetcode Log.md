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

032_LongestValidParentheses 1TLE 2Y
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
