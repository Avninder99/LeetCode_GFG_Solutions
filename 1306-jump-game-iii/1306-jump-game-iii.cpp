class Solution {
public:
    
    bool func1(vector<int> &arr, int startI, vector<int> &v1, int size){
        if(startI >= size || startI < 0 || v1[startI] == 0) return false;
        else if(arr[startI] == 0) return true;
        v1[startI] = 0;
        
        return (func1(arr, startI + arr[startI], v1, size) || func1(arr, startI - arr[startI], v1, size));
    }
    
    bool canReach(vector<int>& arr, int start) {
        int size = arr.size();
        vector<int>v1 (size, 1);
        return func1(arr, start, v1, size);
    }
};