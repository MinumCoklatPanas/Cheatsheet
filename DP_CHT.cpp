struct Line {
	int m, c;
	
	int getY(int x) {
		return m * x + c;
}

double getMid(Line other) {
	return (double) (c - other.c) / 
 (double) (other.m - m);
	}
};

vector<Line> ch;

bool cmp(Line a, Line b, Line c) {
	return 	ch[a].getMid(b) < 
		 	ch[b].getMid(c);
}

void add(Line line) {
	while (SZ(ch) ≥ 2 && 
 !cmp(ch[SZ(ch) - 1], ch.back(), line))
ch.pop_back();

ch.push_back(line);
}

int getOpt(int x) {
	int l = 0, r = SZ(ch) - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (line[mid].getMid(line[mid + 1]) ≥ x)
			r = mid;
		else
			l = mid + 1;
	}
	return line[l].getY(x);
}

dp[0] = 0
for (int i = 1; i ≤ N; i++) {
add(Line(-i, dp[i - 1]));
dp[i] = getOpt(A[i]) + A[i] * (i + 1);
}
