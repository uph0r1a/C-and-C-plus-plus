#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

template <typename T>
class SimpleVector
{
private:
   T *aptr;          // Pointer to the allocated array
   int arraySize;    // Number of elements in the array

   void memError()   // Handles memory allocation errors
   {
      cout << "ERROR: Cannot allocate memory.\n";
      exit(EXIT_FAILURE);
   }

   void subError()   // Handles subscripts out of range
   {
      cout << "ERROR: Subscript out of range.\n";
      exit(EXIT_FAILURE);
   }

public:
   // Default constructor
   SimpleVector()
   {
      aptr = nullptr;
      arraySize = 0;
   }

   // Constructor
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
         aptr[i] = T();  // better than = 0 for templates
   }

   // Copy constructor
   SimpleVector(const SimpleVector &obj)
   {
      arraySize = obj.arraySize;
      aptr = new T[arraySize];

      if (!aptr)
         memError();

      for (int i = 0; i < arraySize; i++)
         aptr[i] = obj.aptr[i];
   }

   // Destructor
   ~SimpleVector()
   {
      delete[] aptr;
   }

   // Return size
   int size() const
   {
      return arraySize;
   }

   // Get element
   T getElementAt(int sub)
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }

   // Overloaded []
   T &operator[](const int &sub)
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }
};

template <typename T>
class SortableVector : public SimpleVector
{
private: 

public:
    
};


// ===== MAIN PROGRAM =====
int main(int argc, char const *argv[])
{
   const int SIZE = 10;
   
   SimpleVector<int> intTable(SIZE);
   SimpleVector<double> doubleTable(SIZE);

   // Fill values
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

   // Add 5
   cout << "\nAdding 5 to each element...\n";
   for (int i = 0; i < SIZE; i++)
   {
      intTable[i] += 5;
      doubleTable[i] += 5;
   }

   // Display again
   cout << "intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << endl;

   // Increment
   cout << "\nIncrementing each element...\n";
   for (int i = 0; i < SIZE; i++)
   {
      intTable[i]++;
      doubleTable[i]++;
   }

   // Final display
   cout << "intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << endl;

   cout << "doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << endl;

   return 0;
}