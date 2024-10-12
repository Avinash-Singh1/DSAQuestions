#include <bits/stdc++.h>
using namespace std;

vector<int> getMintime(int cache_size, int cache_time, int server_time, vector<string> urls) {
   vector<int>timeTaken;
   unordered_set<string> track_url;
   queue<string>Qu;

   for(auto s: urls)
   {
    cout<<"s : "<<s<<endl;
    if(track_url.find(s)!=track_url.end()){
        timeTaken.push_back(cache_time);
    }else{
        if(Qu.size()>=cache_size){
            string fronturl_Q= Qu.front();
            Qu.pop();
            track_url.erase(fronturl_Q);
        }
        timeTaken.push_back(server_time);
        track_url.insert(s);
        Qu.push(s);
    }
      
   }

    return timeTaken;

}

int main() {
    int cache_size = 2;
    int cache_time = 2;
    int server_time = 3;
    vector<string> urls = {
        "www.google.com",
        "www.yahoo.com",
        "www.google.com",
        "www.yahoo.com",
        "www.coursera.com"
    };
    vector<int> result = getMintime(cache_size, cache_time, server_time, urls);
    
    for (int time : result) {
        cout << time << " ";
    }
    cout << endl;
    
    return 0;
}
