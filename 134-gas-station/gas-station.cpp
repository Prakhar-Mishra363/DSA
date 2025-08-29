class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSize=0,costSize=0;
        queue<int>q;
        for(int i=0;i<gas.size();i++){
            gasSize+=gas[i];
            costSize+=cost[i];
        }
        if(gasSize<costSize)return -1;
        int ans=0;
        int round=2;
        int n=gas.size();
        for(int i=0;i<gas.size();i=(i+1)){
            if(gas[i]>=cost[i]){
                gas[(i+1)%n]+=gas[i]-cost[i];
                if(q.empty())q.push(i);
                // break;
            }else{
                if(q.size()>0)q.pop();
            }
        }
        return q.front();
    }
};