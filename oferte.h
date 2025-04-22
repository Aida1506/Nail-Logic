#ifndef OFERTE_H_INCLUDED
#define OFERTE_H_INCLUDED

#include <string>
#include<vector>
using namespace std;

class Oferta {
private:
    string numeOferta;
    int pret;

public:
    Oferta(const string& nume, int pret);
    string getNumeOferta() const;
    int getPret() const;
};


vector<Oferta> citesteOferteDinFisier(const string& numeFisier);
void vizualizareOferte();
void adaugaOferta();
void stergeOferta();


#endif // OFERTE_H_INCLUDED
