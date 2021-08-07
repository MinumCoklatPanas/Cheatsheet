SET(lastPrime, 0);
	tot[1] = 1;
	for (LL i = 2; i < N; i++) {
		if (!lastPrime[i]) {
			tot[i] = i - 1;
			lastPrime[i] = i;
			prime.pb(i);	
		} else {
			if (lastPrime[i] == lastPrime[i / lastPrime[i]])
				tot[i] = tot[i / lastPrime[i]] * lastPrime[i];
			else tot[i] = tot[i / lastPrime[i]] * (lastPrime[i] - 1);
		}
		for (LL j = 0; j < prime.size() && prime[j] <= lastPrime[i] && i * prime[j] < N; j++)
			lastPrime[i * prime[j]] = prime[j];
	}
