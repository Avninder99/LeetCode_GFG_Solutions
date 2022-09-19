class Solution {
public:
    string func(string &s, int &ptr){
        string s1 = "";
        int num=0;
        while(s[ptr] != ']'){
            if(isdigit(s[ptr])){
                num = (int)s[ptr]-(int)'0' + num*10;
            }
            else if(s[ptr] == '['){
                ptr++;
                string temp = func(s, ptr);
                for(int z=0;z<num;z++) s1 += temp;
                num=0;
            }else{
                s1 += s[ptr];
            }
            ptr++;
        }
        return s1;
    }
    string decodeString(string s) {
        int size = s.size(), ptr=0;
        string s1 = "";
        int num=0;
        while(ptr<size){
            if(isdigit(s[ptr])){
                num = (int)s[ptr]-(int)'0' + num*10;
            }
            else if(s[ptr] == '['){
                ptr++;
                string temp = func(s, ptr);
                for(int z=0;z<num;z++) s1 += temp;
                num=0;
            }
            else{
                s1 += s[ptr];
            }
            ptr++;
        }
        return s1;
    }
};