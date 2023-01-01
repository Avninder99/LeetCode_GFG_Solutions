class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<char, string>m1;
        unordered_map<string, char>m2;
        s += ' ';
        int len1 = p.length(), len2 = s.length(), scount=0;
        string temp;
        for(int i=0;i<len2;i++){
            if(s[i] == ' '){
                if(m1.find(p[scount]) != m1.end() || m2.find(temp) != m2.end()){
                    if(m1[p[scount]] != temp || m2[temp] != p[scount]) return false; 
                }else{
                    m1[p[scount]] = temp;
                    m2[temp] = p[scount];
                }
                temp = "";
                scount++;
            }else{
                temp += s[i];
            }
        }
        if(scount != len1) return false;
        return true;
    }
};