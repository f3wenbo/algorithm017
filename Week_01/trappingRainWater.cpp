class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int leftMax = 0, rightMax = 0, water = 0;
        int l = 0, r = height.size() - 1;
      
        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax < rightMax) {
                water += (leftMax - height[l++]);
            } else {
                water += (rightMax - height[r--]);                
            }
        }
        return water;
    }
};