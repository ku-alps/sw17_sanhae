#include<ios>
int n, a[129][129], i, j, p[2];

int f(int x, int y, int k) {
	k >>= 1;
	if (!k) {
		p[a[x][y]]++;
		return a[x][y];
	}
	int af = f(x, y, k), m;
	for (int h = 0; h < 3; h++) {
		m = f(x + k * ("212"[h] - '1'), y + k * ("122"[h] - '1'), k);
		if (m > 1 || af > 2 || af - m) af = 2;
	}
	if (af < 2) p[af] -= 3;
	return af;
}

int main() {
	scanf("%d", &n);
	for (; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", a[i] + j);
	f(0, 0, n);
	printf("%d %d", p[0], p[1]);
}

