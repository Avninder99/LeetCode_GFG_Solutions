class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>m1, m2;
        pair<int,int>p1 = {-1, 1000000};
        // loop to setup both of the maps
        int ts = t.length();
        for(int i=0;i<ts;i++){
            m1[t[i]] += 1;
            m2[t[i]] = 0;
        }
        if(m2.find(s[0]) != m2.end()) m2[s[0]]++;
        
        int l=0,r=0;
        while(l<=r){
            // for comparision
            bool matched = true;
            for(auto itr: m2){
                if(itr.second < m1[itr.first]){
                    matched = false;
                    continue;
                }
            }
            // if matched then save the l,r pair
            // and inc the l and remove the char
            // from m2 map if it exist in it
            if(matched){
                if(p1.second > r-l) p1 = {l,r-l};
                if(m2.find(s[l]) != m2.end()) m2[s[l]]--;
                l++;
            }else{
                if(r == s.length()-1) break;
                r++;
                if(m2.find(s[r]) != m2.end()) m2[s[r]]++;
            }
        }
        if(p1.first > -1) return s.substr(p1.first, p1.second + 1);
        return "";
    }
};