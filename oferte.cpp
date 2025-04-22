
#include "oferte.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Oferta::Oferta(const string& nume, int pret) : numeOferta(nume), pret(pret) {}

string Oferta::getNumeOferta() const {
    return numeOferta;
}

int Oferta::getPret() const {
    return pret;
}

vector<Oferta> citesteOferteDinFisier() {
    vector<Oferta> oferte;
    ifstream fisier("oferte.txt");
    if (!fisier) {
        return oferte;
    }

    string antet;
    getline(fisier, antet);

    string linie;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        string nume;
        string pretStr;
        double pret;
        getline(ss, nume, ',');
        getline(ss, pretStr, ',');
        pret = stod(pretStr);
        oferte.push_back(Oferta(nume, pret));

    }

    fisier.close();
    return oferte;
}

void vizualizareOferte() {

    vector<Oferta> oferte = citesteOferteDinFisier();

    if (oferte.empty()) {
        cout << "Nu exista oferte disponibile.\n";
        return;
    }

    cout << "Oferte disponibile:\n\n";
    int i=1;
    for (const auto& oferta : oferte) {
        cout <<i<<". "<< oferta.getNumeOferta() << " - "<< oferta.getPret()<<" RON" << endl;
        i++;
    }
}

void adaugaOferta() {
    vector<Oferta> oferte = citesteOferteDinFisier();
    string nume;
    double pret;
    cout<<"Adaugati o oferta: "<<endl;
    cout<<"Nume: ";
    cin>>nume;
    cout<<"Pret: ";
    cin>>pret;
    oferte.push_back(Oferta(nume, pret));

    ofstream fisier("oferte.txt");
    if (!fisier) {
        cout << "Eroare la deschiderea fișierului.\n";
        return;
    }

    fisier << "OFERTA,PRET\n"; // Scriem antetul în fișier
    for (const auto& oferta : oferte) {
        fisier << oferta.getNumeOferta() << "," << oferta.getPret() << endl;
    }

    cout << "Oferta adaugata cu succes.\n";
}

void stergeOferta() {
    vector<Oferta> oferte = citesteOferteDinFisier();

    if (oferte.empty()) {
        cout << "Nu există oferte disponibile pentru ștergere.\n";
        return;
    }


    cout << "Oferte disponibile pentru stergere:\n";
    for (size_t i = 0; i < oferte.size(); ++i) {
        cout << i+1 << ". Nume: " << oferte[i].getNumeOferta() << ", Pret: " << oferte[i].getPret() << endl;
    }

    cout<<"Ce oferta vreti sa stergeti?"<<endl;
    size_t indice;
    cin>>indice;

    if (indice <= 0 || indice > oferte.size()) {
        cout << "Indicele introdus nu corespunde unei oferte.\n";
        return;
    }

    oferte.erase(oferte.begin() + (indice-1));

    ofstream fisier("oferte.txt");
    if (!fisier) {
        cout << "Eroare la deschiderea fișierului.\n";
        return;
    }

    fisier << "OFERTA,PRET\n";
    for (const auto& oferta : oferte) {
        fisier << oferta.getNumeOferta() << "," << oferta.getPret() << endl;
    }

    cout << "Oferta stearsa cu succes.\n";
}




