class Solution {
public:
    int helper(int idx , string s , vector<bool> &isCarry){
        if(idx==s.size()-1){
            if(s[idx]=='1'){
                isCarry[idx]=true;
                return 2;
            }
            return 1;
        }
        int cal_steps = helper(idx+1 , s , isCarry);
        if(isCarry[idx+1]){
            if(s[idx]=='1') cal_steps += 1;
            else cal_steps += 2;
            isCarry[idx]=true;
        }else{
            if(s[idx]=='1'){
                isCarry[idx]=true;
                cal_steps += 2;
            }else{
                cal_steps += 1;
            }
        }
        return  cal_steps;
    }
    int numSteps(string s) {
        int n=s.size() , cal_steps=0;
        vector<bool>isCarry(s.size() , false);

        // return helper(0 , s , isCarry);
        if(s[n-1]=='1' && (n-1)>0){
            cal_steps += 2;
            isCarry[n-1]=true;
        }else cal_steps += ((n-1)>0) ? 1 : 0;
        for(int idx=n-2 ; idx>=0 ; idx--){
            if(!isCarry[idx+1] && idx==0)continue;
            if(isCarry[idx+1]){
                if(s[idx]=='1') cal_steps += 1;
                else cal_steps += 2;
                isCarry[idx]=true;
            }else{
                if(s[idx]=='1' && idx>0){
                    isCarry[idx]=true;
                    cal_steps += 2;
                }else{
                    cal_steps += 1;
                }
            }
        }
        return cal_steps;
    }
};