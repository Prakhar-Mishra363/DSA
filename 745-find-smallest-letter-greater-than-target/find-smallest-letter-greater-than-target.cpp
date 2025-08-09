class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0,end=letters.size()-1;
        char ans;
        while(start<=end){
            int mid = start+(end-start)/2;
            if((mid!=letters.size()-1)&&((letters[mid]==target)&&(letters[mid+1]!=target))){
                return letters[mid+1];
            }else if((mid!=0)&&(letters[mid]>target)&&(letters[mid-1]<target)){
                // end=mid-1;
                return letters[mid];
            }else if(letters[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }return letters[0];
    }
};