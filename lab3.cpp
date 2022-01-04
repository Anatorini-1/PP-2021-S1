#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define ROZMIAR 5
using namespace std;
/*
Autor: Marcin Szymczak
Data: 19.11.2021
Tytuł: Labolatorium 3
Grupa: PT/N 17:05
*/

bool menu(float *arr);
void zad1_wczytaj(float *arr);
void zad1_wypisz(float *arr);
void zad1_informacje(float *arr);
void zad1_uporzodkowanie(float *arr);
void zad2_losuj(float *arr);
void zad3_sortuj(float *arr);

int main()
{
    cout << "Autor: Marcin Szymczak 263909" << endl;
    float tab[ROZMIAR];

    while (menu(tab))
    {
        cout << endl
             << "Nacisnij dowolny klawisz aby kontynuowac..." << endl;
        cin.ignore();
        getch();
        system("cls");
    }
}

bool menu(float *arr)
{
    char x;
    cout << "\n\n---  Wybierz funkcje:  ---" << endl;
    cout << "1. Wprowadz dane do tablicy" << endl;
    cout << "2. Wypisz dane zapisane w tablicy " << endl;
    cout << "3. Informacje o liczbach dodatnich i ujemnych " << endl;
    cout << "4. Informacje o uporzadkowaniu elementow" << endl;
    cout << "5. Wylosuj zawartosc tablicy" << endl;
    cout << "6. Uporzadkuj wartosci w tablicy rosnaco" << endl;
    cout << "7. Zakoncz program \n\n"
         << endl;
    char c;
    cin >> c;
    switch (c)
    {
    case '1':
        zad1_wczytaj(arr);
        break;
    case '2':
        zad1_wypisz(arr);
        break;
    case '3':
        zad1_informacje(arr);
        break;
    case '4':
        zad1_uporzodkowanie(arr);
        break;
    case '5':
        zad2_losuj(arr);
        break;
    case '6':
        zad3_sortuj(arr);
        break;
    case '7':
        return false;
    }
    return true;
}
void zad1_wczytaj(float *arr)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        printf("Tab[%d] = ", i);
        scanf("%f", arr + i);
        printf("\n");
    }
}
void zad1_wypisz(float *arr)
{
    printf("Tab = [ ");
    for (int i = 0; i < ROZMIAR; i++)
        printf(" %.3f ", arr[i]);
    printf(" ]");
}
void zad1_informacje(float *arr)
{
    int dodatnie = 0;
    int ujemne = 0;
    float suma_dodatnie = 0;
    float suma_ujemne = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (arr[i] < 0)
        {
            suma_ujemne += arr[i];
            ujemne++;
        }
        else if (arr[i] > 0)
        {
            suma_dodatnie += arr[i];
            dodatnie++;
        }
    }
    if (dodatnie)
        printf("Liczb dodatnich jest %d a ich srednia wynosi %.3f \n", dodatnie, suma_dodatnie / (float)dodatnie);
    else
        printf("Brak liczb dodatnich \n");
    if (ujemne)
        printf("Liczb ujemnych jest %d a ich srednia wynosi %.3f \n", ujemne, suma_ujemne / (float)ujemne);
    else
        printf("Brak liczb ujemnych \n");
}
void zad1_uporzodkowanie(float *arr)
{
    bool wszystkie_rowne = true;
    bool rosnace = true;
    bool niemalejace = true;
    bool nierosnace = true;
    bool malejace = true;
    for (int i = 1; i < ROZMIAR; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            rosnace = false;
            malejace = false;
        }
        else
        {
            wszystkie_rowne = false;
            if (arr[i] < arr[i - 1])
            {
                rosnace = false;
                niemalejace = false;
            }
            else if (arr[i] > arr[i - 1])
            {
                malejace = false;
                nierosnace = false;
            }
        }
    }
    if (wszystkie_rowne)
        printf("Wszystkie elementy tablicy sa sobie rowne \n");
    else if (rosnace)
        printf("Elementy tablicy sa uporzadowane rosnaco\n");
    else if (niemalejace)
        printf("Elementy tablicy sa uporzadkowane niemalejaco\n");
    else if (malejace)
        printf("Elementy tablicy sa uporzadowane malejaco\n");
    else if (nierosnace)
        printf("Elementy tablicy sa uporzadkowane nierosnaco\n");
    else
        printf("Elementy tablicy nie sa uporzadkowane\n");
}
void zad2_losuj(float *arr)
{
    float min, max;
    printf("Podaj minimalna wartosc: ");
    scanf("%f", &min);
    printf("\n");
    printf("Podaj maksymalna wartosc: ");
    scanf("%f", &max);
    printf("\n");
    srand(time(NULL));
    for (int i = 0; i < ROZMIAR; i++)
        arr[i] = min + (max - min) * rand() / ((double)RAND_MAX);
}
void zad3_sortuj(float *arr)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int j = 1; j < ROZMIAR; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                float tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                isSorted = false;
            }
        }
    }
    printf("\nTablica została posortowana\n");
}
