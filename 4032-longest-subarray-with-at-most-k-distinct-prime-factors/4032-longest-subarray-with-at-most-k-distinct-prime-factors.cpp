class Solution {
public:

    vector<int> primeFactors(int n) {
        vector<int> factors;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        if(n > 1) factors.push_back(n);
        return factors;
    }
    
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] = primeFactors(nums[i]);
        }
        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;
        int distinct = 0;

        for (int right = 0; right < nums.size(); right++){
            
            for (int p : mp[nums[right]]) {
                if (freq[p] == 0)
                    distinct++;

                freq[p]++;
            }
            while (distinct > k) {

                for (int p : mp[nums[left]]) {
                    freq[p]--;
                    if (freq[p] == 0)
                        distinct--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};