class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diffrence;
        int n = capacity.size();
        for(int i=0;i<n;i++)
        {
            diffrence.push_back(capacity[i]-rocks[i]);
        }
        sort(begin(diffrence),end(diffrence));
        int i;
        for(i=0;i<n && additionalRocks >= diffrence[i];i++)
        {
            additionalRocks -= diffrence[i];
        }
        return i;
    }
};