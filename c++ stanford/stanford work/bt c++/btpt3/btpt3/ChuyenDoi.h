#pragma once
#include <iostream>
#include <string>
using namespace std;

class ChuyenDoi {
public:
	static int nhiPhanSangThapPhan(string nhiPhan) {
		int thapPhan = 0;
		for (char bit : nhiPhan) {
			thapPhan = thapPhan * 2 + (bit - '0');
		}
		return thapPhan;
	}
};