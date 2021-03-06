void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1; // starting values
  while (i < m) { // pre-process the pattern string P
    while (j >= 0 && P[i] != P[j]) j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
} }           // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0;
  // cout<<n<<" n\n"; // starting values
  while (i < n) 
  { 
  	// cout<<i<<" i\n";
  // search through string T
    while (j >= 0 && T[i] != P[j]) j = b[j];
    // cout<<j<<" j\n";
    i++; j++; // if same, advance both pointers
    if (j == m) { // a match found when j == m
      return i-j;
      // j = b[j]; // prepare j for the next possible match
	}
}
return -1; 
}
