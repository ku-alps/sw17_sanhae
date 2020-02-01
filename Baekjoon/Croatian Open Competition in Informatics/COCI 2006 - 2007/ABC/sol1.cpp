//https://www.acmicpc.net/problem/3047

#include<ios>
int a[101], d[3], t, i = 3;
char s[4];

int main() {
	while (i--) {
		scanf("%d", &t);
		a[t] = 1;
	}
	for (i = t = 0; i < 101; i++)
		if (a[i]) d[t++] = i;
	scanf("%s", s);

	for (i = 0; i < 3; i++)
		printf("%d ", d[s[i] - 'A']);
}
