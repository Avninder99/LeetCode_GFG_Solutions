```
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
if(k == 1){
return nums;
}
O(K * N) solution (TLE) on large test cases with descending order of elements
int lptr = 0, rptr = k-1, mEI = 0, size = nums.size();
for(int i=lptr;i<=rptr;i++){
if(nums[i] >= nums[mEI]){
mEI = i;
}
}
vector<int>res(size - k + 1);
int itr = 0;
res[itr++] = nums[mEI];
while(rptr < size-1){
lptr++;
rptr++;
if(mEI < lptr){
mEI = lptr;
for(int i=lptr;i<=rptr;i++){
if(nums[i] >= nums[mEI]){
mEI = i;
}
}
}
if(nums[mEI] <= nums[rptr]){
mEI = rptr;
}
res[itr++] = nums[mEI];
}
return res;
}
```