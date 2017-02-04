#include "persoana.h"

Persoana::Persoana(){
    _nume = setNume();
    _prenume = setPrenume();
}

string Persoana::setNume(){
    cout<<"Insert person firstname: ";
    cin>>_nume;
    return _nume;
}

string Persoana::setPrenume(){
    cout<<"Insert person lastname: ";
    cin>>_prenume;
    return _prenume;
}
