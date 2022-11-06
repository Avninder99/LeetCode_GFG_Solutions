class Solution {
public:
    string orderlyQueue(string s, int k) {
        // basic brute force
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string minSt=s, t=s;
        for(int i=0;i<s.length();i++){
            t += t[0];
            t = t.erase(0,1);
            if(lexicographical_compare(t.begin(), t.end(), minSt.begin(), minSt.end())){
                minSt = t;
            }
        }
        return minSt;
    }
};