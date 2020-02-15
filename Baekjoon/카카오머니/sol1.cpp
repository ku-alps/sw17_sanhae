https://www.acmicpc.net/problem/15998
#include<ios>
typedef long long ll;

int n, f;
ll a, b, w, d, q, mx = 1;

ll gcd(ll y, ll z) {
	return z % y ? gcd(z%y, y) : y;
}

int main() {
	scanf("%*d");
	while (~scanf("%lld%lld", &a, &b)) {
		if (a > 0) f += (w + a != b);
		else {
			if ((d = b - a - w) > 0) {
				q = q ? gcd(q, d) : d;
				if (b > mx)	mx = b;
			}
			f += d < 0;
		}
		w = b;
	}

	printf("%lld", !f ? (!q ? 1 : (q > mx ? q : -1)) : -1);
}
