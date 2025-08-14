class Solution {
public:
    bool solver(string s){
        int j=2,i=0;
        while(j){
            if(s[i]!=s[i+1])return false;
            j--;i++;
        }
        return true;
    }
    string largestGoodInteger(string num) {
        string ans;
        char ch;
        char larger='0';
        for(int i=0;i<num.length()-1;){
            bool isExecuted=false;
            ch=num[i];
            if(ch!=num[i+1])i++;
            else{
                if(solver(num.substr(i,3))){
                    if(larger<=num[i]){
                        ans = num.substr(i,3);
                        larger = num[i];
                        i=i+3;
                        isExecuted=true;
                    }
                }
                if(!isExecuted)i++;
            } 
                
        }
        return ans;
    }
};