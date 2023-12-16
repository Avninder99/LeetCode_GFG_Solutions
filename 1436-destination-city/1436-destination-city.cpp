class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Basic approach using set
        string result = "";
        unordered_set<string> citiesHolder;
        for(vector<string> path: paths) {
            citiesHolder.insert(path[1]);
        }
        for(vector<string> path: paths) {
            citiesHolder.erase(path[0]);
        }
        for(string destinationCity: citiesHolder) {
            result = destinationCity;
        }
        return result;
    }
};