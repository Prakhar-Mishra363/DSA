class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int val = -(n/2);
        if(n&1){
            for(int i=0;i<n;i++){
                ans.push_back(val);
                val++;
            }
        }else{
            for(int i=0;i<n+1;i++){
                if(val==0)val++;
                else{
                   ans.push_back(val);
                    val++; 
                }
            }
        }
        return ans;
    }
};