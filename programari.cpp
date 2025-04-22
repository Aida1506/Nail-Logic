
#include "programari.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Programare::Programare(const std::string& nume, const std::string& prenume, int ziua, int luna, int anul, const std::string& oraInceput, const std::string& oraFinal, const std::string& serviciu)
    : nume(nume), prenume(prenume), ziua(ziua), luna(luna), anul(anul), oraInceput(oraInceput), oraFinal(oraFinal), serviciu(serviciu) {}

string Programare::getNume() const
{
    return nume;
}

string Programare::getPrenume() const
{
    return prenume;
}

int Programare::getZiua() const
{
    return ziua;
}

int Programare::getLuna() const
{
    return luna;
}

int Programare::getAnul() const
{
    return anul;
}

string Programare::getOraInceput() const
{
    return oraInceput;
}

string Programare::getOraFinal() const
{
    return oraFinal;
}

string Programare::getServiciu() const{
    return serviciu;
}

vector<Programare> citesteProgramariDinFisier()
{
    vector<Programare> programari;
    ifstream fisier("programari.txt");
    if (!fisier)
    {

        return programari;
    }


    string antet;
    getline(fisier, antet);

    string linie;
    while (getline(fisier, linie))
    {
        stringstream ss(linie);
        string nume, prenume, oraInceput, oraFinal, ziuaStr, lunaStr, anulStr,serviciu;
        int ziua, luna, anul;
        getline(ss, nume, ',');
        getline(ss, prenume, ',');
        getline(ss, ziuaStr, ',');
        getline(ss, lunaStr, ',');
        getline(ss, anulStr, ',');
        getline(ss, oraInceput, ',');
        getline(ss, oraFinal, ',');
        getline(ss, serviciu, ',');
        ziua = stod(ziuaStr);
        luna = stod(lunaStr);
        anul = stod(anulStr);
        programari.push_back(Programare(nume, prenume, ziua, luna, anul, oraInceput, oraFinal,serviciu));

    }


    fisier.close();
    return programari;
}

void vizualizareProgramari(const string& role, const string& nume, const string& prenume)
{
    vector<Programare> programari = citesteProgramariDinFisier();

    if (programari.empty())
    {
        cout << "Nu exista programari disponibile.\n";
        return;
    }
    int i=1;
    for (const auto& programare : programari)
    {
        if (role == "manager")
        {

            cout <<i<<". "<< "Nume: " << programare.getNume() << ", Prenume: " << programare.getPrenume() << ", Data: " << programare.getZiua() << "/" << programare.getLuna() << "/" << programare.getAnul()
            << ", Ora inceput: " << programare.getOraInceput() << ", Ora final: " << programare.getOraFinal() << ", Serviciu: " << programare.getServiciu() << endl;
            i++;
        }
        else if(role=="client" && programare.getNume() == nume && programare.getPrenume() == prenume)
        {
            cout <<i<<". "<< "Nume: " << programare.getNume() << ", Prenume: " << programare.getPrenume() << ", Data: " << programare.getZiua() << "/" << programare.getLuna() << "/" << programare.getAnul()
            << ", Ora inceput: " << programare.getOraInceput() << ", Ora final: " << programare.getOraFinal() << ", Serviciu: " << programare.getServiciu() << endl;
            i++;
        }
    }
    if(i==1) cout<<"Nu aveti nicio programare";
}

void anuleazaProgramare(const string& role, const string& nume, const string& prenume)
{
    vector<Programare> programari = citesteProgramariDinFisier();



    if(role=="manager")
    {
        cout << "Programari :\n\n";
        for (size_t i = 0; i < programari.size(); ++i)
        {


            cout << i+1 << ". Nume: " << programari[i].getNume() << ", Prenume: " << programari[i].getPrenume()
                 << ", Data: " << programari[i].getZiua() << "/" << programari[i].getLuna() << "/"
                 << programari[i].getAnul() << ", Ora inceput: " << programari[i].getOraInceput()
                 << ", Ora final: " << programari[i].getOraFinal() << endl;

        }
        cout<<"Alege numarul programarii pe care vrei sa o anulezi: ";
        size_t indice;
        cin>>indice;
        if (programari.empty() || indice <= 0 || indice > programari.size())
        {
            cout << "Nu exista o programare cu acest indice.\n";
            return;
        }

        programari.erase(programari.begin() + (indice-1));
    }
    else if(role=="client")
    {
        printf("Ati ales optiunea de stergere a unei programari.\n\n");

        printf("Acestea sunt programarile dumneavoastra:\n");
        size_t i;
        int a=1;
        for (i = 0; i < programari.size(); ++i)
        {
            if (role == "client" && programari[i].getNume() == nume && programari[i].getPrenume() == prenume)
            {
                cout << a << ". Nume: " << programari[i].getNume() << ", Prenume: " << programari[i].getPrenume()
                     << ", Data: " << programari[i].getZiua() << "/" << programari[i].getLuna() << "/"
                     << programari[i].getAnul() << ", Ora inceput: " << programari[i].getOraInceput()
                     << ", Ora final: " << programari[i].getOraFinal() << endl;
                     a++;
            }
        }

        size_t progr_aleasa;
        cout<<"\nAlege programarea pe care vrei sa o anulezi: ";
        cin>>progr_aleasa;


        if (progr_aleasa < 1 || progr_aleasa > i)
        {
            cout << "Nu exista o programare cu acest indice.\n";
            return;
        }

        size_t in = 0;
        for (size_t i = 0; i < programari.size(); ++i)
        {
            if (programari[i].getNume() == nume && programari[i].getPrenume() == prenume)
            {
                in++;
                if (progr_aleasa == in)
                {
                    programari.erase(programari.begin() + i);
                    break;
                }
            }
        }


    }


    ofstream fisier("programari.txt");
    if (!fisier)
    {
        cout << "Eroare la deschiderea fisierului.\n";
        return;
    }

    fisier << "NUME,PRENUME,ZIUA,LUNA,ANUL,ORA_INCEPUT,ORA_FINAL,SERVICIU\n"; // Scrie antetul în fișier

    for (const auto& programare : programari)
    {
        fisier << programare.getNume() << "," << programare.getPrenume() << ","
               << programare.getZiua() << "," << programare.getLuna() << ","
               << programare.getAnul() << "," << programare.getOraInceput() << ","
               << programare.getOraFinal() << programare.getServiciu()<< endl;
    }

    cout << "Programare anulata cu succes.\n";
}

///rescrie fisierul programari cu noua programare adauagata !!!
void scrieProgramariInFisier(const std::vector<Programare>& listaProgramari) {
    std::ofstream outfile("programari.txt");

    if (!outfile.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului de programari.\n";
        return;
    }
    outfile<< "NUME,PRENUME,ZIUA,LUNA,ANUL,ORA_INCEPUT,ORA_FINAL,SERVICIU\n";
    for (const auto& programare : listaProgramari) {
        outfile << programare.getNume() << "," << programare.getPrenume() << "," << programare.getZiua() << "," << programare.getLuna() << "," << programare.getAnul() << ","
                << programare.getOraInceput() << "," << programare.getOraFinal()<<"," << programare.getServiciu()<< "\n";
    }

    outfile.close();
}


/// Funcție pentru a compara două ore !!!
int comparaOre(const std::string& ora1, const std::string& ora2) {
    // Funcția pentru a converti timpul în minute
    auto timpLaMinute = [](const std::string& timp) {
        std::istringstream ss(timp);
        std::string oraPart, minutePart;
        std::getline(ss, oraPart, ':');
        std::getline(ss, minutePart);
        return std::stoi(oraPart) * 60 + std::stoi(minutePart);
    };

    int ora1Minute = timpLaMinute(ora1);
    int ora2Minute = timpLaMinute(ora2);

    if (ora1Minute < ora2Minute) {
        return -1; // ora1 este înainte de ora2
    } else if (ora1Minute > ora2Minute) {
        return 1; // ora1 este după ora2
    } else {
        return 0; // orele sunt egale
    }
}

///verifica daca data si ora introduse pentru programare sunt valide !!!
bool verificaDataSiOra(int ziua, int luna, int anul, const std::string& oraInceput, const std::string& oraFinal) {
    // Funcția pentru a converti timpul în minute
    auto timpLaMinute = [](const std::string& timp) {
        std::istringstream ss(timp);
        std::string oraPart, minutPart;
        std::getline(ss, oraPart, ':');
        std::getline(ss, minutPart);
        int ora = std::stoi(oraPart);
        int minut = std::stoi(minutPart);
        return ora * 60 + minut;
    };

    // Separăm orele și minutele din șiruri
    int oraInceputInt = timpLaMinute(oraInceput);
    int oraFinalInt = timpLaMinute(oraFinal);

    // Verificăm corectitudinea dată și oră
    if (ziua < 1 || ziua > 31 || luna < 1 || luna > 12 || anul < 2023 ||
        oraInceputInt < 0 || oraInceputInt > 1439 || oraFinalInt < 0 || oraFinalInt > 1439 ||
        (oraInceputInt >= oraFinalInt)) {
        //std::cout << "Data sau ora sunt invalide.\n";
        return false;
    }
    return true;
}

/// Funcție pentru a face textul să fie într-un format uniform !!!
std::string toLowercase(const std::string& text) {
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerText;
}

/// Funcție pentru a verifica dacă un serviciu există în fișierul cu oferte !!!
bool verificaServiciuInOferte(const std::string& serviciuCautat) {
    std::ifstream infile("oferte.txt");
    if (!infile.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului cu oferte.\n";
        return false;
    }

    string antet;
    getline(infile,antet);

     std::string linie;
    std::string serviciuLower = toLowercase(serviciuCautat);
    while (std::getline(infile, linie)) {
        // Găsim poziția virgulei
        std::size_t pozitieVirgula = linie.find(',');
        if (pozitieVirgula != std::string::npos) {
            // Luăm doar prima parte, înainte de virgulă
            std::string serviciuLinie = linie.substr(0, pozitieVirgula);
            // Transformăm în litere mici pentru verificare necase-sensitive
            std::string serviciuLinieLower = toLowercase(serviciuLinie);
            // Verificăm dacă serviciul liniei corespunde cu serviciul căutat
            if (serviciuLinieLower == serviciuLower) {
                infile.close();
                return true; // Serviciul a fost găsit în fișier
            }
        }
    }


    infile.close();
    return false; // Serviciul nu a fost găsit în fișier
}

///functia care adauga programarea !!!
void adaugaProgramare(const string& name, const string& surname) {
    ///numele si prenumele sunt parametrii pentru a nu putea sa facem programari pe orice nume, adica sa il citim de la tastatura
    vector<Programare> listaProgramari = citesteProgramariDinFisier();

    // Citirea datelor de la tastatură
    std::string nume, prenume, oraInceput,oraFinal, serviciu;
    int ziua, luna, anul;
    nume = name;
    prenume = surname;
    std::cout << "Introdu ziua: ";
    std::cin >> ziua;
    std::cout << "Introdu luna: ";
    std::cin >> luna;
    std::cout << "Introdu anul: ";
    std::cin >> anul;
    std::cout << "Introdu ora de inceput (format 24h): ";
    std::cin >> oraInceput;
    std::cout << "Introdu ora de final (format 24h): ";
    std::cin >> oraFinal;
    std::cout << "Introdu serviciul dorit: ";
    std::cin >> serviciu;

    // Verifică validitatea datei și orei
     if (!verificaDataSiOra(ziua, luna, anul, oraInceput, oraFinal)) {
        std::cout << "Data sau ora nu sunt invalide.\n";
        cout<<"Introduceti o data si o ora valida"<<endl;
        do{
             std::cout << "Introdu ziua: ";
            std::cin >> ziua;
            std::cout << "Introdu luna: ";
            std::cin >> luna;
            std::cout << "Introdu anul: ";
            std::cin >> anul;
            std::cout << "Introdu ora de inceput (format 24h): ";
            std::cin >> oraInceput;
            std::cout << "Introdu ora de final (format 24h): ";
            std::cin >> oraFinal;
        }while(!verificaDataSiOra(ziua, luna, anul, oraInceput, oraFinal));
    }

    if(!verificaServiciuInOferte(serviciu)){
         cout<<"Nu avem serviciul dorit"<<endl;
         do{
            cout<<"Introduceti un serviciu valid: ";
            cin>>serviciu;
        }while(!verificaServiciuInOferte(serviciu));
    }


    /// Verifică dacă există deja o programare la aceeași dată și în același interval orar
    for (const auto& programare : listaProgramari) {
        if (programare.getZiua() == ziua && programare.getLuna() == luna && programare.getAnul() == anul &&
            ((comparaOre(oraInceput, programare.getOraInceput()) >= 0 && comparaOre(oraInceput, programare.getOraFinal()) < 0) ||
            (comparaOre(oraFinal, programare.getOraInceput()) > 0 && comparaOre(oraFinal, programare.getOraFinal()) <= 0) ||
            (comparaOre(oraInceput, programare.getOraInceput()) <= 0 && comparaOre(oraFinal, programare.getOraFinal()) >= 0))) {
            std::cout << "Exista deja o programare in intervalul specificat.\n";
            return;
        }
    }

    /// Adaugă noua programare
    Programare nouaProgramare(nume, prenume, ziua, luna, anul, oraInceput, oraFinal, serviciu);
    listaProgramari.push_back(nouaProgramare);

    /// Scrie toate programările înapoi în fișier
    scrieProgramariInFisier(listaProgramari);

    std::cout << "Programare adaugata cu succes.\n";
}
