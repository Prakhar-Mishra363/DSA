class DSU{
    public: 
        vector<int>parent;
        int total_comp;
        DSU(int n){
            parent.resize(n , -1);
            total_comp=n;
        }
        int find_parent(int u){
            if(parent[u]<0)return u;
            return parent[u] = find_parent(parent[u]);
        }
        void union_by_size(int u , int v){
            int par_u = find_parent(u);
            int par_v = find_parent(v);
            if(par_u == par_v)return;
            if(parent[par_u]>parent[par_v])swap(par_u , par_v);
            parent[par_u] += parent[par_v];
            parent[par_v]=par_u;
            total_comp--;
        }
};
bool comp(vector<int> a , vector<int> b){
    return a[2]> b[2];
}
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // priority_queue<vector<int> , vector<vector<int>> , comp_for_max_heap>pq;
        vector<vector<int>>non_must_edges;
        DSU d(n);
        vector<int>mas;
        vector<int>nmas;
        // sort(edges.begin() , edges.end() , comp);
        int max_poss_stab=INT_MAX;
        //building the st of the "must" be included edges
        for(int idx=0 ; idx<edges.size() ; idx++){
            auto curr_edge=edges[idx];
            if(curr_edge[3]){
                if(d.find_parent(curr_edge[0]) == d.find_parent(curr_edge[1]))return -1;
                else{
                    d.union_by_size(curr_edge[0] , curr_edge[1]);
                }
                mas.push_back(curr_edge[2]);
                // max_poss_stab = min(max_poss_stab , curr_edge[2]);
            }else{
                non_must_edges.push_back(curr_edge);
            }
        }
        if(non_must_edges.size()>0){
            sort(non_must_edges.begin() , non_must_edges.end() , comp);
        }
        for(int idx=0 ; idx<non_must_edges.size() ;  idx++){
            auto curr_edge=non_must_edges[idx];
            if(d.find_parent(curr_edge[0]) == d.find_parent(curr_edge[1]))continue;
            else{
                d.union_by_size(curr_edge[0] , curr_edge[1]);
                nmas.push_back(curr_edge[2]);
            }
        }
        for(int idx=nmas.size()-1 ; idx>=0 && k>0 ; idx--){
            nmas[idx] *= 2;
            k--;
        }
        int ans=INT_MAX;
        if(d.total_comp>1)return -1;
        if(nmas.size()>0)ans = *min_element(nmas.begin() , nmas.end());
        if(mas.size()>0)ans = min(ans , *min_element(mas.begin() , mas.end()));
        return ans;
    }
};