#ifndef TREEMODE
#define TREEMODE

#include "imode.h"
#include <array>

template<auto& ...pins>
class TreeMode : public IMode
{
public:
  void Update() override
  {
    leds[LEDposition++]->Toggle();
    if(LEDposition== leds.size())
    {
      LEDposition=0;
    }
  }
  void StartPosition() override
  {
      LEDposition=0;
     for(auto it: leds)
      {
          it->SetLow();
      }
  }
private:
  std::size_t LEDposition=0;
  std::array<IPin*, sizeof ...(pins)> leds = {static_cast<IPin*> (&pins)...};
};

#endif