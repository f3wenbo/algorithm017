class Solution {
public:

// using std api swap() T:O(n) S:O(1)
    void moveZeroes(vector<int>& nums) {
        for (int zeroPos = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0)
                swap(nums[zeroPos++], nums[cur]);
        }
        return;
    }
};
