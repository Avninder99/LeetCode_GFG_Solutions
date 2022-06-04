class Solution {
public:
    vector<vector<string>>v1;
    map<int,string>m1;
    
    void map_create(int n){
        string s1;
        for(int i=0;i<n;i++){
            s1 += '.';
        }
        for(int i=0;i<n;i++){
            s1[i] = 'Q';
            m1.insert({i+1, s1});
            s1[i] = '.';
        }
    }
    
    bool dia_check(int lvl, vector<int>v2, int pos){    // this check vertically and diagonals
        for(int i=0;i<lvl;i++){
            if(v2[lvl-1-i] == pos || v2[lvl-1-i] == pos-(i+1) || v2[lvl-1-i] == pos+(i+1)) return false;
        }
        return true;
    }
    
    void func1(int lvl, vector<int>v2, int n){
        if(lvl == n){
            vector<string>v3;
            for(int i=0;i<n;i++){
                v3.push_back(m1.find(v2[i])->second);
            }
            v1.push_back(v3);
            return;
        }
        
        for(int i=1;i<=n;i++){
            if(dia_check(lvl,v2,i)){
                v2.push_back(i);
                func1(lvl+1,v2,n);
                v2.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        map_create(n);
        vector<int>v2;
        func1(0,v2,n);
        return v1;
    }
};