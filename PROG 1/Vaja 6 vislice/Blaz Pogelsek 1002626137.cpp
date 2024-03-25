#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const char *scenarij1 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **             \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij2 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **       O-    \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij3 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij4 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *              \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij5 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *       /      \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij6 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *       / \\   \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij7 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *        |     \n"
        "       *        |     \n"
        "       *       / \\   \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij8 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *     --=|     \n"
        "       *        |     \n"
        "       *       / \\   \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij9 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *     --=|=--  \n"
        "       *        |     \n"
        "       *       / \\   \n"
        "       *              \n"
        "      * *             \n"
        "     *   *            \n";

const char *scenarij10 =
        "       *  * * * *     \n"
        "       * *      *     \n"
        "       **      -O-    \n"
        "       *    |--=|=--| \n"
        "       *        |     \n"
        "       *      ./ \\.  \n"
        "       *              \n"
        "      * *  GAME OVER! \n"
        "     *   *            \n";

const char *scenariji[] = {scenarij1, scenarij2, scenarij3,scenarij4,scenarij5,scenarij6, scenarij7, scenarij8, scenarij9, scenarij10};

struct Igralec {
    int id;
    string ime;
    string trenutnoUgibanoGeslo;
    string zgodovinaUgibanihCrk;
    time_t zacetekCas;
    time_t pretecenCas;
    int st_poskusov = 0;
};

const int ST_IGRALCEV = 5;
const int ST_GESL = 100;
const string gesla[ST_GESL] = {
        "jabolko", "morje", "sonce", "trgovina", "gozd", "knjiga", "hrana", "avto", "pes", "cvet", "reka", "planina",
        "telefon", "miza", "racunalnik", "vlak", "kolo", "zoga", "gora", "zival", "voda", "ribolov", "gasilci", "muzej",
        "casopis", "sola", "zdravnik", "leto", "jezero", "vlak", "kava", "svetloba", "mesto", "hrast", "trava", "veter",
        "clovek", "zenska", "moski", "stanovanje", "telefon", "denar", "urh", "bencin", "nahrbtnik", "park", "kruh",
        "trgovina", "papir", "pust", "zima", "kino", "zdravje", "jajce", "pesem", "umetnost", "glasba", "slika", "barva",
        "cas", "dan", "noc", "trgovina", "sadje", "zelenjava", "meso", "pica", "sladkarije", "pivo", "vino", "zganje",
        "igraca", "obleka", "cevlji", "kapa", "rokavice", "oblak", "dez", "sneg", "mraz", "zvezda", "mesec", "soncnicna",
        "zita", "solata", "skodelica", "stol", "miza", "racunalniska", "miska", "vrt", "stolp", "ograja","potovanje","recept","narava","oblak","zabava","koledar","prijatelj"
};

void izberiNakljucnoGeslo(string& geslo);
void izrisiScenarij(int scenarij);
void igraj(Igralec& igralec);
void izpisStatistike(const Igralec igralci[], int stIgralcev);
void zapisHTML(const Igralec igralci[], int stIgralcev);

int main() {
    srand(time(NULL));
    Igralec igralci[ST_IGRALCEV];

    for (int i = 0; i < ST_IGRALCEV; ++i) {
        cout << "Vnesite ime igralca: ";
        cin >> igralci[i].ime;
        igralci[i].id = i + 1;
        igraj(igralci[i]);
    }

    izpisStatistike(igralci, ST_IGRALCEV);
    zapisHTML(igralci, ST_IGRALCEV);

    return 0;
}

void izberiNakljucnoGeslo(string& geslo) {
    int randomIndex = rand() % ST_GESL;
    geslo = gesla[randomIndex];
}

const int ST_SCENARIJEV = 10;

void izrisiScenarij(int scenarij) {
    if (scenarij < 0 || scenarij >= ST_SCENARIJEV) {
        cout << "Napaka: Neveljaven scenarij" << endl;
        return;
    }
    cout << scenariji[scenarij] << endl;
}

void igraj(Igralec& igralec) {
    string geslo;
    izberiNakljucnoGeslo(geslo);

    igralec.trenutnoUgibanoGeslo = string(geslo.length(), '_');
    igralec.zgodovinaUgibanihCrk = "";
    int scenarijIndex = 0;
    int napake = 0;

    igralec.zacetekCas = time(nullptr);

    while (true) {
        cout << "Trenutno stanje: " << igralec.trenutnoUgibanoGeslo << endl;
        cout << "Ugibajte crko ali geslo: ";
        string ugib;
        cin >> ugib;


        if (ugib.length() > 1) {
            if (ugib == geslo) {
                igralec.trenutnoUgibanoGeslo = geslo;
                break;
            } else {
                napake++;
            }
        } else {
            char ugibanaCrka = ugib[0];
            bool pravilno = false;

            for (int i = 0; i < geslo.length(); i++) {
                if (geslo[i] == ugibanaCrka) {
                    igralec.trenutnoUgibanoGeslo[i] = ugibanaCrka;
                    pravilno = true;
                }
            }

            if (!pravilno){
                napake++;
                igralec.zgodovinaUgibanihCrk += ugibanaCrka;
            }
        }

        igralec.st_poskusov++;

        scenarijIndex = napake;

        izrisiScenarij(scenarijIndex);

        if (igralec.trenutnoUgibanoGeslo == geslo) {
            cout << "Čestitam! Uganili ste geslo: " << geslo << endl;
            break;
        }

        if (napake >= 9) {
            cout << "Game over! Geslo je bilo: " << geslo << endl;
            break;
        }
    }

    igralec.pretecenCas = time(nullptr) - igralec.zacetekCas;
}

void izpisStatistike(const Igralec igralci[], int stIgralcev) {
    for (int i = 0; i < stIgralcev; ++i) {
        const Igralec& igralec = igralci[i];

        cout << "Statistika za igralca: " << igralec.ime << endl;
        cout << "ID igralca: " << igralec.id << endl;
        cout << "Pretecen cas: " << igralec.pretecenCas << " sekunde" << endl;
        cout << "Stevilo ugibanj: " << igralec.st_poskusov + 1<< endl;
        cout << endl;
    }
}

void zapisHTML(const Igralec igralci[], int stIgralcev) {
    ofstream htmlFile("history.html");

    htmlFile << "<html>" << endl;
    htmlFile << "<head><title>History</title></head>" << endl;
    htmlFile << "<body>" << endl;
    htmlFile << "<h1>Game History</h1>" << endl;
    htmlFile << "<table border=\"1\">" << endl;
    htmlFile << "<tr><th>Ime</th><th>Ugib</th><th>St_ugibov</th><th>Cas(seconds)</th></tr>" << endl;

    for (int i = 0; i < stIgralcev; i++) {
        htmlFile << "<tr>" << endl;
        htmlFile << "<td>" << igralci[i].ime << "</td>" << endl;
        htmlFile << "<td>" << igralci[i].trenutnoUgibanoGeslo << "</td>" << endl;
        htmlFile << "<td>" << igralci[i].zgodovinaUgibanihCrk.length() << "</td>" << endl;
        htmlFile << "<td>" << igralci[i].pretecenCas << "</td>" << endl;
        htmlFile << "</tr>" << endl;
    }

    htmlFile << "</table>" << endl;
    htmlFile << "</body>" << endl;
    htmlFile << "</html>" << endl;

    htmlFile.close();

    cout << "Napisano v history.html" << endl;
}
