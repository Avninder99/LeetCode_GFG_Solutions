class Solution {
public:
    int maxVowels(string s, int k) {
        int l=0, r = k-1, count = 0, maxi = 0;
        unordered_set<char>v = {'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<k;i++){
            if(v.count(s[i])){
                count++;
            }
        }
        maxi = count;
        while(r < s.length() - 1){
            if(v.count(s[l++])){
                count--;
            }
            if(v.count(s[++r])){
                count++;
            }
            cout << l << " " << r << endl;
            maxi = max(maxi, count);
        }
        return maxi;
    }
};