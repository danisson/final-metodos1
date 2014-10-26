#include "tabela.h"


/* Converte double pra string com número específico de espaços após a casa decimal 
   e margem à esquerda */
std::string tnw::prd(const double x, const int decDigits, const int width) {
    stringstream ss;
    ss << fixed << right;
    ss.fill(' ');        
    ss.width(width);     
    ss.precision(decDigits);    ss << x;
    return ss.str();
}

/*! Alinha centralmente strings dentro de uma margem de largura w. Usa espaços em branco
    para forçar alinhamento */
std::string tnw::center(const string s, const int w) {
    stringstream ss, spaces;
    int padding = w - s.size();
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();
    if(padding>0 && padding%2!=0)
        ss << " ";
    return ss.str();
}
