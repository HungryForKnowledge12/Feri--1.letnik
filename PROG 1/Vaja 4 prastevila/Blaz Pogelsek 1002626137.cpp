#include <iostream>
#include <cmath>

using namespace std;

// Funkcija za preverjanje, ali je število praštevilo
bool prastevilo(int stevilo) {
    if (stevilo < 2) {
        return false;
    }
    for (int i = 2; i < stevilo; i++) {
        if (stevilo % i == 0) {
            return false; // Če najdemo delitelja, število ni praštevilo
        }
    }
    return true;
}

// Funkcija za izračun vsote praštevil do 512
int vsota() {
    int vsota = 0;
    for (int x = 0; x <= 512; x++) {
        if (prastevilo(x)) {
            vsota += x;
        }
    }
    return vsota;
}

// Funkcija za izračun povprečja naslednjih 20 praštevil po danem številu
float povprecje(int polje[], int st) {
    int pov = 0;
    int stevec = 0;
    for (int i = st; stevec < 20; i++) {
        if (prastevilo(i)) {
            polje[stevec] = i;
            pov += i;
            stevec++;
        }
    }
    return pov / 20.0; // Vrni povprečje
}

// Funkcija za izpis prvih 20 praštevil v polju
void izpisi(int polje[]) {
    for (int x = 0; x < 20; x++) {
        cout << polje[x] << " ";
    }
}

// Funkcija za izracun najblizjega prastevila korenu
void najblizji(int &najblizje, int prastevila[], float root) {
    if (root <= prastevila[0]) {
        najblizje = prastevila[0];
        return;
    }
    if (root >= prastevila[19]) {
        najblizje = prastevila[19];
        return;
    }
    for (int i = 0; i < 20; i++) {
        if (prastevila[i] <= root && prastevila[i + 1] >= root) {
            najblizje = prastevila[i];
            return;
        }
    }
}

// Glavna funkcija
int main() {
    int stevilo, st, najblizje = 0;
    int prastevila[20];

    cout << "Vnesi stevilo: ";
    cin >> stevilo;
    if (prastevilo(stevilo)) {
        cout << "Stevilo " << stevilo << " je prastevilo" << endl << endl;
    } else {
        cout << "Stevilo " << stevilo << " ni prastevilo" << endl << endl;
    }

    // Izpis vsote praštevil med -256 in 512
    cout << "____________________________________________________________________" << endl;
    cout << "Med intervalom -256 in 512 je vsota: " << vsota() << endl << endl;

    // Povpraševanje po številu za izračun povprečja
    cout << "____________________________________________________________________" << endl;
    cout << "Vnesi stevilo: ";
    cin >> st;
    cout << "Povprecna vrednost naslednjih 20 prastevil: " << povprecje(prastevila, st) << endl;
    izpisi(prastevila);
    cout << endl << endl;

    // Izračun najbližjega praštevila korenu danega števila
    cout << "____________________________________________________________________" << endl;
    cout << "Vnesi se eno stevilo: ";
    cin >> st;
    float root = sqrt(st);
    cout << "Koren je: " << root << endl;
    najblizji(najblizje, prastevila, root);
    cout << "Najblizje vasemu korenu je: " << najblizje;
    return 0;
}