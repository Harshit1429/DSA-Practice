class Solution {
public:
    int findGCD(vector<int>& nums) {
     int mini = INT_MAX , maxi = INT_MIN;
        for(int num : nums){
            mini = min(mini,num);
            maxi = max(maxi,num);
        }

        return gcd(mini,maxi);
    }
    int gcd(int a , int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;   
    }
};