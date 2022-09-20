class Solution {
public:
    void func(vector<int>&n, int size, int i, int j, int &k, int &val){
        int si=i, sj=j, t, ptr = i;
        i++;
        while(i<j){
            if(i < j && n[i] <= n[ptr]) i++;
            if(j > i && n[j] >= n[ptr]) j--;
            if(i>=j) break;
            if(n[i] <= n[ptr] && n[j] > n[ptr]){
                t = n[i];
                n[i] = n[j];
                i++;
                n[j] = t;
                j--;
            }
        }
        t = n[j], n[j] = n[ptr], n[ptr] = t;
        if(j+1 == k){
            val = n[j];
        }else if(j+1 < k){
            func(n, size, j+1, sj, k, val);
        }else{
            func(n, size, si, j-1, k, val);
        }
        return;
    }
    int findKthLargest(vector<int>& n, int k) {
        // n.push_back(INT_MAX);
        // int size = n.size(), val;
        // k = size-k;
        // func(n, size, 0, size-1, k, val);
        // return val;
        int size = n.size();
        nth_element(n.begin(), n.begin()+size-k, n.end());
	    return n[size-k];
    }
};