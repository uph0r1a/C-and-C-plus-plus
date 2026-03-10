#include <iostream>
#include <string>
using namespace std;

class ParkedCar
{
private:
    string carMake, carModel, carColor, carLicenseNumber;
    int carMinutesParked;

public:
    ParkedCar(string make = "", string model = "", string color = "", string licenseNumber = "", int minutes = 0)
        : carMake(make),
          carModel(model),
          carColor(color),
          carLicenseNumber(licenseNumber),
          carMinutesParked(minutes) {}

    string getCarMake() const
    {
        return carMake;
    }

    string getCarModel() const
    {
        return carModel;
    }

    string getCarColor() const
    {
        return carColor;
    }

    string getCarLicenseNumber() const
    {
        return carLicenseNumber;
    }

    int getCarMinutesParked() const
    {
        return carMinutesParked;
    }
};

class ParkingMeter
{
private:
    int parkingMinutesPurchased;

public:
    ParkingMeter(int minutes = 0)
        : parkingMinutesPurchased(minutes) {}

    int getParkingMinutesPurchased() const
    {
        return parkingMinutesPurchased;
    }
};

class ParkingTicket
{
private:
    string carMake, carModel, carColor, carLicenseNumber;
    string officerName, officerBadge;
    int carFine;

public:
    ParkingTicket(string make = "", string model = "", string color = "", string license = "", string officer = "", string badge = "", int fine = 0)
        : carMake(make),
          carModel(model),
          carColor(color),
          carLicenseNumber(license),
          officerName(officer),
          officerBadge(badge),
          carFine(fine) {}

    string getCarMake() const
    {
        return carMake;
    }

    string getCarModel() const
    {
        return carModel;
    }

    string getCarColor() const
    {
        return carColor;
    }

    string getCarLicenseNumber() const
    {
        return carLicenseNumber;
    }

    string getOfficerName() const
    {
        return officerName;
    }

    string getOfficerBadge() const
    {
        return officerBadge;
    }

    int getCarFine() const
    {
        return carFine;
    }

    void printTicket() const
    {
        cout << "Parking Ticket Issued\n";
        cout << "Car: " << carMake << " " << carModel << endl;
        cout << "Color: " << carColor << endl;
        cout << "License: " << carLicenseNumber << endl;
        cout << "Officer: " << officerName << endl;
        cout << "Badge: " << officerBadge << endl;
        cout << "Fine: $" << carFine << endl;
    }
};

class PoliceOfficer
{
private:
    string officerName;
    string officerBadge;

public:
    PoliceOfficer(string name = "", string badge = "")
        : officerName(name), officerBadge(badge) {}

    ParkingTicket examineCar(const ParkedCar &car, const ParkingMeter &meter)
    {
        int fine = 0;

        if (car.getCarMinutesParked() > meter.getParkingMinutesPurchased())
        {
            int overtime = car.getCarMinutesParked() - meter.getParkingMinutesPurchased();

            int hours = overtime / 60;
            if (overtime % 60 > 0)
                hours++;

            fine = 25;

            if (hours > 1)
                fine += (hours - 1) * 10;
        }

        ParkingTicket ticket(car.getCarMake(), car.getCarModel(), car.getCarColor(), car.getCarLicenseNumber(), officerName, officerBadge, fine);

        return ticket;
    }
};

int main(int argc, char const *argv[])
{
    ParkedCar car("Toyota", "Camry", "White", "ABC123", 125);
    ParkingMeter meter(60);
    PoliceOfficer officer("John Smith", "4587");

    ParkingTicket ticket = officer.examineCar(car, meter);

    if (ticket.getCarFine() > 0)
    {
        ticket.printTicket();
    }
    else
    {
        cout << "No parking violation.\n";
    }

    return 0;
}