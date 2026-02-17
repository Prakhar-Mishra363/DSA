class Solution {
public:
    int candy(vector<int>& r) {
        vector<int>distri(r.size(),0);
        int candy=1;
        distri[0]=1;
        for(int idx=1 ; idx<r.size() ; idx++){
            if(r[idx]>r[idx-1])candy+=1;
            else candy=1;
            distri[idx]=candy;
        }
        candy=1;
        for(int idx=r.size()-2 ; idx>=0 ; idx--){
            if(r[idx]>r[idx+1])candy+=1;
            else candy=1;
            distri[idx]=max(distri[idx],candy);
        }
        return accumulate(distri.begin(),distri.end(),0);
    }
};