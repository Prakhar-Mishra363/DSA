class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int idx1=a.size()-1 , idx2=b.size()-1;
        string result="";
        while(idx1>=0 || idx2>=0){
            int b1,b2;
            if(idx1<0)b1=0;
            else{
                b1=a[idx1]-'0'; idx1--;
            }
            if(idx2<0)b2=0;
            else{
                b2=b[idx2]-'0'; idx2--;
            }
            int sum=b1+b2+carry;
            if(sum>1)carry=1;
            else carry=0;
            sum = sum%2;
            char ch=sum+'0';
            result += ch;
        }
        if(carry)result += '1';
        reverse(result.begin(),result.end());
        return result;
    }
};