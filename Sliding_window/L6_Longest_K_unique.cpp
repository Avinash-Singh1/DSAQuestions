class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
     int n =s.length();
     int l=0; int r =0; int maxlen =-1; map<char,int> mpp;
     while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
          mpp[s[l]]--;
          if(mpp[s[l]]==0){
              mpp.erase(s[l]);
          }
          l++;
        }
        
        if(mpp.size()==k){
            int len =r-l+1;
            maxlen=max(maxlen,len);
        }
        r++;
     }
     return maxlen;
    }
};