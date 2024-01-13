#include <iostream>
#include <vector>
#include <string.h>
#include "RandomGenerator.cc"

int main(int argc, char** argv) {
    unsigned int seed = 0;
    if(argv > 0){
    seed = atof(argv[1]);
    }

    else {
        std::cout << "seed must be more than 0" << std::endl;
    }

    RandomGenerator r(seed);
    int min = -1;
    int max = 1;
    double x;
    double y;
    unsigned int numberOfPoints = atof(argv[2]);
    unsigned long insideCircle = 0;



    for(int i = 0; i < numberOfPoints; i++){
        x = r.GetRndm(min, max);
        y = r.GetRndm(min, max);
        if(x*x + y*y < 1.0) {

        insideCircle++;
    }
}

    std::cout<< "Value of PI is: "  << 4*((double)insideCircle/numberOfPoints) << std::endl;

    return 0;
}
