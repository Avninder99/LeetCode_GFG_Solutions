class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        queue<char>q1;
        int itr=0, size = sp.size();
        for(int i=0;i<size;i++) s.push_back('#');
        for(int i=0;i<s.length();i++){
            if(itr < size && i == sp[itr]+itr){
                q1.push(s[i]);
                s[i] = ' ';
                itr++;
            }else if(!q1.empty()){
                q1.push(s[i]);
                s[i] = q1.front();
                q1.pop();
            }
        }
        return s;
    }
};