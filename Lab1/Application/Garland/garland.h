#ifndef GARLAND
#define GARLAND

#include <array>

template<auto& ...modes>
class Garland 
{
public:
  void NextMode() 
  {
    i++;
    if(i== regime.size()) 
    {
      i=0;
    }
    currentMode = regime[i];  
    currentMode->StartPosition(); 
    
    
  }
  void Update()
  {
    currentMode->Update();
  }
private:
  std::size_t i=0;
  std::array<IMode*, sizeof ...(modes)> regime = {static_cast<IMode*> (&modes)...};
  IMode* currentMode = regime[0]; 
};

#endif