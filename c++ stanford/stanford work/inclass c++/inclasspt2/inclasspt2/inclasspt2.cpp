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
	for (int i = 0; i < N; i++)
	{
		tongDay += arr[i];

		if (arr[i] >= 0)
		{
			tongDuong += arr[i];
		}
		else
		{
			tongAm += arr[i];
		}

		if (i % 2 == 0)//true
		{
			tongViTriChan += arr[i];
		}
		else
		{
			tongViTriLe += arr[i];
		}
	}

	trungBinh = tongDay / N;

	cout << "Tong day la: " << tongDay << endl;
	cout << "Trung binh day la: " << trungBinh << endl;
	cout << "Tong cac so duong la: " << tongDuong << endl;
	cout << "Tong cac so am la: " << tongAm << endl;
	cout << "Tong cac so o vi tri chan la: " << tongViTriChan << endl;
	cout << "Tong cac so o vi tri le la: " << tongViTriLe << endl;

	//Bài tập 2: Tìm và chỉ ra vị trí xuất hiện đầu tiên của phần tử x trong dãy.
	float x = 0;
	cout << "Nhap gia tri x can tim x = ";
	cin >> x;

	//Duyệt từng phần tử để tìm vị trí đầu tiên của x
	for (int i = 0; i < N; i++)
	{
		if (x == arr[i])//true
		{
			cout << "Vi tri dau tien cua " << x << " la: " << i + 1 << endl;
			break;
		}
	}

	//Bài tập 3: Nhập vào dãy n số. Hãy in ra số lớn nhất, bé nhất của dãy.
	//Khai báo biến
	float max = arr[0], min = arr[0];

	//Duyệt từng phần tử để lấy max, min
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}

		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	cout << "Gia tri lon nhat la: " << max << endl;
	cout << "Gia tri nho nhat la: " << min << endl;

	//Bài tập 4: Nhập vào dãy số. In ra dãy đã được sắp xếp tăng dần, giảm dần.
	//Khai báo biến
	float temp = 0;
	//Tăng dần
	//Xử lý sắp xếp
	//Duyệt từng phần tử
	for (int i = 0; i <= N - 1; i++)
	{
		//Duyệt từng phần tử tại vị trí i + 1 để hoán đổi nếu cần
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[i])//true
			{
				//Hoán đổi
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Day sap xep tang dan: " << endl;

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << endl;

	cout << "Day sap xep giam dan: " << endl;

	for (int i = N - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	system("pause");

	return 0;
}
/*
#include <iostream>
#include <vector>
#include<string>
#include <math.h>
using namespace std;

int main()
{

	//Bài tập 5: Hãy nhập vào 16 số nguyên. In ra thành 4 dòng, 4 cột. Nhập dạng chuỗi
	//Khai báo mảng 2 chiều kiểu số nguyên
	int arr[4][4];

	cout << "Nhap cac phan tu cho mang: " << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}

	cout << "Cac phan tu cua mang 4x4 la: " << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
		}
		//Xuống dòng
		cout << endl;
	}

	//Bài tập 8:
	//Nhập ma trận 4x4, báo ra:
	//Số các phần tử lớn hơn 0, liệt kê các phần tử lớn hơn 0 đó, tính tổng của chúng.
	//Số các phần tử nhỏ hơn 0, liệt kê các phần tử nhỏ hơn 0 đó, tính tổng của chúng.

	vector<int> vecDuong, vecAm;
	int tongDuong = 0, tongAm = 0;

	//Xử lý tách mảng 2 chiều về 1 chiều
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] >= 0)
			{
				vecDuong.push_back(arr[i][j]);
				tongDuong += arr[i][j];
			}
			else
			{
				vecAm.push_back(arr[i][j]);
				tongAm += arr[i][j];
			}
		}
	}

	cout << "Cac phan tu duong la: " << endl;
	for (const& i : vecDuong)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "Tong cac phan tu duong la: " << tongDuong << endl;

	cout << "Cac phan tu am la: " << endl;
	for (const& i : vecAm)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "Tong cac phan tu am la: " << tongAm << endl;

	//Bài tập 6:
	//Cho một chuỗi ký tự như sau: “Cong ty Stanford – Dao tao va phat trien cong nghe”. Hãy
	//chuyển chuỗi này thành một mảng, trong đó mỗi phần tử là một từ. Ví dụ a[0] = Cong,a[1] = ty, a[2] = Stanford,…Sau đó in kết quả ra màn hình

	string strCongTy = "Cong ty Stanford - Dao tao va phat trien cong nghe";

	vector<string> words;

	//Duyệt từng kí tự trong chuỗi
	string temp = "";
	for (int i = 0; i <= strCongTy.length();i++)
	{
		//Khi gặp kí tự khoảng trắng hoặc cuối chuỗi thì gán chuỗi temp vào danh sách
		if (strCongTy[i] == ' ' || i == strCongTy.length())
		{
			words.push_back(temp);
			temp = "";
		}
		else
		{
			temp += strCongTy[i];
		}
	}

	cout << "Cac tu sau khi cat ra la: " << endl;
	for (const string& gt : words)
	{
		cout << gt << endl;
	}

	//Bài 11: Viết chương trình nhập vào N số nguyên(N nhỏ hơn 20) và tính tổng các số nguyên tố trong các số đã nhập vào đó.
	const int MAX = 20;

	int arr[MAX];

	int n = 0;
NhapLai:
	cout << "Nhap mang gom n phan tu voi n = ";
	cin >> n;

	if (n > MAX) {
		cout << "Ban can phai nhap n nho hon " << MAX << endl;
		goto NhapLai;
	}

	cout << "Nhap cac phan tu: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	cout << "Cac so nguyen to la: " << endl;

	//Duyệt để tìm số nguyên tố và tính tổng
	bool isSoNguyenTo = true;
	int tongSoNguyenTo = 0;
	for (int i = 0; i < n; i++)
	{
		int giaTri = (int)sqrt(arr[i]);
		isSoNguyenTo = true;
		//Kiểm tra xem có phải là số nguyên tố không
		for (int j = 2; j <= giaTri; j++)
		{
			if (arr[i] % j == 0)
			{
				isSoNguyenTo = false;
			}
		}
		if (isSoNguyenTo)
		{
			tongSoNguyenTo += arr[i];
			cout << arr[i] << endl;
		}
	}

	cout << "Tong cac so nguyen to la: " << tongSoNguyenTo << endl;


	return 0;
}


#include <iostream>
#include <vector>
//Khai báo thư viện để làm việc với chuỗi
#include <string>
using namespace std;

int main()
{
	//Khai báo 1 danh sách
	vector<int> arr = { 1, 2, 3 };

	cout << "Gia tri cua phan tu 1 la: " << arr[0] << endl;
	cout << "Gia tri cua phan tu 2 la: " << arr[1] << endl;

	//Thêm 1 phần tử
	arr.push_back(5);

	//Chèn giá trị vào vị trí đầu tiên
	arr.insert(arr.begin(), 8);

	cout << "Cac phan tu trong danh sach: " << endl;
	//Duyệt từng phần tử để in ra
	for (const int& i : arr)
	{
		cout << i << "\t";
	}

	cout << endl;

	cout << "Phan tu dau tien: " << arr.front() << endl;
	cout << "Phan tu cuoi cung: " << arr.back() << endl;

	cout << "Phan tu o vi tri thu 3: " << arr.at(2) << endl;

	cout << "So luong phan tu cua danh sach la: " << arr.size() << endl;

	//Xóa phần tử
	arr.erase(arr.end());

	cout << "In danh sach cac phan tu trong danh sach: " << endl;

	for (auto i = arr.begin(); i != arr.end(); ++i)
	{
		cout << *i << endl;
	}

	//Khai báo biến
	string strChuoi = "";

	cout << "Nhap vao 1 chuoi la: " << endl;

	//Lấy 1 chuỗi và gán cho biến
	getline(cin, strChuoi);

	cout << "Chuoi thong tin la: " << strChuoi << endl;

	return 0;
}


#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{

	//Khai báo mảng kí tự
	char s[10], t[10];

	//Gán giá trị cho mảng
	strcpy_s(t, "Stanford");

	//Gán mảng t cho s
	//strcpy_s(s, t);

	//Lấy 5 kí tự của t gán cho s
	strncpy_s(s, t, 5);

	//Nối thêm kí tự vào mảng chuỗi
	strcat_s(s, "Ord");

	//So sánh 2 chuỗi
	int ketQua = strcmp(s, t);

	//So sánh 5 kí tự đầu tiên
	ketQua = strncmp(s, t, 5);

	//So sánh không phân biệt hoa thường
	ketQua = strcmpi(s, t);

	cout << "Ket qua so sanh la: " << ketQua << endl;

	cout << "Gia tri mang " << s << " to " << t << endl;

	cout << "In cac ki tu trong mang ki tu: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << t[i] << endl;
	}

	cout << "Chu thuong: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << (char)tolower(t[i]);
	}

	cout << endl << "Chu hoa: " << endl;

	for (int i = 0; i < 8; i++)
	{
		cout << (char)toupper(t[i]);
	}
	cout << endl;

	cout << "Do dai cua chuoi la: " << strlen(t) << endl;

	// Bài 12: Hãy nhập một xâu kí tự. In ra màn hình đảo ngược của xâu đó.
	string strChuoi = "";
	cout << "Nhap vao 1 chuoi: ";
	getline(cin, strChuoi);

	cout << "Chuoi la: " << strChuoi << endl;

	cout << "Chuoi nguoc la: " << endl;
	for (int i = strChuoi.length(); i >= 0; i--)
	{
		cout << strChuoi[i];
	}

	cout << endl;

	// Bài 13: Nhập xâu. Thống kê số các chữ số ‘0’, số chữ số ‘1’, …, số chữ số ‘9’ trong xâu.
	int tk[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


	//Duyệt từng kí tự để thống kê
	for (int i = 0; i < strChuoi.length(); i++)
	{
		switch (strChuoi[i])
		{
		case '0':
			tk[0]++;
			break;
		case '1':
			tk[1]++;
			break;
		case '2':
			tk[2]++;
			break;
		case '3':
			tk[3]++;
			break;
		case '4':
			tk[4]++;
			break;
		case '5':
			tk[5]++;
			break;
		case '6':
			tk[6]++;
			break;
		case '7':
			tk[7]++;
			break;
		case '8':
			tk[8]++;
			break;
		case '9':
			tk[9]++;
			break;
		}
	}


	// Bài 13 - Cách 2
	// Duyệt từng kí tự để thống kê
	for (int i = 0; i < strChuoi.length(); i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int giaTri = strChuoi[i] - 48;

			if (j == giaTri)
			{
				tk[j]++;
			}
		}
	}

	cout << "Thong ke so luong tung ki tu la: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << ": " << tk[i] << endl;
	}
	// Bài 14: Nhập xâu. In ra tất các các vị trí của chữ ‘a’ trong xâu và tổng số lần xuất hiện của nó.

	int soLan = 0;

	cout << "Cac vi tri ki tu a xuat hien la: " << endl;

	// Duyệt để thống kê các vị trí kí tự a
	for (int i = 0; i < strChuoi.length(); i++)
	{
		if (strChuoi[i] == 'a')
		{
			cout << i + 1 << endl;
			soLan++;
		}
	}

	cout << "Tong so lan ki tu a xuat hien: " << soLan << endl;
	return 0;
}


#include <iostream>
using namespace std;

int main()
{
	//Ví dụ 1: Khai báo 1 mảng 2 chiều kiểu số nguyên gồm 3 dòng và 2 cột
	/*
	a00     a01
	a10     a11
	a20     a21
	*/
	//Khai báo 1 biến mảng 2 chiều
	int arr[3][2];

	//Gán dữ liệu cho dòng 1
	arr[0][0] = 2;
	arr[0][1] = 3;

	//Dòng 2
	arr[1][0] = 5;
	arr[1][1] = 6;

	//Dòng 3
	arr[2][0] = 8;
	arr[2][1] = 9;

	cout << "Gia tri cua dong 1 cot 1 la: " << arr[0][0] << endl;
	cout << "Gia tri cua dong 2 cot 1 la: " << arr[1][0] << endl;
	cout << "Gia tri cua dong 3 cot 2 la: " << arr[2][1] << endl;

	cout << "In cac phan tu cua mang 3x2 la: " << endl;

	//Duyệt dòng
	for (int i = 0; i < 3; i++)
	{
		//Duyệt cột
		for (int j = 0; j < 2; j++)
		{
			cout << arr[i][j] << "\t";
		}

		//Xuống dòng
		cout << endl;
	}
	//Ví dụ 2: Khai báo 1 mảng 2 chiều kiểu số thực gồm m dòng và nột sau đó nhập thông tin cho các phần tử rồi in ra màn hình
	const int MAX = 20;

	//Khai báo biến
	float arr2[MAX][MAX];

	int m = 0, n = 0;
NhapLai:
	cout << "Nhap mang 2 chieu gom: " << endl;
	cout << "Nhap so dong m = ";
	cin >> m;

	cout << "Nhap so cot n = ";
	cin >> n;

	if (m > MAX || n > MAX)
	{
		cout << "Ban phai nhap m, n nho hon " << MAX << endl;
		goto NhapLai;
	}

	cout << "Nhap gia tri cho cac phan tu: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "arr2[" << i << "][" << j << "] = ";
			cin >> arr2[i][j];
		}
	}

	cout << "Cac phan tu cua mang " << m << "x" << n << " la: " << endl;
	//Duyệt dòng
	for (int i = 0; i < m; i++)
	{
		//Duyệt cột
		for (int j = 0; j < n; j++)
		{
			cout << arr2[i][j] << "\t";
		}

		//Xuống dòng
		cout << endl;
	}
	return 0;
}