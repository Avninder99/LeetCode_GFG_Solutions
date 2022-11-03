class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>m1;
        int counter=0;
        for(auto itr: words){
            string t = itr;
            // cout << t << endl;
            reverse(t.begin(), t.end());
            // cout << t << endl;
            if(m1[t] > 0){
                m1[t] -= 1;
                counter+=4;
            }else{
                m1[itr]+=1;
            }
        }
        for(int i=0;i<26;i++){
            string t = "  ";
            t[0]=(char)(i+'a'), t[1]=(char)(i+'a');
            if(m1[t] == 1){
                counter+=2;
                break;
            }
        }
        return counter;
    }
};