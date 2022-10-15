class Solution {
public:
    int compress(vector<char>& c) {
        c.push_back(' ');
        int size = c.size(), tc=1, ptr=0;
        char prev = c[0];
        for(int i=1;i<size;i++){
            if(c[i] == prev){
                tc++;
            }else{
                c[ptr++] = prev;
                if(tc > 1){
                    string str = to_string(tc);
                    int len = str.length();
                    for(int j=0;j<len;j++){
                        c[ptr++] = str[j];
                    }
                }
                tc=1;
                prev = c[i];
            }
        }
        return ptr;
    }
};