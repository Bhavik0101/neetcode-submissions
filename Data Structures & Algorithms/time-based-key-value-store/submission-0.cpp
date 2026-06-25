class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,vector<pair<int,string>>>mpp;
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp)  {
         string ans="";
        if(mpp.find(key)!=mpp.end()){
            
           
            int low=0;
            int high=mpp[key].size()-1;
            int mid;
           
            while(low<=high){
                mid=(low+high)/2;
                if(mpp[key][mid].first==timestamp) return mpp[key][mid].second;
                else if(mpp[key][mid].first>timestamp) high=mid-1;
                else{
                    ans=mpp[key][mid].second;
                    low=mid+1;
                }
          
            }
           
        }
         return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */