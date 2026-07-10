class Solution {
public:
    bool isValid(int mid,vector<int>&houses,vector<int>&heaters){
        int i=0,j=0;
        int n=houses.size(),m=heaters.size();
        while(i<n && j<m){
            while(j<m && abs(houses[i]-heaters[j])>mid){
                j++;
                if(j==m) return false;
            }
            i++;
        }
        return i==n;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int low=0;
        int high=1e9;
        int res=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        while(low<=high){
            int mid=(low+high)>>1;
            if(isValid(mid,houses,heaters)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};