#include <iostream>

using namespace std;

int main(void)
{
	double a[3];
	double max[3];
	char c[3];
	char s[3] = { 'W', 'T', 'L' };
	for (int i = 0; i < 3; i++) {
		cin >> a[0] >> a[1] >> a[2];
		int index = 0;
		for (int j = 0; j < 3; j++)
			if (a[index] < a[j]) index = j;
		max[i] = a[index];
		c[i] = s[index];
	}
	double tot = (max[0] * max[1] * max[2] * 0.65 - 1) * 2;
	printf("%c %c %c %.2f", c[0], c[1], c[2], tot);

	return 0;
}
