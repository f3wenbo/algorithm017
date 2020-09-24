class Solution {
public:

// T:O(n) S:O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int pos = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[pos] != nums[i]) nums[++pos] = nums[i];
        }
        return pos + 1;
    }
};