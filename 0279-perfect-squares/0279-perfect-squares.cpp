class Solution {
public:
    
    int numSquares(int tar) {
        unordered_set<int>s1;
        for(int i=0;i<101;i++){
            s1.insert(i*i);
        }
        
        for(auto itr: s1){
            if(tar == itr){
                return 1;
            }
        }
        
        for(auto itr: s1){
            if(s1.count(tar-itr)){
                return 2;
            }
        } 
            
        while(tar % 4 == 0){
            tar /= 4;
        }
        if(tar % 8 != 7) return 3;
        
        return 4;
    }
};