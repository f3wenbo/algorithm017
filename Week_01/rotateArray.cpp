class Solution {
public:
// using extra vector T:O(n) S:O(n)
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k <= 0) return;
        
        vector<int> copy(nums);
        
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = copy[i];
        }
        
        return;
    }

// using reverse api T:O(n) S:O(1)
    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k <= 0) return;
        
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);

        return;
    }

// 
};