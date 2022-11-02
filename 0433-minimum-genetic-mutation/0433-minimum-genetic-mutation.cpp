class Solution {
public:
    int minMutation(string s, string e, vector<string>&bank) {
        if(s == e) return 0;
        else if(bank.size() == 0) return -1;
        bool sfound = false, efound=false;
        for(auto itr: bank){
            if(itr == s) sfound = true;
            else if(itr == e) efound = true;
        }
        if(!efound) return -1;
        if(!sfound) bank.push_back(s);
        queue<string>q1;
        q1.push(s);
        q1.push("Z");
        int counter=0, diffCount=0;
        while(q1.size()>1){
            if(q1.front() == e) return counter;
            
            if(q1.front() == "Z"){
                counter++;
                q1.push("Z");
                q1.pop();
                continue;
            }
            
            s = q1.front();
            q1.pop();
            
            for(int i=0;i<bank.size();i++){
                if(bank[i] == "-") continue;
                diffCount=0;
                for(int j=0;j<8;j++){
                    if(s[j] != bank[i][j]) diffCount++;
                }
                if(diffCount == 1){
                    q1.push(bank[i]);
                    bank[i] = "-";
                }
            }
        }
        return -1;
    }
};