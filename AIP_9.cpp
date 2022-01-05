#include <iostream>
#include <ctime>

using namespace std;

int ex_1();
int ex_2();

int main() {
	ex_1();
	ex_2();

	return 0;
}

// ********************* Задание 1 ************************* //
unsigned long long fact(unsigned long long N);
double series(int x, int N);
double* sums = new double[5];
int max_N(double* sums);

int ex_1() {
	int N[5] = { 5, 10, 15, 20, 25 };
	int max, x = 2;

	for (int i = 0; i < 5; i++) sums[i] = series(x, N[i]);

	for (int i = 0; i < 5; i++)
		cout << "Series " << i << " = " << sums[i] << endl;

	max = max_N(sums);
	cout << "max = " << max << '\n' << endl;

	return 0;
};

unsigned long long fact(unsigned long long N) {
	if (N < 0) return 0;
	if (N == 0) return 1;
	if (N > 0) return N * fact(N - 1);
}

double series(int x, int N) {
	int i, k = 0;
	unsigned long long P = 1;
	double R = 0, Q;

	for (int i = 1; i <= N; i++) {
		Q = pow(x, 2 * i - 1);
		P = fact(2 * i);
		R += Q / P;
	}

	return R;
}

int max_N(double* sums) {
	double max = sums[0];
	int N = 0;

	for (int i = 0; i < 5; i++) {
		if (sums[i] > max) {
			max = sums[i];
			N = i;
		}
	}
	return N;
}


// ********************* Задание 2 ************************* //
void metering(double** rad);
void dangerous_level(double** rad);

int ex_2() {
	srand(time(0));

	double** rad = new double* [2];
	for (int i = 0; i < 2; i++) rad[i] = new double[16];
	metering(rad);
	dangerous_level(rad);

	return 0;
};

void metering(double** rad) {

	for (int i = 7; i <= 22; i++) cout << '\t' << i;
	cout << '\n' << endl;

	for (int k = 0; k < 2; k++) {
		cout <<"RAD-" << k + 1 << "\t";
		for (int i = 0; i < 16; i++)
		{
			rad[k][i] = (5 + rand() % 46) / 100.;
			cout << rad[k][i] << '\t';
		}
		cout << endl;
	}

}

void dangerous_level(double** rad) {

	for (int k = 0; k < 2; k++) {
		cout << endl;
		for (int i = 0; i < 16; i++)
			if (rad[k][i] > 0.1) 
				cout << "Radiation at point RAD-" << k << " exceeded the norm at " << i + 7 << " o'clock" << endl;
	}
}
