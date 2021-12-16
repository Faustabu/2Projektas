#include "studentasclass.h"
#include "studentas.h"
using std::cout;
using std::cin;
using std::endl; // vietoj vardas -> getVardas;

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
    // cout << "iveskite pazymiu kieki: ";
     //cin >> paz;
    double balas = 5.00;
    //auto_skaiciai(paz);
    vector<int> skaiciai;

    //int kiek = generavimas(skaiciai);
    cout << "kiek studentu " << endl; cin >> kiek;

    list <studentas> duom;
    list<studentas> galvociai;
    list<studentas> nuskriaustukai;
    vector<studentas> duomvec;
    vector<studentas_struct> duomvec_struct;
    vector<studentas> galvociaivec;
    vector<studentas> nuskriaustukaivec;
    vector<studentas_struct> galvociaivec_struct;
    vector<studentas_struct> nuskriaustukaivec_struct;
    //deque<studentas> duomdeq;
    //deque<studentas> nuskriaustukaideq;
    //deque<studentas> galvociaideq;

    int galvoc = 0;
    int nuskr = 0;
    string pavad1, pavad2;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << std::fixed;
    //------------------------------------------------LIST----------------------------------------
    /*
    pirma_strategija(duom, galvociai, nuskriaustukai, balas);

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su list uztruko( 1 str ):  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    pavad1 = "nuskriaustukai_" + std::to_string(kiek) + ".txt";
    std::ofstream nuskr_failas(pavad1);


    for (const auto& laik : duom)
    {
        if (laik.getGal() < balas) {
            nuskr_failas << laik.getVardas() << std::setw(20) << laik.getPavarde() << std::setw(20) << laik.getGal() << endl;
        }
    }


    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    //cout << "Surūšiuotų studentų išvedimas į failą - nuskriaustukai:  " << diff.count() << endl;



    start = std::chrono::high_resolution_clock::now();

    pavad2 = "galvociai_" + std::to_string(kiek) + ".txt";
    std::ofstream galvoc_failas(pavad2);


    for (const auto& laik : duom)
    {
        if (laik.getGal() >= balas) {
            galvoc_failas << laik.getVardas() << std::setw(20) << laik.getPavarde() << std::setw(20) << laik.getGal() << endl;
        }
    }


    using std::remove;
    using std::rename;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";
    //remove(pavadinimas);



    galvociai.clear();
    nuskriaustukai.clear();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    //cout << "Surūšiuotų studentų išvedimas į failą - galvočiai:  " << diff.count() << endl;


    start = std::chrono::high_resolution_clock::now();
    antra_strategija(duom, nuskriaustukai, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su list uztruko( su antra strategija):  " << diff.count() << endl;
    duom.clear();
    nuskriaustukai.clear(); */

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

    //--------------------DEQUE----------------------------------------------
   /* failo_skaitymas(duomdeq, kiek);
    start = std::chrono::high_resolution_clock::now();

    pirma_strategija(duomdeq, galvociaideq, nuskriaustukaideq, balas);

    galvociaideq.clear();
    nuskriaustukaideq.clear();

    galvociaideq.shrink_to_fit();
    nuskriaustukaideq.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su deque uztruko( 1 str ):  " << diff.count() << endl;

    start = std::chrono::high_resolution_clock::now();
    antra_strategija(duomdeq, nuskriaustukaideq, balas);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Studentu rusiavimas i dvi grupes su deque uztruko( su antra strategija):  " << diff.count() << endl;
    duomdeq.clear();
    nuskriaustukaideq.shrink_to_fit();
    nuskriaustukaideq.clear();
    duomdeq.shrink_to_fit();
    */

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


/*void failo_skaitymas(list<studentas>& kint, int kiek) {
    int stud = 0;
    std::ifstream skaitymas;
    string buff;
    string pavadinimas = "studentai_" + std::to_string(kiek) + ".txt";


    skaitymas.open(pavadinimas);

    if (skaitymas.is_open()) {
        auto start = std::chrono::high_resolution_clock::now();
        auto st = start;
        getline(skaitymas >> std::ws, buff);
        while (stud < kiek)
        {
            //kint.resize(kint.size() + 1);
            studentas student;
            student.failo_nuskaitymas(skaitymas);

            kint.push_back(student);
            stud += 1;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "nuskaitymas su listu uztruko: " << diff.count() << endl;
    }

}*/
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

/*
void failo_skaitymas(deque<studentas>& kint, int kiek) {
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
    cout << "nuskaitymas su deque uztruko: " << diff.count() << endl;
}*/
