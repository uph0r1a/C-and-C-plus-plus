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

   void memError() const
   {
      cout << "ERROR: Cannot allocate memory.\n";
      exit(EXIT_FAILURE);
   }

   void subError() const
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

template <typename T>
class SearchableVector : public SimpleVector<T>
{
public:
   SearchableVector() : SimpleVector<T>() {}

   SearchableVector(int size) : SimpleVector<T>(size) {}

   SearchableVector(const SearchableVector &obj)
       : SimpleVector<T>(obj.size())
   {
      for (int i = 0; i < this->size(); i++)
         (*this)[i] = obj[i];
   }

   void sort()
   {
      int n = this->size();
      for (int i = 0; i < n - 1; i++)
      {
         for (int j = 0; j < n - i - 1; j++)
         {
            if ((*this)[j] > (*this)[j + 1])
            {
               T temp = (*this)[j];
               (*this)[j] = (*this)[j + 1];
               (*this)[j + 1] = temp;
            }
         }
      }
   }

   int findItem(const T item)
   {
      sort();

      int low = 0;
      int high = this->size() - 1;

      while (low <= high)
      {
         int mid = (low + high) / 2;

         if (this->getElementAt(mid) == item)
            return mid;
         else if (this->getElementAt(mid) > item)
            high = mid - 1;
         else
            low = mid + 1;
      }

      return -1;
   }
};

int main(int argc, char const *argv[])
{
   const int SIZE = 10;
   int result;

   SearchableVector<int> intTable(SIZE);
   SearchableVector<double> doubleTable(SIZE);

   for (int i = 0; i < SIZE; i++)
   {
      intTable[i] = i * 2;
      doubleTable[i] = i * 2.14;
   }

   cout << "These values are in intTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << intTable[i] << " ";
   cout << "\n\n";

   cout << "These values are in doubleTable:\n";
   for (int i = 0; i < SIZE; i++)
      cout << doubleTable[i] << " ";
   cout << "\n";

   cout << "\nSearching for 6 in intTable.\n";
   result = intTable.findItem(6);
   if (result == -1)
      cout << "6 was not found.\n";
   else
      cout << "6 found at index " << result << endl;

   cout << "\nSearching for 12.84 in doubleTable.\n";
   result = doubleTable.findItem(12.84);
   if (result == -1)
      cout << "12.84 was not found.\n";
   else
      cout << "12.84 found at index " << result << endl;

   return 0;
}