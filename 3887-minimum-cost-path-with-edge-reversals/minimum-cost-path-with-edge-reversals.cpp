class Solution {
public:
    bool bfs(int node , vector<vector<pair<int,int>>> &graph){
        queue<int>q;
        vector<bool>vis(graph.size(), false);
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int curr_node = q.front();
            q.pop();
            for(auto neighbour : graph[curr_node]){
                int neigh_node=neighbour.first;
                if(!vis[neigh_node]){
                    vis[neigh_node]=true;
                    q.push(neigh_node);
                }
            }
        }
        return vis[graph.size()-1]==true;
    }
    int dijksta(vector<vector<pair<int,int>>> &graph , vector<int> &dis){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;//dis, node
        pq.push({0 , 0});//dis=0 , node=0;
        while(!pq.empty()){
            auto top_ele = pq.top();
            pq.pop();
            int curr_dis = top_ele.first;
            int curr_node = top_ele.second;
            for(auto neighbour : graph[curr_node]){
                int neigh_node = neighbour.first;
                int weight = neighbour.second;
                if((curr_dis + weight) < dis[neigh_node]){
                    dis[neigh_node] = curr_dis + weight;
                    pq.push({dis[neigh_node] , neigh_node});
                }
            }
        }
        return dis[graph.size()-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>graph(n);//neightbour , dis
        //created adjacency list
        vector<bool>node_switch(n,false);
        for(auto a:edges){
            graph[a[0]].push_back({a[1],a[2]});
            graph[a[1]].push_back({a[0],2*a[2]});
        }
        //last one will be the node to
        //need to check if the n-1 th node is reachable and if it is then from which node
        int node=-1;
        if(bfs(0 , graph)){
            node = 0;
        }
        if(node == -1)return -1;
        vector<int>dis(n,1e9);
        dis[node]=0;
        return dijksta(graph , dis); 
    }
};