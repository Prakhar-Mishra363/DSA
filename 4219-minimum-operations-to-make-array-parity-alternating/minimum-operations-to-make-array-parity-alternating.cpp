class Solution {
public:
    vector<int> helper(bool was_odd , int mini , int maxi , vector<int> nums){
        int operations_per=0;
        bool flag = ((mini==maxi) && (nums.size() > 1)) ? true : false;
        for(int idx=0 ; idx<nums.size() ; idx++){
            if((was_odd && (nums[idx]&1)) || (!was_odd && !(nums[idx]&1))){
                if(nums[idx]==maxi && !flag)nums[idx]--;
                else if(nums[idx]==mini && !flag)nums[idx]++;
                operations_per++;
            }
            was_odd = !was_odd;
        }
        // cout<<mini<<" "<<maxi<<endl;
        mini=*min_element(nums.begin(),nums.end());
        maxi=*max_element(nums.begin(),nums.end());
        int diff=(flag) ? 1 : maxi-mini;
        // cout<<operations_per<<" "<<diff<<endl<<endl;
        return {operations_per,diff};
    }
    vector<int> makeParityAlternating(vector<int> nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        //making first element even counting the operations required
        bool was_odd=true;
        vector<int> even_result = helper(was_odd,mini,maxi,nums);
        //makeing first element odd counting the operations required
        was_odd=false;
        vector<int> odd_result = helper(was_odd,mini,maxi,nums);
        if(even_result[0]<odd_result[0])return even_result;
        else if(even_result[0]==odd_result[0])return (even_result[1]<odd_result[1]) ? even_result : odd_result;
        return odd_result;
    }
};