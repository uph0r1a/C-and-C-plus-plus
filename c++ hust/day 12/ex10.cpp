#include <iostream>
using namespace std;

class NumberArray
{
public:
    NumberArray(int arrSize)
    {
        size = arrSize;
        array = new float[size];
    }

    ~NumberArray()
    {
        delete[] array;
    }

    void setNumber(float numb, int pos)
    {
        array[pos] = numb;
    }

    float getNumber(int pos) const
    {
        return array[pos];
    }

    float getMax() const
    {
        float max;

        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                max = array[i];
                continue;
            }

            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }

    float getMin() const
    {
        float min;

        for (int i = 0; i < size; i++)
        {
            if (i == 0)
            {
                min = array[i];
                continue;
            }

            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }

    float getAverage()
    {
        float sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += array[i];
        }
        return sum / size;
    }

private:
    float *array;
    int size;
};

int main(int argc, char const *argv[])
{
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    NumberArray array(size);

    for (int i = 0; i < size; i++)
    {
        int numb;

        cout << "Enter number " << i + 1 << ": ";
        cin >> numb;
        array.setNumber(numb, i);
    }

    for (int i = 0; i < size; i++)
    {
        cout << array.getNumber(i) << "\t";
    }

    cout << endl;

    cout << "The highest value stored in the array: " << array.getMax() << endl
         << "The lowest value stored in the array: " << array.getMin() << endl
         << "The average of all the numbers stored in the array: " << array.getAverage() << endl;

    return 0;
}
