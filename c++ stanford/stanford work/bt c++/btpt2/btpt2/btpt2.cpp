//Bài tập 1: Nhập vào dãy n số thực. Tính tổng dãy, trung bình dãy, tổng các số âm,
//dương và tổng các số ở vị trí chẵn, vị trí lẻ trong dãy.
#include <iostream.h>

using namespace std;

void calculateStats(double numbers[], int n, double& totalSum, double& average,
	double& negativeSum, double& positiveSum, double& evenIndexSum, double& oddIndexSum) {
	totalSum = 0.0;
	negativeSum = 0.0;
	positiveSum = 0.0;
	evenIndexSum = 0.0;
	oddIndexSum = 0.0;

	for (int i = 0; i < n; ++i) {
		totalSum += numbers[i];

		if (numbers[i] < 0)
			negativeSum += numbers[i];
		else if (numbers[i] > 0)
			positiveSum += numbers[i];

		if (i % 2 == 0)
			evenIndexSum += numbers[i];
		else
			oddIndexSum += numbers[i];
	}

	average = totalSum / n;
}

int main() {
	int n;
	cout << "Nhập vào số lượng phần tử của dãy: ";
	cin >> n;

	double numbers[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhập số thực thứ " << i + 1 << ": ";
		cin >> numbers[i];
	}

	double totalSum, average, negativeSum, positiveSum, evenIndexSum, oddIndexSum;
	calculateStats(numbers, n, totalSum, average, negativeSum, positiveSum, evenIndexSum, oddIndexSum);

	cout << "Tổng của dãy: " << totalSum << endl;
	cout << "Trung bình của dãy: " << average << endl;
	cout << "Tổng các số âm: " << negativeSum << endl;
	cout << "Tổng các số dương: " << positiveSum << endl;
	cout << "Tổng các số ở vị trí chẵn: " << evenIndexSum << endl;
	cout << "Tổng các số ở vị trí lẻ: " << oddIndexSum << endl;

	return 0;
}

//Bài tập 2: Tìm và chỉ ra vị trí xuất hiện đầu tiên của phần tử x trong dãy.
#include <iostream.h>

using namespace std;

int findFirstOccurrence(double numbers[], int n, double x) {
	for (int i = 0; i < n; ++i) {
		if (numbers[i] == x) {
			return i;
		}
	}
	return -1; // Nếu không tìm thấy x trong dãy
}

int main() {
	int n;
	cout << "Nhập vào số lượng phần tử của dãy: ";
	cin >> n;

	double numbers[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhập số thực thứ " << i + 1 << ": ";
		cin >> numbers[i];
	}

	double x;
	cout << "Nhập giá trị x cần tìm: ";
	cin >> x;

	int position = findFirstOccurrence(numbers, n, x);
	if (position != -1) {
		cout << "Phần tử " << x << " xuất hiện đầu tiên tại vị trí: " << position << endl;
	}
	else {
		cout << "Phần tử " << x << " không tồn tại trong dãy." << endl;
	}

	return 0;
}

//Bài tập 3: Nhập vào dãy n số. Hãy in ra số lớn nhất, bé nhất của dãy.
#include <iostream.h>

using namespace std;

void findMinMax(double numbers[], int n, double& maxNumber, double& minNumber) {
	maxNumber = numbers[0];
	minNumber = numbers[0];

	for (int i = 1; i < n; ++i) {
		if (numbers[i] > maxNumber) {
			maxNumber = numbers[i];
		}
		if (numbers[i] < minNumber) {
			minNumber = numbers[i];
		}
	}
}

int main() {
	int n;
	cout << "Nhập vào số lượng phần tử của dãy: ";
	cin >> n;

	double numbers[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhập số thứ " << i + 1 << ": ";
		cin >> numbers[i];
	}

	double maxNumber, minNumber;
	findMinMax(numbers, n, maxNumber, minNumber);

	cout << "Số lớn nhất trong dãy là: " << maxNumber << endl;
	cout << "Số bé nhất trong dãy là: " << minNumber << endl;

	return 0;
}

//Bài tập 4: Nhập vào dãy số. In ra dãy đã được sắp xếp tăng dần, giảm dần.
#include <iostream.h>

using namespace std;

// Hàm hoán đổi hai số
void swap(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

// Hàm sắp xếp mảng theo thứ tự tăng dần
void sortAscending(double numbers[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] > numbers[j]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

// Hàm sắp xếp mảng theo thứ tự giảm dần
void sortDescending(double numbers[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] < numbers[j]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

int main() {
	int n;
	cout << "Nhập vào số lượng phần tử của dãy: ";
	cin >> n;

	double numbers[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhập số thứ " << i + 1 << ": ";
		cin >> numbers[i];
	}

	// Sắp xếp tăng dần
	sortAscending(numbers, n);
	cout << "Dãy số được sắp xếp tăng dần: ";
	for (int i = 0; i < n; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	// Sắp xếp giảm dần
	sortDescending(numbers, n);
	cout << "Dãy số được sắp xếp giảm dần: ";
	for (int i = 0; i < n; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài tập 5: Hãy nhập vào 16 số nguyên. In ra thành 4 dòng, 4 cột. Nhập dạng chuỗi
#include <iostream.h>
#include <string.h>

using namespace std;

int main() {
	const int SIZE = 16;
	int numbers[SIZE];
	char input[100];

	cout << "Nhập vào 16 số nguyên (ngăn cách bằng khoảng trắng): ";
	cin.getline(input, 100);

	// Tách chuỗi thành các số nguyên
	char* token = strtok(input, " ");
	int index = 0;
	while (token != NULL && index < SIZE) {
		numbers[index++] = atoi(token);
		token = strtok(NULL, " ");
	}

	// Kiểm tra nếu không đủ 16 số nguyên
	if (index != SIZE) {
		cout << "Bạn đã nhập không đủ 16 số nguyên." << endl;
		return 1;
	}

	// In ra thành 4 dòng, 4 cột
	cout << "Ma trận 4x4:" << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << numbers[i] << "\t";
		if ((i + 1) % 4 == 0) {
			cout << endl;
		}
	}

	return 0;
}

//Bài tập 6:
//Cho một chuỗi ký tự như sau : “Cong ty Stanford – Dao tao va phat trien cong nghe”.Hãy
//chuyển chuỗi này thành một mảng, trong đó mỗi phần tử là một từ.Ví dụ a[0] = Cong,
//a[1] = ty, a[2] = Stanford, …Sau đó in kết quả ra màn hình.
#include <iostream.h>
#include <string.h>

using namespace std;

int main() {
	const char str[] = "Cong ty Stanford – Dao tao va phat trien cong nghe";
	const int MAX_WORDS = 100;
	char* words[MAX_WORDS];
	int wordCount = 0;

	// Tách chuỗi thành các từ
	char tempStr[strlen(str) + 1];
	strcpy(tempStr, str);
	char* token = strtok(tempStr, " ");
	while (token != NULL && wordCount < MAX_WORDS) {
		words[wordCount++] = token;
		token = strtok(NULL, " ");
	}

	// In kết quả ra màn hình
	for (int i = 0; i < wordCount; ++i) {
		cout << "a[" << i << "] = " << words[i] << endl;
	}

	return 0;
}

//Bài tập 7:
//Cho một dãy các số sau : 10, 20, 90, 50, 100, 60, 30, 80, 70, 40. Hãy sắp xếp các dãy này
//theo chiều tăng dần, giảm dần.
//Yêu cầu :
//Thiết kế giao diện nhập từng phần tử và hiển thị kết quả ra màn hình.
//Sau khi nhập đủ 10 phần tử theo đúng thứ tự như đề bài thì thực hiện sắp xếp theo chiều
//tăng dần, giảm dần.
#include <iostream.h>

using namespace std;

// Hàm hoán đổi hai số
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Hàm sắp xếp mảng theo thứ tự tăng dần
void sortAscending(int numbers[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] > numbers[j]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

// Hàm sắp xếp mảng theo thứ tự giảm dần
void sortDescending(int numbers[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] < numbers[j]) {
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

int main() {
	const int SIZE = 10;
	int numbers[SIZE];
	int predefinedNumbers[SIZE] = { 10, 20, 90, 50, 100, 60, 30, 80, 70, 40 };

	// Nhập vào 10 phần tử theo đúng thứ tự
	cout << "Nhập vào 10 phần tử của dãy theo thứ tự sau: 10, 20, 90, 50, 100, 60, 30, 80, 70, 40" << endl;
	for (int i = 0; i < SIZE; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> numbers[i];

		// Kiểm tra nếu phần tử không đúng thứ tự định trước
		if (numbers[i] != predefinedNumbers[i]) {
			cout << "Phần tử không đúng thứ tự yêu cầu. Vui lòng nhập lại." << endl;
			--i; // Yêu cầu nhập lại phần tử hiện tại
		}
	}

	// Sắp xếp tăng dần
	sortAscending(numbers, SIZE);
	cout << "Dãy số được sắp xếp tăng dần: ";
	for (int i = 0; i < SIZE; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	// Sắp xếp giảm dần
	sortDescending(numbers, SIZE);
	cout << "Dãy số được sắp xếp giảm dần: ";
	for (int i = 0; i < SIZE; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài tập 8:
//Nhập ma trận 4x4, báo ra :
//Số các phần tử lớn hơn 0, liệt kê các phần tử lớn hơn 0 đó, tính tổng của chúng.
//Số các phần tử nhỏ hơn 0, liệt kê các phần tử nhỏ hơn 0 đó, tính tổng của chúng.
#include <iostream.h>

using namespace std;

int main() {
	const int SIZE = 4;
	int matrix[SIZE][SIZE];
	int positiveCount = 0, negativeCount = 0;
	int positiveSum = 0, negativeSum = 0;

	// Nhập ma trận 4x4
	cout << "Nhập ma trận 4x4:" << endl;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << "Nhập phần tử [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> matrix[i][j];
		}
	}

	// Xử lý các phần tử lớn hơn 0 và nhỏ hơn 0
	cout << "\nCác phần tử lớn hơn 0:" << endl;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (matrix[i][j] > 0) {
				cout << matrix[i][j] << " ";
				positiveCount++;
				positiveSum += matrix[i][j];
			}
		}
	}

	cout << "\nSố lượng phần tử lớn hơn 0: " << positiveCount << endl;
	cout << "Tổng các phần tử lớn hơn 0: " << positiveSum << endl;

	cout << "\nCác phần tử nhỏ hơn 0:" << endl;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (matrix[i][j] < 0) {
				cout << matrix[i][j] << " ";
				negativeCount++;
				negativeSum += matrix[i][j];
			}
		}
	}

	cout << "\nSố lượng phần tử nhỏ hơn 0: " << negativeCount << endl;
	cout << "Tổng các phần tử nhỏ hơn 0: " << negativeSum << endl;

	return 0;
}

//Bài 9: Viết chương trình nhập vào 1 mảng gồm N phần tử, với N được nhập từ bàn phím.
//Tách mảng đã cho thành 2 mảng, 1 mảng chứa các số âm, 1 mảng chứa các số dương.
//In ra 3 mảng trên.
#include <iostream.h>

using namespace std;

int main() {
	int N;
	cout << "Nhập vào số lượng phần tử của mảng: ";
	cin >> N;

	int arr[N], negativeArr[N], positiveArr[N];
	int negCount = 0, posCount = 0;

	// Nhập mảng ban đầu
	cout << "Nhập các phần tử của mảng: " << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tách mảng thành mảng số âm và mảng số dương
	for (int i = 0; i < N; ++i) {
		if (arr[i] < 0) {
			negativeArr[negCount++] = arr[i];  // Lưu vào mảng số âm
		}
		else if (arr[i] > 0) {
			positiveArr[posCount++] = arr[i];  // Lưu vào mảng số dương
		}
	}

	// In mảng ban đầu
	cout << "\nMảng ban đầu: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}

	// In mảng số âm
	cout << "\nMảng số âm: ";
	if (negCount == 0) {
		cout << "Không có số âm." << endl;
	}
	else {
		for (int i = 0; i < negCount; ++i) {
			cout << negativeArr[i] << " ";
		}
	}

	// In mảng số dương
	cout << "\nMảng số dương: ";
	if (posCount == 0) {
		cout << "Không có số dương." << endl;
	}
	else {
		for (int i = 0; i < posCount; ++i) {
			cout << positiveArr[i] << " ";
		}
	}

	return 0;
}

//Bài 10: Viết chương trình nhập vào một mảng gồm N số nguyên và số nguyên K (N được
//nhập từ bàn phím).
//Tìm và đưa ra màn hình :
//Giá trị lớn nhất của mảng, vị trí lớn nhất đó.
//Giá trị nhỏ nhất của mảng, vị trí đó.
//Tổng bình phương các giá trị ở vị trí chẵn.
//Sắp xếp mảng theo thứ tự tăng dần và giảm dần.
//Đếm xem trong mảng có bao nhiêu giá trị bằng k và đưa ra các vị trí đó.
#include <iostream.h>

using namespace std;

int main() {
	int N, K;

	// Nhập kích thước mảng N và số nguyên K
	cout << "Nhập số lượng phần tử của mảng: ";
	cin >> N;

	int arr[N];

	// Nhập mảng
	cout << "Nhập các phần tử của mảng: " << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Nhập giá trị K
	cout << "Nhập giá trị K: ";
	cin >> K;

	// Tìm giá trị lớn nhất và vị trí lớn nhất
	int maxVal = arr[0], maxPos = 0;
	int minVal = arr[0], minPos = 0;

	for (int i = 1; i < N; ++i) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
			maxPos = i;
		}
		if (arr[i] < minVal) {
			minVal = arr[i];
			minPos = i;
		}
	}

	// Tính tổng bình phương các giá trị ở vị trí chẵn
	int sumOfSquares = 0;
	for (int i = 0; i < N; i += 2) {
		sumOfSquares += arr[i] * arr[i];
	}

	// Sắp xếp mảng theo thứ tự tăng dần
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// In ra mảng sau khi sắp xếp tăng dần
	cout << "\nMảng sau khi sắp xếp theo thứ tự tăng dần: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Sắp xếp mảng theo thứ tự giảm dần
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// In ra mảng sau khi sắp xếp giảm dần
	cout << "\nMảng sau khi sắp xếp theo thứ tự giảm dần: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// Đếm các giá trị bằng K và in các vị trí
	int countK = 0;
	cout << "\nCác vị trí có giá trị bằng K: ";
	for (int i = 0; i < N; ++i) {
		if (arr[i] == K) {
			cout << i << " ";
			countK++;
		}
	}
	if (countK == 0) {
		cout << "Không có giá trị nào bằng K.";
	}
	cout << endl;

	// In ra giá trị lớn nhất và vị trí của nó
	cout << "\nGiá trị lớn nhất của mảng: " << maxVal << " tại vị trí " << maxPos << endl;

	// In ra giá trị nhỏ nhất và vị trí của nó
	cout << "Giá trị nhỏ nhất của mảng: " << minVal << " tại vị trí " << minPos << endl;

	// In ra tổng bình phương các giá trị ở vị trí chẵn
	cout << "Tổng bình phương các giá trị ở vị trí chẵn: " << sumOfSquares << endl;

	return 0;
}

//Bài 11: Viết chương trình nhập vào N số nguyên(N nhỏ hơn 20) và tính tổng các số
//nguyên tố trong các số đã nhập vào đó.
#include <iostream.h>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
	if (num <= 1) {
		return false; // Số nhỏ hơn hoặc bằng 1 không phải số nguyên tố
	}
	for (int i = 2; i <= num / 2; ++i) {
		if (num % i == 0) {
			return false; // Nếu chia hết cho i thì không phải số nguyên tố
		}
	}
	return true; // Nếu không chia hết cho bất kỳ số nào thì là số nguyên tố
}

int main() {
	int N;

	// Nhập số lượng phần tử N (N nhỏ hơn 20)
	do {
		cout << "Nhập số lượng phần tử N (N < 20): ";
		cin >> N;
		if (N >= 20) {
			cout << "N phải nhỏ hơn 20. Vui lòng nhập lại." << endl;
		}
	} while (N >= 20);

	int arr[N];
	int primeSum = 0;

	// Nhập các phần tử vào mảng
	cout << "Nhập " << N << " số nguyên: " << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tính tổng các số nguyên tố
	for (int i = 0; i < N; ++i) {
		if (isPrime(arr[i])) {
			primeSum += arr[i];
		}
	}

	// In ra tổng các số nguyên tố
	cout << "Tổng các số nguyên tố trong mảng là: " << primeSum << endl;

	return 0;
}

//Bài 12: Hãy nhập một xâu kí tự. In ra màn hình đảo ngược của xâu đó.
#include <iostream.h>
#include <string.h>

using namespace std;

int main() {
	char str[100];

	// Nhập xâu ký tự
	cout << "Nhập một xâu ký tự: ";
	cin.getline(str, 100);

	// Tính chiều dài của xâu
	int length = strlen(str);

	// In xâu đảo ngược
	cout << "Xâu ký tự sau khi đảo ngược: ";
	for (int i = length - 1; i >= 0; --i) {
		cout << str[i];
	}
	cout << endl;

	return 0;
}

//Bài 13: Nhập xâu. Thống kê số các chữ số ‘0’, số chữ số ‘1’, …, số chữ số ‘9’ trong xâu.
#include <iostream.h>
#include <string.h>

using namespace std;

int main() {
	char str[100];
	int count[10] = { 0 }; // Mảng để đếm số lần xuất hiện của từng chữ số từ 0 đến 9

	// Nhập xâu ký tự
	cout << "Nhập một xâu ký tự: ";
	cin.getline(str, 100);

	// Duyệt qua từng ký tự trong xâu và đếm các chữ số
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			count[str[i] - '0']++;  // Tăng giá trị tương ứng với chữ số trong mảng count
		}
	}

	// In ra số lần xuất hiện của từng chữ số từ 0 đến 9
	cout << "Thống kê số lần xuất hiện của từng chữ số trong xâu: " << endl;
	for (int i = 0; i <= 9; ++i) {
		cout << "Số chữ số '" << i << "': " << count[i] << endl;
	}

	return 0;
}

//Bài 14: Nhập xâu. In ra tất các các vị trí của chữ ‘a’ trong xâu và tổng số lần xuất hiện
//của nó.
#include <iostream.h>
#include <string.h>

using namespace std;

int main() {
	char str[100];
	int count = 0;

	// Nhập xâu ký tự
	cout << "Nhập một xâu ký tự: ";
	cin.getline(str, 100);

	// Duyệt qua từng ký tự trong xâu và tìm các vị trí của chữ 'a'
	cout << "Các vị trí của chữ 'a' trong xâu: ";
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 'a') {
			cout << i << " ";  // In ra vị trí (chỉ số) của chữ 'a'
			count++;  // Tăng biến đếm số lần xuất hiện của chữ 'a'
		}
	}

	// In ra tổng số lần xuất hiện của chữ 'a'
	cout << "\nTổng số lần xuất hiện của chữ 'a': " << count << endl;

	return 0;
}

//Bài 15: Thay kí tự x trong xâu s bởi kí tự y (s, x, y được đọc vào từ bàn phím)
#include <iostream.h>
#include <cstring>

using namespace std;

int main() {
	char s[100];
	char x, y;

	// Nhập xâu ký tự s
	cout << "Nhập xâu ký tự: ";
	cin.getline(s, 100);

	// Nhập ký tự x và y
	cout << "Nhập ký tự x (kí tự cần thay thế): ";
	cin >> x;
	cout << "Nhập ký tự y (kí tự thay thế): ";
	cin >> y;

	// Duyệt qua xâu và thay thế ký tự x bằng y
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == x) {
			s[i] = y;  // Thay ký tự x bằng y
		}
	}

	// In ra xâu sau khi thay đổi
	cout << "Xâu sau khi thay đổi: " << s << endl;

	return 0;
}

//Bài 16: Cho một chuỗi có tên như sau : “Cong ty Stanford – Dao tao va phat trien cong
//nghe”.
//Yêu cầu :
//✓ Hãy lấy chữ Stanford từ chuỗi trên.
//✓ Hiển thị vị trí đầu tiên của chữ “t” và vị trí cuối cùng của chữ 
#include <iostream.h>
#include <cstring>

using namespace std;

int main() {
	// Chuỗi cho trước
	char str[] = "Cong ty Stanford – Dao tao va phat trien cong nghe";

	// Tìm và lấy chữ "Stanford" từ chuỗi
	char* word = strstr(str, "Stanford"); // Dùng strstr để tìm chuỗi con "Stanford"
	if (word != NULL) {
		cout << "Chữ 'Stanford' trong chuỗi là: " << word << endl;
	}
	else {
		cout << "Không tìm thấy chữ 'Stanford' trong chuỗi!" << endl;
	}

	// Tìm vị trí đầu tiên và cuối cùng của chữ 't' trong chuỗi
	int firstPos = -1, lastPos = -1;

	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 't') {
			if (firstPos == -1) {
				firstPos = i;  // Lưu vị trí đầu tiên của 't'
			}
			lastPos = i;  // Cập nhật vị trí cuối cùng của 't'
		}
	}

	if (firstPos != -1) {
		cout << "Vị trí đầu tiên của chữ 't' là: " << firstPos << endl;
		cout << "Vị trí cuối cùng của chữ 't' là: " << lastPos << endl;
	}
	else {
		cout << "Không tìm thấy chữ 't' trong chuỗi!" << endl;
	}

	return 0;
}

//Bài 1: Viết chương trình nhập vào 1 mảng gồm N phần tử, với N được nhập từ bàn phím.
//Tách mảng đã cho thành 2 mảng, 1 mảng chứa các số âm, 1 mảng chứa các số dương.
//In ra 3 mảng trên.
#include <iostream.h>

using namespace std;

int main() {
	int N;

	// Nhập vào số phần tử N của mảng
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];       // Mảng ban đầu
	int negative[N];  // Mảng chứa các số âm
	int positive[N];  // Mảng chứa các số dương
	int negCount = 0, posCount = 0;  // Đếm số phần tử âm và dương

	// Nhập các phần tử cho mảng ban đầu
	cout << "Nhập các phần tử cho mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tách mảng thành 2 mảng âm và dương
	for (int i = 0; i < N; ++i) {
		if (arr[i] < 0) {
			negative[negCount++] = arr[i];  // Nếu là số âm, lưu vào mảng negative
		}
		else if (arr[i] > 0) {
			positive[posCount++] = arr[i];  // Nếu là số dương, lưu vào mảng positive
		}
	}

	// In ra mảng ban đầu
	cout << "\nMảng ban đầu: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	// In ra mảng chứa các số âm
	cout << "\nMảng chứa các số âm: ";
	for (int i = 0; i < negCount; ++i) {
		cout << negative[i] << " ";
	}
	cout << endl;

	// In ra mảng chứa các số dương
	cout << "\nMảng chứa các số dương: ";
	for (int i = 0; i < posCount; ++i) {
		cout << positive[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài 2: Viết chương trình nhập vào một mảng gồm N số nguyên và số nguyên K (N được
//nhập từ bàn phím).
//Tìm và đưa ra màn hình :
//Giá trị lớn nhất của mảng, vị trí lớn nhất đó.
//Giá trị nhỏ nhất của mảng, vị trí đó.
//Tổng bình phương các giá trị ở vị trí chẵn.
//Sắp xếp mảng theo thứ tự tăng dần và giảm dần.
//Đếm xem trong mảng có bao nhiêu giá trị bằng k và đưa ra các vị trí đó.
#include <iostream.h>
#include <algorithm>  // Dùng cho hàm sort()

using namespace std;

int main() {
	int N, K;

	// Nhập số lượng phần tử N và số K
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;
	cout << "Nhập số nguyên K: ";
	cin >> K;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm giá trị lớn nhất và nhỏ nhất cùng với vị trí của chúng
	int maxVal = arr[0], minVal = arr[0];
	int maxPos = 0, minPos = 0;
	for (int i = 1; i < N; ++i) {
		if (arr[i] > maxVal) {
			maxVal = arr[i];
			maxPos = i;
		}
		if (arr[i] < minVal) {
			minVal = arr[i];
			minPos = i;
		}
	}

	// Tính tổng bình phương các giá trị ở vị trí chẵn
	int sumSquares = 0;
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			sumSquares += arr[i] * arr[i];
		}
	}

	// Sắp xếp mảng theo thứ tự tăng dần
	int arrAsc[N];
	for (int i = 0; i < N; ++i) {
		arrAsc[i] = arr[i];
	}
	sort(arrAsc, arrAsc + N);  // Sắp xếp tăng dần

	// Sắp xếp mảng theo thứ tự giảm dần
	int arrDesc[N];
	for (int i = 0; i < N; ++i) {
		arrDesc[i] = arr[i];
	}
	sort(arrDesc, arrDesc + N, greater<int>());  // Sắp xếp giảm dần

	// Đếm số lần xuất hiện của K và liệt kê các vị trí
	cout << "\nCác vị trí của số K trong mảng: ";
	bool foundK = false;
	for (int i = 0; i < N; ++i) {
		if (arr[i] == K) {
			cout << i << " ";
			foundK = true;
		}
	}
	if (!foundK) {
		cout << "Không tìm thấy giá trị K trong mảng.";
	}
	cout << endl;

	// In kết quả
	cout << "\nGiá trị lớn nhất của mảng là: " << maxVal << ", Vị trí: " << maxPos << endl;
	cout << "Giá trị nhỏ nhất của mảng là: " << minVal << ", Vị trí: " << minPos << endl;
	cout << "Tổng bình phương các giá trị ở vị trí chẵn là: " << sumSquares << endl;

	cout << "\nMảng sau khi sắp xếp tăng dần: ";
	for (int i = 0; i < N; ++i) {
		cout << arrAsc[i] << " ";
	}
	cout << endl;

	cout << "Mảng sau khi sắp xếp giảm dần: ";
	for (int i = 0; i < N; ++i) {
		cout << arrDesc[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài 3: Viết chương trình nhập vào N số nguyên(N nhỏ hơn 20) và tính tổng các số nguyên
//tố trong các số đã nhập vào đó.
#include <iostream.h>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;  // Số nhỏ hơn hoặc bằng 1 không phải là số nguyên tố
	for (int i = 2; i * i <= n; ++i) {  // Kiểm tra đến căn bậc 2 của n
		if (n % i == 0) return false;  // Nếu n chia hết cho i thì không phải số nguyên tố
	}
	return true;
}

int main() {
	int N;

	// Nhập vào số lượng phần tử N
	cout << "Nhập số lượng phần tử N (N < 20): ";
	cin >> N;

	// Kiểm tra điều kiện N nhỏ hơn 20
	if (N >= 20) {
		cout << "N phải nhỏ hơn 20. Vui lòng nhập lại." << endl;
		return 0;
	}

	int arr[N];
	int sumPrimes = 0;

	// Nhập các số nguyên vào mảng
	cout << "Nhập các số nguyên:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tính tổng các số nguyên tố trong mảng
	for (int i = 0; i < N; ++i) {
		if (isPrime(arr[i])) {
			sumPrimes += arr[i];  // Cộng số nguyên tố vào tổng
		}
	}

	// In kết quả
	cout << "Tổng các số nguyên tố trong mảng là: " << sumPrimes << endl;

	return 0;
}

//Bài 4: Nhập từ bàn phím N số nguyên với N được nhập từ bàn phím và số nguyên x, y.
//Tìm kiếm vị trí xuất hiện của x trên mảng.Thay thế những giá trị x thành y.
//Ví dụ : Mảng A : 1 3 5 7 3 11
//X = 3 Y = 9
//Kêt quả : Vị trí xuất hiện của 3 là 2 và 5.
//Kết quả thay thế : 1 9 5 7 9 11
#include <iostream.h>

using namespace std;

int main() {
	int N, x, y;

	// Nhập vào số lượng phần tử N, số nguyên x và y
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Nhập giá trị x và y
	cout << "Nhập giá trị x: ";
	cin >> x;
	cout << "Nhập giá trị y: ";
	cin >> y;

	// Tìm và in các vị trí xuất hiện của x trong mảng
	cout << "Các vị trí xuất hiện của " << x << " là: ";
	bool found = false;
	for (int i = 0; i < N; ++i) {
		if (arr[i] == x) {
			cout << i << " ";
			found = true;
		}
	}

	if (!found) {
		cout << "Không có giá trị x trong mảng.";
	}
	cout << endl;

	// Thay thế tất cả các giá trị x thành y
	for (int i = 0; i < N; ++i) {
		if (arr[i] == x) {
			arr[i] = y;
		}
	}

	// In mảng sau khi thay thế
	cout << "Mảng sau khi thay thế: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài 5: Viết chương trình nhập N số nguyên ( với N được nhập từ bàn phím, N < 20). Tìm
//kiếm các cặp 2 phần tử gần nhau có tổng chia hết cho 10. Thay thế các phần tử đó bằng
//tổng của chúng.
#include <iostream.h>

using namespace std;

int main() {
	int N;

	// Nhập vào số lượng phần tử N
	cout << "Nhập số lượng phần tử N (N < 20): ";
	cin >> N;

	// Kiểm tra điều kiện N < 20
	if (N >= 20) {
		cout << "N phải nhỏ hơn 20. Vui lòng nhập lại." << endl;
		return 0;
	}

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm các cặp phần tử gần nhau có tổng chia hết cho 10 và thay thế
	for (int i = 0; i < N - 1; ++i) {
		if ((arr[i] + arr[i + 1]) % 10 == 0) {
			arr[i] = arr[i] + arr[i + 1];  // Thay thế phần tử i bằng tổng của phần tử i và i+1
			arr[i + 1] = arr[i];           // Thay thế phần tử i+1 bằng tổng của chúng
		}
	}

	// In mảng sau khi thay thế
	cout << "Mảng sau khi thay thế: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài 6: Viết chương trình nhập mảng gồm 10 số nguyên từ bàn phím. Kiểm tra mảng có đối
//xứng không ? Mảng có tăng dần hay giảm dần không ?
#include <iostream.h>

using namespace std;

// Hàm kiểm tra mảng có đối xứng không
bool isSymmetric(int arr[], int size) {
	for (int i = 0; i < size / 2; ++i) {
		if (arr[i] != arr[size - i - 1]) {
			return false;  // Nếu có phần tử không đối xứng, trả về false
		}
	}
	return true;  // Nếu tất cả các phần tử đối xứng, trả về true
}

// Hàm kiểm tra mảng có tăng dần không
bool isAscending(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] > arr[i + 1]) {
			return false;  // Nếu có phần tử nào không thỏa điều kiện tăng dần, trả về false
		}
	}
	return true;  // Nếu tất cả các phần tử tăng dần, trả về true
}

// Hàm kiểm tra mảng có giảm dần không
bool isDescending(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] < arr[i + 1]) {
			return false;  // Nếu có phần tử nào không thỏa điều kiện giảm dần, trả về false
		}
	}
	return true;  // Nếu tất cả các phần tử giảm dần, trả về true
}

int main() {
	int arr[10];

	// Nhập mảng gồm 10 số nguyên
	cout << "Nhập 10 số nguyên:" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Kiểm tra mảng có đối xứng không
	if (isSymmetric(arr, 10)) {
		cout << "Mảng đối xứng." << endl;
	}
	else {
		cout << "Mảng không đối xứng." << endl;
	}

	// Kiểm tra mảng có tăng dần không
	if (isAscending(arr, 10)) {
		cout << "Mảng tăng dần." << endl;
	}
	else if (isDescending(arr, 10)) {
		cout << "Mảng giảm dần." << endl;
	}
	else {
		cout << "Mảng không tăng dần cũng không giảm dần." << endl;
	}

	return 0;
}

//Bài 7: Viết chương trình nhập N số từ bàn phím. Kiểm tra xem các phần tử đó theo thứ tự
//có phải là cấp số cộng hay không ?
#include <iostream.h>

using namespace std;

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Kiểm tra mảng có phải là cấp số cộng hay không
	bool isArithmetic = true;
	if (N > 1) {
		int difference = arr[1] - arr[0];  // Tính hiệu của 2 phần tử đầu tiên

		// Kiểm tra sự chênh lệch giữa các phần tử
		for (int i = 2; i < N; ++i) {
			if (arr[i] - arr[i - 1] != difference) {
				isArithmetic = false;  // Nếu có phần tử không thỏa mãn điều kiện cấp số cộng
				break;
			}
		}
	}

	// In kết quả
	if (isArithmetic) {
		cout << "Các phần tử tạo thành cấp số cộng." << endl;
	}
	else {
		cout << "Các phần tử không tạo thành cấp số cộng." << endl;
	}

	return 0;
}

//Bài 8: Viết chương trình nhập vào N số nguyên (N được người dùng nhập vào), chèn gía
//trị X vào vị trí x trong mảng, xóa phần tử ở vị trí y trong mảng.x và y cũng được nhập vào
//từ bàn phím.
#include <iostream>
using namespace std;

int main() {
	int N, X, x, y;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Nhập giá trị X và vị trí x để chèn
	cout << "Nhập giá trị X để chèn vào mảng: ";
	cin >> X;
	cout << "Nhập vị trí x để chèn giá trị X (0 <= x < " << N << "): ";
	cin >> x;

	// Kiểm tra vị trí x hợp lệ
	if (x < 0 || x > N) {
		cout << "Vị trí chèn không hợp lệ!" << endl;
		return 0;
	}

	// Chèn giá trị X vào vị trí x
	for (int i = N; i > x; --i) {
		arr[i] = arr[i - 1];  // Di chuyển các phần tử từ vị trí x đến cuối mảng một vị trí về sau
	}
	arr[x] = X;  // Chèn giá trị X vào vị trí x
	N++;  // Tăng kích thước mảng

	// Nhập vị trí y để xóa phần tử
	cout << "Nhập vị trí y để xóa phần tử (0 <= y < " << N << "): ";
	cin >> y;

	// Kiểm tra vị trí y hợp lệ
	if (y < 0 || y >= N) {
		cout << "Vị trí xóa không hợp lệ!" << endl;
		return 0;
	}

	// Xóa phần tử ở vị trí y
	for (int i = y; i < N - 1; ++i) {
		arr[i] = arr[i + 1];  // Di chuyển các phần tử sau vị trí y về trước
	}
	N--;  // Giảm kích thước mảng

	// In mảng sau khi chèn và xóa
	cout << "Mảng sau khi chèn và xóa: ";
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}

//Bài 9: Viết chương trình tỉnh tổng và hiệu 2 ma trận 4x5 và in kết quả ra màn hình.
#include <iostream>
using namespace std;

int main() {
	int matrix1[4][5], matrix2[4][5], sum[4][5], diff[4][5];

	// Nhập các phần tử cho ma trận 1
	cout << "Nhập ma trận 1 (4x5): " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "Nhập phần tử matrix1[" << i << "][" << j << "]: ";
			cin >> matrix1[i][j];
		}
	}

	// Nhập các phần tử cho ma trận 2
	cout << "Nhập ma trận 2 (4x5): " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << "Nhập phần tử matrix2[" << i << "][" << j << "]: ";
			cin >> matrix2[i][j];
		}
	}

	// Tính tổng và hiệu của ma trận 1 và ma trận 2
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			sum[i][j] = matrix1[i][j] + matrix2[i][j];  // Tính tổng
			diff[i][j] = matrix1[i][j] - matrix2[i][j];  // Tính hiệu
		}
	}

	// In kết quả tổng
	cout << "\nTổng của ma trận 1 và ma trận 2 là: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << sum[i][j] << "\t";
		}
		cout << endl;
	}

	// In kết quả hiệu
	cout << "\nHiệu của ma trận 1 và ma trận 2 là: " << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << diff[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}

//Bài 1: Hãy tìm giá trị trong mảng các số thực xa giá trị x nhất
#include <iostream>
#include <cmath>  // Thư viện để sử dụng hàm fabs() tính giá trị tuyệt đối
using namespace std;

int main() {
	int N;
	double x;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Nhập giá trị x
	cout << "Nhập giá trị x: ";
	cin >> x;

	// Tìm giá trị trong mảng xa x nhất
	double max_diff = fabs(arr[0] - x);  // Lấy chênh lệch tuyệt đối của phần tử đầu tiên
	double farthest_value = arr[0];      // Giá trị xa x nhất ban đầu

	for (int i = 1; i < N; ++i) {
		double diff = fabs(arr[i] - x);  // Tính chênh lệch tuyệt đối với x
		if (diff > max_diff) {
			max_diff = diff;            // Cập nhật chênh lệch lớn nhất
			farthest_value = arr[i];    // Cập nhật giá trị xa x nhất
		}
	}

	// In kết quả
	cout << "Giá trị trong mảng xa " << x << " nhất là: " << farthest_value << endl;

	return 0;
}

//Bài 2: Hãy tìm giá trị trong mảng các số thực gần giá trị x nhất
#include <iostream>
#include <cmath>  // Thư viện để sử dụng hàm fabs() tính giá trị tuyệt đối
using namespace std;

int main() {
	int N;
	double x;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Nhập giá trị x
	cout << "Nhập giá trị x: ";
	cin >> x;

	// Tìm giá trị trong mảng gần x nhất
	double min_diff = fabs(arr[0] - x);  // Lấy chênh lệch tuyệt đối của phần tử đầu tiên
	double closest_value = arr[0];       // Giá trị gần x nhất ban đầu

	for (int i = 1; i < N; ++i) {
		double diff = fabs(arr[i] - x);  // Tính chênh lệch tuyệt đối với x
		if (diff < min_diff) {
			min_diff = diff;            // Cập nhật chênh lệch nhỏ nhất
			closest_value = arr[i];     // Cập nhật giá trị gần x nhất
		}
	}

	// In kết quả
	cout << "Giá trị trong mảng gần " << x << " nhất là: " << closest_value << endl;

	return 0;
}

//Bài 3: Cho mảng 1 chiều các số thực, hãy tìm đoạn [a, b] sao cho đoạn này chứa tất cả các
//giá trị trong mảng
#include <iostream>
#include <limits>  // Thư viện để sử dụng giá trị vô cùng lớn và vô cùng nhỏ
using namespace std;

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Khởi tạo giá trị nhỏ nhất và lớn nhất
	double min_value = numeric_limits<double>::infinity();  // Giá trị lớn nhất có thể
	double max_value = -numeric_limits<double>::infinity(); // Giá trị nhỏ nhất có thể

	// Tìm giá trị nhỏ nhất và lớn nhất trong mảng
	for (int i = 0; i < N; ++i) {
		if (arr[i] < min_value) {
			min_value = arr[i];
		}
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}

	// In kết quả
	cout << "Đoạn [a, b] chứa tất cả các giá trị trong mảng là: [" << min_value << ", " << max_value << "]" << endl;

	return 0;
}

//Bài 4: Cho mảng 1 chiều các số thực, hãy tìm giá trị x sao cho đoạn [-x, x] chứa tất cả
//các giá trị trong mảng
#include <iostream>
#include <cmath>  // Thư viện để sử dụng hàm fabs() tính giá trị tuyệt đối
using namespace std;

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm giá trị x sao cho đoạn [-x, x] chứa tất cả các giá trị trong mảng
	double max_abs_value = fabs(arr[0]);  // Lấy giá trị tuyệt đối của phần tử đầu tiên

	// Duyệt qua các phần tử còn lại để tìm giá trị tuyệt đối lớn nhất
	for (int i = 1; i < N; ++i) {
		if (fabs(arr[i]) > max_abs_value) {
			max_abs_value = fabs(arr[i]);  // Cập nhật giá trị tuyệt đối lớn nhất
		}
	}

	// Giá trị x là giá trị tuyệt đối lớn nhất
	double x = max_abs_value;

	// In kết quả
	cout << "Giá trị x sao cho đoạn [-x, x] chứa tất cả các giá trị trong mảng là: " << x << endl;

	return 0;
}

//Bài 5: Cho mảng 1 chiều các số thực, hãy tìm giá trị đầu tiên lớn hơn giá trị 2003. Nếu
//mảng không có giá trị thỏa điều kiện trên thì trả về - 1
#include <iostream>
using namespace std;

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm phần tử đầu tiên lớn hơn 2003
	double result = -1;  // Nếu không tìm thấy, trả về -1
	for (int i = 0; i < N; ++i) {
		if (arr[i] > 2003) {
			result = arr[i];
			break;  // Dừng lại khi tìm được phần tử đầu tiên thỏa điều kiện
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có giá trị nào lớn hơn 2003 trong mảng." << endl;
	}
	else {
		cout << "Giá trị đầu tiên lớn hơn 2003 là: " << result << endl;
	}

	return 0;
}

//Bài 6: Cho mảng 1 chiều các số thực, hãy tìm giá trị âm cuối cùng lớn hơn giá trị -1. Nếu
//mảng không có giá trị thỏa điều kiện trên thì trả về - 1
#include <iostream>
using namespace std;

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm giá trị âm cuối cùng lớn hơn -1
	double result = -1;  // Mặc định trả về -1 nếu không tìm thấy
	for (int i = N - 1; i >= 0; --i) {  // Duyệt từ cuối mảng
		if (arr[i] < 0 && arr[i] > -1) {
			result = arr[i];
			break;  // Dừng lại khi tìm thấy giá trị thỏa mãn
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có giá trị âm lớn hơn -1 trong mảng." << endl;
	}
	else {
		cout << "Giá trị âm cuối cùng lớn hơn -1 là: " << result << endl;
	}

	return 0;
}

//Bài 7: Cho mảng 1 chiều các số nguyên, hãy tìm giá trị đầu tiên nằm trong khoảng [x, y]
//cho trước.Nếu mảng không có giá trị thỏa điều kiện trên thì trả về - 1
#include <iostream>
using namespace std;

int main() {
	int N, x, y;

	// Nhập số lượng phần tử N và giá trị x, y
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;
	cout << "Nhập giá trị x: ";
	cin >> x;
	cout << "Nhập giá trị y: ";
	cin >> y;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm phần tử đầu tiên trong khoảng [x, y]
	int result = -1;  // Mặc định trả về -1 nếu không tìm thấy
	for (int i = 0; i < N; ++i) {
		if (arr[i] >= x && arr[i] <= y) {
			result = arr[i];
			break;  // Dừng lại khi tìm được phần tử đầu tiên thỏa điều kiện
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có giá trị nào trong khoảng [" << x << ", " << y << "] trong mảng." << endl;
	}
	else {
		cout << "Giá trị đầu tiên trong khoảng [" << x << ", " << y << "] là: " << result << endl;
	}

	return 0;
}

//Bài 8: Cho mảng 1 chiều các số thực. Hãy viết hàm tìm một vị trí trong mảng thỏa 2 điều
//kiện: có 2 giá trị lân cận và giá trị tại đó bằng tích 2 giá trị lân cận.Nếu mảng không tồn
//tại giá trị như vậy thì trả về giá trị - 1
#include <iostream>
using namespace std;

// Hàm tìm vị trí thỏa điều kiện
int findPosition(double arr[], int N) {
	// Kiểm tra mảng có đủ ít nhất 3 phần tử
	if (N < 3) {
		return -1;
	}

	// Duyệt qua mảng từ phần tử thứ 1 đến phần tử thứ (N-2)
	for (int i = 1; i < N - 1; ++i) {
		if (arr[i] == arr[i - 1] * arr[i + 1]) {
			return i;  // Trả về vị trí thỏa mãn
		}
	}

	return -1;  // Không tìm thấy giá trị thỏa mãn
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	double arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm vị trí thỏa điều kiện
	int result = findPosition(arr, N);

	// In kết quả
	if (result == -1) {
		cout << "Không có vị trí thỏa mãn trong mảng." << endl;
	}
	else {
		cout << "Vị trí thỏa mãn là: " << result << endl;
	}

	return 0;
}

//Bài 9: Tìm số chính phương đầu tiên trong mảng 1 chiều các số nguyên
#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra một số có phải là số chính phương không
bool isPerfectSquare(int n) {
	int sqrtN = (int)sqrt(n); // Lấy căn bậc 2 của n và ép kiểu thành số nguyên
	return (sqrtN * sqrtN == n); // Kiểm tra n có bằng bình phương của sqrtN không
}

int main() {
	int N;

	// Nhập số lượng phần tử của mảng
	cout << "Nhập số lượng phần tử của mảng N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Duyệt qua mảng để tìm số chính phương đầu tiên
	int result = -1;
	for (int i = 0; i < N; ++i) {
		if (isPerfectSquare(arr[i])) {
			result = arr[i];
			break;  // Dừng lại khi tìm thấy số chính phương đầu tiên
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có số chính phương trong mảng." << endl;
	}
	else {
		cout << "Số chính phương đầu tiên là: " << result << endl;
	}

	return 0;
}

//Bài 10: Cho mảng 1 chiều các số nguyên. Hãy tìm giá trị đầu tiên thỏa mãn tính chất số
//gánh
#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra một số có phải là số gánh không
bool isBalanced(int num) {
	int sumOdd = 0, sumEven = 0;
	bool isOddPosition = true;  // Vị trí chữ số bắt đầu từ 1, xác định chẵn/lẻ

	// Tách các chữ số của số num
	while (num > 0) {
		int digit = num % 10; // Lấy chữ số cuối
		if (isOddPosition) {
			sumOdd += digit;  // Cộng vào tổng các chữ số ở vị trí lẻ
		}
		else {
			sumEven += digit;  // Cộng vào tổng các chữ số ở vị trí chẵn
		}
		num /= 10;  // Loại bỏ chữ số cuối
		isOddPosition = !isOddPosition;  // Chuyển vị trí lẻ/chan
	}

	// Kiểm tra nếu tổng các chữ số ở vị trí lẻ và chẵn bằng nhau
	return sumOdd == sumEven;
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Duyệt qua mảng để tìm số gánh đầu tiên
	int result = -1;
	for (int i = 0; i < N; ++i) {
		if (isBalanced(abs(arr[i]))) {  // Sử dụng abs để bỏ qua dấu của số âm
			result = arr[i];
			break;  // Dừng lại khi tìm thấy số gánh đầu tiên
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có số gánh trong mảng." << endl;
	}
	else {
		cout << "Số gánh đầu tiên là: " << result << endl;
	}

	return 0;
}

//Bài 11: Cho mảng 1 chiều các số nguyên. Hãy tìm giá trị đầu tiên có chữ số đầu tiên là chữ
//số lẻ
#include <iostream>
#include <cmath>
using namespace std;

// Hàm lấy chữ số đầu tiên của một số
int getFirstDigit(int num) {
	// Lấy giá trị tuyệt đối của số để bỏ qua dấu âm
	num = abs(num);

	// Tiến hành chia cho 10 đến khi số còn lại chỉ có một chữ số
	while (num >= 10) {
		num /= 10;
	}
	return num;  // Trả về chữ số đầu tiên
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Duyệt qua mảng để tìm số có chữ số đầu tiên là số lẻ
	int result = -1;
	for (int i = 0; i < N; ++i) {
		int firstDigit = getFirstDigit(arr[i]);  // Lấy chữ số đầu tiên
		if (firstDigit % 2 != 0) {  // Kiểm tra xem chữ số đầu tiên có phải là số lẻ không
			result = arr[i];
			break;  // Dừng lại khi tìm thấy số đầu tiên có chữ số đầu tiên là số lẻ
		}
	}

	// In kết quả
	if (result == -1) {
		cout << "Không có số nào có chữ số đầu tiên là số lẻ trong mảng." << endl;
	}
	else {
		cout << "Số đầu tiên có chữ số đầu tiên là số lẻ là: " << result << endl;
	}

	return 0;
}

//Bài 12: Cho mảng 1 chiều các số nguyên. Hãy viết hàm tìm giá trị đầu tiên trong mảng có
//dạng 2 ^ k.Nếu mảng không có giá trị dạng 2k thì hàm sẽ trả về 0
#include <iostream>
using namespace std;

// Hàm kiểm tra xem số có phải là dạng 2^k hay không
bool isPowerOfTwo(int num) {
	return (num > 0) && (num & (num - 1)) == 0;  // Kiểm tra điều kiện là số lũy thừa của 2
}

// Hàm tìm giá trị đầu tiên có dạng 2^k trong mảng
int findFirstPowerOfTwo(int arr[], int N) {
	for (int i = 0; i < N; ++i) {
		if (isPowerOfTwo(arr[i])) {
			return arr[i];  // Trả về giá trị đầu tiên có dạng 2^k
		}
	}
	return 0;  // Nếu không tìm thấy số nào có dạng 2^k, trả về 0
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm giá trị đầu tiên có dạng 2^k trong mảng
	int result = findFirstPowerOfTwo(arr, N);

	// In kết quả
	if (result == 0) {
		cout << "Không có số nào có dạng 2^k trong mảng." << endl;
	}
	else {
		cout << "Giá trị đầu tiên có dạng 2^k trong mảng là: " << result << endl;
	}

	return 0;
}

//Bài 13: Cho mảng 1 chiều các số nguyên. Hãy viết hàm tìm giá trị lớn nhất trong mảng có
//dạng 5 ^ k.Nếu mảng khong tồn tại giá trị 5 ^ k thì hàm sẽ trả về 0
#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra xem một số có phải là dạng 5^k hay không
bool isPowerOfFive(int num) {
	if (num <= 0) {
		return false; // Số phải lớn hơn 0
	}
	while (num % 5 == 0) {
		num /= 5;
	}
	return num == 1;  // Nếu sau khi chia liên tục, còn lại 1 thì là lũy thừa của 5
}

// Hàm tìm giá trị lớn nhất có dạng 5^k trong mảng
int findMaxPowerOfFive(int arr[], int N) {
	int maxValue = 0;  // Giá trị mặc định nếu không tìm thấy

	for (int i = 0; i < N; ++i) {
		if (isPowerOfFive(arr[i]) && arr[i] > maxValue) {
			maxValue = arr[i];  // Cập nhật giá trị lớn nhất nếu thỏa mãn
		}
	}

	return maxValue;  // Trả về giá trị lớn nhất tìm được, hoặc 0 nếu không có
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm giá trị lớn nhất có dạng 5^k trong mảng
	int result = findMaxPowerOfFive(arr, N);

	// In kết quả
	if (result == 0) {
		cout << "Không có giá trị nào có dạng 5^k trong mảng." << endl;
	}
	else {
		cout << "Giá trị lớn nhất có dạng 5^k trong mảng là: " << result << endl;
	}

	return 0;
}

//Bài 14: Cho mảng 1 chiều các số nguyên. Hãy viết hàm tìm số chẵn nhỏ nhất lớn hơn mọi
//giá trị có trong mảng
#include <iostream>
#include <climits> // Để sử dụng INT_MIN cho giá trị nhỏ nhất

using namespace std;

// Hàm tìm số chẵn nhỏ nhất lớn hơn mọi giá trị trong mảng
int findSmallestEvenGreaterThanMax(int arr[], int N) {
	// Nếu mảng rỗng, trả về -1
	if (N == 0) return -1;

	// Tìm giá trị lớn nhất trong mảng
	int maxValue = INT_MIN;
	for (int i = 0; i < N; ++i) {
		if (arr[i] > maxValue) {
			maxValue = arr[i];
		}
	}

	// Nếu maxValue là chẵn, trả về maxValue + 2
	if (maxValue % 2 == 0) {
		return maxValue + 2;
	}
	else {
		// Nếu maxValue là lẻ, trả về maxValue + 1 (số chẵn gần nhất lớn hơn maxValue)
		return maxValue + 1;
	}
}

int main() {
	int N;

	// Nhập số lượng phần tử N
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	// Mảng
	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm số chẵn nhỏ nhất lớn hơn mọi giá trị trong mảng
	int result = findSmallestEvenGreaterThanMax(arr, N);

	// In kết quả
	cout << "Số chẵn nhỏ nhất lớn hơn mọi giá trị trong mảng là: " << result << endl;

	return 0;
}

//Bài 15: Cho mảng 1 chiều các số nguyên. Hãy viết hàm tìm số nguyên tố nhỏ nhất lớn hơn
//mọi giá trị có trong mảng
#include <iostream>
#include <cmath> // Để sử dụng hàm sqrt() tính căn bậc hai

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false; // Số nguyên tố phải lớn hơn 1
	if (n == 2) return true; // 2 là số nguyên tố
	if (n % 2 == 0) return false; // Số chẵn lớn hơn 2 không phải là nguyên tố

	// Kiểm tra các số lẻ từ 3 đến căn bậc 2 của n
	for (int i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false; // Nếu n chia hết cho i, n không phải là nguyên tố
	}
	return true; // Nếu không chia hết cho bất kỳ số nào thì n là nguyên tố
}

// Hàm tìm số nguyên tố nhỏ nhất lớn hơn mọi giá trị trong mảng
int findSmallestPrimeGreaterThanMax(int arr[], int N) {
	if (N == 0) return -1; // Nếu mảng rỗng, trả về -1

	// Tìm giá trị lớn nhất trong mảng
	int maxValue = arr[0];
	for (int i = 1; i < N; ++i) {
		if (arr[i] > maxValue) {
			maxValue = arr[i];
		}
	}

	// Tìm số nguyên tố nhỏ nhất lớn hơn maxValue
	int candidate = maxValue + 1;
	while (!isPrime(candidate)) {
		candidate++;
	}

	return candidate;
}

int main() {
	int N;

	// Nhập số lượng phần tử của mảng
	cout << "Nhập số lượng phần tử N: ";
	cin >> N;

	// Mảng
	int arr[N];

	// Nhập các phần tử của mảng
	cout << "Nhập các phần tử của mảng:" << endl;
	for (int i = 0; i < N; ++i) {
		cout << "Nhập phần tử thứ " << i + 1 << ": ";
		cin >> arr[i];
	}

	// Tìm số nguyên tố nhỏ nhất lớn hơn mọi giá trị trong mảng
	int result = findSmallestPrimeGreaterThanMax(arr, N);

	// In kết quả
	cout << "Số nguyên tố nhỏ nhất lớn hơn mọi giá trị trong mảng là: " << result << endl;

	return 0;
}

//Bài 1: Viết chương trình nhập vào ngày tháng năm dạng Mỹ (MM/DD/YY), đổi sang dạng
//ngày tháng năm của Việt Nam(DD / MM / YY).
#include <iostream>
#include <iomanip> // Để sử dụng setfill và setw cho định dạng đầu ra

using namespace std;

int main() {
	int month, day, year;

	// Nhập ngày tháng năm theo định dạng Mỹ (MM/DD/YY)
	cout << "Nhập ngày tháng năm theo định dạng MM/DD/YY: ";
	scanf("%d/%d/%d", &month, &day, &year);

	// In ra kết quả theo định dạng Việt Nam (DD/MM/YY)
	cout << "Ngày tháng năm theo định dạng Việt Nam (DD/MM/YY): ";
	printf("%02d/%02d/%02d\n", day, month, year);

	return 0;
}

//Bài 2: Viết chương trình nhập vào một chuỗi ký tự. Thống kê ký tự ‘a’ xuất hiện trong xâu
//trên.
#include <iostream>
#include <string> // Thư viện string để làm việc với chuỗi ký tự

using namespace std;

int main() {
	string str;  // Khai báo biến chuỗi

	// Nhập chuỗi ký tự từ bàn phím
	cout << "Nhập một chuỗi ký tự: ";
	getline(cin, str);

	// Biến đếm số lần ký tự 'a' xuất hiện
	int count = 0;

	// Duyệt qua từng ký tự trong chuỗi
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == 'a') {
			count++; // Nếu ký tự là 'a', tăng biến đếm
		}
	}

	// In kết quả
	cout << "Số lần ký tự 'a' xuất hiện trong chuỗi: " << count << endl;

	return 0;
}

//Bài 3: Viết chương trình bỏ ký tự ‘a’ trong 1 chuỗi.
#include <iostream>
#include <string>  // Thư viện string để làm việc với chuỗi

using namespace std;

int main() {
	string str;  // Khai báo biến chuỗi

	// Nhập chuỗi ký tự từ bàn phím
	cout << "Nhập một chuỗi ký tự: ";
	getline(cin, str);

	// Duyệt qua từng ký tự trong chuỗi và loại bỏ ký tự 'a'
	string result = "";  // Khởi tạo chuỗi kết quả
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] != 'a') {
			result += str[i];  // Nếu không phải 'a', thêm vào chuỗi kết quả
		}
	}

	// In chuỗi kết quả sau khi bỏ ký tự 'a'
	cout << "Chuỗi sau khi bỏ ký tự 'a': " << result << endl;

	return 0;
}

//Bài 4: Viết chương trình nhập vào họ tên của học viên và tách họ, tên đệm và tên ra. Hiển
//thị chúng trên mỗi dòng riêng biệt.
#include <iostream>
#include <sstream>  // Thư viện sstream để tách chuỗi theo khoảng trắng
#include <string>   // Thư viện string để làm việc với chuỗi

using namespace std;

int main() {
	string fullName;  // Khai báo chuỗi để lưu họ tên đầy đủ

	// Nhập họ tên của học viên
	cout << "Nhập họ tên của học viên: ";
	getline(cin, fullName);

	// Sử dụng stringstream để tách chuỗi
	stringstream ss(fullName);
	string firstName, middleName, lastName;

	// Tách họ, tên đệm và tên
	ss >> lastName;  // Đọc họ
	ss >> middleName; // Đọc tên đệm (nếu có)
	ss >> firstName;  // Đọc tên

	// In ra kết quả
	cout << "Họ: " << lastName << endl;
	cout << "Tên đệm: " << (middleName.empty() ? "Không có" : middleName) << endl;
	cout << "Tên: " << firstName << endl;

	return 0;
}

//Bài 5: Viết chương trình nhập vào tên của không quá 10 học sinh, sắp xếp và in ra theo thứ
//tự abc theo bảng chữ cái.
#include <iostream>
#include <string>   // Thư viện string để làm việc với chuỗi
#include <algorithm> // Thư viện algorithm để sử dụng hàm sort

using namespace std;

int main() {
	int n; // Số lượng học sinh (không quá 10)

	// Nhập số lượng học sinh
	cout << "Nhập số lượng học sinh (tối đa 10): ";
	cin >> n;

	// Kiểm tra nếu n vượt quá 10
	if (n > 10) {
		cout << "Số học sinh không được vượt quá 10!" << endl;
		return 1;  // Kết thúc chương trình nếu số học sinh không hợp lệ
	}

	cin.ignore(); // Xóa bộ đệm sau khi nhập n (để đọc chuỗi tiếp theo)

	string names[10];  // Mảng để lưu tên học sinh

	// Nhập tên học sinh
	cout << "Nhập tên của " << n << " học sinh:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << "Tên học sinh " << i + 1 << ": ";
		getline(cin, names[i]);
	}

	// Sắp xếp tên học sinh theo thứ tự abc
	sort(names, names + n);

	// In danh sách tên học sinh sau khi sắp xếp
	cout << "\nDanh sách học sinh đã sắp xếp theo thứ tự abc:" << endl;
	for (int i = 0; i < n; ++i) {
		cout << names[i] << endl;
	}

	return 0;
}

//Bài 6: Viết chương trình nhập vào 1 chuỗi và đảo ngược chuỗi đó.
#include <iostream>
#include <string> // Thư viện string để làm việc với chuỗi

using namespace std;

int main() {
	string str; // Chuỗi nhập vào

	// Nhập chuỗi từ bàn phím
	cout << "Nhập vào một chuỗi: ";
	getline(cin, str); // Dùng getline để nhập chuỗi có chứa khoảng trắng

	// Đảo ngược chuỗi
	int left = 0, right = str.length() - 1;
	while (left < right) {
		swap(str[left], str[right]); // Đổi chỗ các ký tự ở vị trí left và right
		left++;
		right--;
	}

	// In chuỗi đã đảo ngược
	cout << "Chuỗi sau khi đảo ngược: " << str << endl;

	return 0;
}

//Bài 7: Viết chương trình nhập vào một chuỗi từ bàn phím. Đếm số ký tự, số từ trong chuỗi
//đó.
#include <iostream>
#include <string> // Thư viện string để làm việc với chuỗi
#include <sstream> // Thư viện stringstream để xử lý chuỗi

using namespace std;

int main() {
	string str; // Chuỗi nhập vào

	// Nhập chuỗi từ bàn phím
	cout << "Nhập vào một chuỗi: ";
	getline(cin, str); // Dùng getline để nhập chuỗi có chứa khoảng trắng

	// Đếm số ký tự
	int numChars = str.length();

	// Đếm số từ
	int numWords = 0;
	stringstream ss(str);
	string word;
	while (ss >> word) {
		numWords++;
	}

	// In kết quả
	cout << "Số ký tự trong chuỗi: " << numChars << endl;
	cout << "Số từ trong chuỗi: " << numWords << endl;

	return 0;
}

//Bài 8: Viết chương trình tìm từ dài nhất trong một chuỗi.
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string str; // Chuỗi nhập vào

	// Nhập chuỗi từ bàn phím
	cout << "Nhập vào một chuỗi: ";
	getline(cin, str); // Dùng getline để nhập chuỗi có chứa khoảng trắng

	stringstream ss(str);
	string word;
	string longestWord;
	int maxLength = 0;

	// Tìm từ dài nhất
	while (ss >> word) {
		if (word.length() > maxLength) {
			maxLength = word.length();
			longestWord = word;
		}
	}

	// In từ dài nhất
	if (maxLength > 0) {
		cout << "Từ dài nhất trong chuỗi là: " << longestWord << " với độ dài: " << maxLength << endl;
	}
	else {
		cout << "Không có từ nào trong chuỗi." << endl;
	}

	return 0;
}

//Bài 9: Viết chương trình giải hệ phương trình bậc nhất.
#include <iostream>
#include <iomanip>  // để sử dụng setprecision

using namespace std;

void solveLinearSystem(double a1, double b1, double c1, double a2, double b2, double c2) {
	// Tính định thức của ma trận hệ phương trình
	double det = a1 * b2 - a2 * b1;

	if (det == 0) {
		// Nếu định thức bằng 0 thì hệ phương trình vô nghiệm hoặc vô số nghiệm
		if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) {
			cout << "Hệ phương trình vô số nghiệm!" << endl;
		}
		else {
			cout << "Hệ phương trình vô nghiệm!" << endl;
		}
	}
	else {
		// Tính nghiệm của hệ phương trình
		double x = (c1 * b2 - c2 * b1) / det;
		double y = (a1 * c2 - a2 * c1) / det;

		cout << "Nghiệm của hệ phương trình là: " << endl;
		cout << "x = " << fixed << setprecision(2) << x << endl;
		cout << "y = " << fixed << setprecision(2) << y << endl;
	}
}

int main() {
	double a1, b1, c1, a2, b2, c2;

	// Nhập các hệ số của hệ phương trình
	cout << "Nhập các hệ số của hệ phương trình: " << endl;
	cout << "a1, b1, c1 (a1 * x + b1 * y = c1): ";
	cin >> a1 >> b1 >> c1;
	cout << "a2, b2, c2 (a2 * x + b2 * y = c2): ";
	cin >> a2 >> b2 >> c2;

	// Giải hệ phương trình
	solveLinearSystem(a1, b1, c1, a2, b2, c2);

	return 0;
}

//Bài 10: Viết chương trình in ra bảng cửu chương.
#include <iostream>
#include <iomanip>  // để căn chỉnh bảng

using namespace std;

int main() {
	// In tiêu đề của bảng cửu chương
	cout << "BANG CUU CHUONG" << endl;

	// Dùng 2 vòng lặp để in bảng cửu chương từ 1 đến 9
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			// In kết quả phép nhân i * j và căn chỉnh cho dễ đọc
			cout << setw(2) << i * j << " ";
		}
		cout << endl;  // Xuống dòng sau mỗi hàng
	}

	return 0;
}
