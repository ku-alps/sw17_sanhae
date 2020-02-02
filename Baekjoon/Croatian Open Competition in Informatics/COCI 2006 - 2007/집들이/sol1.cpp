//https://www.acmicpc.net/problem/3050

#include<ios>
int r, c, i, j, k, mx, my, tx, ty, d[401][401];

char a[401][401];

void f() {
	if (ty && tx + ty > mx + my) {
        mx = tx;
        my = ty;
    }
	ty = 0;
}

int main() {
	scanf("%d%d", &r, &c);
	for (; i < r; i++)
		scanf("%s", a[i]);

	for (i = 0; i < c; i++)
		for (j = i, tx = 1; j < c; j++, tx++) {
			for (k = 0; k < r; k++) {
				d[i][k] += a[k][j] == '.';
				if (d[i][k] == tx) ty++;
				else f();
			}
			f();
        }
    
	printf("%d", my ? (mx + my) * 2 - 1 : 0);
}
