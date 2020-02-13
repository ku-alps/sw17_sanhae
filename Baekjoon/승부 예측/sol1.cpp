// https://www.acmicpc.net/problem/15997
#include<ios>
#include<string.h>

int i, j, m[6][2], pt[4], d[10], dc[10], t;
double mp[6][3], pa[4];
char s[4][11], s1[11], s2[11], cm[16] = "111111121133146";

void chk(double pc) {
	for (i = 0; i < 10; i++) d[i] = dc[i] = 0;

	for (i = 0; i < 4; i++) {
		d[pt[i]] |= 1 << i;
		dc[pt[i]]++;
	}

	for (i = 9, t = 0; i >= 0 && t < 2; i--) {
		if (d[i]) {
			for (j = 0; j < 4; j++)
				if (d[i] & (1 << j))
					pa[j] += pc * (cm[3*dc[i] - 2 - t] - '0') / (cm[3*dc[i] + 2 - t] - '0');
			t += dc[i];
		}
	}
	
}

void bck(int cnt, double pc) {
	if (cnt == 6) {
		chk(pc);
		return;
	}

	for (int k = 0; k < 3; k++) {
		pt[m[cnt][0]] += "310"[k] - '0';
		pt[m[cnt][1]] += "013"[k] - '0';

		bck(cnt + 1, pc * mp[cnt][k]);

		pt[m[cnt][0]] -= "310"[k] - '0';
		pt[m[cnt][1]] -= "013"[k] - '0';
	}
}

int main() {
	for (; i < 4; i++)
		scanf("%s", s[i]);
	
	for (i = 0; i < 6; i++) {
		scanf("%s%s%lf%lf%lf", s1, s2, mp[i], mp[i] + 1, mp[i] + 2);
		for (j = 0; j < 4; j++) {
			if (!strcmp(s[j], s1))	m[i][0] = j;
			if (!strcmp(s[j], s2))	m[i][1] = j;
		}
	}
	
	
	bck(0, 1);

	for (i = 0; i < 4; i++) {
		printf("%.9f\n", pa[i]);
	}
}
