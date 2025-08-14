class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        // if((i-1>=0)&&(arr[i]==arr[i-1])){}
        int i=0,j=1;
        while(j<arr.size()){
            if(arr[i]==arr[j])j++;
            else{
                i++;
                arr[i]=arr[j];
            }
        }return i+1;
    }
};