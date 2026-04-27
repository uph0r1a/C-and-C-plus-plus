#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int demChuSo5(const int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int so = abs(arr[i]);
		if (so == 0)
			continue;
		while (so > 0)
		{
			if (so % 10 == 5)
				count++;
			so /= 10;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	const int N = 10;
	int arr[N];

	cout << "Nhap " << N << " phan tu:\n";
	for (int i = 0; i < N; i++)
	{
		cout << "  so " << (i + 1) << ": ";
		cin >> arr[i];
	}

	int original[N];
	copy(arr, arr + N, original);

	int *pMax = max_element(arr, arr + N);
	int *pMin = min_element(arr, arr + N);
	cout << "\nGia tri lon nhat: " << *pMax
		 << " o vi tri " << (pMax - arr + 1) << "\n";
	cout << "Gia tri nho nhat: " << *pMin
		 << " o vi tri " << (pMin - arr + 1) << "\n";

	sort(arr, arr + N);

	cout << "\nDay sap xep giam dan:\n  ";
	for (int i = N - 1; i >= 0; i--)
		cout << arr[i] << (i > 0 ? "\t" : "\n");

	cout << "\nTop 3 gia tri cao nhat: "
		 << arr[N - 1] << ", " << arr[N - 2] << ", " << arr[N - 3] << "\n";

	int tongChan = 0;
	for (int i = 0; i < N; i++)
		if (original[i] % 2 == 0)
			tongChan += original[i];
	cout << "Tong cac so chan: " << tongChan << "\n";

	cout << "So lan chu so 5 xuat hien: " << demChuSo5(original, N) << "\n";

	return 0;
}