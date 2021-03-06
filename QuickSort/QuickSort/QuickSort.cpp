0// QuickSort.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::ifstream arquivo;
std::vector<int> vetor;

/* Troca os dois elementos do vetor*/
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta função pega o ultimo elemento como pivo,coloca
o elemento de pivô na sua posição correta na matriz
ordenada e coloca todo o menor (menor que o pivô) para 
a esquerda do pivô e todos os elementos maiores para 
o direito do pivô */
int partition(int menor, int maior)
{
	int pivo = vetor[maior];    // pivo
	int i = (menor - 1);  // Indice do menor elemento

	for (int j = menor; j <= maior - 1; j++)
	{
		// Se o elemento for menor ou igual ao pivo
		if (vetor[j] <= pivo)
		{
			i++;    // Incrementa o indice do menor elemento
			swap(&vetor[i], &vetor[j]);
		}
	}
	swap(&vetor[i + 1], &vetor[maior]);
	return (i + 1);
}

/* A função principal que implementa o QuickSort
menor  --> Indice Inicial,
maior  --> Indice final */
void quickSort(int low, int high)
{
	if (low < high)
	{
		/* pi é índice de particionamento, vetor [p] está agora no lugar certo */
		int pi = partition(low, high);

		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}


int main() {
	std::string arquivoname;
	std::cout << "Quick Sort:" << std::endl << "Digite o nome do arquivo(ex. exemplo.txt): ";
	std::cin >> arquivoname;

	arquivo.open(arquivoname.data());
	if (!arquivo.is_open()) {
		system("pause");
		return -1;
	}
	int i, j, aux;
	std::string stringer;
	while (!arquivo.eof()) {
		std::getline(arquivo, stringer);
		int num = std::stoi(stringer);
		vetor.push_back(num);
	}

	quickSort(0, vetor.size()-1);

	for (i = 0; i < vetor.size(); i++) {
		std::cout << vetor[i] << " " << std::endl;
	}
	system("pause");
	return 0;
}


