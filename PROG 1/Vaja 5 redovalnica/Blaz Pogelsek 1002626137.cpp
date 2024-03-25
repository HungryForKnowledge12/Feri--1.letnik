#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Funkcija za zamenjavo dveh celih števil.
void zamenjaj(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funkcija za generiranje naključne številke.
int generirajNakljucno(int spodnjaMeja, int zgornjaMeja) {
    return rand() % (zgornjaMeja - spodnjaMeja + 1) + spodnjaMeja;
}

// Funkcija za izračun povprečne ocene.
int izracunajPovprecje(int kviz, int laboratorijskeVaje, int kolokvij) {
    int povprecje = 0;
    if (laboratorijskeVaje < 50 && kolokvij < 50) {
        return 0;
    }
    if (laboratorijskeVaje < 50) {
        return 2;
    }
    if (kolokvij < 50) {
        return 1;
    }
    povprecje = (kviz*0.33 + laboratorijskeVaje*0.33 + kolokvij * 0.33) / 10;
    return povprecje < 5 ? 5 : povprecje;
}

// Funkcija za izračun povprečne ocene študentov, ki so opravili izpit.
double izracunajPovprecjeVseh(int seznam[166][7], int &stStudentov) {
    double povprecje = 0;
    double sum = 0;
    for (int i = 0; i < 166; i++) {
        if (seznam[i][6] >= 5) {
            sum += seznam[i][6];
            stStudentov++;
        }
    }
    povprecje = sum / stStudentov;
    return povprecje;
}

// Funkcija za določanje ocen in imen študentov.
void dodeliOceneInImena(int seznam[166][7], string imena[], string priimki[]) {
    for (int i = 0; i < 166; i++) {
        int koncnaOcena = 0;
        seznam[i][0] = i + 1;
        seznam[i][1] = generirajNakljucno(0, 29);
        seznam[i][2] = generirajNakljucno(0, 19);
        seznam[i][3] = generirajNakljucno(0, 100);
        seznam[i][4] = generirajNakljucno(0, 100);
        seznam[i][5] = generirajNakljucno(0, 100);
        koncnaOcena = izracunajPovprecje(seznam[i][3], seznam[i][4], seznam[i][5]);
        seznam[i][6] = koncnaOcena;
    }
}

// Funkcija za prikaz redovalnice.
void izpisiRedovalnico(int seznam[166][7], string imena[], string priimki[]) {
    for (int i = 0; i < 166; i++) {
        cout <<"\t|" << seznam[i][0] << "\t|" << imena[seznam[i][1]] << "\t" << priimki[seznam[i][2]] << "\t|" << seznam[i][3] << "\t|" << seznam[i][4] << "\t|" << seznam[i][5] << "\t|";
        if (seznam[i][6] == 2) {
            cout << "RV";
        }
        else if (seznam[i][6] == 1) {
            cout << "VI";
        }
        else if (seznam[i][6] == 0) {
            cout << "RV,VI";
        }
        else {
            cout << seznam[i][6];
        }
        cout << endl;
    }
}

// Funkcija za urejanje redovalnice po padajočem vrstnem redu na podlagi končnih ocen.
void urediRedovalnico(int seznam[166][7]) {
    int temp[7];
    for (int i = 0; i < 166; i++) {
        for (int j = i + 1; j < 166; j++) {
            if (seznam[i][6] < seznam[j][6]) {
                for (int k = 0; k < 7; k++) {
                    temp[k] = seznam[i][k];
                    seznam[i][k] = seznam[j][k];
                    seznam[j][k] = temp[k];
                }
            }
        }
    }
}

// Funkcija za prikaz ocen, ki so najbližje povprečju.
void izpisiNajblizje(int seznam[166][7], int povprecje, int stStudentov) {
    for (int i = 0; i < stStudentov; i++) {
        if (seznam[i][6] == povprecje) {
            cout << seznam[i][0] << " ";
        }
    }
}

int main() {
    srand(time(NULL));
    int redovalnica[166][7];
    string ime[30] = { "Luka", "Tina", "Sara", "Miha", "Kata", "Nina", "Jure", "Andrej", "Lara", "Matej", "Vid", "Lana", "Nik", "Eva", "Maja", "Zala", "Jan", "Ana", "Lina", "Tim", "Matic", "Ela", "Urban", "Nina", "Lan", "Teja", "Ziga", "Pia", "Leon", "Taja" };
    string priimek[20] = {"Kovac", "Potok", "Bergant", "Zupan", "Bizjak", "Jerman", "Knez", "Mavric", "Vidic", "Babic", "Bozic", "Vidmar", "Jereb", "Brezni", "Kranjc", "Pavlic", "Lovse", "Zorman", "Cerne", "Majer"};
    double povprecjeVsehStudentov = 0;
    int stStudentov = 0;

    dodeliOceneInImena(redovalnica, ime, priimek);
    urediRedovalnico(redovalnica);

    cout << "\t|ID\t|Ime in Priimek\t|KV\t|RV\t|VI\t|OC" << endl;
    cout << "\t-------------------------------------------------------" << endl;
    izpisiRedovalnico(redovalnica, ime, priimek);
    cout << "\t-------------------------------------------------------";

    povprecjeVsehStudentov = izracunajPovprecjeVseh(redovalnica, stStudentov);
    cout.precision(2);
    cout << endl << "Povprecna ocena studentov, ki so opravili izpit je: " << povprecjeVsehStudentov << " (najblizje pod zaporedno st.: ";
    izpisiNajblizje(redovalnica, povprecjeVsehStudentov, stStudentov);
    cout << ")." << endl << endl;

    return 0;
}
