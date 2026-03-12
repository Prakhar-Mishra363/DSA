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
        bool union_by_size(int u , int v){
            int par_u = find_parent(u);
            int par_v = find_parent(v);
            if(par_u == par_v)return true;
            if(parent[par_u]>parent[par_v])swap(par_u , par_v);
            parent[par_u] += parent[par_v];
            parent[par_v]=par_u;
            total_comp--;
            return false;
        }
};
bool comp(vector<int> &a , vector<int> &b){
    return a[2]> b[2];
}
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>non_must_edges;
        DSU d(n);
        int ans=INT_MAX;
        vector<int>nmas;
        int max_poss_stab=INT_MAX;
        //O(1e5)
        for(int idx=0 ; idx<edges.size() ; idx++){
            auto &curr_edge=edges[idx];
            if(curr_edge[3]){
                if(d.union_by_size(curr_edge[0] , curr_edge[1]))return -1;
                else{  
                    ans=min(ans , curr_edge[2]);
                }
            }else{
                non_must_edges.push_back(curr_edge);
            }
        }
        //O(5*1e5)
        if(non_must_edges.size()>0){
            sort(non_must_edges.begin() , non_must_edges.end() , comp);
        }
        //O(1e5)
        for(int idx=0 ; idx<non_must_edges.size() ;  idx++){
            auto &curr_edge=non_must_edges[idx];
            if(d.union_by_size(curr_edge[0] , curr_edge[1]))continue;
            else{
                nmas.push_back(curr_edge[2]);
            }
        }
        //O(1e5)
        for(int idx=nmas.size()-1 ; idx>=0 && k>0 ; idx--){
            nmas[idx] *= 2;
            k--;
        }
        if(d.total_comp>1)return -1;
        if(nmas.size()>0)ans = min(ans , *min_element(nmas.begin() , nmas.end()));
        return ans;
    }
};