#include<ios>
#include<vector>
#include<algorithm>
int m, l, x, y, z;
std::vector<int> v = { -(int)2e9, (int)2e9 };

int f(int k) {
	int a = 0, b = m, c;
	while (a + 1 < b)
		if (v[c = (a + b) / 2] >= k) b = c;
		else a = c;
	return b;
}

int main() {
	scanf("%d%*d%d", &m, &l);
	while (m--) { scanf("%d", &x);  v.push_back(x); }
	sort(v.begin(), v.end()); m = v.size() - 1;
	while (~scanf("%d%d", &x, &y)) 
    	if (v[f(x + y - l)] <= x - y + l)
      		z++;
	printf("%d", z);
}
