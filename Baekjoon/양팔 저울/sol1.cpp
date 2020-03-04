//https://www.acmicpc.net/problem/1653

#include<ios>
#include<vector>
#include<algorithm>

int n, k, c, d[10];
bool a[10], f[10];
std::vector<int> v;
std::vector<long long> t;

void bck(int ii, int s) {
	if (s == 0) {
		int x = 10; long long ss = 0;
		while (x--) {
			ss *= 10;
			ss += d[x];
		}
		t.push_back(ss);
	}

	for (int i = ii; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (a[j] && !f[j]) {
				d[i] = j; f[j] = 1;
				bck(i + 1, s + ((i < 5 ? 5 : 4) - i) * j); 
				d[i] = 0; f[j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &k);
		a[k] = 1;
	}
	scanf("%d", &k);
	bck(0, 0);
	std::sort(t.begin(), t.end());
	printf("%lld\n", t.size() <= k ? t[t.size()-1] : t[k]);
}
