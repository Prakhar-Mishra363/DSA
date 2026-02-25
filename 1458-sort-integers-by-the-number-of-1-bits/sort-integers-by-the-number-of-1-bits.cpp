bool comp(int a1 , int a2){
    if(__builtin_popcount(a1)<__builtin_popcount(a2))return true;
    return false;
}
class Solution {
public:
    int partition(int start , int end , vector<int> &arr){
        int key=__builtin_popcount(arr[end]);
        int i=start-1 , j=start;
        while(j<end){
            int curr=__builtin_popcount(arr[j]);
            if(curr<key){
                i++;
                swap(arr[i],arr[j]);
            }else if(curr==key){
                if(arr[j]<=arr[end]){
                    i++;
                    swap(arr[i],arr[j]);
                }
            }
            j++;
        }
        swap(arr[i+1] , arr[end]);
        return i+1;
    }
    void QuickSort(int start , int end , vector<int> &arr){
        if(start<end){
            int pivot=partition(start , end , arr);
            QuickSort(start , pivot-1 , arr);
            QuickSort(pivot+1 , end , arr);
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        QuickSort(0 , arr.size()-1 , arr);
        return arr;
    }
};