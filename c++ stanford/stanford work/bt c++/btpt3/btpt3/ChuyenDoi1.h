#pragma once
#include <iostream>
#include <string>
using namespace std;

class ChuyenDoi1 {
public:
	static string thapPhanSangNhiPhan(int n) {
		if (n == 0) return "0";

		string nhiPhan = "";
		while (n > 0) {
			nhiPhan = to_string(n % 2) + nhiPhan;
			n /= 2;
		}
		return nhiPhan;
	}

	static int nhiPhanSangThapPhan(string nhiPhan) {
		int thapPhan = 0;
		for (char bit : nhiPhan) {
			thapPhan = thapPhan * 2 + (bit - '0');
		}
		return thapPhan;
	}
};