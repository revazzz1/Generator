#include <iostream>
#include "RandomGenerator.hh"
#include "Histo.hh"
#include "Graph.hh"
#include "SignalGenerator.hh"

int main(int argc, char** argv) {
    Histo histo("three",100, -5, 15);
    RandomGenerator rnd(10000);
    double gaus;
for(int i = 0; i < 10000; i++){
    gaus = rnd.GetGaus(2 ,1);
    histo.Fill(gaus);
}

//histo.draw();

SignalGenerator signal1;
    signal1.AddHarmonics(1,0.2,0);
    signal1.AddHarmonics(4,0.8,0);
    signal1.AddHarmonics(4,500,0);

    signal1.SetNoise(2);
    signal1.SetDC(3);

    signal1.Generate(10,0.01);

    Graph graph("four");

    signal1.Generate(10,0.01);

    for(int i = 0; i < signal1.GetNPoints(); i++){
   graph.AddPoint(signal1.GetTime()[i],signal1.GetSignal()[i]);
}


graph.draw();

return 0;
}
