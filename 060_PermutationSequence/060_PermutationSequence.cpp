/*************************************************************************
	> File Name: 060_PermutationSequence.cpp
	> Author: Sheng Qin
	> Mail: sheng.qin@yale.edu
	> Created Time: Fri Sep  2 22:02:36 2016
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    /*string getPermutation(int n, int k) {
        vector<int> num;

        for(int i = 0; i < n; i++)
            num.push_back(i + 1);
        
        while(k > 1){
            k--;
            for(int j = n - 2; j >= 0; j--){
                bool find = false;
                for(int i = n - 1; i > j; i--){
                    if(num[i] > num[j]){
                        swap(num[i], num[j]);
                        sort(num.begin() + j + 1, num.end() );
                        find = true;
                        break;
                    }
                }
                if(find)
                    break;
            }
        }

        string result;
        
        for(auto i = num.begin(); i != num.end(); ++i)
            result += *i + '0';
        return result;
    }*/

    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 0; i < n; i++)
            nums.push_back(i + 1);

        return getPermutationOrder(n, k, nums);
    }

private:
    string getPermutationOrder(int n, int k, vector<int> nums){
        if(n == 1){
            string result;
            result  += nums[0] + '0';
            return result;
        }

        int fac = factor(n - 1);
        int step = (k - 1) / fac;
        
        string result = "";
        result += nums[step] + '0';
        nums.erase(nums.begin() + step);

        return result + getPermutationOrder(n - 1, k - step * fac, nums);

    }

    int factor(int n){
        int result = 1;
        while(n > 0){
            result *= n;
            n--;
        }

        return result;
    }
};

int main () {
    Solution newSolution;

    cout << newSolution.getPermutation(5,6) << endl;

    return 0;
}
