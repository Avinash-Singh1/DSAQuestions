class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size(); 
        int maxlen =0;
        for( int i =0;i <n; i++){
             vector<int> hash(26, 0); 
              int maxf = 0;
            for( int j =i;j<n;j++){
                hash[s[j]-'A']++;
                maxf =max(maxf,hash[s[j]-'A']);
                int len =(j-i+1);
                int noofchanges= len-maxf;
                if(noofchanges<=k){
                    maxlen=max(len,maxlen);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
};

// better and optimal 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size(); 
        // int maxlen =0;
        // for( int i =0;i <n; i++){
        //      vector<int> hash(26, 0); 
        //       int maxf = 0;
        //     for( int j =i;j<n;j++){
        //         hash[s[j]-'A']++;
        //         maxf =max(maxf,hash[s[j]-'A']);
        //         int len =(j-i+1);
        //         int noofchanges= len-maxf;
        //         if(noofchanges<=k){
        //             maxlen=max(len,maxlen);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;

        //better 
        int maxlen =0; int maxf =0;  vector<int> hash(26, 0); 
        int l =0; int r=0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf =max(maxf,hash[s[r]-'A']);
            int noof_convertion= (r-l+1)-maxf;
            if(noof_convertion>k){
            // while(noof_convertion>k){
                hash[s[l]-'A']--;
                maxf=0;
              //  for( int i=0;i<=26;i++) maxf =max(maxf,hash[i]);
                l++;
            }

            if(noof_convertion<=k){
                 maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

    }
};

