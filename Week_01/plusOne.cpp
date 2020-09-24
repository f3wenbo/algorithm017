class Solution {
public:
// T:O(n) S:O(1)
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();
        
        while (carry && n--) {
            if (digits[n] < 9) {
                digits[n] += 1;
                carry = 0;
            } else {
                digits[n] = 0;
            }
            
        }
        
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};