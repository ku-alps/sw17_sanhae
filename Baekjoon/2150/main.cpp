#include<ios>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> g[2];
vector<int> aa[10001];
int v, e, n, a, b, i = 1, t, st[10002], x;
bool vi[10001][2];
void dfs(int k) {
	vi[k][x] = 1;
	for (int h : g[x][k])
		if (!vi[h][x])
			dfs(h);

	if (x) aa[n].push_back(k);
	else st[t++] = k;
}

int main() {
	scanf("%d%d", &v, &e);
	g[0].resize(v + 1);
	g[1].resize(v + 1);
	while (e--) {
		scanf("%d%d", &a, &b);
		g[0][a].push_back(b);
		g[1][b].push_back(a);
	}

	for (; i <= v; i++) if (!vi[i][0])	dfs(i);
	x = 1;
	while (t--) {
		if (!vi[st[t]][1]) {
			dfs(st[t]);
			n++;
		}
	}
	printf("%d\n", n);
	for (i = 0; i < n; i++) sort(aa[i].begin(), aa[i].end());
	sort(aa, aa + n, [](vector<int> p, vector<int> q) -> bool {
		return p[0] < q[0];
	});
	for (i = 0; i < n; i++) {
		for (int h : aa[i])
			printf("%d ", h);
		printf("-1\n");
	}
}
