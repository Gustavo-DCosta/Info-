#ifndef CONSOLE_H
#define CONSOLE_H

#ifdef __cplusplus
extern "C"{
#endif

int getch(void); // lecture d'un caractère sans echo
int getche(void); // lecture d'un caractère avec echo
void gotoxy(int x,int y); // postionnement du curseur en (x,y) avec (1,1) en haut à gauche
void clrscr(void); // effacement de l'écran
void delay(int milliseconde); // delai en milliseconde
int kbhit(void); // repond vrai si une touche est tapée sinon faux
void clearkeyboard(void); // efface le buffer clavier

#ifdef __cplusplus
}
#endif

#define KEY_ESC 27
#define KEY_ENTER 10


#endif
