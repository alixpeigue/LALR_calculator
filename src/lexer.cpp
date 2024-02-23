#include "lexer.h"

Symbole *Lexer::Consulter() {
    if (!tampon) {

        if ((size_t)tete == flux.length())
            tampon = new Symbole(FIN);
        else {

            switch (flux[tete]) {
            case '(':
                tampon = new Symbole(OPENPAR);
                tete++;
                break;
            case ')':
                tampon = new Symbole(CLOSEPAR);
                tete++;
                break;
            case '*':
                tampon = new Symbole(MULT);
                tete++;
                break;
            case '+':
                tampon = new Symbole(PLUS);
                tete++;
                break;
            case ' ':
                while (flux[tete] == ' ') {
                    tete++;
                }
                Lexer::Consulter();
                break;
            default:
                if (flux[tete] <= '9' && flux[tete] >= '0') {
                    int resultat = flux[tete] - '0';
                    int i = 1;
                    while (flux[tete + i] <= '9' && flux[tete + i] >= '0') {
                        resultat = resultat * 10 + (flux[tete + i] - '0');
                        i++;
                    }
                    tete = tete + i;
                    tampon = new Entier(resultat);
                } else {
                    tampon = new Symbole(ERREUR);
                }
            }
        }
    }
    return tampon;
}

void Lexer::Avancer() { tampon = nullptr; }
