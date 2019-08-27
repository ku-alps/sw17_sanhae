#include<ios>
#include<algorithm>
int m, n, l, x, y, z, v[100005];
int main() {
	scanf("%d%*d%d", &m, &l);
	v[0] = -(v[n = m + 1] = 2e9);
	while (m) scanf("%d", v + m--);
	std::sort(v, v + n);
	while (~scanf("%d%d", &x, &y)) {
		int a = 0, b = n, c;
		while (a + 1 < b) v[c = (a + b) / 2] >= x + y - l ? b = c : a = c;
		if (v[b] <= x - y + l) z++;
	}
	printf("%d", z);
}
