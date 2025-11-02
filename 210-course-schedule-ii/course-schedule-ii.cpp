class Solution {
public:
    bool detectCycle(vector<list<int>>&graph,vector<bool>&vis,int src,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        for(auto it:graph[src]){
            if(!vis[it]){
                if(detectCycle(graph,vis,it,recPath))return true;
            }else{
                if(recPath[it])return true;
            }
        }
        recPath[src] = false;
        return false;
    }
    bool isCycle(vector<list<int>>&graph){
        vector<bool>vis(graph.size(),false);
        vector<bool>recPath(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                if(detectCycle(graph,vis,i,recPath))return true;
            }
        }
        return false;
    }
    void topoSort(vector<list<int>>&graph,vector<bool>&vis,stack<int>&res,int src){
        vis[src] = true;
        for(auto it:graph[src]){
            if(!vis[it]){
                topoSort(graph,vis,res,it);
            }
        }
        res.push(src); 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>>graph(numCourses);
        //creating graph 
        for(int i = 0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>vis(numCourses,false);
        stack<int>temp;
        vector<int>result;
        if(isCycle(graph))return {};
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topoSort(graph,vis,temp,i);
            }
        }
        while(!temp.empty()){
            result.push_back(temp.top());
            temp.pop();
        }
        return result;
    }
};