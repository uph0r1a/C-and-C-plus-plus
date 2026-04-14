#include <iostream>
#include <cstdlib>
using namespace std;

class IntArray
{
private:
   int *aptr;
   int arraySize;

   void subscriptError()
   {
      throw "ERROR: Subscript out of range.\n";
   }

public:
   IntArray(int s)
   {
      arraySize = s;
      aptr = new int[s];
      for (int count = 0; count < arraySize; count++)
         aptr[count] = 0;
   }

   IntArray(const IntArray &obj)
   {
      arraySize = obj.arraySize;
      aptr = new int[arraySize];
      for (int count = 0; count < arraySize; count++)
         aptr[count] = obj.aptr[count];
   }

   ~IntArray()
   {
      if (arraySize > 0)
         delete[] aptr;
   }

   int size() const
   {
      return arraySize;
   }

   IntArray &operator=(const IntArray &right)
   {
      if (this != &right)
      {
         delete[] aptr;
         arraySize = right.arraySize;
         aptr = new int[arraySize];
         for (int count = 0; count < arraySize; count++)
            aptr[count] = right.aptr[count];
      }
      return *this;
   }

   int &operator[](const int &sub)
   {
      if (sub < 0 || sub >= arraySize)
         subscriptError();
      return aptr[sub];
   }
};

int main(int argc, char const *argv[])
{

   return 0;
}
