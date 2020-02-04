//https://www.acmicpc.net/problem/1062

#include<ios>
#include<string.h>

char s[50][17];
int n, k, i, j, t, mx;
int f[50], bf[27];

void bck(int c, int x, int nxt) {
	if (c++ == k - 5) {		
		int cnt = 0;
		for (int h = 0; h < n; h++)
			if ((x & f[h]) == f[h]) cnt++;
		if (mx < cnt) mx = cnt;
		return;
	}

	for (int h = nxt; h < 26; h++)
		if (!bf[h]) {
			bf[h] = 1;
			bck(c, x | (1 << h), h + 1);
			bf[h] = 0;
		}

}

int main() {
	scanf("%d%d", &n, &k);
	for (; i < n; i++) {
		scanf("%s", s[i]);

		for (j = 0; s[i][j]; j++)
			f[i] |= 1 << (s[i][j] - 'a');
	}

	for (i = 0; i < 5; i++) {
		j = "antic"[i] - 'a';
		t |= 1 << j;
		bf[j] = 1;
	}

	bck(0, t, 1);

	printf("%d", mx);
}
