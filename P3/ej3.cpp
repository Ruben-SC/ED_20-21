// Ari Ruben Simao Sanchez
// Miguel Pomboza Guadalupe

#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

bool esEquilibrada(const string& cadena) {
	Stack<char> T;
	for (unsigned int i = 0; i < cadena.length(); i++) {
		if (cadena[i] == '[' || cadena[i] == '(' || cadena[i] == '{') {
			T.push(cadena[i]);
		}
		else if (cadena[i] == ']' || cadena[i] == ')' || cadena[i] == '}') {
			if (!T.empty()) {
				if ((T.top() == '[' && cadena[i] == ']') || (T.top() == '(' && cadena[i] == ')') || (T.top() == '{' && cadena[i] == '}')) {
					T.pop();
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}

	if (T.empty())
		return true;
	else
		return false;
}


int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}