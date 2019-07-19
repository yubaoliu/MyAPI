#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
  Entity()
  {
    std::cout<<"Created Entity"<<std::endl;
    
  }
  ~Entity()
  {
    std::cout<<"Destroyed Entity!"<<std::endl;
  }
  void Print()
  {}
};

int main()
{
  std::unique_ptr<Entity> entity(new Entity());// --std=c++11
  //std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //--std=c++14
  entity->Print();


  std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
  std::shared_ptr<Entity> e0;
  e0 = sharedEntity;
  
  return std::cin.get();
}
