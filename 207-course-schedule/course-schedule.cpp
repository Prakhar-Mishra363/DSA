class Solution {
public:
    bool isCycle(vector<list<int>>& graph, vector<bool>& vis,int i,vector<bool>&recPath){
        vis[i]=true;
        recPath[i]=true;
        for(auto &it:graph[i]){
            if(!vis[it]){
                if(isCycle(graph,vis,it,recPath)) return true;
            }else{
                if(recPath[it])return true;
            }
        }
        recPath[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>>graph(numCourses);
        //creating the graph
        for(int i = 0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        //using cycle detection now
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(graph,vis,i,recPath))return false;
            }
        }
        return true;
    }
};