class Solution {
public:
    vector<int>arr;
    int t, ans=-1;
    
    void bs(int left, int right){
        int middle = (left+right)/2;
        if(arr[middle]==t){
            ans = middle;
            return;
        }
        if(left <= right){
            if(t>arr[middle]){
                bs(middle+1,right);
            }else{
                bs(left,middle-1);
            }
        }
        return;
    }
    
    void finder(int left, int right){
        int middle = (left+right)/2;
        if(arr[middle]==t){
            ans = middle;
            return;
        }
        if(arr[left] < arr[right]){
            bs(left,right);
            return;
        }
        if(arr[middle]<arr[right] && (t > arr[middle] && t <= arr[right])){
            bs(middle+1,right);
            return;
        }else if(arr[middle]<arr[right]){
            if(t >= arr[left] || t < arr[middle]){
                if(middle-1 >= left)
                    finder(left, middle-1);
            }
            return;
        }else if(arr[left]<arr[middle] && (t >= arr[left] && t < arr[middle])){
            bs(left,middle-1);
            return;
        }else{
            if(t>arr[middle] || t<=arr[right]){
                if(middle+1 <= right)
                    finder(middle+1,right);
            }
            return;
        }
        return;
    }
    
    
    int search(vector<int>& nums, int target) {
        arr = nums;
        t = target;
        int left_i=0,right_i=nums.size()-1;
        if(left_i==right_i){
            if(arr[left_i] == target) return left_i;
            return -1;
        }
        if(arr[left_i] == target) return left_i;
        if(arr[right_i] == target) return right_i;
        
        if(target > arr[right_i] && target < arr[left_i]) return -1;
        
        
        finder(left_i, right_i);
        return ans;
    }
};