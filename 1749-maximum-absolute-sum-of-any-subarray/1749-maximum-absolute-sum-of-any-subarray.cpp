class Solution {
public:
        int maxAbsoluteSum(vector<int>& A) {
        int s = 0, mi = 0, ma = 0;
        for (int a: A) {
            s += a;
            cout<<s<<" ";
            mi = min(mi, s);
            ma = max(ma, s);
        }
        cout<<mi<< " "<< "min";
        cout<<ma<<" "<<"max";
        return ma - mi;
    }
};