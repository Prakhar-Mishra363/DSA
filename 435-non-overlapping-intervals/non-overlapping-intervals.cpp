class Solution {
public:
    static bool comp(vector<int>a1 , vector<int>a2){
        return a1[1]<a2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),comp);
        int freeTime=inter[0][1];
        int count=0;
        for(int i=1 ; i<inter.size() ; i++){
            if(inter[i][0]>=freeTime){
                freeTime=inter[i][1];
            }else{
                count++;
            }
        }
        return count;
    }
};