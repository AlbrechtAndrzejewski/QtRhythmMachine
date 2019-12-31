#ifndef DR110KIT_H
#define DR110KIT_H

#include <string>

using namespace std;



class DR110Kit {
public:
    static const string& KICK;
    static const string& SNARE;
    static const string& HIHAT;
    static const string& CLAPS;
};

// Resources courtesy of Music Machines - http://machines.hyperreal.org
const string& DR110Kit::HIHAT = string(":/Resources/dr110kit/DR110OHT.WAV");
const string& DR110Kit::SNARE = string(":/Resources/dr110kit/DR110SNR.WAV");
const string& DR110Kit::KICK = string(":/Resources/dr110kit/DR110KIK.WAV");
const string& DR110Kit::CLAPS = string(":/Resources/dr110kit/DR110CLP.WAV");


#endif // DR110KIT_H
