#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstdlib>
#include <string.h>

#define L 25

using namespace std;

/*
Autor: Marcin Szymczak
Data: 04.01.2022
Tytuł: Labolatorium 5
Grupa: PT/N 17:05
*/

bool menu(char***); //Done
void dodaj_imie(char***);//Done
void drukuj(char**);//Done
void drukuj_litera(char**);//Done
void usun_index_wrapper(char***); //Done
void usun_index(char***, int); //Done
void usun_imie(char***);//Done
void sortuj_alfabetycznie(char**);//Done
void sortuj_dlugosc(char**);//Done
int zlicz(char**);//Zwraca indeks ostatniego elementy tablicy tab (elementu NULL)


int main()
{
    printf("Marcin Szymczak 263909 PT/N 17:05\n");
    char** tab = (char**)malloc(sizeof(char**));
    tab[0] = NULL;
    while (menu(&tab));
}

bool menu(char*** tab) {
    printf("--- Co chcesz zrobic? ---\n");
    printf("1. Dodaj nowe imie do slownika\n");
    printf("2. Wydrukuj caly slownik\n");
    printf("3. Wydrukuj imiona na wskazana litere\n");
    printf("4. Usun imie po indeksie\n");
    printf("5. Usun imie \n");
    printf("6. Posortuj slownik alfabetycznie \n");
    printf("7. Posortuj slownik po dlugosci imion \n");
    printf("[ESC] Zakoncz program \n\n\n");

    char c = _getch();
    switch (c) {
    case '1': dodaj_imie(tab); break;
    case '2': drukuj(*tab); break;
    case '3': drukuj_litera(*tab); break;
    case '4': usun_index_wrapper(tab); break;
    case '5': usun_imie(tab); break;
    case '6': sortuj_alfabetycznie(*tab); break;
    case '7': sortuj_dlugosc(*tab); break;
    case 27:  return false; break;
    default:  return menu(tab); break;
    }
    //printf("\n Wcisnij dowolny przycisk\n");
    //_getch();
    // system("cls");
    return true;

}
int zlicz(char** tab) {
    int size = 0;
    while (tab[size] != NULL) size++;
    return size;
}

void dodaj_imie(char*** tab) {
    //pobierz imie do bufora
    char buffer[L];
    printf("Podaj nowe imie: ");
    fgets(buffer, L, stdin);
    //zwieksz rozmiar tablicy
    int size = zlicz(*tab);
    (*tab) = (char**)realloc((*tab), sizeof(char**) * (size + 2));
    //wpisz nowe imie do tablicy
    (*tab)[size] = (char*)malloc(sizeof(char) * L);
    strcpy((*tab)[size], buffer);
    (*tab)[size + 1] = NULL;
    //potwierdz operacje
    printf("Dodano Tab[%d] = %s\n", size, buffer);
}
void drukuj(char** tab) {
    //przejdz pętlą po tablicy, drukuj indeks i wartość aż napotkasz wartość NULL
    printf("\n");
    int i = 0;
    while (tab[i] != NULL) { printf("Tab[%d] = %s\n", i, tab[i]); i++; };
    printf("\n");
}
void drukuj_litera(char** tab) {
    //Pobierz pojedynczy znak C
    char C;
    printf("Podaj znak rozpoczynajacy imie: ");
    scanf("%c", &C);
    // Sprawdź czy C [a,z] U [A,Z]
    if (!((C >= 'a' && C <= 'z') || (C >= 'A' || C <= 'Z'))) {
        printf("Niepoprawny znak");
        return;
    }
    //przejdz pętlą po tablicy, drukuj indeks i wartość jeśli wartosc[0] == C aż napotkasz wartość NULL
    for (int i = 0; tab[i] != NULL; i++) if (tab[i][0] == C) printf("Tab[%d] = %s\n", i, tab[i]);
}
void usun_index_wrapper(char*** tab) {
    //pobierz indeks
    int i;
    printf("Podaj indeks ktory chcesz usunac: ");
    scanf("%d", &i);
    //sprawdz poprawnosc indeksu
    if (i<0 || i > zlicz(*tab)) printf("Niepoprawny indeks\n");
    //wywołaj usun_index()
    else usun_index(tab, i);
}
void usun_index(char*** tab, int index) {
    //zakładamy że indeks przekazany do funckji jest poprawny
    //zwolnij pamiec pod indeksem
    free((*tab)[index]);
    //przesun adresy imion o jeden w lewo, zaczynajac od indeksu
    int i = index;
    int size = zlicz(*tab);
    while (i < size) {
        (*tab)[i] = (*tab)[i + 1];
        i++;
    }
    //zmniejsz rozmiar tablicy
    *tab = (char**)realloc(*tab, sizeof(char**) * (size));
   
}
void usun_imie(char*** tab) {
    //pobierz imie i zapisz do bufora
    char buffer[L];
    printf("Podaj imie do usuniecia: ");
    fgets(buffer, L, stdin);
    
    //przeszukaj tablice, gdy znajdziesz imie, wywołaj usun_index()
    int i = 0;
    while ((*tab)[i] != NULL) {
        if (strcmp((*tab)[i], buffer) == 0) usun_index(tab, i--);
        i++;
    }
    
}
void sortuj_alfabetycznie(char** tab) {
    int size = zlicz(tab);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j + 1 < size; j++) {
            if (strcmp(tab[j],tab[j+1]) > 0) {
                char* tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}
void sortuj_dlugosc(char** tab) {
    int size = zlicz(tab);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j + 1 < size; j++) {
            if (strlen(tab[j]) > strlen(tab[j + 1])) {
                char* tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
        }
    }
}
