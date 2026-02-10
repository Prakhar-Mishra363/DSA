class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& NI) {
        
        //linear search to find the correct position where the new interval should be inserted
        int pos_to_be_checked=-1;
        for(int i=0 ; i<intervals.size() ; i++){
            if(NI[0] >= intervals[i][0] && NI[0] <= intervals[i][1]){
                pos_to_be_checked = i;
                break;
            }
            //position where NI can be inserted
            else if(NI[0] < intervals[i][0]){
                pos_to_be_checked=i;
                break;
            }
        }
        if(pos_to_be_checked==-1){
            intervals.push_back(NI);
            return intervals;
        }
        cout<<pos_to_be_checked;
        if(NI[0] >= intervals[pos_to_be_checked][0] && NI[0] <= intervals[pos_to_be_checked][1]){
            int idx=pos_to_be_checked;
            if(NI[1]>intervals[pos_to_be_checked][1]){
                idx += 1;
                for( ; idx<intervals.size() ; idx++){
                    if(intervals[idx][1]<NI[1])continue;
                    else{
                        if(NI[1] < intervals[idx][0]){
                            intervals[pos_to_be_checked][1]=NI[1];
                            intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.begin()+idx);
                            return intervals;
                        }else if(NI[1] >= intervals[idx][0] && NI[1] <= intervals[idx][1]){
                            intervals[pos_to_be_checked][1]=intervals[idx][1];
                            intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.begin()+idx+1);
                            return intervals;
                        }
                    }
                }
                if(idx==intervals.size()){
                    intervals[pos_to_be_checked][1]=NI[1];
                    intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.end());
                }
            }
        }else if(NI[0] < intervals[pos_to_be_checked][0]){
            if(NI[1]<intervals[pos_to_be_checked][0]){
                intervals.insert(intervals.begin()+pos_to_be_checked , NI);
            }
            else if(NI[1]<=intervals[pos_to_be_checked][1]){
                intervals[pos_to_be_checked][0]=NI[0];
            }else{
                int idx=pos_to_be_checked+1;
                for( ; idx<intervals.size() ; idx++){
                    if(intervals[idx][1]<NI[1])continue;
                    else{
                        if(NI[1] < intervals[idx][0]){
                            intervals[pos_to_be_checked][1]=NI[1];
                            intervals[pos_to_be_checked][0]=NI[0];
                            intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.begin()+idx);
                            return intervals;
                        }else if(NI[1] >= intervals[idx][0] && NI[1] <= intervals[idx][1]){
                            intervals[pos_to_be_checked][1]=intervals[idx][1];
                            intervals[pos_to_be_checked][0]=NI[0];
                            intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.begin()+idx+1);
                            return intervals;
                        }
                    }
                }
                if(idx==intervals.size()){
                    intervals[pos_to_be_checked][0]=NI[0];
                    intervals[pos_to_be_checked][1]=NI[1];
                    intervals.erase(intervals.begin()+pos_to_be_checked+1 , intervals.end());
                }
            }
        }
        return intervals;;
    }
};