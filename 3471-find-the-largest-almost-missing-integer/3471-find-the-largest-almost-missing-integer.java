class Solution {
    public int largestInteger(int[] nums, int k) {

        HashMap<Integer, Integer> map = new HashMap<>();

        int left = 0;
        int right = k - 1;

        while (right < nums.length) {

            HashSet<Integer> set = new HashSet<>();

            // Take each element only once per subarray
            for (int i = left; i <= right; i++) {
                set.add(nums[i]);
            }

            // Count how many subarrays contain each number
            for (int x : set) {
                map.put(x, map.getOrDefault(x, 0) + 1);
            }

            left++;
            right++;
        }

        int ans = -1;

        for (int x : map.keySet()) {
            if (map.get(x) == 1) {
                ans = Math.max(ans, x);
            }
        }

        return ans;
    }
}