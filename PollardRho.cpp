bool millerTest(ll d, ll s, ll n)
{
    ll a = rand() % (n-4) + 2;
    ll x = Mod(a, s, n);
 
    if (x==1 or x==n-1)
        return true;
 
    for (int r = 1; r < d; r++)
    {
        x = mulMod(x, x, n);
 
        if (x==1)
            return false;
        if (x==n-1)
            return true;
    }
    return false;
}
 
 
 
bool isPrime(ll n, int k = 20)
{
    if (n <= 1 || n==4)
        return false;
    if (n<=3)
        return true;
    if (n%2==0)
        return false;
 
    ll s = n-1, d = 0;
    while (s%2==0)
    {
        s/=2;
        d++;
    }
    for (int i = 0; i < k; i++)
    {
        if (millerTest(d, s, n)==false)
            return false;
    }
    return true;
}
 
map <ll, ll> MAP;
 
ll pollard_rho(ll n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;
 
    ll x = rand()%n+1;
    ll c = rand()%n+1;
    ll y = x;
    ll g = 1;
 
    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = (mulMod(x, x, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        y = (mulMod(y, y, n) + c)%n;
        g = gcd(abs_val(x-y),n);
    }
    return g;
}
 
void factorize(ll n)   //fn to factorize the number
{
    if(n == 1)
        return;
 
    if(isPrime(n))      //if n is prime,store it
    {
        MAP[n]++;
        return;
    }
    ll divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}
