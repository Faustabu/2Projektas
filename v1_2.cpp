#include "studentasclass.h"
#include "studentas.h"
using std::cout;
using std::cin;
using std::endl; 

template<class C>
void antra_strategija(C& studentai, C& v, double& balas);
template<class C>
void pirma_strategija(C& studentai, C& v, C& n, double& balas);
template<class C>
void pirma_strategija_struct(C& studentai, C& v, C& n, double& balas);
template<class C>
void antra_strategija_struct(C& studentai, C& v, double& balas);

int main()
{
    int kiek;
    double balas = 5.00;
    vector<int> skaiciai;

   
    cout << "kiek studentu " << endl; cin >> kiek;

   
    vector<studentas> duomvec;
    vector<studentas_struct> duomvec_struct;
    vector<studentas> galvociaivec;
    vector<studentas> nuskriaustukaivec;
    vector<studentas_struct> galvociaivec_struct;
    vector<studentas_struct> nuskriaustukaivec_struct;
    

    int galvoc = 0;
    int nuskr = 0;
    string pavad1, pavad2;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << std::fixed;
   

    //---------------------------------------VECTOR class-----------------------------------------
    failo_skaitymas(duomvec, kiek);

    start = std::chrono::high_resolution_clock::now();

    pirma_strategija(duomvec, galvociaivec, nuskriaustukaivec, balas);



    galvociaivec.clear();
    nuskriaustukaivec.clear();

    galvociaivec.shrink_to_fit();
    nuskriaustukaivec.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector CLASS uztruko ( 1 str):  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    antra_strategija(duomvec, nuskriaustukaivec, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector CLASS uztruko( 2str ):  " << diff.count() << endl;
    //duomvec.clear();
    nuskriaustukaivec.clear();
    galvociaivec.shrink_to_fit();
    nuskriaustukaivec.shrink_to_fit();
    // ------------------------------------vector struct-----------------------------

    failo_skaitymas_struct(duomvec_struct, kiek);

    start = std::chrono::high_resolution_clock::now();

    pirma_strategija_struct(duomvec_struct, galvociaivec_struct, nuskriaustukaivec_struct, balas);



    galvociaivec.clear();
    nuskriaustukaivec.clear();

    galvociaivec.shrink_to_fit();
    nuskriaustukaivec.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector STRUCT uztruko ( 1 str):  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    antra_strategija_struct(duomvec_struct, nuskriaustukaivec_struct, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su vector STRUCT uztruko( 2 str):  " << diff.count() << endl;
    duomvec.clear();
    nuskriaustukaivec.clear();
    galvociaivec.shrink_to_fit();
    nuskriaustukaivec.shrink_to_fit();

   

}



template<class C>
void antra_strategija(C& studentai, C& v, double& balas) {

    using std::remove_if;
    studentai.erase(remove_if(studentai.begin(), studentai.end(), [balas, &v](studentas& s) {
        if (s.getGal() < balas) {
            v.push_back(s);
            return true;
        }
        else { return false; }
        }), studentai.end());


}


template<class C>
void antra_strategija_struct(C& studentai, C& v, double& balas) {

    using std::remove_if;
    studentai.erase(remove_if(studentai.begin(), studentai.end(), [balas, &v](studentas_struct& s) {
        if (s.gal < balas) {
            v.push_back(s);
            return true;
        }
        else { return false; }
        }), studentai.end());


}

template<class C>
void pirma_strategija(C& studentai, C& v, C& n, double& balas) {
    for (auto it = studentai.begin(); it != studentai.end(); it++) {
        if (it->getGal() >= balas) {
            v.push_back(*it);

        }
        else {
            n.push_back(*it);
        }

    }

}

template <class C>

void pirma_strategija_struct(C& studentai, C& v, C& n, double& balas) {
    for (auto it = studentai.begin(); it != studentai.end(); it++) {
        if (it->gal >= balas) {
            v.push_back(*it);

        }
        else {
            n.push_back(*it);
        }

    }

}


void failo_skaitymas(vector<studentas>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now();
    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            kint.resize(kint.size() + 1);
            studentas student;
            student.failo_nuskaitymas(skaitymas);
            stud += 1;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "CLASS nuskaitymas su vectoriumi uztruko: " << diff.count() << endl;
}

void failo_skaitymas_struct(vector<studentas_struct>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now();
    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            kint.resize(kint.size() + 1);

            skaitymas >> kint.at(stud).vardas;
            skaitymas >> kint.at(stud).pavarde;

            skaitymas >> kint.at(stud).gal;
            stud += 1;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "STRUCT nuskaitymas su vectoriumi uztruko: " << diff.count() << endl;
}

