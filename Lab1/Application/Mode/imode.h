#ifndef IMODE
#define IMODE

class IMode
{
  public:
  virtual void Update() = 0;
  virtual void StartPosition() = 0;
};

#endif