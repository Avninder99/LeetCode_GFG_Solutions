class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        // Time complexity - O(N)
        // 2 iterations only
        int size = arr.size(), count=0, tcount=0, iptr=0, jptr=2;
        string str = "", t = "", h1 = "", h2 = "";
        vector<int>res(2,-1);
        for(int i=0;i<size;i++){
            str += (arr[i] ? '1' : '0');
            count += arr[i];
        }
        if(count == 0){
            res[0] = 0, res[1] = size-1;
            return res;
        }
        if(count%3) return res;
        count /= 3;
        reverse(str.begin(), str.end());    // reversed the string
        //==============================================================
        
        // find first part string for future comparision
        tcount = 0;
        for(int i=0;i<size && tcount < count;i++){
            t += str[i];
            if(str[i] == '1') tcount++;
            jptr = i;
        }
        
        //==============================================================
        
        // find second string for comparision
        h1 = t, t = "";
        tcount = 0;
        for(int i=jptr+1;i<size && tcount < count;i++){
            t += str[i];
            if(str[i] == '1') tcount++;
            iptr = i;
        }
        
        if(t.length() < h1.length()) return res;
        h2 = t.substr( (t.length()-h1.length()), h1.length() );
        
        if(h1 != h2) return res;
        jptr += t.length()-h1.length();
        
        //==============================================================
        
        // find last string for comparision
        t = "";
        tcount = 0;
        for(int i=iptr+1;i<size && tcount < count;i++){
            t += str[i];
            if(str[i] == '1') tcount++;
        }
        
        if(t.length() < h1.length()) return res;
        h2 = t.substr( (t.length()-h1.length()), h1.length() );
        if(h1 != h2) return res;
        
        iptr += t.length()-h1.length();
        
        res[0] = size-1-(iptr+1);
        res[1] = size-1-jptr;
        return res;
    }
};