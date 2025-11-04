// bt 5
#include <iostream>
using namespace std;

int main()
{
    unsigned int tuoiCha = 0, tuoiCon = 0, soNam = 0;

    do
    {
        cout << "nhao tuoi cha ";
        cin >> tuoiCha;
        cout << "nhap tuoi con ";
        cin >> tuoiCon;
    } while (tuoiCha <= 2 * tuoiCon);

    soNam = tuoiCha - 2 * tuoiCon;

    tuoiCha += soNam;
    tuoiCon += soNam;

    cout << "So nam de tuoi cha gap 2 lan tuoi con la: " << soNam << endl;
    cout << "Tuoi cha moi la: " << tuoiCha << endl;
    cout << "Tuoi con moi la: " << tuoiCon << endl;
}

// bt6
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double s1 = 0, s2 = 0;
    int N = 0;

    do
    {
        N++;
        s1 += 1 / (2.0 * N - 1);
    } while (s1 < 2.101999);

    cout << "Gia tri lon nhat cua N de thoa man dieu kien la: " << N - 1 << endl;

    N = 0;
    do
    {
        N++;
        s2 = exp(N) - 1999 * log10(N);
    } while (s2 < 2000);

    cout << "6b. Gia tri lon nhat cua Nde thoa man dieu kien la: " << N - 1 << endl;
}

// bt1

#include <iostream>
using namespace std;

int main()
{
    char kitu, t;
Nhaplai:

    cout << "Nhap vao ki tu: ";
    cin.get(kitu);

    if ((kitu >= 65 && kitu <= 90) || (kitu >= 97 && kitu <= 122))
    {
        cout << "Day la ki tu chu cai" << endl;
    }
    else
    {
        cout << "Khong phai la ki tu chu cai" << endl;
    }

    cout << "Ban co muon tiep tuc thuc hien ? Nhan 1 de tiep tuc: ";

    cin.ignore(1);

    cin.get(t);

    if (t == '1')
    {
        cin.ignore(1);
        goto Nhaplai;
    }
}
#include <iostream>
using namespace std;

int main()
{
    int i = 0, j = 0;
    while (i < 8)
    {
        j = 0;
        while (j <= i)
        {
            cout << "#";
            j++;
        }
        cout << endl;
        i++;
    }
}