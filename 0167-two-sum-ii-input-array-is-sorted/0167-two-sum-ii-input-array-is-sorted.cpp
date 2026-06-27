class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin() , numbers.end());
        int left = 0 , right = numbers.size() -1;

        while(left < right){
            long sum = numbers[left] + numbers[right];

            if(sum == target){
                return {left+1 , right+1};
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {-1 , -1};
    }
};