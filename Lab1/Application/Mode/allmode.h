#ifndef ALLMODE
#define ALLMODE

#include "imode.h"
#include <array>

template<auto& ...pins>
class AllMode : public IMode
{
public:
  void Update() override
  {
    for(int LEDposition=0; LEDposition<leds.size(); ++LEDposition)
        {
            leds[LEDposition]->Toggle();
        }
  }
  void StartPosition() override
  {
      LEDposition =0;
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