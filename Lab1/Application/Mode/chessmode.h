#ifndef CHESSMODE
#define CHESSMODE

#include "imode.h"
#include <array>

template<auto& ...pins>
class ChessMode : public IMode
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
    for(auto it: leds)
    {
        it->SetLow();
    }
    for(int LEDposition=0; LEDposition<leds.size(); LEDposition+=2)
    {
      leds[LEDposition]->Toggle();
    }
  }
private:
  std::size_t LEDposition=0;
  std::array<IPin*, sizeof ...(pins)> leds = {static_cast<IPin*> (&pins)...};
};

#endif