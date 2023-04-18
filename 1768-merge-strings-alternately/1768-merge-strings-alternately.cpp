class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int i = 0, j = 0, l1 = w1.length(), l2 = w2.length();
        while(i < l1 || j < l2){
            if(i < l1){
                res.push_back(w1[i++]);
            }
            if(j < l2){
                res.push_back(w2[j++]);
            }
        }
        return res;
    }
};