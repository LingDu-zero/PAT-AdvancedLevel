#include <iostream>

using namespace std;

int arr[10000];
int m = 0, n = 0, K;
int max_tot = 0;

void sub(int i,int j, int tot) {
	if (j == K) return;
	tot += arr[j];
	if (tot > max_tot) {
		max_tot = tot;
		n = j;
		m = i;
	}
	else if (tot == 0 && tot == max_tot) {
		m = n = i;
	}
	sub(i, j + 1, tot);
}

int main(void)
{
	int tot = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> arr[i];
	n = K - 1;
	for (int i = 0; i < K; i++) {
		if (arr[i] < 0) continue;
		sub(i, i, tot);
	}
	cout << max_tot << " " << arr[m] << " " << arr[n] << endl;

	return 0;
}
