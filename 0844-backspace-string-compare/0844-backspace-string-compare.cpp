class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int size1 = s.size(), size2 = t.size();
        
        int counter = 0;
        for(int i=size1-1;i>=0;i--){
            if(s[i] == '#'){
                counter++;
                s.erase(s.begin()+i);
            }else{
                if(counter>0){
                    s.erase(s.begin()+i);
                    counter--;
                }
            }
        }
        counter = 0;
        for(int i=size2-1;i>=0;i--){
            if(t[i] == '#'){
                counter++;
                t.erase(t.begin()+i);
            }else{
                if(counter>0){
                    t.erase(t.begin()+i);
                    counter--;
                }
            }
        }
        return s == t;
    }
};