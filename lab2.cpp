#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <random>
#include <cmath>
#include <conio.h>
using namespace std;
/*
Autor: Marcin Szymczak 263909
Data: 5.11.2021
Grupa: Pt/N 17:05
Tytul: Labolatorium 2

*/

void zad1();
void zad2();
int nwd(int a, int b);
void zad3();
void zad4();
void zad5();

int main()
{
    char c = '0';
    while(true){
        system("cls");
        printf("Wybierz zadanie: \n");
        printf("1. Tabliczka mnozenia\n");
        printf("2. Suma cyfr\n");
        printf("3. NWD i NWW\n");
        printf("4. Suma szeregow\n");
        printf("5. Losowa srednia\n");
        printf("6. Zakoncz program\n");
        c = _getch();
        switch (c) {
        case '1':
            zad1();
            break;
        case '2':
            zad2();
            break;
        case '3':
            zad3();
            break;
        case '4':
            zad4();
            break;
        case '5':
            zad5();
            break;
        case '6':
            return 0;
            break;
        }
        cout << "\nKontynowac? t/n: ";
        c = _getch();
        if (c == 'n') break;
    };
    
    return 0;
}

void zad1() {
    int wiersze, kolumny;
    printf("\nZadanie 1:\n");
    printf("Poaj ilosc wierszy: ");
    scanf_s("%d", &wiersze);
    printf("Poaj ilosc kolumn: ");
    scanf_s("%d", &kolumny);
    printf("     :");
    for (int i = 1; i <= kolumny; i++) printf("%4d ", i);
    printf("\n");
    for (int i = 1; i <= kolumny; i++) printf("-----");
    printf("\n");
    for (int i = 1; i <= wiersze; i++) {
        printf("%4d :",i);
        for (int j = 1; j <= kolumny; j++) {
            printf("%4d ",i*j);
        }
        printf("\n");
    }
}
void zad2() {
    printf("\nZadanie 2:\n");
    printf("Podaj liczbe: ");
    unsigned long x;
    scanf_s("%ul", &x);
    int base = 10;
    printf("W jakim systemie liczbowym wykonac obliczenia? ");
    scanf_s("%d", &base);
    int suma_cyfr = 0;
    while (x > 0) {
        suma_cyfr += x % base;
        x /= base;
    }
    printf("Suma cyfr wynosi %d w BASE(10)\n", suma_cyfr);

}
int nwd(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else if (b > a) b -= a;
    }
    return a;
    
}
void zad3() {
    printf("\nZadanie 3:\n");
    int a, b;
    printf("Podaj a: ");
    scanf_s("%d", &a);
    printf("\nPodaj b: ");
    scanf_s("%d", &b);
    printf("\nNWD(a,b) = %d", nwd(a, b));
    printf("\nNWW(a,b) = %d", (a * b / nwd(a, b)));

}
void zad4() {
    printf("\nZadanie 4:\n");
    float eps;
    printf("123Podaj dokladnosc obliczen ( < 0.1 ): ");
    scanf_s("%f", &eps);
    if (eps < 0.1) {
        //S1
        double suma_s1 = 0;
        double wyraz;
        int k=1;
        do {
            wyraz = (1 / ((2 * (double)k) - 1)) * (k % 2 ? 1 : -1);
            suma_s1 += wyraz;
            //printf("Wyraz: %f\n", wyraz);
            k++;
        } while (fabs(wyraz) >= eps);
        printf("\nSuma szeregu 1 z dokladnoscia do %f wynosi %f", eps,suma_s1*4);


        //S2
        double suma_s2 = 1;
        wyraz = 1;
        k = 1;
        do {
            wyraz = wyraz / k;
            k++;
            suma_s2 += wyraz;

        } while (fabs(wyraz) >= eps);

        printf("\nSuma szeregu 2 z dokladnoscia do %f wynosi %f", eps, suma_s2);

    }
    else {
        printf("Zbyt duza dokladnosc\n");
        return;
    }
    
}
void zad5() {
    printf("\nZadanie 5:\n");
    int from, to,amount;
    printf("Poczatek zakresu: ");
    scanf_s("%d", &from);
    printf("Koniec zakresu: ");
    scanf_s("%d", &to);
    if (to < from) {
        cout << "Niepoprawny zakres\n";
        return;
    }
    printf("Ile liczb wygenerowac? ");
    scanf_s("%d", &amount);
    srand(time(NULL));
    int sum_p = 0;
    int sum_n = 0;
    int count_p = 0;
    int count_n = 0;
    for (int i = 0; i < amount; i++) {
        int tmp = rand() % (to - from + 1) + from;
        if (tmp < 0) {
            count_n++;
            sum_n += tmp;
        }
        else if (tmp > 0) {
            count_p++;
            sum_p += tmp;
        }
    }
    printf("Wygenerowano %d liczb dodatnich, srednia tych liczb wynosi %.3f\n", count_p, (float)sum_p / (float)count_p);
    printf("Wygenerowano %d liczb ujemnych, srednia tych liczb wynosi %.3f\n", count_n, count_n ? (float)sum_n / (float)count_n : 0);
    
}