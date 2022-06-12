class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size(), fsum=0, bsum=0, ans1=-1, ans2=-1, ans3=-1;
        vector<int>l;
        unordered_map<int,int>r;
        for(int i=0;i<size;i++){
            fsum += nums[i];
            l.push_back(fsum);
            bsum += nums[size - 1 - i];
            r.insert({bsum,i});
            if(fsum == x || bsum == x){
                if(ans1 == -1) ans1 = i+1;
            }
        }
        for(int i=0;i<size;i++){
            auto itr = r.find(x-l[i]);
            if(itr != r.end() && itr->second < (size - i - 1)){
                if(ans2 == -1 || ans2 > i + itr->second + 2)
                        ans2 = i + itr->second + 2;
            }
        }
        if(ans1 >= 0 && ans2 >= 0) return min(ans1, ans2);
        else if(ans1 >= 0) return ans1;
        else return ans2;
    }
};