#include "lexer.h"
#include "symbole.h"
#include <iostream>
#include <memory>

int main(void) {
    string chaine("(1+34)*123");

    Lexer l(chaine);

    unique_ptr<Symbole> s;
    while (*(s = unique_ptr<Symbole>(l.Consulter())) != FIN) {
        s->Affiche();
        cout << endl;
        l.Avancer();
    }
    return 0;
}