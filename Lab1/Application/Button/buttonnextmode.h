#ifndef BUTTONNEXTMODE
#define BUTTONNEXTMODE

#include "gpioaregisters.hpp" // for GPIOA

template<typename Port, int pinNumber>
class ButtonNextMode
{
public:
  void ButtonProcessing() 
  {
    
    previouspositionbutton = buttonposition;
    buttonposition = ((Port::IDR::Get()&(1<<pinNumber))!=(1<<pinNumber));
    if((previouspositionbutton==1) && (buttonposition==0))
    {
      IsPressedButton=1;
    } else 
    {
      IsPressedButton=0;
    }

  }
  std::size_t buttonposition;
  std::size_t previouspositionbutton;
  std::size_t IsPressedButton;
};

#endif