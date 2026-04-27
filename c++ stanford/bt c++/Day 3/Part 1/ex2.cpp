#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const int MAX = 5;
    int cost[MAX] = {0};

    cost[2] = 100;
    cout << "Cach 1 - Dung chi so (cost[2] = 100): " << cost[2] << endl;

    int *p = &cost[2];
    *p = 200;
    cout << "Cach 2 - Dung con tro (*p = 200): " << cost[2] << endl;

    int *pBase = cost;
    *(pBase + 2) = 300;
    cout << "Cach 3 - Dung con tro co so + offset (*(pBase+2) = 300): " << cost[2] << endl;

    pBase[2] = 400;
    cout << "Cach 4 - Dung con tro voi cu phap mang (pBase[2] = 400): " << cost[2] << endl;

    cout << endl;
    cout << "Toan bo mang cost: ";
    for (int i = 0; i < MAX; i++)
    {
        cout << cost[i] << " ";
    }
    cout << endl;

    return 0;
}
