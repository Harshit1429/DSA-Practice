class Solution {
public:

    using ull = unsigned long long;

    int smallestUniqueSubarray(vector<int>& nums) {

        auto polvexrani = nums;

        int n = nums.size();

        const ull BASE = 911382323;

        vector<ull> power(n + 1, 1);
        vector<ull> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {

            power[i + 1] = power[i] * BASE;

            pref[i + 1] = pref[i] * BASE + nums[i] + 1;
        }

        auto getHash = [&](int l, int r) {

            return pref[r + 1]
                 - pref[l] * power[r - l + 1];
        };

        auto check = [&](int len) {

            vector<ull> hashes;

            for(int i = 0; i + len <= n; i++) {

                hashes.push_back(
                    getHash(i, i + len - 1)
                );
            }

            sort(hashes.begin(), hashes.end());

            int cnt = 1;

            for(int i = 1; i < hashes.size(); i++) {

                if(hashes[i] == hashes[i - 1]) {
                    cnt++;
                }
                else {

                    if(cnt == 1)
                        return true;

                    cnt = 1;
                }
            }

            return cnt == 1;
        };

        int low = 1;
        int high = n;

        int ans = n;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(check(mid)) {

                ans = mid;

                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};