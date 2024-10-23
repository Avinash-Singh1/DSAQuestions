class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l =0; int r=0;
        int n =s.size(); int maxlen=0;
        if(n==0)return 0;
        map<char,int>hash;

        while(r<n){
           
           if(hash.find(s[r])!= hash.end() && hash[s[r]]>=l)
             l= hash[s[r]]+1;
           

           int  len = r-l+1;
           maxlen=max(maxlen,len);
           hash[s[r]]=r;
           r++;
        }
        return maxlen;
    }
};