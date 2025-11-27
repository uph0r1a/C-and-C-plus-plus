//Đề bài 1: Dựa vào kiến thức đã được học về lập trình trong C++. Bạn hãy viết một chương
//trình C++ cho phép người dùng nhập 1 tập các số từ bàn phím vào với thông tin như sau :
//55, 65, 10, 75, 20, 45, 100, 85, 95, 30. Sau đó thực hiện các yêu cầu :
//✔ Tạo và gán các giá trị trên lấy được từ bàn phím cho các phần tử thuộc mảng(1đ)
//✔ Hiển thị vị trí, giá trị của phần tử lớn nhất và nhỏ nhất về mặt giá trị trong mảng lấy
//được ở trên. (2đ)
//✔ Thực hiện sắp xếp theo thứ tự giảm dần về mặt giá trị của các phần tử trong mảng
//lấy được và hiển thị danh sách ra ngoài màn hình. (2đ)
//✔ Thực hiện lấy top 3 thông tin có giá trị cao nhất và tổng các số chẵn trong mảng trên
//tập đã cho. (1đ)
//✔ Thống kê số lần xuất hiện số 5 trong dãy đã cho(2đ)
#include <iostream>
using namespace std;

int main()
{
	int arr[10], tongsoChan = 0, vitrimax = 0, vitrimin = 0, temp = 0, lan = 0, top1 = 0, top2 = 0, top3 = 0;

	cout << "Nhap cac phan tu: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "so " << i + 1 << " : ";
		cin >> arr[i];
	}

	int max = arr[0], min = arr[0];

	for (int i = 1; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			vitrimax = i;
		}

		if (arr[i] < min)
		{
			min = arr[i];
			vitrimin = i;
		}
	}

	cout << "Gia tri lon nhat la: " << max << " o vi tri " << vitrimax + 1 << endl;
	cout << "Gia tri nho nhat la: " << min << " o vi tri " << vitrimin + 1 << endl;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Day sap xep giam dan: " << endl;

	for (int i = 9; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > top1)
		{
			top3 = top2;
			top2 = top1;
			top1 = arr[i];
		}
		else if (arr[i] > top2)
		{
			top3 = top2;
			top2 = arr[i];
		}
		else if (arr[i] > top3)
		{
			top3 = arr[i];
		}
	}

	cout << "Ba phan tu lon nhat la: " << top1 << ", " << top2 << ", " << top3 << endl;

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
		{
			tongsoChan += arr[i];
		}
	}
	cout << endl;

	cout << "Tong cac so chan la: " << tongsoChan << endl;

	for (int i = 0; i < 10; i++)
	{
		if ((arr[i] - 5) % 10 == 0)
		{
			lan++;
		}
	}
	cout << "So lan so 5 xuat hien la: " << lan << endl;
}



//Đề bài 2: Bạn hãy viết một chương trình nhập vào 1 chuỗi các số như đề bài 1. Sau đó thực
//hiện tách lấy các số từ chuỗi để thực hiện tính tổng của chúng rồi in ra màn hình. (2đ)
#include<iostream>
using namespace std;

int main()
{
	const int MAX = 100;
	float arr[MAX], tongDay = 0;
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
		cout << "so " << i + 1 << " : ";
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		tongDay += arr[i];
	}

	cout << "Tong day la: " << tongDay << endl;
}
