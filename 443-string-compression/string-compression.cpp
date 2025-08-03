class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        for(int i=0;i<chars.size();){
            char currChar = chars[i];
            int count = 0;
            while((i<chars.size())&&(chars[i]==currChar)){
                count++;
                i++;
            }
            if(count==1){
                chars[idx++]=currChar;
            }else{
                chars[idx++]=currChar;
                string s = to_string(count);
                for(char digit:s){
                    chars[idx++]=digit;
                }
            }
        }
        return idx;
    }
};