#include<stdio.h>

//functie care returneaza nr. de cifre ale numarului dat ca si parametru
int how_many_digits(int number) {
	if (number == 0) {
		return 1;
	}

	int len = 0;

	while (number != 0) {
		number = number / 10;
		len++;
	}
	return len;
}

//functie ce returneaza nr. de cifre a celui m. mare nr. din matrice (indexul ultimei pozitii)
int max_nr_digits(int n) {
	return how_many_digits(n * n - 1);
}

//functie de afisare spatii libere
void blank_spaces(int nr, int max) {
	for (int i = 0; i < (max - how_many_digits(nr)); i++) printf(" ");
}

//functie ce afiseaza pe orizontala elementele unui vector dat
void line_display(int* line, int n) {
	int max = max_nr_digits(n);

	for (int i = 0; i < n-1; i++) { blank_spaces(line[i], max); printf("%u  ", line[i]); }
	blank_spaces(line[n-1], max); printf("%u\n\n", line[n-1]);
}