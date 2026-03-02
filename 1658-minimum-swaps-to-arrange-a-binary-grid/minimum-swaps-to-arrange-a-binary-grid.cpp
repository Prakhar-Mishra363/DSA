class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int swaps_required=0 , n=grid.size();
        vector<int>freq(n,0);
        for(int row=0 ; row<n ; row++){
            int curr_zeroes=0;
            for(int col=n-1 ; col>=0 ; col--){
                if(!grid[row][col])curr_zeroes++;
                else break;
            }
            freq[row]=curr_zeroes;
        }
        // for(auto a:freq)cout<<a<<" ";
        // cout<<endl;
        for(int row=0 ; row<n-1 ; row++){
            if(freq[row]<n-row-1){
                for(int col=row+1 ; col<n ; col++){
                    if(freq[col]>=n-row-1){
                        swaps_required += (col-row);
                        swap(freq[row],freq[col]);
                        swap(grid[row],grid[col]);
                        break;
                    }else{
                        swap(freq[row],freq[col]);
                        swap(grid[row],grid[col]);
                    }
                }
            }
        }
        for(int row=0 ; row<n ; row++){
            for(int col=n-1 ; col>row ; col--){
                if(grid[row][col])return -1;
            }
        }
        return swaps_required;

        
    }
};