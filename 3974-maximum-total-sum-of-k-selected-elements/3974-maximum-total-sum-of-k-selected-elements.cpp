class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
         long long maxtotal = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<long long> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        sort(ans.rbegin(), ans.rend());
        int i = 0;
        while(i < ans.size()){
            if(mul > 0){
              maxtotal += 1LL * ans[i] * mul;
              mul--;
            }
            else{
                maxtotal += 1LL * ans[i];
            }
            i++;
        }
        return maxtotal;
    }
};