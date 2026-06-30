class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(101);

        for(int i = 0 ; i < logs.size() ; i++){
            int birth = logs[i][0];
            int death = logs[i][1];

            arr[birth - 1950]++;
            arr[death - 1950]--;
        }
        int live = 0;
        int year = 1950;
        for(int i = 0 ; i < 101 ; i++){
            live += arr[i];
            if(live > arr[i]){
                live = arr[i];
                year = 1950 + i;
            }
        }
        return year-1;
    }
};