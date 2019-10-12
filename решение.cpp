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
	
	cout << "Введите x (-1; 1), k (> 1): ";
	cin >> x;
	cin >> k;
	cout.precision(10);
	cout << "Результат через функцию: " << 1 / pow((1 + x), 3) << endl;
	int a = 2, b = 3;
	double result = 1.0;
	while (true) {
		if (fabs(pow(-1, a - 1) * a * b * pow(x, (a - 1)) / 2) > pow(10, (double)-k)) {
			result += (pow(-1, a - 1) * a * b * pow(x, a - 1) / 2);
		}
		else break;
		a++;
		b++;
	};
	cout.precision(k + 1);
	cout << "Результат через формулу: " << result << endl;
	return 0;
}