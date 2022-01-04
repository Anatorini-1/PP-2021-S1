#include <iostream>
#include <string>
#define _USE_MATH_CONSTANTS
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
/*
 * Autor: Marcin Szymczak
 * Grupa: Pt/N 17:05
 * Data: 22.10.2021
 * Temat: Labolatorium 1
 */

using namespace std;

bool valiDate(int day, int month, int year); // Funkcja sprawdzajaca poprawnosc daty
void zad1();
void zad2();
void zad3();
void zad4();

int main() {

    cout << "Autor: Marcin Szymczak (PT/N 17:05)" << endl;
    zad1();
    zad2();
    zad3();
    zad4();
    system("pause");
    return 0;
}

void zad1(){
    float a,b,c;
    cout << "Zadanie 1, podaj wspolczynniki trojmianu: ";
    cin >> a >> b >> c;
    if (a == 0){
        cout << "Nie jest to rownanie kwadratowe\n";
        return;
    }
    float delta = b*b - 4*(a*c);
    cout << endl;
    if (delta < 0) cout <<"Brak rozwiazan"<<endl;
    else if (delta == 0) cout <<"1 rozwiazanie: "<< (-b)/(2*a) <<endl;
    else cout <<"Rozwiazania: x1 = "<<(-b - sqrt(delta))/(2*a) << " x2 = "<< (-b + sqrt(delta))/(2*a)<<endl;
}

bool valiDate(int day , int month, int year){
    if (day > 31 || month > 12 || month < 1 || day < 1 ) return false;
    if (day <= 28) return true;
    if (month == 2 ) {
        if (day == 29)
            return !(year % 4 || (year % 100 == 0 && year % 400));
        else
            return false;
    }
    if (day == 30) return true;
    return (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12);

}
void zad2(){
    int day,month,year;
    cout << endl << "Zadanie 2, podaj date: ";
    cin >> day >> month >> year;
    cout <<endl << "Data jest " << (valiDate(day,month,year) ? "poprawna" : "niepoprawna");

}

void zad3(){
    float a,b,c;
    cout << endl << "Zadanie 3, podaj 3 odcinki: ";
    cin >> a >> b >> c;
    if (a+b > c && a+c > b && b+c > a){
        cout << endl << "Z podnaych odcinkow mozna utworzyc trojkat" << endl;
        if (a == b || a == c || b == c) cout << "Bedzie to trojkat rownoramienny" << endl;
        if (a == b && b == c) cout << "Bedzie to trojkat rownoboczny" << endl;
            if (a > b){
                float tmp = a;
                a = b;
                b = tmp;
            }
            if (b > c){
                float tmp = b;
                b = c;
                c = tmp;
            }
            float a2_b2 = a*a + b*b;
            if( a2_b2 == (c*c)) cout << "Trojkat bedzie prostokatny"<< endl;
            else if (a2_b2 < (c*c)) cout << "Trojkat bedzie rozwartokatny" << endl;
            else cout << "Trojkat bedzie ostrokatny" << endl;
    }
    else{
        cout << endl << "Z podanych odcinkow nie mozna utworzyc trojkata :(" << endl;
    }

}

void zad4(){
    float min,max;
    int wiersze;
    cout << "\nZadanie 4, podaj promien min, max i ilosc wierszy: ";
    cin >> min >> max >> wiersze;
    cout << setw(42) << setfill('=') << "" << endl;
    cout << ": Lp : promien : odwod kola : pole kola  :"<<endl;
    cout << setw(42) << setfill('=') << "" << endl;
    for(int i = 0; i < wiersze; i++) {
        float r = min + ((float) i * (((max - min) / (float) (wiersze - 1))));
        printf(": %2d : %7.2f : %10.2f : %9.2f :\n", i + 1, r, 2 * M_PI * r, M_PI * r * r);
    }
    cout << setw(42) << setfill('=') << "" << endl;

}
