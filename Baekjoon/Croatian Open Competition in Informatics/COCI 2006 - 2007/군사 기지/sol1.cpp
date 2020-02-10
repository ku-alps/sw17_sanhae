// https://www.acmicpc.net/problem/3051

#include<ios>
#include<vector>

typedef double db;

struct line {
	int x1, y1, x2, y2;

	line(int _x1, int _y1, int _x2, int _y2) {
		if ((_x1 == _x2 && _y1 > _y2) || _x1 > _x2) {	// 두 점끼리의 정렬
			x1 = _x2; y1 = _y2;
			x2 = _x1; y2 = _y1;
		}
		else {
			x1 = _x1; y1 = _y1;
			x2 = _x2; y2 = _y2;
		}
	}
};

bool isBtw(int a1, int a2, int a) {	// a의 값이 a1과 a2 사이에 있는지 확인
	if (a1 < a2) return a1 <= a && a <= a2;
	return a2 <= a && a <= a1;
}

bool chkInc(line l1, line l2) {	// 기울기 체크, 삼각형의 비례관계를 이용
	return (l1.x1 - l1.x2)*(l2.y1 - l2.y2) == (l1.y1 - l1.y2)*(l2.x1 - l2.x2);
}

bool isIn(line l, int x, int y) {
	if (isBtw(l.x1, l.x2, x) && isBtw(l.y1, l.y2, y))	// 점의 x값과 y값이 선분의 양 끝점 사이에 존재하면 
		return (x - l.x1)*(l.y2 - y) == (l.x2 - x)*(y - l.y1);	// 삼각형의 비례관계를 이용하여 점이 해당 선분 위에 있는지 확인
	return 0;
}

line con(line l1, line l2) {	
	/*
	두 선분의 합치기 (이미 두 선분이 한 직선에 포함되고,
		한점 이상에서 만난다는 사실을 알고있기 때문에 따로 조건 체크하지 않음)
	*/
	if (l1.x1 < l2.x1 || (l1.x1 == l2.x1 && l1.y1 < l2.y1)) {
		if (l1.x2 < l2.x2 || (l1.x2 == l2.x2 && l1.y2 < l2.y2)) {
			return line(l1.x1, l1.y1, l2.x2, l2.y2);
		}
		else {
			return line(l1.x1, l1.y1, l1.x2, l1.y2);
		}
	}
	else {
		if (l1.x2 < l2.x2 || (l1.x2 == l2.x2 && l1.y2 < l2.y2)) {
			return line(l2.x1, l2.y1, l2.x2, l2.y2);
		}
		else {
			return line(l2.x1, l2.y1, l1.x2, l1.y2);
		}
	}
}


bool interPt(line l1, line l2, db *ix, db *iy) {	// http://www.gisdeveloper.co.kr/?p=89
	double under = (l2.y2 - l2.y1) * (l1.x2 - l1.x1)
		- (l2.x2 - l2.x1) * (l1.y2 - l1.y1);

	if (!under) return 0;

	db _t = (l2.x2 - l2.x1)*(l1.y1 - l2.y1) - (l2.y2 - l2.y1)*(l1.x1 - l2.x1);
	db _s = (l1.x2 - l1.x1)*(l1.y1 - l2.y1) - (l1.y2 - l1.y1)*(l1.x1 - l2.x1);

	db t = _t / under;
	db s = _s / under;

	if (t < 0.0 || t > 1.0 || s < 0.0 || s > 1.0) return 0;

	*ix = l1.x1 + t * (l1.x2 - l1.x1);
	*iy = l1.y1 + t * (l1.y2 - l1.y1);

	return 1;
}


bool same(db x1, db y1, db x2, db y2) {	// 오차 범위 안에 들어오는지 확인
	return (x1 - 1e-9 < x2 && x2 < x1 + 1e-9)
		&& (y1 - 1e-9 < y2 && y2 < y1 + 1e-9);
}


std::vector<line> v;	// 독립된(서로 합쳐지지 않는) 선분들
int n, i, j, k, t1, t2, t3, t4, in[4], ans;

int main() {
	//freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		for (i = 0; i < 4; i++) {
			scanf("%d", in + i);
		}

		line l = line(in[0], in[1], in[2], in[3]);

		for (j = 0; j < v.size(); j++) {
			if (chkInc(v[j], l)) {
				t1 = isIn(v[j], in[0], in[1]);
				t2 = isIn(v[j], in[2], in[3]);
				t3 = isIn(l, v[j].x1, v[j].y1);
				t4 = isIn(l, v[j].x2, v[j].y2);
				// 서로의 끝점이 상대 선분에 포함되는지 확인

				if (t1 + t2 + t3 + t4 >= 2) {
					// 합치기
					l = con(v[j], l);

					v.erase(v.begin() + j--);	//j번째 선분 지우고 for문에서의 j값 그대로 유지
					continue;
				}
			}
		}
		v.push_back(l);
	}


	for (i = 0; i < v.size(); i++) {
		for (j = i + 1; j < v.size(); j++) {
			for (k = j + 1; k < v.size(); k++) {
				db x12 = 0, y12 = 0, x23 = 0, y23 = 0, x31 = 0, y31 = 0;

				if (interPt(v[i], v[j], &x12, &y12) 
					&& interPt(v[j], v[k], &x23, &y23)
					&& interPt(v[k], v[i], &x31, &y31)) {
					if (!same(x12, y12, x23, y23))	// 교점이 서로 다르면
						ans++;
				}
			}
		}
	}
	printf("%d", ans);
}
