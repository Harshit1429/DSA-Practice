class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;

        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }

        return count;
    }
};



// class Solution {
// public:
//     void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
//         visited[node] = true;
//         for(int nbr : adj[node]){
//             if(!visited[nbr]){
//                 dfs(nbr,adj,visited);
//             }
//         }
//     }

      
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V = isConnected.size();
//         vector<vector<int>> adj(V);
//         for(int i = 0; i < V; i++){
//             for(int j = 0; j < V; j++){
//                 if(isConnected[i][j] == 1 && i != j){
//                     adj[i].push_back(j);
//                 }
//             }
//         }

//         int count = 0;
//         vector<bool> visited(V ,false);

//         for(int i = 0 ; i < V ;i++){
//             if(!visited[i]){
//                 count++;
//                 dfs(i,adj,visited);
//             }
//         }
        
//         return count;
//     }
// };