//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class node{
public:
    string name, email;
    vector<node*>connections;
    node(string n, string e){
        name = n, email = e;
    }
    /*
        email
        name
        connections
    */
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        unordered_map<string, node*>emailToNode;
        unordered_set<string>vis;
        
        for(auto itr: accounts){
            string name = itr[0];
            node* prev = NULL;
            for(int i=1;i<itr.size();i++){
                if(emailToNode.find(itr[i]) == emailToNode.end()){
                    node* newNode = new node(name, itr[i]);
                    emailToNode[itr[i]] = newNode;
                    if(prev){
                        newNode->connections.push_back(prev);
                        prev->connections.push_back(newNode);
                    }
                    prev = newNode;
                }else{
                    node* t = emailToNode.find(itr[i])->second;
                    if(prev){
                        t->connections.push_back(prev);
                        prev->connections.push_back(t);
                    }
                    prev = t;
                }
            }
        }
        
        vector<vector<string>>res;
        for(auto it = emailToNode.begin(); it != emailToNode.end(); it++){
            if(vis.count(it->second->email)) continue;
            
            string name = it->second->name;
            vector<string>holder(1, name);
            
            vis.insert(it->second->email);
            traverser(it->second, holder, emailToNode, vis);
            
            sort(holder.begin() + 1, holder.end());
            
            res.push_back(holder);
        }
        return res;
    }
private:
    void traverser(node* curr, vector<string>&holder, unordered_map<string, node*>&etn, unordered_set<string>&vis){
        holder.push_back(curr->email);
        for(auto itr: curr->connections){
            if(vis.count(itr->email) == 0){
                vis.insert(itr->email);
                traverser(itr, holder, etn, vis);
            }
        }
        return;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends