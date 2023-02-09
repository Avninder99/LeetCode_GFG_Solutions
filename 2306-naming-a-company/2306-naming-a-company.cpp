class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string>s1;
        for(auto itr: ideas){
            s1.insert(itr);
        }
        vector<vector<int>>safeRec(26, vector<int>(26, 0));
        for(auto itr: ideas){
            int i = (int)itr[0] - 97;
            string t = itr;
            for(int j=0;j<26;j++){
                t[0] = (char)(97+j);
                if(s1.find(t) == s1.end()){
                    safeRec[i][j]++;
                }
            }
        }
        
        long long int res = 0;
        
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                res += safeRec[i][j] * safeRec[j][i];
            }
        }
        
        return res;
    }
};