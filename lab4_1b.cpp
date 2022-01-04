#include <iostream>

using namespace std;

void wczytaj_rownanie(float*, float*, float*);
void wypisz_rozwiazanie(int, float, float);
float wyznacznik(float, float, float, float);
int oblicz_rozwiazanie(float, float, float, float, float, float, float*, float*);
int main() {
    float a1, a2, b1, b2, c1, c2, x, y;
    float* a1_ptr = &a1;
    float* a2_ptr = &a2;
    float* b1_ptr = &b1;
    float* b2_ptr = &b2;
    float* c1_ptr = &c1;
    float* c2_ptr = &c2;
    float* x_ptr = &x;
    float* y_ptr = &y;
    int N;
    int* N_ptr = &N;
    wczytaj_rownanie(a1_ptr, b1_ptr, c1_ptr);
    wczytaj_rownanie(a2_ptr, b2_ptr, c2_ptr);
    *N_ptr = oblicz_rozwiazanie(a1, a2, b1, b2, c1, c2, x_ptr, y_ptr);
    wypisz_rozwiazanie(N, x, y);
	return 0;
}


void zad1a() {
    float a1, a2, b1, b2, c1, c2, x, y;
    int N;
    wczytaj_rownanie(&a1, &b1, &c1);
    wczytaj_rownanie(&a2, &b2, &c2);
    N = oblicz_rozwiazanie(a1, a2, b1, b2, c1, c2, &x, &y);
    wypisz_rozwiazanie(N, x, y);
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

int oblicz_rozwiazanie(float a1, float a2, float b1, float b2, float c1, float c2, float* x, float* y) {
    float W = wyznacznik(a1, a2, b1, b2);
    float Wx = wyznacznik(c1, c2, b1, b2);
    float Wy = wyznacznik(a1, a2, c1, c2);
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
