class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<long long, int> mp;

        long long prefixSum = 0;
        int maxLen = 0;
        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {


            prefixSum += arr[i];

            
            if (mp.find(prefixSum - k) != mp.end()) {
                maxLen = max(maxLen, i - mp[prefixSum - k]);
            }

            
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};