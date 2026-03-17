#include <iostream>
#include "calculadora.h"

int main() {
	double n1, n2, result;
	char op;
	bool continuar = true;

	while (continuar) {
		std::cout << "\n--- Calculadora (Digite 'q' na operacao para sair) ---\n";

		std::cout << "Primeiro Numero: ";
		if (!(std::cin >> n1)) {
			std::cerr << "Erro: Digite um numero valido.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "Operacao (+, -, *, /): ";
		std::cin >> op;
		if (op == 'q') break;

		std::cout << "Segundo Numero: ";
		if (!(std::cin >> n2)) {
			std::cerr << "\n[Erro]: Digite um numero valido.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (op == '/' && n2 == 0) {
			std::cerr << "\n[Erro]: Divisao por zero nao permitida.\n";
		}
		else {
			try {
				result = calcular(n1, n2, op);
				std::cout << "Resultado: " << n1 << " " << op << " " << n2 << " = " << result << "\n";
			}
			catch (...) {
				std::cerr << "\n[Erro]: Operacao invalida!\n";
			}
		}
	}

	return 0;
}
