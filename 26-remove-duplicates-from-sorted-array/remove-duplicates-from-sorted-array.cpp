class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        // if((i-1>=0)&&(arr[i]==arr[i-1])){}
        for(int i=0;i<arr.size();i++){
            int count=0;
            int j=i;
            while((j+1<arr.size())&&arr[j]==arr[j+1]){
                count++;
                j++;
            }
            while(count){
                for(int j=i;j<arr.size()-1;j++){
                    arr[j]=arr[j+1];
                }arr.pop_back();
                count--;
            }
        }return arr.size();
    }
};