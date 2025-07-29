#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, total;
	cin >> n;
	vector<int> user(n);
	int max_val = 0;

	for (int i = 0; i < n; i++) {
		cin >> user[i];
		max_val = max(max_val, user[i]);	//�ʿ� �ڿ����� �ִ밪
	}

	cin >> total;

	int left = 0, right = max_val;
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += min(user[i], mid);
		}

		if (sum <= total) {
			answer = mid; // ���� ���Ѽ� ����, �� ������ �Ǵ��� Ȯ��
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << answer << endl;
	return 0;
}