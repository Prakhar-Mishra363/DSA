class Solution {
public:
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
        vector<int>dis(n,1e9);
        dis[0]=0;
        int result = dijksta(graph , dis); 
        return (result == 1e9) ? -1 : result;
    }
};