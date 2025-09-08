class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10)return -1;
        vector<int>store;
        int num = n;
        while(num>0){
            store.push_back(num%10);
            num/=10;
        }
        reverse(store.begin(),store.end());
        int pivot = -1,end=store.size()-1;//find the element which is not in decreaseing order from the back
        for(int i=end-1;i>=0;i--){
            if(store[i]<store[i+1]){
                pivot = i;break;
            }
        }
        long ans = 0;
        if(pivot==-1)return -1;
        for(int i=end;i>=0;i--){
            if(store[i]>store[pivot]){
                swap(store[i],store[pivot]);
                break;
            }
        }
        for(int i=pivot+1,j=end;i<j;){
            swap(store[i++],store[j--]);
        }
        for(int i=0;i<store.size();i++){
            ans = ans*10+store[i];
        }
        if(ans>INT_MAX || ans<=n)return -1;
        return ans;
    }
};