
#include <iostream>
//#include "DateTests.h"
#include "SetOfInts3.h"
//#include "SetTests.h"
using namespace std;

void mostrar(SetOfInts3 conjunto, int tam) {

	for (int i = 0; i < tam; i++) {
		cout << conjunto.getMin();
		if (!conjunto.isEmpty()) {
			cout << " ";
		}
		conjunto.removeMin();
	}
	cout << endl;
}

// El coste del algoritmo seria n log n, siendo n el tamaño del conjunto a, ya que se recorre todo el conjunto y
// en ciertas ocasiones se inserta un elemento que tiene como coste log n, por lo que en el caso peor es n log n

void lee_datos(SetOfInts3 conjunto, int& k) {
	int a;
	int cont = 0;

	cin >> a;

	do {
		if (cont < k && !conjunto.contains(a)) {
			conjunto.add(a);
			cont++;
		}
		else {
			if (!conjunto.contains(a) && conjunto.getMax() > a) {
				conjunto.removeMax();
				conjunto.add(a);
			}
		}
		cin >> a;
	} while (a != -1);

	mostrar(conjunto, k);
}

int main() {
	//testSetOfInts();
	//testGenericSet();
	//testDate1();
	//testDate2();
	//testDate3();
	//cout <<endl;
	//testDate4();

	SetOfInts3 conjunto = SetOfInts3();
	int k;

	cin >> k;

	while (k != 0 && k <= 100 && k > 0) {
		lee_datos(conjunto, k);
		cin >> k;
	}

}

// 3
// 1 1 4 4 7 7 6 7 - 1