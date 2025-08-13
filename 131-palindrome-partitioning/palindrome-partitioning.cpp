class Solution {
public:
    bool isSafe(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }return true;
    }
    void getPar(string s,vector<vector<string>>& ans,vector<string>& partition){
        if(s.size()==0){
            ans.push_back({partition});
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isSafe(part)){
                partition.push_back(part);
                getPar(s.substr(i+1),ans,partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        getPar(s,ans,partition);
        return ans;
    }
};