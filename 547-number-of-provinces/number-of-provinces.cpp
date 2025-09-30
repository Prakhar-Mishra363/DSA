class Solution {
public:
    void dfs(int src,vector<list<int>>& graph,vector<bool>&vis){
        vis[src]=true;
        for(auto it:graph[src]){
            if(!vis[it]){
                dfs(it,graph,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        vector<bool>vis(isConnected.size(),false);
        vector<list<int>>graph(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(i!=j){
                    if(isConnected[i][j]){
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                provinces++;
                dfs(i,graph,vis);
            }
        }
        return provinces;
    }
};