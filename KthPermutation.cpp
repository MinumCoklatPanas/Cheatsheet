string kthpermute(LL k, string s) {
	int len = s.length();
	char ss[len+2];
	sprintf(ss, "%s", s.c_str());
	LL fac = 1LL;
	FOR(i,2,len-1) fac = LL(i) * LL(fac);
	REP(i, len-1) {
		int tidx = ( k / fac ) % ( len - i );
		char ch = ss[ i + tidx ];
		for(int j = i+tidx; j > i; j--) ss[j] = ss[j-1];
		ss[i] = ch;
		fac = fac / LL( (len - i - 1) );
	}
	return (s = ss);
}
int main() {
	string s = "abcdefghijklmnopqrst";
	printf("%s\n", kthpermute(123456789987654321LL, s).c_str() );
	return 0;
}
