//https://www.acmicpc.net/problem/4991

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<tuple>
using namespace std;

int a[21][21], w, h, d[11][11], i, j, si, sj, sd[11], mn;
bool f[21][21], bf[11];
vector<pair<int, int>> v;
queue<tuple<int, int, int>> que;

void bck(int idx, int dist, int cnt) {
	if (cnt++ == v.size()) {
		if (mn > dist) {
			mn = dist;
		}

		return;
	}

	for (int k = 0; k < v.size(); k++) {
		if (!bf[k]) {
			bf[k] = 1;

			bck(k, dist + (idx < 0 ? sd[k] : d[idx][k]), cnt);

			bf[k] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {
		cin >> w >> h;
		if (!w && !h) break;
		v.clear();
		for (i = 0; i < h; i++) {
			string s;
			cin >> s;
			for (j = 0; j < s.length(); j++) {
				switch (s[j]) {
				case 'o': si = i; sj = j;
				case '.': a[i][j] = 0; break;
				case '*': v.emplace_back(i, j);
					a[i][j] = v.size(); break;
				case 'x': a[i][j] = -1; break;
				}
			}
		}

		for (i = 0; i < v.size(); i++) {
			fill_n(d[i], v.size(), 0);
			sd[i] = 0;
		}

		mn = 500;

		for (i = 0; i < v.size(); i++) {
			que.emplace(v[i].first, v[i].second, 0);

			for (j = 0; j < h; j++)
				fill_n(f[j], w, 0);

			while (!que.empty()) {
				auto t = que.front();
				que.pop();

				int x = a[get<0>(t)][get<1>(t)] - 1;
				if (x >= 0) {
					d[i][x] = d[x][i] = get<2>(t);
				}

				if (get<0>(t) == si && get<1>(t) == sj) {
					sd[i] = get<2>(t);
				}

				for (int k = 0; k < 4; k++) {
					int ii = get<0>(t) + "2101"[k] - '1',
						jj = get<1>(t) + "1210"[k] - '1';
					if (ii >= 0 && ii < h && jj >= 0 && jj < w) {
						if (a[ii][jj] >= 0 && !f[ii][jj]) {
							f[ii][jj] = 1;
							que.emplace(ii, jj, get<2>(t) + 1);
						}
					}
				}
			}

			if (!sd[i]) {
				mn = -1;
			}

		}

		if (mn > 0)
			bck(-1, 0, 0);

		cout << mn << '\n';
	}

}
