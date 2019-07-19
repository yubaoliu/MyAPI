#include <iostream>
#include "SmartPointer.h"
using namespace std;
using namespace YBLib;
class Test
{
public:
  Test()
  {
    cout<<"Test()"<<endl;
  }
  ~Test()
  {
    cout<<"~Test()"<<endl;
  }
};

int main(int argc, char *argv[])
{
  SmartPointer<Test> sp = new Test();
  SmartPointer<Test> nsp;

  nsp = sp;
  cout<<sp.isNull()<<endl;
  cout<<nsp.isNull()<<endl;
  return 0;
}
