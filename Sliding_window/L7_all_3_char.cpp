// brute: 
class Solution {
public:
    int numberOfSubstrings(string s) {
       int n = s.size();
        int cnt = 0;
        map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp.clear();
            for (int j = i; j < n; j++) {
                mpp[s[j]-'a']=1;
                if (mpp[0]+mpp[1]+mpp[2]==3) {
                   // cnt++;  // Count the valid substring
                    cnt=cnt + (n-j);
                    break;
                }
            }
        }
        return cnt;
    }
};

// better
class Solution {
public:
    int numberOfSubstrings(string s) {
        // brute 
    //    int n = s.size();
    //     int cnt = 0;
    //     map<int, int> mpp;
        
    //     for (int i = 0; i < n; i++) {
    //         mpp.clear();
    //         for (int j = i; j < n; j++) {
    //             mpp[s[j]-'a']=1;
    //             if (mpp[0]+mpp[1]+mpp[2]==3) {
    //                // cnt++;  // Count the valid substring
    //                 cnt=cnt + (n-j);
    //                 break;
    //             }
    //         }
    //     }
    //     return cnt;

        // better
        int n =s.size(); vector<int>lastseen(3,-1);
        int cnt =0;
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                cnt =cnt+(1+min(lastseen[0],min(lastseen[1], lastseen[2])));
                cnt = cnt + (1 + min({lastseen[0], lastseen[1], lastseen[2]})); 

            }
        }
        return cnt;
    }
};