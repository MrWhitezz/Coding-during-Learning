#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5; // largest prime
const int N = maxn; // # prime numbers
bool val[maxn];
int prime[N], cnt = 0; // cnt must be init as 0, prime[1] = 2
void init(int n){ // n < maxn
	memset(val, 1, sizeof(val));
	val[1] = 0;
	for (int i = 2; i <= n; i++){
		if (val[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= n; j++){
			val[i * prime[j]] = 0;
			if (i % prime[j] == 0) break;
		}
	}
}