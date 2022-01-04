#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

/*
Autor: Marcin Szymczak 263909
Data: 03.12.2021
Temat: Labolatorium 4
Grupa: Pt/N 17:05

*/

char global_c = 'a';
int global_i = 78236478;
long global_l = 21;
float global_f = 3.7f;
double global_d = 20.04;

bool menu(); // Funkcja kontrolująca które zadanie zostanie wykonane. Zwraca false po wciśnięciu klawisza ESC, true w każdym innym
void zad1a();

void zad2();
void zad4();
int usun_cyfry(char*); //Przyjmuje wskaźnik na początek łancucha znaków, z założenie nie dłuższego niż 80, usuwa wszystkie cyfry z łańcucha i zapisuje pod oryginalnym adresem.
void wczytaj_rownanie(float*, float*, float*); //wczytuje pojedyncze równanie liniowe postaci ax+by=c, zapisuje a b i c w zmiennych których adresy są argumentami
void wypisz_rozwiazanie(int, float, float); // w zaleznosic od N wypisuje "brak rozwiazan" dla N=-1, "inf rozwiazan" dla N=0, konkretna pare liczb dla N=1
float wyznacznik(float, float, float, float);// fliczy wyznacznik macierzy [(a1,b1).(a2,b2)], kolejnosc argumentow to a1,a2,b1,b2
int oblicz_rozwiazanie(float, float, float, float,float,float, float*, float*);
    // rozwiazuje uklad 2 rownan liniowych, argumenty to a1,a2,b1,b2,c1,c2,adresy 2 zmiennych gdzie nalezy zapisac rozwiazanie.
    //zwraca -1 dla ukladu sprzecznego, 0 dla nieoznaczonego, 1 dla oznaczonego
char* usun_komentarze(char*); //z lancucha znakow rozpoczynajacego sie od podanego adresu usuwa wszystkie komentarze, zapisuje lancuch pod jego oryginalnym adresem i zwraca ten adres
void print_raw_data(void*,size_t);//wypisuje wartosci pojednczych bajtów pamięci składających sie na zmienną której adres jest argumentem. Drugi argument to rozmiar zmiennej w B
void zad4_print_all(char*,int*,long*,float*,double*);

int main()
{
    while(menu());
    return 0;
}

bool menu() {
    char c;
    system("cls");
    void (* arr[10])();
    arr[0] = &zad1a;
    arr[1] = &zad2;
    arr[2] = &zad4;
    cout << "Wybierz zadanie\n";
    cout << "1: Zadanie 1a\n";
    cout << "2: Zadanie 2 i 3\n";
    cout << "3: Zadanie 4\n";
    cout << "[ESC] Zakoncz program\n";
    c = _getch();
    if (c == 27) return false;
    while (c < 0 || c > '4') c = _getch();
    arr[c-'0'-1]();
    cout << "\n --- Wcisnij dowolny klawisz --- \n";
    _getch();
    return true;
}

void zad1a() {
    float a1, a2, b1, b2,c1,c2, x, y;
    int N;
    wczytaj_rownanie(&a1, &b1,&c1);
    wczytaj_rownanie(&a2, &b2,&c2);
    N = oblicz_rozwiazanie(a1, a2, b1, b2,c1,c2, &x, &y);
    wypisz_rozwiazanie(N,x,y);
}



void wczytaj_rownanie(float* a, float* b, float* c)
{
    cout << "\nPodaj a: "; cin >> *a;
    cout << "\nPodaj b: "; cin >> *b;
    cout << "\nPodaj c: "; cin >> *c;
    return;
}

void wypisz_rozwiazanie(int N, float x, float y)
{
    if (N == -1) cout << "\nUklad sprzeczny\n";
    else if (N == 0) cout << "\nUklad nieoznaczony\n";
    else if (N == 1) {
        cout << "\n x = " << x << "\n y = " << y;
    }
    return;
}

float wyznacznik(float a1, float a2, float b1, float b2)
{
    float f = 0.0f;
    f += (a1 * b2);
    f -= (b1 * a2);
    return f;
}

int oblicz_rozwiazanie(float a1, float a2, float b1, float b2,float c1, float c2, float* x, float* y){
    float W = wyznacznik(a1, a2, b1, b2);
    float Wx = wyznacznik(c1, c2, b1, b2);
    float Wy = wyznacznik(a1,a2,c1,c2);
    if (W == 0) {
        if (Wx == 0 && Wy == 0) return 0;
        else return -1;
    }
    else {
        *x = Wx / W;
        *y = Wy / W;
        return 1;
    }
    
}

void zad2() {
    char str[81];
    cout << "Podaj lancuch znakow:\n";
    fgets(str, 80, stdin);
    int cyfry = usun_cyfry(str);
    cout << "Usunieto " << cyfry << " cyfr" << endl;
    cout << endl << str << endl;
    cout << "*Usuwanie komentarzy*" << endl;
    cout << usun_komentarze(str) << endl;
}

int usun_cyfry(char* str) {
    int i = 0;
    int counter = 0;
    while (str[i] != 0 && i < 80) {
        if (str[i] >= '0' && str[i] <= '9') counter++;
        else str[i - counter] = str[i];
        i++;
    }
    str[i - counter] = 0;
    return counter;
}

char* usun_komentarze(char* str) {
    bool inComment = false;
    int pos = 0;
    int i;
    for (i = 0; i < 80; i++) {
        if (str[i] == '/' && i < 79 && str[i + 1] == '*') inComment = true;
        else if (str[i] == '/' && i < 79 && str[i + 1] == '/') { i--; break; }
        else if (str[i] == '*' && i < 79 && str[i + 1] == '/') {
            inComment = false;
            i += 2;
        }
        if (!inComment) {
            str[pos] = str[i];
            pos++;
        }
    }
    str[pos] = 0;
    return str;

}

void print_raw_data(void* ptr, size_t s) {
    for (int i = 0; i < s; i++)
        printf(" 0x%02x ", *((unsigned char*)ptr + i));
}

void zad4() {
    char local_c = 'a';
    int local_i = 1;
    long local_l = 21;
    float local_f = 3.7f;
    double local_d = 20.04;
    
    char* lc = &local_c;
    int* li = &local_i;
    long* ll = &local_l;
    float* lf = &local_f;
    double* ld = &local_d;

    char* gc = &global_c;
    int* gi = &global_i;
    long* gl = &global_l;
    float* gf = &global_f;
    double* gd = &global_d;

    zad4_print_all(&local_c, &local_i, &local_l, &local_f, &local_d);

    *gc = 'x';
    *gi = 5;
    *gl = 5;
    *gf = 5.0f;
    *gd = 5;

    *lc = 'd';
    *li = 20;
    *ll = 20;
    *lf = 20.0f;
    *ld = 20;
    printf("\n\n");
    zad4_print_all(&local_c, &local_i, &local_l, &local_f, &local_d);
    *(gi + 1) = 13;
    printf("\n\n");
    zad4_print_all(&local_c, &local_i, &local_l, &local_f, &local_d);
}

void zad4_print_all(char* c,int* i,long* l,float* f,double* d) {
    printf("Zmienne globalne:\n");
    printf("\t Zmienna c: Adres:0x%p  Wartosc: %-10c  Bajty:", &global_c, global_c);
    print_raw_data(&global_c, sizeof(char));
    printf("\n\t Zmienna i: Adres:0x%p  Wartosc: %-10d  Bajty:", &global_i, global_i);
    print_raw_data(&global_i, sizeof(int));
    printf("\n\t Zmienna l: Adres:0x%p  Wartosc: %-10ld  Bajty:", &global_l, global_l);
    print_raw_data(&global_l, sizeof(long));
    printf("\n\t Zmienna f: Adres:0x%p  Wartosc: %-10f  Bajty:", &global_f, global_f);
    print_raw_data(&global_f, sizeof(float));
    printf("\n\t Zmienna d: Adres:0x%p  Wartosc: %-10f  Bajty:", &global_d, global_d);
    print_raw_data(&global_d, sizeof(double));
    printf("\nZmienne lokalne:\n");
    printf("\t Zmienna c: Adres:0x%p  Wartosc: %-10c  Bajty:", c, *c);
    print_raw_data(c, sizeof(char));
    printf("\n\t Zmienna i: Adres:0x%p  Wartosc: %-10d  Bajty:", i, *i);
    print_raw_data(i, sizeof(int));
    printf("\n\t Zmienna l: Adres:0x%p  Wartosc: %-10ld  Bajty:", l, *l);
    print_raw_data(l, sizeof(long));
    printf("\n\t Zmienna f: Adres:0x%p  Wartosc: %-10f  Bajty:", f, *f);
    print_raw_data(f, sizeof(float));
    printf("\n\t Zmienna d: Adres:0x%p  Wartosc: %-10f  Bajty:",d, *d);
    print_raw_data(d, sizeof(double));
    printf("\n");

}