#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "RandomGenerator.hh"

RandomGenerator::RandomGenerator(unsigned int seed) {
    if(seed == 0){
        srand(time(NULL));
    }
    else srand(seed);

    _IsEven = false;
}

double RandomGenerator::GetRndm() {
    return (double) rand() / RAND_MAX;
}

double RandomGenerator::GetRndm(double min, double max){
    return GetRndm()*(max - min) + min;
}

double RandomGenerator::GetGaus(double mean, double sigma){
    _IsEven = !_IsEven;

    double sum = 0;
    double u1 = GetRndm();
    double u2 = GetRndm();
    while(u1 == 0) {
    double u1 = GetRndm();
    }

    double zOne;
    double ln;

    if(_IsEven) {
        ln = sqrt(-2* log(u1));
        zOne = ln * sin(2* M_PI * u2);
        _Ztwo = ln * cos(2* M_PI * u2);
        return zOne * sigma + mean;
    }
    else{
        return _Ztwo * sigma + mean;
    }
}

double RandomGenerator::GetGaus2(double mean, double sigma, int n){
    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += GetRndm();
    }

    sum -= (double)n/2;
    sum /= sqrt((double)n/12);

    return sum * sigma + mean;
}
