//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int>temp;
	    unordered_map<int, int>m1;
	    for(int i=0;i<nums.size();i++){
	        m1[nums[i]] = i;
	        temp.push_back(nums[i]);
	    }
	    sort(temp.begin(), temp.end());
	    int ans = 0;
	    for(int i=0;i<nums.size();i++){
	        if(nums[i] != temp[i]){
	            int cvInd = m1[temp[i]], orgH = nums[i];
	            nums[i] = nums[cvInd];
	            m1[temp[i]] = i;
	            
	            nums[cvInd] = orgH;
	            m1[orgH] = cvInd;
	            
	            ans++;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends