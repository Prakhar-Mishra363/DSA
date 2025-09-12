class Solution {
public:
    bool doesAliceWin(string s) {
        bool ans = false;
        int turn=1,i=0;
        unordered_set<char>ch={'a','e','i','o','u'};
        while(i<s.length()){
            int count=0;
            for(;i<s.length();i++){
                if(ch.find(s[i])!=ch.end())count++;
                if(count){
                    if(turn&1 ){
                        if(count&1){
                            turn++; 
                            ans = true;
                            i++;
                            break;
                        }
                    }else{
                        if(!count&1){
                            turn++;
                            ans = false;
                            i++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
        
    }
};