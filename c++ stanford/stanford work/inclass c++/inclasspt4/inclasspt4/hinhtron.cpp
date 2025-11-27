#include "hinhtron.h"

hinhtron::hinhtron(double r)
{
	this->r = r;
}

hinhtron::hinhtron()
{

}

double hinhtron::getBanKinh()
{
	return this->r;
}

void hinhtron::setBanKinh(double r)
{
	cout << "Ham gan ban kinh hinh tron" << endl;

	if (r <= 0)
	{
		this->r = 0;
	}
	else
	{
		this->r = r;
	}
}

double hinhtron::chuvi()
{
	return 2 * this->pi * r;
}

double hinhtron::dientich()
{
	return this->pi * r * r;
}

void hinhtron::InThongTin()
{
	cout << "Cu vi hinh tron la: " << this->chuvi() << endl;
	cout << "Dien tich hinh tron la: " << this->dientich() << endl;
}