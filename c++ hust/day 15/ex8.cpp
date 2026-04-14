#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <typename T>
class SimpleVector
{
private:
   T *aptr;
   int arraySize;

   void memError()
   {
      cout << "ERROR: Cannot allocate memory.\n";
      exit(EXIT_FAILURE);
   }

   void subError()
   {
      cout << "ERROR: Subscript out of range.\n";
      exit(EXIT_FAILURE);
   }

public:
   SimpleVector()
   {
      aptr = nullptr;
      arraySize = 0;
   }

   SimpleVector(int s)
   {
      arraySize = s;
      try
      {
         aptr = new T[s];
      }
      catch (bad_alloc)
      {
         memError();
      }

      for (int i = 0; i < arraySize; i++)
         aptr[i] = T();
   }

   SimpleVector(const SimpleVector &obj)
   {
      arraySize = obj.arraySize;
      aptr = new T[arraySize];

      if (!aptr)
         memError();

      for (int i = 0; i < arraySize; i++)
         aptr[i] = obj.aptr[i];
   }

   ~SimpleVector()
   {
      delete[] aptr;
   }

   int size() const
   {
      return arraySize;
   }

   T getElementAt(int sub)
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }

   T *push_back(T value)
   {
      T *newArr = new T[arraySize + 1];

      for (int i = 0; i < arraySize; i++)
      {
         newArr[i] = aptr[i];
      }

      newArr[arraySize] = value;

      delete[] aptr;

      aptr = newArr;
      arraySize++;

      return aptr;
   }

   T *pop_back()
   {
      T *newArr = new T[arraySize - 1];

      for (int i = 0; i < arraySize - 1; i++)
      {
         newArr[i] = aptr[i];
      }

      delete[] aptr;

      aptr = newArr;
      arraySize--;

      return aptr;
   }

   T &operator[](const int &sub)
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }
};

int main(int argc, char const *argv[])
{
   const int SIZE = 10;

   SimpleVector<int> intTable(SIZE);
   SimpleVector<double> doubleTable(SIZE);

   for (int i = 0; i < SIZE; i++)
   {
      intTable[i] = i * 2;
      doubleTable[i] = i * 2.14;
   }

   cout << "These values are in intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "These values are in doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << endl;

   cout << "\nAdding 5 to each element...\n";
   for (int i = 0; i < SIZE; i++)
   {
      intTable[i] += 5;
      doubleTable[i] += 5;
   }

   cout << "intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << endl;

   cout << "\nIncrementing each element...\n";
   for (int i = 0; i < SIZE; i++)
   {
      intTable[i]++;
      doubleTable[i]++;
   }

   cout << "intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << endl;

   cout << "Push back:\n";
   intTable.push_back(5);
   for (int i = 0; i < intTable.size(); i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "Pop back:\n";
   intTable.pop_back();
   for (int i = 0; i < intTable.size(); i++)
      cout << intTable[i] << " ";
   cout << endl;

   return 0;
}