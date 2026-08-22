class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 , mul = 1 , number = n;
        while(n != 0){
            int num = n % 10;
             sum += num;
             mul *= num;
            n /= 10;
        }
        cout<<sum << " "<<mul;
        return number % (sum + mul) == 0;
    }
};