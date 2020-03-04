// https://www.acmicpc.net/problem/2096

#include<ios>
#include<algorithm>
int n, a[3], i, ii, j, dx[3][2], dn[3][2], f, mn = 1e6, mx;

int main() {
	scanf("%d", &n);

	while (n--) {
		scanf("%d%d%d", a, a + 1, a + 2);

		dn[0][f] = dn[1][f] = dn[2][f] = mn;

		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				ii = i + "012"[j] - '1';
				if (ii >= 0 && ii < 3) {
					dx[ii][f] = std::max(dx[i][!f] + a[ii], dx[ii][f]);
					dn[ii][f] = std::min(dn[i][!f] + a[ii], dn[ii][f]);
				}
			}
		}

		f = !f;
	}

	for (i = 0, f = !f; i < 3; i++) {
		if (dx[i][f] > mx) mx = dx[i][f];
		if (dn[i][f] < mn) mn = dn[i][f];
	}

	printf("%d %d", mx, mn);
}
