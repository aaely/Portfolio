#ifndef PRODUCE_ITEM
#define PRODUCE_ITEM

#include <string>

using namespace std;

class ProduceItem {
   public:
      ProduceItem(string n);
      void SetName(string n) { name = n; }
      void SetOccurance(int occ) { occurance = occ; }
      string GetName() { return name; }
      int GetOccurance() { return occurance; }
   private:
      string name;
      int occurance;
};

#endif