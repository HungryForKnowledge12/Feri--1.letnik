#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Igralec {
    int id;
    string ime;
    string trenutnoUgibanoGeslo;
    string zgodovinaUgibanihCrk;
    time_t zacetekCas;
    time_t pretecenCas;
    Igralec* next;
};

const int ST_IGRALCEV = 10;
const int ST_GESL = 100;
string gesla[ST_GESL];
const int ST_SCENARIJEV = 10;
string scenariji[ST_SCENARIJEV];

int napolniGesla(int dolzina);
void izberiNakljucnoGeslo(string& geslo, int dolzinaGesel);
void napolniScenariji();
void izrisiScenarij(int scenarij);
void igraj(Igralec& igralec, int loadedPasswordCount);
void izpisStatistike(Igralec* seznamIgralcev);
void dodajIgralcaVSeznam(Igralec** seznam, Igralec* novIgralec);
void shraniStatistike(Igralec* seznamIgralcev);

int main() {
    srand(time(NULL));
    Igralec* seznamIgralcev = nullptr;
    int dolzinaGesla;

    cout << "Vnesite dolzino gesla: ";
    cin >> dolzinaGesla;
    int countLoadedPasswords = napolniGesla(dolzinaGesla);
    napolniScenariji();

    for (int i = 0; i < ST_IGRALCEV; ++i) {

        cin >> igralec.ime ;
        Igralec* novIgralec = new Igralec;
        cout << "Vnesite ime igralca: ";
        cin >> novIgralec->ime;
        novIgralec->id = i + 1;
        novIgralec->next = nullptr;
        igraj(*novIgralec, countLoadedPasswords);
        dodajIgralcaVSeznam(&seznamIgralcev, novIgralec);
    }

    izpisStatistike(seznamIgralcev);
    shraniStatistike(seznamIgralcev);

    while (seznamIgralcev != nullptr) {
        Igralec* temp = seznamIgralcev;
        seznamIgralcev = seznamIgralcev->next;
        delete temp;
    }

    return 0;
}

void dodajIgralcaVSeznam(Igralec** seznam, Igralec* novIgralec) {
    if (*seznam == nullptr) {
        *seznam = novIgralec;
        return;
    }

    int stNapacnihUgibanjNovIgralec = novIgralec->zgodovinaUgibanihCrk.length();
    int stNapacnihUgibanjPrviIgralec = (*seznam)->zgodovinaUgibanihCrk.length();

    if (stNapacnihUgibanjNovIgralec < stNapacnihUgibanjPrviIgralec) {
        novIgralec->next = *seznam;
        *seznam = novIgralec;
    } else {
        Igralec* trenutni = *seznam;
        while (trenutni->next != nullptr && trenutni->next->zgodovinaUgibanihCrk.length() < stNapacnihUgibanjNovIgralec) {
            trenutni = trenutni->next;
        }
        novIgralec->next = trenutni->next;
        trenutni->next = novIgralec;
    }

    Igralec* temp = *seznam;
    int count = 1;
    while (temp != nullptr && count < 5) {
        temp = temp->next;
        count++;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Igralec* toDelete = temp->next;
        temp->next = nullptr;
        while (toDelete != nullptr) {
            Igralec* nextToDelete = toDelete->next;
            delete toDelete;
            toDelete = nextToDelete;
        }
    }
}

void izpisStatistike(Igralec* seznamIgralcev) {
    Igralec* trenutni = seznamIgralcev;
    while (trenutni != nullptr) {
        cout << "Statistika za igralca: " << trenutni->ime << endl;
        cout << "ID igralca: " << trenutni->id << endl;
        cout << "Pretecen cas: " << trenutni->pretecenCas << " s" << endl;
        cout << "Stevilo napacnih ugibanj: " << trenutni->zgodovinaUgibanihCrk.length() << endl;
        cout << endl;
        trenutni = trenutni->next;
    }
}

int napolniGesla(int dolzina) {
    ifstream file("gesla.txt");
    string line;
    int index = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.length() == dolzina) {
                gesla[index++] = line;
                if (index >= ST_GESL) break;
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file gesla.txt" << endl;
    }
    return index;
}

void izberiNakljucnoGeslo(string& geslo, int dolzinaGesel) {
    if (dolzinaGesel == 0) {
        cout << "Ni gesel ustrezne dolzine." << endl;
        return;
    }

    int randomIndex = rand() % dolzinaGesel;
    geslo = gesla[randomIndex];
}

void napolniScenariji() {
    ifstream file("scenariji.txt");
    string line, trenutniScenari;
    int scenariIndex = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("const char *scenarij") != string::npos) {
                if (!trenutniScenari.empty()) {
                    scenariji[scenariIndex++] = trenutniScenari;
                    trenutniScenari.clear();
                }
            } else {
                trenutniScenari += line + "\n";
            }
        }
        if (!trenutniScenari.empty()) {
            scenariji[scenariIndex] = trenutniScenari;
        }
        file.close();
    } else {
        cerr << "Unable to open file scenariji.txt" << endl;
    }
}

void izrisiScenarij(int stNapak) {
    if (stNapak < 0 || stNapak >= ST_SCENARIJEV) {
        cout << "Napaka: Neveljaven scenarij" << endl;
        return;
    }
    cout << scenariji[stNapak] << endl;
}

void igraj(Igralec& igralec, int passDolzina) {
    string geslo;
    izberiNakljucnoGeslo(geslo, passDolzina);

    igralec.trenutnoUgibanoGeslo = string(geslo.length(), '_');
    igralec.zgodovinaUgibanihCrk = "";
    int scenarijIndex = 0;
    int napacniUgib = 0;

    igralec.zacetekCas = time(nullptr);

    while (true) {
        cout << "Trenutno stanje: " << igralec.trenutnoUgibanoGeslo << endl;
        cout << "Ugibajte crko ali geslo: ";
        string ugib;
        cin >> ugib;

        if (ugib.length() > 1) {
            if (ugib == geslo) {
                igralec.trenutnoUgibanoGeslo = geslo;
                cout << "Uspesno ste uganili geslo!" << endl;
                break;
            } else {
                napacniUgib++;
            }
        } else {
            char guessedChar = ugib[0];
            bool correctGuess = false;

            for (size_t i = 0; i < geslo.length(); i++) {
                if (geslo[i] == guessedChar) {
                    igralec.trenutnoUgibanoGeslo[i] = guessedChar;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                napacniUgib++;
                if (igralec.zgodovinaUgibanihCrk.find(guessedChar) == string::npos) {
                    igralec.zgodovinaUgibanihCrk += guessedChar;
                }
            }
        }

        izrisiScenarij(napacniUgib);

        if (igralec.trenutnoUgibanoGeslo == geslo) {
            cout << "Cestitamo! Uganili ste geslo: " << geslo << endl;
            break;
        }

        if (napacniUgib >= ST_SCENARIJEV) {
            cout << "Game over! Geslo je bilo: " << geslo << endl;
            break;
        }
    }

    igralec.pretecenCas = time(nullptr) - igralec.zacetekCas;
}

void shraniStatistike(Igralec* seznamIgralcev) {
    ofstream file("statistika.txt");
    if (!file.is_open()) {
        cerr << "Unable to open file statistika.txt" << endl;
        return;
    }

    Igralec* trenutni = seznamIgralcev;
    while (trenutni != nullptr) {
        file << "Statistika za igralca: " << trenutni->ime << endl;
        file << "ID igralca: " << trenutni->id << endl;
        file << "Pretecen cas: " << trenutni->pretecenCas << " s" << endl;
        file << "Stevilo napacnih ugibanj: " << trenutni->zgodovinaUgibanihCrk.length() << endl;
        file << endl;
        trenutni = trenutni->next;
    }

    file.close();
}