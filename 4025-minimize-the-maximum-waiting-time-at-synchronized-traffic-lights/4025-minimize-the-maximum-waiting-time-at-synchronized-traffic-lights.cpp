class Solution {
public:
    int minPenalty(
        int period,
        vector<int>& lights,
        vector<int>& arrivalTime
    ) {
        int maxLight = INT_MIN;
        int maxAns = INT_MIN;

        for (int light : lights) {
            maxLight = max(maxLight, light);
        }

        for (int at : arrivalTime) {
            int currentTime = at % period;

            if (currentTime >= maxLight) {
                maxAns = max(
                    maxAns,
                    period - currentTime
                );
            }
        }

        return maxAns == INT_MIN ? 0 : maxAns;
    }
};