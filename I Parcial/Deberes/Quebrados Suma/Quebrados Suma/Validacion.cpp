#include "Validacion.h"
float Validacion::ingresarDatosfloat() {
	char* dato = new char[100];
	char c;
	int p = 0, x = 0, e = 1, i = 0;
	float n = 0.0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			std::cout << c;;
			dato[i++] = c;
		}
		if (p == 0) {
			if (c == '.') {
				printf("%c", c);
				dato[i++] = c;
				p++;
			}
		}
		if (i != 0) {
			if (c == 8) {
				i--;
				putchar(8);
				putchar(32);
				putchar(8);
				if (dato[i] == '.') {
					p--;
				}
			}
		}
	}
	dato[i] = '\0';
	while (dato[x] != '\0') {
		if (dato[x] == '.') {
			x++;
			while (dato[x] != '\0') {
				n = n + (dato[x] - '0') * pow(0.1, e);
				e++;
				x++;
			}
		}
		else {
			n = (n * 10) + (dato[x] - '0');
			x++;
		}
	}
	std::cout << "\n";
	return n;
}

int Validacion::ingresarDatosEnteros() {
	char* dato = new char[100];
	char c;
	int i = 0;
	int x = 0, n = 0;
	int result = 0;
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			std::cout << c;;
			dato[i++] = c;
		}
		else {
			if (i != 0) {
				if (c == 8) {
					i--;
					putchar(8);
					putchar(32);
					putchar(8);
				}
			}
		}
	}
	dato[i] = '\0';
	while (dato[x] != '\0') {
		n = 10 * n + (dato[x] - '0');
		x++;
	}
	std::cout << "\n";
	return n;
}