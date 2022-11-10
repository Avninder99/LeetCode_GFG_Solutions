class cmp {
    public:
    constexpr bool operator()(pair<int, string> const& a, pair<int, string> const& b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};
class FoodRatings {
public:
    // food => < cuisine, rating >
    unordered_map<string, pair<string, int>>rateM;
    
    // cuisine => priority_queue < rating, food >
    unordered_map<string, priority_queue< pair<int, string>, vector< pair<int, string> >, cmp > >cusM;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int size = f.size();
        for(int i=0;i<size;i++){
            rateM[f[i]] = make_pair(c[i], r[i]);
            cusM[c[i]].push(make_pair(r[i], f[i]));
        }
    }
    
    void changeRating(string f, int nr) {
        rateM[f].second = nr;
        cusM[rateM[f].first].push(make_pair(nr, f));
    }
    
    string highestRated(string c) {
        // remove any invalid values from top of priority queue
        while(rateM[ cusM[c].top().second ].second != cusM[c].top().first){
            cusM[c].pop();
        }
        return cusM[c].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */