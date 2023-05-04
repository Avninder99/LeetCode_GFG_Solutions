class Solution {
public:
    string predictPartyVictory(string s) {
        int skipR = 0, skipD = 0, totalR = 0, totalD = 0, ptr = 0, len = s.size();
        for(auto itr: s){
            if(itr == 'R'){
                totalR++;
            }else{
                totalD++;
            }
        }
        while(totalR > 0 && totalD > 0){
            if(s[ptr] == 'R'){
                if(skipR > 0){
                    s[ptr] = 'S';
                    totalR--;
                    skipR--;
                }else{
                    skipD++;
                }
            }else if(s[ptr] == 'D'){
                if(skipD > 0){
                    s[ptr] = 'S';
                    totalD--;
                    skipD--;
                }else{
                    skipR++;
                }
            }
            ptr = (++ptr)%len;
        }
        if(totalR > 0){
            return "Radiant";
        }
        return "Dire";
    }
};