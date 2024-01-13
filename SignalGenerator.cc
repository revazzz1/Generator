#include <iostream>
#include <math.h>
#include "SignalGenerator.hh"

SignalGenerator::SignalGenerator(){
    _Signal = 0x0;
    _Time = 0x0;
    _NPoints = 0x0;
    _DC = 0x0;
    _Sigma = -1;
    _A = 0x0;
    _F = 0x0;
    _P= 0x0;
}

void SignalGenerator::AddHarmonics(double a, double f, double p) {
     Harmonic h{a,f,p};
    _HarmonicsVect.push_back(h);
}

void SignalGenerator::Generate(double t, unsigned long np){
    if(_Signal != 0x0){
        std::cout<< "Signal already exists" << std::endl;
        return;
    }

        _NPoints = np;
    try {
            _Signal = new double[np];
            _Time = new double[np];
        }
    catch (std::bad_alloc& ba)
        {

            std::cerr << "bad_alloc caught: " << ba.what() << '\n';

            if(_Signal != 0x0) {
                delete []_Signal;
            }

        return;
        }
        double dt = t/(np - 1);
        double nyQuistFreq = 1/(2*dt);

        for(int i = 0; i < np; i++){
            _Time[i] = i * dt;
            _Signal[i] = 0;
            for(int j = 0; j < _HarmonicsVect.size(); j++) {
                if(nyQuistFreq > _HarmonicsVect[j].f)
              _Signal[i] += _HarmonicsVect[j].a * sin(2* M_PI * _HarmonicsVect[j].f * _Time[i] + _HarmonicsVect[j].p);
              else std::cout << "Harmonic with index " << j << " can not be used"  << '\n';

            }
            _Signal[i] += _DC;
            if(_Sigma > 0)
            _Signal[i] += GetGaus(0, _Sigma);
        }
    }

void SignalGenerator::Generate(double t, double dt){
    unsigned long np = t/dt + 1;
    Generate(t, np);
}

void SignalGenerator::SetDC(double dc){
    _DC = dc;
}
void SignalGenerator::SetNoise(double sigma){
    _Sigma = sigma;
}

SignalGenerator::~SignalGenerator(){
    if(_Signal != 0x0) {
        std::cout<< "Deleting Signal" << std::endl;
        delete []_Signal;
    }
    if(_Time != 0x0) {
        std::cout<< "Deleting Time" << std::endl;
        delete []_Time;
    }
 }
