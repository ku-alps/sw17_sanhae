// https://www.acmicpc.net/problem/2206

#include<ios>
#include<queue>
#include<tuple>

using namespace std;

queue<tuple<int, int, int, bool>> que;
int a[1001][1001], d[1001][1001][2], n, m, i, j, cnt, k;

int main() {
	scanf("%d%d", &n, &m);
	for (; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%1d", a[i] + j);
		}
	}

	que.emplace(0, 0, 1, 1);
	d[0][0][1] = d[0][0][0] = 1;

	while (!que.empty()) {
		i = get<0>(que.front());
		j = get<1>(que.front());
		cnt = get<2>(que.front());
		k = get<3>(que.front());
		que.pop();

		if (i == n - 1 && j == m - 1) {
			printf("%d", cnt);
			exit(0);
		}

		for (int h = 0; h < 4; h++) {
			int ii = i + "2101"[h] - '1',
				jj = j + "1210"[h] - '1';
			
			if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
				if (!a[ii][jj]) {
					if (!d[ii][jj][k]) {
						que.emplace(ii, jj, cnt + 1, k);
						d[ii][jj][k] = 1;
						if (k) d[ii][jj][0] = 1;
					}
				}
				else if(k){
					if (!d[ii][jj][0]) {
						que.emplace(ii, jj, cnt + 1, 0);
						d[ii][jj][0] = 1;
					}
				}
			}
		}
	}
	printf("-1");
}
