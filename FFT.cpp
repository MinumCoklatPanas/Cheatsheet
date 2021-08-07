
// MAXN = ceil(log2(x)) where x = Maximum size of Polynomial
const int MAXN = 20;
const int MAX = (1<<MAXN);
complex<double>W[MAX], invW[MAX], F1[MAX], G1[MAX];
 
void precompute_root_of_unity(){
    for(int i = 0; i < MAX/2; i++){
        double angle = (2 * M_PI * i)/MAX;
        double _cos = cos(angle), _sin = sin(angle);
        W[i] = complex<double>(_cos,_sin);
        invW[i] = complex<double>(_cos,-_sin);
    }
}
 
void FFT(vector<complex<double>>& a,bool invert){
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,add = MAX/len;
            for (int j=0; j<len/2; ++j) {
                complex<double> u = a[i+j],  
                v = (a[i+j+len/2] * (invert?invW[ind]:W[ind]));
                a[i+j] = (u + v);
                a[i+j+len/2] = (u - v);
                ind += add;
            }
        }
    }
    if (invert) for (int i=0; i<n; ++i){
        a[i] /= (double)n;
    }
}
 
vector<int> multiply(vector<int>& A, vector<int>& B) {
    int n1 = A.degree()+1,  n2 = B.degree()+1;
    int final_size = n1+n2-1, N = 1;
    vector<complex<double>> F, G, H;
    vector<LL> result;
 
    while(N < final_size) N <<= 1;
    
    for(int i = 0; i < N; ++i)
        F.PB(complex<double>()),
        G.PB(complex<double>());
    for(int i = 0; i < n1; ++i) F[i] = complex<double>(A[i]);
    for(int i = 0; i < n2; ++i) G[i] = complex<double>(B[i]);
    FFT(F, false);
    FFT(G, false);
 
    for(int i = 0; i < N ; i++) H.PB(F[i]*G[i]);
    FFT(H, true);
 
    for(int i=0;i<final_size; i++) {
        result.PB((LL)(H[i].real()+0.5));
    }
}
