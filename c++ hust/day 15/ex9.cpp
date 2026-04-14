#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

// ===================== SimpleVector =====================
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
         aptr[i] = T();
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

   int size() const
   {
      return arraySize;
   }

   T getElementAt(int sub) const
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }

   T &operator[](const int &sub)
   {
      if (sub < 0 || sub >= arraySize)
         subError();
      return aptr[sub];
   }
};


// ===================== SearchableVector =====================
template <typename T>
class SearchableVector : public SimpleVector<T>
{
public:
   // Default constructor
   SearchableVector() : SimpleVector<T>() {}

   // Constructor
   SearchableVector(int size) : SimpleVector<T>(size) {}

   // Copy constructor
   SearchableVector(const SearchableVector &obj)
      : SimpleVector<T>(obj.size())
   {
      for (int i = 0; i < this->size(); i++)
         (*this)[i] = obj[i];
   }

   // Search function
   int findItem(const T item)
   {
      for (int i = 0; i < this->size(); i++)   // FIXED (was <=)
      {
         if (this->getElementAt(i) == item)
            return i;
      }
      return -1;
   }
};


// ===================== MAIN =====================
int main()
{
   const int SIZE = 10;
   int result;

   SearchableVector<int> intTable(SIZE);
   SearchableVector<double> doubleTable(SIZE);

   // Fill data
   for (int i = 0; i < SIZE; i++)
   {
      intTable[i] = i * 2;
      doubleTable[i] = i * 2.14;
   }

   // Display
   cout << "These values are in intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << "\n\n";

   cout << "These values are in doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << "\n";

   // Search int
   cout << "\nSearching for 6 in intTable.\n";
   result = intTable.findItem(6);
   if (result == -1)
      cout << "6 was not found.\n";
   else
      cout << "6 found at index " << result << endl;

   // Search double
   cout << "\nSearching for 12.84 in doubleTable.\n";
   result = doubleTable.findItem(12.84);
   if (result == -1)
      cout << "12.84 was not found.\n";
   else
      cout << "12.84 found at index " << result << endl;

   return 0;
}