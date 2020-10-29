#include <iostream>
#include "Octathlon.h"


int main(int argc, char const *argv[])
{
  Octathlon *octhalon = new Octathlon(std::atoi(argv[1]), std::atoi(argv[2]));
  octhalon->initLocation();
  octhalon->initEvent();
  octhalon->initWeatherSystem();
  octhalon->initInjurySys();
  octhalon->initTeam();
  octhalon->startTheNovaOcthalon();
  delete octhalon;	
  return 0;
}