class Solution {
public:
    vector<vector<char>>v1;
    vector<string>v2;
    
    void func1(string d, int d_size, int itr, string str1){
        if(itr==d_size){
            v2.push_back(str1);
            return;
        }
        
        for(int i=0;i<( v1[ ( d[itr]-50 ) ].size() );i++){
            str1.push_back( v1[ ( d[itr]-50 ) ][i] );
            func1(d, d_size, itr+1, str1);
            str1.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        v1.push_back({'a','b','c'});
        v1.push_back({'d','e','f'});
        v1.push_back({'g','h','i'});
        v1.push_back({'j','k','l'});
        v1.push_back({'m','n','o'});
        v1.push_back({'p','q','r','s'});
        v1.push_back({'t','u','v'});
        v1.push_back({'w','x','y','z'});
        
        if(digits.length() == 0) return v2;
        
        func1(digits, digits.length(), 0, "");
        return v2;
    }
};