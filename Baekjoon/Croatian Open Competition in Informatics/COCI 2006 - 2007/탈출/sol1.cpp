//https://www.acmicpc.net/problem/3055

#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

vector<pair<int, int>> v;
int q[3000][3], r, c, i, j, a[51][51], k, h, t = 1, cnt, temp = -1;
bool f[51][51];
string s;

bool chk(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
	cin >> r >> c;
	
	for (; i < r; i++) {
		cin >> s;
		for (j = 0; j < c; j++) {
			if (s[j] == 'S') {
				q[0][0] = i;
				q[0][1] = j;

				f[i][j] = 1;
			}
			else if (s[j] == 'D') {
				a[i][j] = 4;
			}
			else if (s[j] == '*') {
				a[i][j] = 2;
				v.emplace_back(i, j);
			}
			else if (s[j] == 'X') {
				a[i][j] = 1;
			}
			
		}
	}

	while (h < t) {
		i = q[h][0];
		j = q[h][1];
		cnt = q[h++][2];

		if (a[i][j] == 4) {
		    cout << cnt;
			exit(0);
		}

		if (temp < cnt) {
			vector<pair<int, int>> vt;
			for (auto x : v) {
				for (k = 0; k < 4; k++) {
					int ii = x.first + "2101"[k] - '1';
					int jj = x.second + "1210"[k] - '1';

					if (chk(ii, jj)) {
						if (!a[ii][jj]) {
							a[ii][jj] = 1;
							vt.emplace_back(ii, jj);
						}
					}
				}
			}
			v = vt;
		}

		temp = cnt;

		for (k = 0; k < 4; k++) {
			int ii = i + "2101"[k] - '1';
			int jj = j + "1210"[k] - '1';
			if (chk(ii, jj)) {
				if ((a[ii][jj] == 0 || a[ii][jj] == 4) && !f[ii][jj]) {
					q[t][0] = ii;
					q[t][1] = jj;
					q[t++][2] = cnt + 1;
					f[ii][jj] = 1;
				}
			}
		}
	}

	cout << "KAKTUS";
}
