class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev_end = 0, rptr = 0, size = s.length(), dup_ptr=0, counter=0,max_count=0;
        unordered_map<char, int>m1;
        
        for(int i=0; i<size; i++){
            if(m1.find(s[i]) != m1.end()){
                if(counter > max_count) max_count = counter;
                dup_ptr = m1.find(s[i])->second;
                for(int j=prev_end ; j<=dup_ptr ; j++){
                    m1.erase(s[j]);
                    counter--;
                }
                prev_end = dup_ptr+1;
            }
            m1[s[i]] = i;
            counter++;
        }
        if(counter > max_count) max_count = counter;
        return max_count;
    }
};