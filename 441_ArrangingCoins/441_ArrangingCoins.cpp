class Solution {
public:
    int arrangeCoins(int n) {
        return floor(sqrt((double)n * 2 + 0.25) - 0.5);
    }
};
