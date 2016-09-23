g`""`public:
    int findMin(vector<int>& nums) {
        return findMinHalf(nums, 0, nums.size());
    }
private:
    int findMinHalf(vector<int> nums, int begin, int end){
        if(end - begin == 1)
            return nums[begin];
        if(end - begin == 2)
            return min(nums[begin], nums[begin + 1]);
        
        int mid = begin + (end - begin)/2;
        
        if(nums[begin] <= nums[end - 1])
            return findMinHalf(nums, begin, mid + 1);
        else
            if(nums[begin] <= nums[mid])
                return findMinHalf(nums, mid + 1, end);
            else
                return findMinHalf(nums, begin, mid + 1);
    }
};

int main() {
    Solution newSolution;
    vector<int> nums({1,2,3});
    cout << newSolution.findMin(nums) << endl;
    
    return 0;
}
