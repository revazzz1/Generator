#ifndef _SIGNALGENERATOR_HH_
#define _SIGNALGENERATOR_HH_
#include <vector>
#include <string>
#include "RandomGenerator.hh"


struct Harmonic {
    double a, f, p;
};

class SignalGenerator : protected RandomGenerator {
protected:
    double _DC;
    double _Sigma;
    double _A;
    double _F;
    double _P;
    std::vector<Harmonic> _HarmonicsVect;
    double* _Signal;
    double* _Time;
    unsigned long _NPoints;
public:
   SignalGenerator();
   void AddHarmonics(double a, double f, double p);
   void SetDC(double dc);
   void SetNoise(double sigma);
   void Generate(double t, unsigned long np);
   void Generate(double t, double dt);
   double* GetSignal() {return _Signal;};
   double* GetTime() {return _Time;};
   unsigned long GetNPoints() const {return _NPoints;};
   virtual ~SignalGenerator();
};

#endif
