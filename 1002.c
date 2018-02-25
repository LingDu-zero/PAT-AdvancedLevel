****************************************
可以只创建一个vector运用insert解决
****************************************
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct polynomial {
	int n;
	float a;
};

int main(void)
{
	vector<polynomial> x, y, z;
	polynomial temp;
	int k;
	cin >> k;
	while (k--) {
		cin >> temp.n >> temp.a;
		x.push_back(temp);
	}
	cin >> k;
	while (k--) {
		cin >> temp.n >> temp.a;
		y.push_back(temp);
	}
	vector<polynomial>::iterator itx, ity;
	itx = x.begin();
	ity = y.begin();
	while (itx != x.end() && ity != y.end()) {
		if ((*itx).n > (*ity).n) {
			z.push_back((*itx));
			itx++;
		}
		else if ((*itx).n < (*ity).n) {
			z.push_back((*ity));
			ity++;
		}
		else {
			temp.n = (*itx).n;
			temp.a = (*itx).a + (*ity).a;
			z.push_back(temp);
			itx++;
			ity++;
		}
	}
	if (itx != x.end()) {
		while (itx != x.end()) {
			z.push_back((*itx));
			itx++;
		}
	}
	if (ity != y.end()) {
		while (ity != y.end()) {
			z.push_back((*ity));
			ity++;
		}
	}
	k = z.size();
	for (int i = 0; i < z.size(); i++) {
		if (z[i].a == 0) k--;
	}
	cout << k;
	for (int i = 0; i < z.size(); i++) {
		if (z[i].a != 0) {
			cout << " " << z[i].n << " ";
			cout << fixed;
			cout << setprecision(1) << z[i].a;
			cout.unsetf(ios::fixed);
		}
	}
	cout << endl;
	return 0;
}
