class Solution {
public:
    int maxProduct(int n) {
        int ans = 0, num = n;
        vector<int> numbers;
        while(num != 0){
           int curr = num % 10;
           numbers.push_back(curr);
           num /= 10;
        }

        for(int i = 0 ; i < numbers.size() ; i++){
            for(int j = i+1 ; j < numbers.size() ; j++){
                ans = max(ans , numbers[i] * numbers[j]);
            }
        }
        return ans;
    }
};