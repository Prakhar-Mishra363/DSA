class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        int idx1=a.size()-1;
        int idx2=b.size()-1;
        string result="";
        while(idx1>=0 && idx2>=0 ){
            if((a[idx1]=='1' && b[idx2]=='0' && carry=='0') || 
                (a[idx1]=='0' && b[idx2]=='1' && carry=='0') || (a[idx1]=='0' && b[idx2]=='0' && carry=='1')){
                result += '1';
                carry='0';
            }
            else if((a[idx1]=='1' && b[idx2]=='1' && carry=='0') || (a[idx1]=='1' && b[idx2]=='0' && carry=='1')
                    || (a[idx1]=='0' && b[idx2]=='1' && carry=='1')){
                result += '0' ;
                carry='1';
            }
            else if(a[idx1]=='0' && b[idx2]=='0' && carry=='0'){
                result += '0';
            }
            else{
                result += '1';
                carry='1';
            }
            idx1--;
            idx2--;
        }
        while(idx1>=0){
            if(carry=='1'){
                if(a[idx1]=='1'){
                    result += '0' ;
                    carry='1';
                }else{
                    result += '1';
                    carry=0;
                }
            }else{
                result += a[idx1];
            }
            idx1--;
        }
        while(idx2>=0){
            if(carry=='1'){
                if(b[idx2]=='1'){
                    result += '0';
                    carry='1';
                }else{
                    result += '1';
                    carry=0;
                }
            }else{
                result += b[idx2];
            }
            idx2--;
        }
        if(carry=='1')result += '1';
        reverse(result.begin(),result.end());
        return result;
    }
};