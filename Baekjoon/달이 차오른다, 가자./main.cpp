//https://www.acmicpc.net/problem/1194

#include<ios>
#include<queue>
#include<tuple>
using namespace std;

int n, m, i, j, ii, jj, si, sj, cnt, key, h, tp;
char a[52][52], c;
bool d[51][51][65], f;	// [행][열][비트마스킹(2^6)]
queue<tuple<int, int, int, int>> que;	// <행, 열, 시간, 키값(비트마스크)>

int main() {
	scanf("%d%d", &n, &m);

	for (; i < n; i++) {
		scanf("%s", a[i]);
		for (j = 0; j < m; j++)
			if (a[i][j] == '0') {	// 시작지점 저장
				si = i; sj = j;
			}
	}

	que.emplace(si, sj, 0, 0);
	
	while (!que.empty()) {
		tie(i, j, cnt, key) = que.front();
		que.pop();

		if (a[i][j] == '1') {	// 탈출
			printf("%d", cnt);
			exit(0);
		}

		for (h = 0; h < 4; h++) {
			ii = i + "2101"[h] - '1';
			jj = j + "1210"[h] - '1';
			
			if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;	// 범위 벗어나면 안감

			c = a[ii][jj];
			
			if (c == '#') continue;	// 벽이면 안감

			f = 1; tp = key;

			if (c >= 'a' && c <= 'f')	// 키 얻음
				tp |= (1 << (c - 'a'));	// 해당 키의 비트값 갱신
			else if (c >= 'A' && c <= 'F')	// 문 도착
				f = tp & (1 << (c - 'A'));	// 해당 키의 비트값이 1인가?

			if (!d[ii][jj][tp] && f) {
				d[ii][jj][tp] = 1;
				que.emplace(ii, jj, cnt + 1, tp);
			}
		}
	}

	printf("-1");
}
