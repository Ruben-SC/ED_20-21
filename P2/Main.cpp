// Ari Rubén Simao Chaves
// Miguel Pomboza Guadalupe

#include <iostream>
#include "SetOfInts1.h"

using namespace std;


int calculo(int n) {
	return n * n;
}

void numeroFeliz(int n, SetOfInts1 conjunto) {
	int a1, a2, a3, u, d, c, sol = n;
	bool encontrado = false;

	conjunto.add(n);
	cout << n << " ";

	if (n == 1) {
		cout << n;
		encontrado = true;
	}

	while (!encontrado) {
		if (sol < 10) {
			a1 = calculo(sol);

			sol = a1;
		}
		else if (sol < 100) {
			u = sol % 10;
			a1 = calculo(u);
			d = sol / 10;
			a2 = calculo(d);

			sol = a1 + a2;
		}
		else {
			u = sol % 10;
			a1 = calculo(u);
			d = (sol / 10) % 10;
			a2 = calculo(d);
			c = sol / 100;
			a3 = calculo(c);

			sol = a1 + a2 + a3;
		}

		if (!conjunto.contains(sol) || sol == 1) {
			conjunto.add(sol);
			cout << sol << " ";
			if (sol == 1) {
				encontrado = true;
				cout << 1;
			}
		}
		else {
			conjunto.add(0);
			cout << sol << " ";
			cout << 0;
			encontrado = true;
		}
	}
	
	cout << endl;
}

int main() {

	SetOfInts1 conjunto = SetOfInts1();
	int n;

	cin >> n;

	while (0 <= n && n < 1000) {
		numeroFeliz(n, conjunto);
		cin >> n;
	}

}