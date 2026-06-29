class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0,b = 0;
        for (int i = 0 ; i<n ; i++)
        {
            b = b^nums[i];
            a = a^i;
        }
        a = a ^ n;
        int num = a^b;
        return num;
    }
};