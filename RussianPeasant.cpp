ll modmul(ll a, ll b, ll n){
   ll res = 0;
   for(;b; b>>=1, a <<=1){
       if(a>=n) a-=n;
       if(b&1){
           res+=a;
           if(res>=n) res-=n;
       }
   }
