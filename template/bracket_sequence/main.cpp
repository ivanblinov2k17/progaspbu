#include "func.h"
#include "time.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	srand(time(NULL));

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}

	print(a);
	int temp = 0;
	cin >> temp;
	if (temp == 1)
		merge_sort(a);
	else
		q_sort(a);
	print(a);
	system("pause");
	return 0;
}