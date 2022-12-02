class Solution {
public:
    bool closeStrings(string w1, string w2) {
        
        // we return true when our strings matches according to the two given condition
        // the first condition is just related to the ordering so all we need to make sure is that all the characters
        // that exist in word 1 must exist in word 2 and length of both words should be same
        
        // we will look at the number of occurances of each character indivizually later on.
        
        // now lets check out second condition - the other way of seeing this is that
        // we are swapping the number of occurnces of 2 characters
        // so what we need for a making the strings close is that we should have the same number of occurances
        // along with same value
        
        // for eg - in example 3
        // word 1 -> cabbba , word 2 -> abbccc
        // look how there is 1 character is occuring 1 time then 2 times then 3 times
        // (Note - repetition of occurances is allowed)
        
        if(w1.length() != w2.length()){
            return false;
        }
        unordered_set<char>holder;
        vector<int> occurances1(26, 0), occurances2(26, 0);
        for(int i=0;i<w1.length();i++){
            holder.insert(w1[i]);
            occurances1[ (int)w1[i] - 97 ]++;
        }
        for(int i=0;i<w2.length();i++){
            holder.erase(w2[i]);
            occurances2[ (int)w2[i] - 97 ]++;
        }
        if(!holder.empty()){
            return false;
        }
        sort(occurances1.begin(), occurances1.end());
        sort(occurances2.begin(), occurances2.end());
        
        for(int i=0;i<26;i++){
            if(occurances1[i] != occurances2[i]){
                return false;
            }
        }
        return true;
    }
};