class Solution {
public:
    int operations_req(bool is_zero , string &s){
        int operations=0;
        for(int idx=0 ; idx<s.size() ; idx++){
            if(is_zero && s[idx]=='0' || !is_zero && s[idx]=='1')operations++;
            is_zero=!is_zero;
        }
        return operations;
    }
    int minOperations(string s) {
        int min_operations=0;
        min_operations=operations_req(false,s);
        int leading_one=operations_req(true,s);
        return min_operations<leading_one ? min_operations : leading_one;
    }
};