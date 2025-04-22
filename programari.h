#ifndef PROGRAMARI_H_INCLUDED
#define PROGRAMARI_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm> // Pentru std::transform
#include <cctype> // Pentru std::tolower
using namespace std;

class Programare {
private:
    string nume;
    string prenume;
    int ziua;
    int luna;
    int anul;
    string oraInceput;
    string oraFinal;
    string serviciu;

public:
    Programare(const string& nume, const string& prenume, int ziua, int luna, int anul, const string& oraInceput, const string& oraFinal, const string& serviciu);
    string getNume() const;
    string getPrenume() const;
    int getZiua() const;
    int getLuna() const;
    int getAnul() const;
    string getOraInceput() const;
    string getOraFinal() const;
    string getServiciu() const;
};

vector<Programare> citesteProgramariDinFisier(const string& numeFisier);
void vizualizareProgramari(const string& role, const string& nume, const string& prenume);
void anuleazaProgramare(const string& role, const string& nume, const string& prenume);
void adaugaProgramare(const string& name, const string& surname);///functia care adauga programare, cu parametrii pentru a adauga numele !!!
void scrieProgramariInFisier(const std::string& numeFisier);  ///daca programarea pe care vrem sa o facem este valida, rescrie tot fisierul, pentru a o adauga !!!

#endif // PROGRAMARI_H_INCLUDED
