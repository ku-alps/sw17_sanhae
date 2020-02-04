//https://www.acmicpc.net/problem/2169#include<ios>

int max(int a, int b) { return a > b ? a : b; }

int n, m, i, j, k, a[1001][1001], d[1001][1001][3], mn = -1e9;

int main() {
	scanf("%d%d", &n, &m);
	for (; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", a[i] + j);
			for (k = 0; k < 3; k++) {
				d[i][j][k] = -1e9;
			}
		}
	}

	d[0][0][0] = d[0][0][1] = a[0][0];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			int ii = i - 1;

			if (ii >= 0 && ii < n && j >= 0 && j < m) {
				if (d[ii][j][0] != mn) {
					d[i][j][0] = max(d[i][j][0], d[ii][j][0] + a[i][j]);
				}

				if (d[ii][j][1] != mn) {
					d[i][j][0] = max(d[i][j][0], d[ii][j][1] + a[i][j]);
				}

				if (d[ii][j][2] != mn) {
					d[i][j][0] = max(d[i][j][0], d[ii][j][2] + a[i][j]);
				}
			}

			int jj = j - 1;

			if (i >= 0 && i < n && jj >= 0 && jj < m) {
				if (d[i][jj][0] != mn) {
					d[i][j][1] = max(d[i][j][1], d[i][jj][0] + a[i][j]);
				}

				if (d[i][jj][1] != mn) {
					d[i][j][1] = max(d[i][j][1], d[i][jj][1] + a[i][j]);
				}
			}
		}

		for(j = m - 1; j >= 0; j--){
			int jj = j + 1;
			if (i >= 0 && i < n && jj >= 0 && jj < m) {
				if (d[i][jj][0] != mn) {
					d[i][j][2] = max(d[i][j][2], d[i][jj][0] + a[i][j]);
				}
				if (d[i][jj][2] != mn) {
					d[i][j][2] = max(d[i][j][2], d[i][jj][2] + a[i][j]);
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("(%d %d %d) ", d[i][j][0], d[i][j][1], d[i][j][2]);
		}
		printf("\n");
	}

	printf("%d", max(d[n - 1][m - 1][0], d[n - 1][m - 1][1]));
	
}
