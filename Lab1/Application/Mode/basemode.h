#ifndef BASEMODE
#define BASEMODE

#include <array>

template<auto& ...pins>
class BaseMode 
{
public:
  void ClearAll() 
  {
      for(auto it: leds)
      {
          it->SetLow();
      }
  }
  std::array<IPin*, sizeof ...(pins)> leds = {static_cast<IPin*> (&pins)...};
};



#endif