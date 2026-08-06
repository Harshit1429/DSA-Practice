class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;
        int sum = 1;
        while(num != 0){
            sum *= num % 10;
            num /= 10;
            cout<<sum;
            if(num == 0){
                if(sum % t == 0){
                    return n;
                }
                else{
                    n = n + 1;
                    num = n;
                    sum = 1;
                }
            }
        }
        return 0;
    }
};