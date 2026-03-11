class Solution {
public:
    int minFlips(int a, int b, int c) {
        int place=0 , minimum_flips_req=0;
        int curr_bit = 1<<place;
        while((curr_bit <= c) || (curr_bit <= a) || (curr_bit <= b)){
            if((curr_bit & c)){
                if(!(curr_bit & a) && !(curr_bit & b))minimum_flips_req++;
            }else{
                if( (curr_bit & a) && (curr_bit & b))minimum_flips_req += 2;
                else if( (curr_bit & a) || (curr_bit & b) )minimum_flips_req += 1;
            }
            place++;
            curr_bit = 1<<place;
        }
        return minimum_flips_req;
    }
};