#include <iostream>
#include <string>
#include <vector>
#include "console/console.h"
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void coffeeList() {
    vector<string> coffes;
}

void SpaceCtr(string msg) {
    int msgLength = msg.length();
    int whiteSpace = 49 - msgLength;

    for (int n = 0; n < whiteSpace; n++) {
        cout << " ";
    }

    cout << "*" << endl;
}

void choixCoffee(int choix) {
    if (choix == 1) {
        gotoxy(0, 9);
        cout << "Un café fort";
    }
    else if (choix == 0) {
        gotoxy(0, 10);
        cout << "Un café faible";
    }
}
void printMenu(string etatMsg) {
    string AlmCaft = "* 1 Allumer la cafetiere";
    string EtdrCaft = "* 2 Eteindre la cafetiere";
    string ChrCaffe = "* 3 Choisir son cafe";
    string Qtr = "* 4 Quitter";
    string Matnance = "* 5 Maintenance";


    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;

    cout << AlmCaft;   SpaceCtr(AlmCaft);
    cout << EtdrCaft;  SpaceCtr(EtdrCaft);
    cout << ChrCaffe;  SpaceCtr(ChrCaffe);
    cout << Qtr;       SpaceCtr(Qtr);
    cout << Matnance;  SpaceCtr(Matnance);
    cout << etatMsg;   SpaceCtr(etatMsg);

    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

void UiMachineON() {
    printMenu("* Cafetiere MARCHE");
}

void UiMachineOFF() {
    printMenu("* Cafetiere ARRETEE");
}

int main() {
    int machineEtat = 0;
    int reponse;
    int coffeChoix = 0;

    clearScreen();

    UiMachineOFF();

    while (true) {
        gotoxy(0, 10);
        cout << "\033[2K";
        cout << "Entrez votre choix entre 1 et 5: ";
        cin >> reponse;

        switch (reponse) {
            case 4:
                exit(0);
        }

        if (reponse != 1 && machineEtat == 0) {
            cout << "Veuillez allumer la machine" << endl;
            continue;
        }

        switch (reponse) {
            case 1:
                machineEtat = 1;
                clearScreen();
                UiMachineON();
                break;
            case 2:
                machineEtat = 0;
                clearScreen();
                UiMachineOFF();
                break;
            case 3:
                gotoxy(0, 10);
                cout << "\033[2K";
                cout << "Tapez 1 pour un café fort, tapez 0 pour un café faible: ";
                cin >> coffeChoix;
                choixCoffee(coffeChoix);

        }
    }

    return 0;
}