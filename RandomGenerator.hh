#ifndef _RANDOMGENERATOR_HH_
#define _RANDOMGENERATOR_HH_

class RandomGenerator {
bool _IsEven;
double _Ztwo;
public:
   RandomGenerator(unsigned int seed = 0);
   double GetRndm(double min, double max);
   double GetRndm();
   double GetGaus(double mean,double sigma);
   double GetGaus2(double mean,double sigma, int n);
};

#endif
