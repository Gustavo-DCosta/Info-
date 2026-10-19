#include <iostream>
#include <string>
#include <vector>
#include "console/console.h"
using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void clearLine() {
    cout << "\033[2K";
}
void histoire() {

}

void SpaceCtr(string msg) {
    int msgLength = msg.length();
    int whiteSpace = 49 - msgLength;

    for (int n = 0; n < whiteSpace; n++) {
        cout << " ";
    }

    cout << "*" << endl;
}

void menuCafefe() {
    gotoxy(0, 10);
    clearLine();
    cout << "0. Caffee faible \n";
    cout << "1. Caffee fort \n";
}

void choixCoffee(int choix) {

    // je dois retoucher cette function pour changer je veux qu'àprès 
    string coffeeFn = "Votre caffe est pret!";
    int ln = coffeeFn.length();
    int x = 50 % ln;
    if (choix == 1) {
        gotoxy(0, 9);
        for (int i = 0; i < 50; i++) {
            cout << "|";
            delay(90);
        }
        delay(100);
        gotoxy(0, 9);
        clearLine();
        gotoxy(x, 9);
        cout << coffeeFn << endl;
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
        clearLine();
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
                clearLine();
                menuCafefe();
                cin >> coffeChoix;
                for (int i = 10; i < 13; i++) {
                    gotoxy(0, i);
                    clearLine();
                }
                choixCoffee(coffeChoix);

        }
    }

    return 0;
}