class Solution {
public:
    bool isSafe(int inter,int i){
        while(inter>0){
            if(inter%10==0)return false;
            inter/=10;
        }
        while(i>0){
            if(i%10==0)return false;
            i/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=0,b=0;
        for(int i=1;i<=n/2;i++){
            if(isSafe(n-i,i)){
                a=i;
                b=n-i;
                break;
            }
        }
        return {a,b};
        
    }
};