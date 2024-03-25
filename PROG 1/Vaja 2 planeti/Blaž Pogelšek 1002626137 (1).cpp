#include <iostream>
using namespace std;

const float pi = 3.14


int main() {
    float radij, copazovanja, obhodnic, makajocap, kroznah, obhod;
    cout << "Vpisi radij, cas opazovanja in obhodni cas: ";

    cin >> radij;
    cin >> copazovanja;
    cin >> obhodnic;

    cout << radij << " " << copazovanja << " " << obhodnic << endl;

    obhod = 2 * pi * radij;
    kroznah = (2 * pi / obhodnic);

    makajocap = obhod - copazovanja * kroznah;

    return 0;

}
