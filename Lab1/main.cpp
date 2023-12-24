#include "rccregisters.hpp" // for RCC
#include "gpioaregisters.hpp" // for GPIOA
#include "gpiocregisters.hpp" // for GPIO�
#include  "pin.h"
#include  "treemode.h"
#include  "chessmode.h"
#include  "basemode.h"
#include  "allmode.h"
#include  "garland.h"
#include  "buttonnextmode.h"
#include <iostream>

std::uint32_t SystemCoreClock = 16'000'000U;
void delay(int cycles)
{
  for(int i = 0; i < cycles; ++i)    
  {   
    asm volatile("");
  }    
}


Pin<GPIOA, 5> pin1;
Pin<GPIOC, 9> pin2;
Pin<GPIOC, 8> pin3;
Pin<GPIOC, 5> pin4;

BaseMode<pin1, pin2, pin3, pin4> baseMode;
TreeMode<pin1, pin2, pin3, pin4> treeMode; 
ChessMode<pin1, pin2, pin3, pin4> chessMode;
AllMode<pin1, pin2, pin3, pin4> allMode;
Garland<treeMode, chessMode, allMode> garland;

ButtonNextMode<GPIOC, 13> button;

int main()
{  
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOAEN::Enable::Set() ;
  //������ ������������ �� ���� �
  RCC::AHB1ENR::GPIOCEN::Enable::Set() ;
  //����� �.5 �� �����
  GPIOA::MODER::MODER5::Output::Set() ;
  //����� C.5,C.8, C.9 �� �����
  GPIOC::MODER::MODER5::Output::Set() ;
  GPIOC::MODER::MODER8::Output::Set() ;
  GPIOC::MODER::MODER9::Output::Set() ;
  //���� �.13 �� ����
  GPIOC::MODER::MODER13::Input::Set() ;
  

  
  for(;;)
  {
     
     button.ButtonProcessing();
     if(button.IsPressedButton == true)
     {
        garland.NextMode();
      
     } 
     garland.Update();
     
     delay(1000000);
  }
  
  return 1;
}
