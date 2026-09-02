class Solution {
public:
    int minOperations(vector<int>& nums) {

        unordered_map<int, int> map;

        for (int num : nums) {
            map[num]++;
        }

        int min = 0;

        for (auto& e : map) {

            int key = e.first;
            int val = e.second;

            if (val == 1) {
                return -1;
            }

            while (val != 0) {

                if (val % 2 == 0 && val % 3 == 0) {

                    map[key] = val - 3;
                    val -= 3;
                    min++;

                }
                else if (val % 2 == 0) {

                    map[key] = val - 2;
                    val -= 2;
                    min++;

                }
                else if (val % 3 == 0) {

                    map[key] = val - 3;
                    val -= 3;
                    min++;

                }
                else {
                    map[key] = val - 2;
                    val -= 2;
                    min++;
                }
            }
        }

        return min;
    }
};