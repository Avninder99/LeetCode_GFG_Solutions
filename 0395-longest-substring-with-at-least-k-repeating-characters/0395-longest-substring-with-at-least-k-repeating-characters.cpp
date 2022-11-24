class Solution {
public:
    // Sliding window + recursion
    int longestSubstring(string s, int k, int end = -1, int start = 0) {
        vector<int>rec(26, 0);
        unordered_map<char, int>m1;
        if(end == -1){
            end = s.length();
        }
        for(int i=start;i<end;i++){
            rec[(int)s[i]-97]++;
        }
        int last = start, maxi = 0;
        
        for(int i=start;i<end;i++){
            if(rec[(int)s[i] - 97] < k){
                bool check = true;
                int sum = 0;
                for(auto itr: m1){
                    if(itr.second < k){
                        check = false;
                        break;
                    }
                    sum += itr.second;
                }
                m1.clear();
                if(check){
                    maxi = max(maxi, sum);    
                }else{
                    maxi = max(maxi, longestSubstring(s, k, i, last));
                }
                last = i + 1;
            }else{
                m1[s[i]]++;
            }
        }
        bool check = true;
        int sum = 0;
        for(auto itr: m1){
            if(itr.second < k){
                check = false;
                break;
            }
            sum += itr.second;
        }
        m1.clear();
        if(check){
            maxi = max(maxi, sum);
        }else{
            maxi = max(maxi, longestSubstring(s, k, end, last));
        }
        
        return maxi;
    }
};