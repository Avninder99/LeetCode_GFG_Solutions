class UndergroundSystem {
public:
    map<int,pair<string,int>>check_in;
    
    map<string,pair<long long int,int>>travel_time;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if(check_in.find(id) == check_in.end()){
            check_in.insert({id, {stationName, t}});
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if(check_in.find(id) != check_in.end()){
            auto itr = check_in.find(id);
            int timeTaken = t - itr->second.second;
            string startStation = itr->second.first;
            
            string name = startStation+"_"+stationName;
            if(travel_time.find(name) != travel_time.end()){
                auto itr2 = travel_time.find(name);
                itr2->second.second += 1;
                itr2->second.first += timeTaken;
            }else{
                travel_time.insert({name,{timeTaken,1}});
            }
            check_in.erase(id);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string name = startStation + "_" + endStation;
        auto itr3 = travel_time.find(name);
        long double res = (long double)itr3->second.first / (long double)itr3->second.second;
        return res;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */