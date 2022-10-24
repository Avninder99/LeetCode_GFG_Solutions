class Solution {
public:
    int func(vector<vector<int>>&m, vector<int>h, int ptr, int size, int hc){
        if(ptr >= size) return hc;
        int t1=0, t2=0;
        // don't consider current string
        t1 = func(m, h, ptr+1, size, hc);
        if(m[ptr][0] == 2) return t1;
        bool unique = true;
        for(int i=0;i<26;i++){
            if(m[ptr][i] == 1){
                if(h[i] == 1){
                    unique = false;
                    break;    
                }else{
                    h[i] = 1;
                    hc++;
                }
            }
        }
        if(unique) t2 = func(m, h, ptr+1, size, hc);    // consider current string
        return max(t1, t2);
    }
    int maxLength(vector<string>& a) {
        vector<vector<int>>v1 (a.size(), vector<int>(26, 0));
        int c;
        for(int i=0;i<a.size();i++){
            c=0;
            for(int j=0;j<a[i].length();j++){
                if(v1[i][((int)a[i][j])-97] == 1){
                    v1[i][0] = 2;
                    break;
                }
                v1[i][((int)a[i][j])-97] = 1;
            }
        }
        vector<int>h(26, 0);
        return func(v1, h, 0, a.size(), 0);
    }
};