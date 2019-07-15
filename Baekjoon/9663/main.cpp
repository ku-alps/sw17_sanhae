// 1116ms, 4044ms
#include<ios>
int n, d[15], cnt;

bool chk(int i, int j){
	for (int k = 0; k < i; k++)
		if (d[k] == j || i-k == j-d[k] || i-k==d[k]-j)
			return 0;
	return 1;
}

void f(int i) {
	if (i == n) {
		cnt++;
		return;
	}
	for (int k = 0; k < n; k++)
		if (chk(i, k)) {
			d[i] = k;
			f(i + 1);
		}
}

int main() {
	scanf("%d", &n);
	f(0);
	printf("%d", cnt);
}
