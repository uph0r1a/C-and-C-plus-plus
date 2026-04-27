#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
	int soMat;
	int soChan;
	string mauLong;

public:
	Animal()
		: soMat(0),
		  soChan(0),
		  mauLong("") {}

	Animal(int soMat, int soChan, const string &mauLong)
		: soMat(soMat),
		  soChan(soChan),
		  mauLong(mauLong) {}

	virtual ~Animal() {}

	int getSoMat() const
	{
		return soMat;
	}

	int getSoChan() const
	{
		return soChan;
	}

	string getMauLong() const
	{
		return mauLong;
	}

	void setSoMat(int n)
	{
		if (n >= 0)
			soMat = n;
	}
	void setSoChan(int n)
	{
		if (n >= 0)
			soChan = n;
	}
	void setMauLong(const string &s)
	{
		mauLong = s;
	}

	virtual string TiengKeu() const
	{
		return "(khong co tieng keu)";
	}

	virtual void InThongTin() const
	{
		cout << "So mat: " << soMat << "\n";
		cout << "So chan: " << soChan << "\n";
		cout << "Mau long: " << mauLong << "\n";
		cout << "Tieng keu: " << TiengKeu() << "\n";
	}
};

class Cat : public Animal
{
private:
	string ten;

public:
	Cat()
		: Animal(2, 4, "Mau xam"),
		  ten("Vo danh") {}

	Cat(const string &ten, const string &mauLong)
		: Animal(2, 4, mauLong),
		  ten(ten) {}

	string getTen() const
	{
		return ten;
	}

	string TiengKeu() const override
	{
		return "Meo Meo~";
	}

	void InThongTin() const override
	{
		cout << "[ Meo - " << ten << " ]\n";
		Animal::InThongTin();
	}
};

class Dog : public Animal
{
private:
	string ten;

public:
	Dog()
		: Animal(2, 4, "Mau den"),
		  ten("Vo danh") {}

	Dog(const string &ten, const string &mauLong)
		: Animal(2, 4, mauLong),
		  ten(ten) {}

	string getTen() const
	{
		return ten;
	}

	string TiengKeu() const override
	{
		return "Gau Gau!";
	}

	void InThongTin() const override
	{
		cout << "[ Cho - " << ten << " ]\n";
		Animal::InThongTin();
	}
};

class Bird : public Animal
{
private:
	string ten;
	bool bietBay;

public:
	Bird()
		: Animal(2, 2, "Mau vang"),
		  ten("Vo danh"),
		  bietBay(true) {}

	Bird(const string &ten, const string &mauLong, bool bietBay)
		: Animal(2, 2, mauLong),
		  ten(ten),
		  bietBay(bietBay) {}

	string TiengKeu() const override
	{
		return "Chip Chip!";
	}

	void InThongTin() const override
	{
		cout << "[ Chim - " << ten << " ]\n";
		Animal::InThongTin();
		cout << "Biet bay: " << (bietBay ? "Co" : "Khong") << "\n";
	}
};

int main(int argc, char const *argv[])
{
	Cat tom("Tom", "Mau xam");
	Dog minu("Minu", "Mau den");
	Bird tweety("Tweety", "Mau vang", true);

	tom.InThongTin();
	cout << "\n";
	minu.InThongTin();
	cout << "\n";
	tweety.InThongTin();

	Animal *ds[] = {&tom, &minu, &tweety};
	int soLuong = sizeof(ds) / sizeof(ds[0]);

	for (int i = 0; i < soLuong; i++)
	{
		ds[i]->InThongTin();
		cout << "\n";
	}

	return 0;
}