class Solution {
public:
    int binaryGap(int n) {
        string s="";
        while(n){
            int rem=n%2;
            s += rem+'0';
            n /= 2;
        }
        reverse(s.begin(),s.end());
        int prev_one=-1 , max_dis=0;
        for(int idx=0 ; idx<s.size() ; idx++){
            if(s[idx]=='1'){
                if(prev_one!=-1){
                    max_dis=max(max_dis,idx-prev_one);
                }
                prev_one=idx;
            }
        }
        return max_dis;
    }
};