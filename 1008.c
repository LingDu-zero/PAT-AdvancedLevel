#include <iostream>

using namespace std;

int main(void)
{
	const int wait = 5;
	const int up = 6;
	const int down = 4;
	int K, curr = 0, time = 0;
	int arr[100];
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> arr[i];
	for (int i = 0; i < K; i++) {
		int temp = arr[i] - curr;
		if (temp > 0) time = time + up*temp + wait;
		else if (temp == 0) time += wait;
		else time = time - down*temp + wait;
		curr = arr[i];
	}
	cout << time << endl;

	return 0;
}
