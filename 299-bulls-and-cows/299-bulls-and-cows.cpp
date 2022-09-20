class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char, int>m1;
        int size = s.length(), bc=0, cc=0;
        for(int i=0;i<size;i++){
            if(s[i] == g[i]) s[i] = '-', g[i] = '-', bc++;
            else m1[s[i]] += 1;
        }
        for(int i=0;i<size;i++){
            if(m1[g[i]] > 0){
                cc++;
                m1[g[i]] -= 1;
            }
        }
        return (to_string(bc) + "A" + to_string(cc) + "B");
    }
};