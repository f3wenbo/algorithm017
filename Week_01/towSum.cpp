class Solution {
public:

// using hash table to find the two nunbers by one loop T:O(n) S:O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        for (int i = 0; i < nums.size(); i++) {
            if (index.find(target - nums[i]) != index.end())
                return {index[target - nums[i]], i};
            index[nums[i]] = i;
        }
        return {};
    }
};