/*#include <iostream>

using namespace std;

int main() {

	int ten, two;

	cin >> ten;
	do {
		two = ten % 2;
		ten = ten / 2;
		cout << two;
	} while (ten != 0);
	return 0;
} */

#include <iostream>
#include <cmath>
#include <clocale>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	double x;
	int k;
	
	cout << "������� x (-1; 1), k (> 1): ";
	cin >> x;
	cin >> k;
	cout.precision(10);
	cout << "��������� ����� �������: " << 1 / pow((1 + x), 3) << endl;
	int a = 2;
	double result = 1.0;
	int current_addendum;
	while (true) {
		current_addendum = fabs(pow(-1, a - 1) * a * (a + 1) * pow(x, (a - 1)) / 2);
		if (current_addendum > pow(10, (double)-k)) {
			result += (pow(-1, a - 1) * a * (a + 1) * pow(x, a - 1) / 2);
		}
		else break;
		a++;
		b++;
	};
	cout.precision(k + 1);
	cout << "��������� ����� �������: " << result << endl;
	return 0;
}