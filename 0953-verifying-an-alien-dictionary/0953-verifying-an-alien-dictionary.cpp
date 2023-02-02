class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o) {
        vector<int>rec(26);
        for(int i=0;i<o.length();i++){
            rec[(int)o[i] - 97] = i;
        }
        
        bool lOrdered, same;
        int len, ws = w.size();
        for(int i=0;i<(ws-1);i++){
            lOrdered = w[i].length() <= w[i+1].length();
            len = min(w[i].length(), w[i+1].length());
            
            same = true;
            for(int j=0;j<len;j++){
                if(w[i][j] != w[i+1][j]){
                    same = false;
                    if(rec[w[i][j] - 'a'] > rec[w[i+1][j] - 'a']){
                        return false;
                    }
                    break;
                }
            }
            if(same && !lOrdered){
                return false;
            }
        }
        return true;
    }
};