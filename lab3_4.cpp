#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char c; // Przechowuje 1 znak pobrany funkcją getch()
	int charCount[26]; // Tablica przechowująca informacje o ilości wystąpień każdej litery A-Z
	int count = 0; // Ile w sumie wposano liter
	for (int i = 0; i < 26; i++) charCount[i] = 0;
	cout << "Dane wejsciowe: " << endl;
	do {
		c = _getch();
		if (c != 27) cout << c;
		if (c >= 'a' && c <= 'z') c -= ('a' - 'A');
		if (c >= 'A' && c <= 'Z') {
			charCount[c - 'A']++;
			count++;
		}
	} while (c != 27);
	cout << endl << "Wpisano w sumie "<<count<<" znakow w tym " << endl;
	for (int i = 0; i < 26; i++) {
		cout << "litera " << (char)(i + 'A') << " " << charCount[i] << " ";
		for (int j = 0; j < charCount[i]; j++) cout << "#";
		cout << endl;
	}
	return 0;
}

