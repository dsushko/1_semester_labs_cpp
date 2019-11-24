#include <iostream>
#include <clocale>

using namespace std;   

bool fGreaterThanS(double a, double b) {
	if (fabs(a) - fabs(b) > 0) return 1;
	else return 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	const int max = 1000;

	double array[max] = { 0 };
	double arrmax;
	int n;
	cout << "������� ���������� ��������� �������, ����� ���� ��������\n";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	};
	arrmax = array[0];

	for (int i = 0; i < n; i++) {
		if (fGreaterThanS(array[i], arrmax)) arrmax = array[i];
	};
	int firstplus = -1, secondplus = -1;

	for (int i = 0; i < n; i++) {
		if (array[i] > 0) {
			if (firstplus == -1) {
				firstplus = i;
			}
			else if (secondplus == -1) {
				secondplus = i;
				break;
			}
		}
	}
	double sum = 0;
	if (firstplus != -1 && secondplus != -1) {
		for (int i = firstplus + 1; i < secondplus; i++) {
			sum += array[i];
		}
	}

	//sort remains
	std::cout << "������������ �� ������ ������� - " << arrmax << "\n";
	std::cout << "����� ��������� ����� ������ � ������ �������������� ���������� - " << sum;
	int n_sootv_chiselok[max] = { 0 };
	std::cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (array[i] == array[j]) {
				n_sootv_chiselok[j]++;
				break;
			}
		};
	};

	for (int i = 0; i < n; i++) {
		cout << n_sootv_chiselok[i] << " ";
	}
	cout << "\n"; 
	int maxFromArr = -99999;
	int nRaspChisel = 0;
	double sortArr[max] = { 0 };
	int currPosSortArr = 0;
	int maxnInIter = 0;
	for (int i = 0; i < n; i++) {
		maxFromArr = -99999;
		nRaspChisel += n_sootv_chiselok[i];

		for (int j = 0; j < n; j++) {
			if (n_sootv_chiselok[j] > maxFromArr) {
				maxFromArr = n_sootv_chiselok[j];
				maxnInIter = j;
			}
		};
		for (int j = 0; j < maxFromArr; j++) {
			sortArr[currPosSortArr] = array[maxnInIter];
			currPosSortArr++;
		}
		n_sootv_chiselok[maxnInIter] = 0;
	}
	std::cout << "��������������� ������ �� ������� ������������� ��������� �� ��������: ";
	for (int i = 0; i < n; i++) {
		cout << sortArr[i] << " ";
	}	
	return 0;
}