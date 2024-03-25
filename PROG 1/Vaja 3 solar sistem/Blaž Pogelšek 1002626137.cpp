#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const float PI = 3.14;
const int STEVILO_PLANETOV = 8;

int IzracunajProcente(float COpazovanja, float obhodniC);
void NarisiPot(int procenti);
float IzracunajMankajocoPot(float radij, float COpazovanja, float obhodniC);
void NarisiGraf(string planet, int sirinaG, int procenti);

int main() {
    string planeti[STEVILO_PLANETOV];
    float radiji[STEVILO_PLANETOV];
    float obhodniCasi[STEVILO_PLANETOV];

    ifstream vhodniFile("vhodni.txt");
    string line;
    int index = 0;

    if (!vhodniFile) {
        cout << "File could not be opened!" << endl;
        return -1; // error code
    }

    while (getline(vhodniFile, line) && index < STEVILO_PLANETOV) {
        stringstream ss(line);
        ss >> planeti[index] >> radiji[index] >> obhodniCasi[index];
        index++;
    }

    vhodniFile.close();

    int sirinaG;
    float COpazovanja;

    cout << "Vpisi cas opazovanja: ";
    cin >> COpazovanja;
    cout << "Vpisi sirino grafa: ";
    cin >> sirinaG;
    cout << endl;

    for (int i = 0; i < STEVILO_PLANETOV; ++i) {
        NarisiGraf(planeti[i], sirinaG, IzracunajProcente(COpazovanja, obhodniCasi[i]));
    }
    return 0;
}

int IzracunajProcente(float COpazovanja, float obhodniC) {
    if (obhodniC == 0) {
        return 0;
    }
    int procenti = static_cast<int>((COpazovanja / obhodniC) * 100);
    return procenti;
}

float IzracunajMankajocoPot(float radij, float COpazovanja, float obhodniC) {
    float kHitrost = (2 * PI * radij) / obhodniC;
    float obhod = 2 * PI * radij;
    float mankajocaP = obhod - COpazovanja * kHitrost;
    return mankajocaP;
}

void NarisiPot(int procenti) {
    float procentMankajocePoti = 100 - procenti;
    for (int x = 0; x < procenti; x++) {
        cout << "*";
    }
    for (int y = 0; y < procentMankajocePoti; y++) {
        cout << ".";
    }
}

void NarisiGraf(string planet, int sirina, int procenti) {
    cout << planet << ":" << endl;
    cout << "Procenti: " << procenti << "%" << endl;
    int obhodi = procenti / 100;
    procenti %= 100;

    if (obhodi > 0) {
        cout << "Naredil je: " << obhodi << (obhodi > 1 ? " obhodov " : " obhod ") << "okrog sonca." << endl;
    }

    for (int i = 0; i < sirina; ++i) {
        NarisiPot(procenti);
        cout << endl;
    }
}