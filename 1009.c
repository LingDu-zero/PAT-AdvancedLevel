#include <iostream>

using namespace std;

int main(void)
{
	int k1, k2, n; 
	double a;
	double pa[1001] = { 0 }, pb[2001] = { 0 };
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		cin >> n >> a;
		pa[n] = a;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		cin >> n >> a;
		for (int j = 0; j < 1001; j++) {
			if (pa[j] != 0) {
				pb[n + j] += pa[j] * a;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++) {
		if (pb[i] != 0) count++;
	}
	cout << count;
	for (int i = 2000; i >= 0; i--) {
		if (pb[i] != 0) {
			printf(" %d %.1f", i, pb[i]);
		}
	}

	return 0;
}
