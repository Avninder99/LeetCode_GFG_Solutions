class Solution {
public:
    int counter = 0;
    
    bool dia_check(int lvl, vector<int>v2, int pos){    // this check vertically and diagonals
        for(int i=0;i<lvl;i++){
            if(v2[lvl-1-i] == pos || v2[lvl-1-i] == pos-(i+1) || v2[lvl-1-i] == pos+(i+1)) return false;
        }
        return true;
    }
    
    void func1(int lvl, vector<int>v2, int n){
        if(lvl == n){
            counter++;
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
    
    int totalNQueens(int n) {
        vector<int>v2;
        func1(0,v2,n);
        return counter;
    }
};