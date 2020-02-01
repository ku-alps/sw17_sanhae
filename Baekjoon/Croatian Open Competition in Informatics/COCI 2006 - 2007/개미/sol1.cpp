//https://www.acmicpc.net/problem/3048

#include<ios>
int a, b, t, i, ai, bi;
char x[27], y[27], s[60];

int main() {
	scanf("%d%d%s%s%d", &a, &b, x, y, &t);
	if (t > a) ai = a - t;
	else bi = t - a;

	for(;bi < b || ai < a;bi++, ai++) {
		if (bi >= 0 && bi < b) printf("%c", y[bi]);
		if (ai >= 0 && ai < a) printf("%c", x[a - ai - 1]);
	}
}
