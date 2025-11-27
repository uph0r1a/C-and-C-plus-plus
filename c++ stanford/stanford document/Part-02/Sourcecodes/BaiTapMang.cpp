#include <iostream>
using namespace std;

int main()
{
    //Bài tập 1: Nhập vào dãy n số thực. Tính tổng dãy, trung bình dãy, tổng các số âm dương và tổng các số ở vị trí chẵn, vị trí lẻ trong dãy.
    const int MAX = 20;
    // Khai báo mảng
    float arr[MAX], tongDay = 0, trungBinh = 0, tongDuong = 0, tongAm = 0, tongViTriChan = 0, tongViTriLe = 0;
    int N = 0;

NhapLai:
    cout << "Nhap mang gom N phan tu voi N = ";
    cin >> N;
    if (N > MAX)
    {
        cout << "Ban phan nhap so phan nho hon " << MAX << endl;
        goto NhapLai;
    }
    cout << "Nhap cac phan tu: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "arr2[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "Cac phan tu trong mang gom " << N << " phan tu: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;

    //Xử lý tính toán
    for(int i = 0; i < N; i++)
    {
        tongDay += arr[i];

        if(arr[i] >= 0)
        {
            tongDuong += arr[i];
        }
        else
        {
            tongAm += arr[i];
        }

        if(i%2 == 0)//true
        {
            tongViTriChan += arr[i];
        }
        else
        {
            tongViTriLe += arr[i];
        }
    }

    trungBinh = tongDay/N;

    cout <<"Tong day la: "<<tongDay<<endl;
    cout <<"Trung binh day la: "<<trungBinh<<endl;
    cout <<"Tong cac so duong la: "<<tongDuong<<endl;
    cout <<"Tong cac so am la: "<<tongAm<<endl;
    cout <<"Tong cac so o vi tri chan la: "<<tongViTriChan<<endl;
    cout <<"Tong cac so o vi tri le la: "<<tongViTriLe<<endl;

    //Bài tập 2: Tìm và chỉ ra vị trí xuất hiện đầu tiên của phần tử x trong dãy.
    float x = 0;
    cout <<"Nhap gia tri x can tim x = ";
    cin>>x;

    //Duyệt từng phần tử để tìm vị trí đầu tiên của x
    for(int i = 0; i < N; i++)
    {
        if(x == arr[i])//true
        {
            cout <<"Vi tri dau tien cua "<<x<<" la: "<<i+1<<endl;
            break;
        }
    }

    //Bài tập 3: Nhập vào dãy n số. Hãy in ra số lớn nhất, bé nhất của dãy.
    //Khai báo biến
    float max = arr[0], min = arr[0];

    //Duyệt từng phần tử để lấy max, min
    for(int i = 1; i < N; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout <<"Gia tri lon nhat la: "<<max<<endl;
    cout <<"Gia tri nho nhat la: "<<min<<endl;

    //Bài tập 4: Nhập vào dãy số. In ra dãy đã được sắp xếp tăng dần, giảm dần.
    //Khai báo biến
    float temp = 0;
    //Tăng dần
    //Xử lý sắp xếp
    //Duyệt từng phần tử
    for(int i = 0; i <= N-1; i++)
    {
        //Duyệt từng phần tử tại vị trí i + 1 để hoán đổi nếu cần
        for(int j = i + 1; j < N; j++)
        {
            if(arr[j] < arr[i])//true
            {
                //Hoán đổi
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout <<"Day sap xep tang dan: "<<endl;

    for(int i = 0; i < N; i++)
    {
        cout <<arr[i]<<"\t";
    }

    cout <<endl;

    cout <<"Day sap xep giam dan: "<<endl;

    for(int i = N- 1; i>= 0; i--)
    {
        cout <<arr[i]<<"\t";
    }
    cout <<endl;

    system("pause");

    return 0;
}