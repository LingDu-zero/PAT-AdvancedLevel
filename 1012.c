#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct S {
	string id;
	int C, M, E, A;
	int rank[4];
}S;

bool cmp_C(S a, S b) {
	return a.C > b.C;
}

bool cmp_M(S a, S b) {
	return a.M > b.M;
}

bool cmp_E(S a, S b) {
	return a.E > b.E;
}

bool cmp_A(S a, S b) {
	return a.A > b.A;
}

int main(void)
{
	int N, M;
	S student[2001];
	char p[4] = { 'A','C','M','E' };
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> student[i].id >> student[i].C >> student[i].M >> student[i].E;
		student[i].A = (student[i].C + student[i].M + student[i].E) / 3;
	}
	sort(student, student + N, cmp_A);
	for (int i = 0; i < N; i++) {
		if (i != 0) student[i].rank[0] = student[i].A != student[i - 1].A ? i + 1 : i;
		else student[i].rank[0] = i + 1;
	}
	sort(student, student + N, cmp_C);
	for (int i = 0; i < N; i++) {
		if (i != 0) student[i].rank[1] = student[i].C != student[i - 1].C ? i + 1 : i;
		else student[i].rank[1] = i + 1;
	}
	sort(student, student + N, cmp_M);
	for (int i = 0; i < N; i++) {
		if (i != 0) student[i].rank[2] = student[i].M != student[i - 1].M ? i + 1 : i;
		else student[i].rank[2] = i + 1;
	}
	sort(student, student + N, cmp_E);
	for (int i = 0; i < N; i++) {
		if (i != 0) student[i].rank[3] = student[i].E != student[i - 1].E ? i + 1 : i;
		else student[i].rank[3] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		int flag = 0;
		string t;
		cin >> t;
		for (int j = 0; j < N; j++) {
			if (t != student[j].id) continue;
			flag = 1;
			int min_index, index;
			min_index = student[j].rank[0] <= student[j].rank[1] ? 0 : 1;
			index = student[j].rank[2] <= student[j].rank[3] ? 2 : 3;
			min_index = student[j].rank[min_index] <= student[j].rank[index] ? min_index : index;
			cout << student[j].rank[min_index] << " " << p[min_index] << endl;
			break;
		}
		if (flag == 0) cout << "N/A" << endl;
	}
	return 0;
}
