#include <iostream>
using namespace std;

int Total_number_of_days_spent_on_trip()
{
    int total_number_of_days_spent_on_trip;
    cout << "Enter the total number of days spent on the trip: ";
    while (1)
    {
        cin >> total_number_of_days_spent_on_trip;
        if (total_number_of_days_spent_on_trip >= 1)
        {
            break;
        }
        cout << "The total number of days spent on the trip cannot be less than 1\nRe-enter the total number of days spent on the trip: ";
    }
    return total_number_of_days_spent_on_trip;
}

float Time_of_departure_first_day()
{
    int hours;
    int minutes;

    cout << "Enter the time of departure on the first day of the trip: ";
    while (1)
    {
        cout << "Enter hours (0-23): ";
        cin >> hours;
        cout << "Enter minutes (0-59): ";
        cin >> minutes;
        if (hours > 0 && hours < 23 && minutes > 0 && minutes < 59)
        {
            break;
        }
        cout << "Invalid time of departure on the first day of the trip\nRe-enter the time of departure on the first day of the trip: ";
    }

    float time_of_departure_first_day = hours + minutes / 60.0;

    return time_of_departure_first_day;
}

float Time_of_arrival_home_last_day()
{
    int hours;
    int minutes;

    cout << "Enter the time of arrival back home on the last day of the trip: ";
    while (1)
    {
        cout << "Enter hours (0-23): ";
        cin >> hours;
        cout << "Enter minutes (0-59): ";
        cin >> minutes;
        if (hours > 0 && hours < 23 && minutes > 0 && minutes < 59)
        {
            break;
        }
        cout << "Invalid time of arrival back home on the last day of the trip\nRe-enter the time of arrival back home on the last day of the trip: ";
    }

    float time_of_arrival_home_last_day = hours + minutes / 60.0;

    return time_of_arrival_home_last_day;
}

float Round_trip_airfare()
{
    float company_round_trip_airfare;
    cout << "Enter the amount of any round-trip airfare: ";
    while (1)
    {
        cin >> company_round_trip_airfare;
        if (company_round_trip_airfare >= 0)
        {
            break;
        }
        cout << "The amount of any round-trip airfare cannot be less than 0\nRe-enter the amount of any round-trip airfare: ";
    }
    return company_round_trip_airfare;
}

float Car_rentals()
{
    float company_car_rentals;
    cout << "Enter the amount of any car rentals: ";
    while (1)
    {
        cin >> company_car_rentals;
        if (company_car_rentals >= 0)
        {
            break;
        }
        cout << "The amount of any car rentals cannot be less than 0\nRe-enter the amount of any car rentals: ";
    }
    return company_car_rentals;
}

float Vehicle_expenses()
{
    float miles_driven = 0;
    cout << "Is a private vehecle used: ";
    while (1)
    {
        string choice;
        cin >> choice;
        if (choice == "Yes" || choice == "yes")
        {
            cout << "Enter the miles driven: ";
            while (1)
            {
                cin >> miles_driven;
                if (miles_driven >= 0)
                {
                    break;
                }
                cout << "The miles driven cannot be less than 0\nRe-enter the miles driven: ";
            }
            break;
        }
        else if (choice == "No" || choice == "no")
        {
            return 0;
            break;
        }
        cout << "Choice must be yes or no\nIs a private vehecle used: ";
    }
    return miles_driven * 0.27;
}

float Total_parking_fees()
{
    float total_parking_fees;
    cout << "Enter the total parking fees: ";
    while (1)
    {
        cin >> total_parking_fees;
        if (total_parking_fees >= 0)
        {
            break;
        }
        cout << "The total parking fees cannot be less than 0\nRe-enter the total parking fees: ";
    }
    return total_parking_fees;
}

void Parking_fees(float &company_parking_fees, float &personal_cover_parking_fee)
{
    float total_parking_fees = Total_parking_fees();

    if (company_parking_fees > 6)
    {
        personal_cover_parking_fee = company_parking_fees - 6;
        company_parking_fees = 6;
    }
    else
    {
        company_parking_fees = total_parking_fees;
    }
}

float Total_taxi_fees()
{
    float total_taxi_fees;
    cout << "Is a taxi used: ";
    while (1)
    {
        string choice;
        cin >> choice;
        if (choice == "Yes" || choice == "yes")
        {
            cout << "Enter the total taxi fees: ";
            while (1)
            {
                cin >> total_taxi_fees;
                if (total_taxi_fees >= 0)
                {
                    break;
                }
                cout << "The total taxi fees cannot be less than 0\nRe-enter the total taxi fees: ";
            }
        }
        else if (choice == "No" || choice == "no")
        {
            break;
        }
        cout << "Choice must be yes or no\nIs a taxi used: ";
    }
    return total_taxi_fees;
}

void Taxi_fees(float &company_taxi_fees, float &personal_cover_taxi_fee)
{
    float total_taxi_fees = Total_taxi_fees();
    if (company_taxi_fees > 10)
    {
        personal_cover_taxi_fee = company_taxi_fees - 10;
        company_taxi_fees = 10;
    }
    else
    {
        company_taxi_fees = total_taxi_fees;
    }
}

float Seminar_registration_fees()
{
    float seminar_registration_fees;
    cout << "Enter the conference or seminar registration fees: ";
    while (1)
    {
        cin >> seminar_registration_fees;
        if (seminar_registration_fees >= 0)
        {
            break;
        }
        cout << "The conference or seminar registration fees cannot be less than 0\nRe-enter the conference or seminar registration fees: ";
    }
    return seminar_registration_fees;
}

float Total_hotel_expense()
{
    float total_hotel_expense;
    cout << "Enter the total hotel expense: ";
    while (1)
    {
        cin >> total_hotel_expense;
        if (total_hotel_expense >= 0)
        {
            break;
        }
        cout << "The total hotel expense cannot be less than 0\nRe-enter the total hotel expense: ";
    }
    return total_hotel_expense;
}

void Hotel_expense(float &company_hotel_expenses, float &personal_cover_hotel_expenses)
{

    float total_hotel_expenses = Total_hotel_expense();
    if (total_hotel_expenses > 90)
    {
        personal_cover_hotel_expenses = total_hotel_expenses - company_hotel_expenses;
        company_hotel_expenses = 90;
    }
    else
    {
        company_hotel_expenses = total_hotel_expenses;
    }
}

void getMealExpenses(int total_number_of_days_spent_on_trip, float time_of_departure_first_day, float time_of_arrival_home_last_day, float &total_meal, float &company_meal)
{
    total_meal = 0;
    company_meal = 0;

    int breakfasts = 0;
    int lunches = 0;
    int dinners = 0;

    if (time_of_departure_first_day < 7)
        breakfasts++;
    if (time_of_departure_first_day < 12)
        lunches++;
    if (time_of_departure_first_day < 18)
        dinners++;

    if (total_number_of_days_spent_on_trip > 2)
    {
        breakfasts += total_number_of_days_spent_on_trip - 2;
        lunches += total_number_of_days_spent_on_trip - 2;
        dinners += total_number_of_days_spent_on_trip - 2;
    }

    if (time_of_arrival_home_last_day > 8)
        breakfasts++;
    if (time_of_arrival_home_last_day > 13)
        lunches++;
    if (time_of_arrival_home_last_day > 19)
        dinners++;

    float amount;

    for (int i = 0; i < breakfasts; i++)
    {
        cout << "Enter cost for breakfast #" << i + 1 << ": ";
        cin >> amount;
        total_meal += amount;
        company_meal += 9;
    }

    for (int i = 0; i < lunches; i++)
    {
        cout << "Enter cost for lunch #" << i + 1 << ": ";
        cin >> amount;
        total_meal += amount;
        company_meal += 12;
    }

    for (int i = 0; i < dinners; i++)
    {
        cout << "Enter cost for dinner #" << i + 1 << ": ";
        cin >> amount;
        total_meal += amount;
        company_meal += 16;
    }
}

int main(int argc, char const *argv[])
{
    int total_number_of_days_spent_on_trip = Total_number_of_days_spent_on_trip();
    float time_of_departure_first_day = Time_of_departure_first_day(), time_of_arrival_home_last_day = Time_of_arrival_home_last_day(), company_round_trip_airfare = Round_trip_airfare(), company_car_rentals = Car_rentals(), company_vehicle_expenses = Vehicle_expenses(), company_parking_fees, personal_cover_parking_fee = 0, company_taxi_fees, personal_cover_taxi_fee = 0, seminar_registration_fees = Seminar_registration_fees(), company_hotel_expenses, personal_cover_hotel_expenses = 0, total_meal, company_meal, total_expenses, total_allowable_expenses, total_personally_cover_expenses, saved, total_allowable;

    Parking_fees(company_parking_fees, personal_cover_parking_fee);
    Taxi_fees(company_taxi_fees, personal_cover_taxi_fee);
    Hotel_expense(company_hotel_expenses, personal_cover_hotel_expenses);
    getMealExpenses(total_number_of_days_spent_on_trip, time_of_departure_first_day, time_of_arrival_home_last_day, total_meal, company_meal);

    total_allowable = company_round_trip_airfare + company_car_rentals + company_vehicle_expenses + (6 * total_number_of_days_spent_on_trip) + (10 * company_taxi_fees) + seminar_registration_fees + (90 * total_number_of_days_spent_on_trip) + company_meal;
    total_allowable_expenses = company_round_trip_airfare + company_car_rentals + company_vehicle_expenses + company_parking_fees + company_taxi_fees + seminar_registration_fees + company_hotel_expenses + company_meal;
    total_personally_cover_expenses = personal_cover_parking_fee + personal_cover_taxi_fee + personal_cover_hotel_expenses + (total_meal - company_meal);

    if (total_allowable_expenses < total_allowable)
    {
        saved = total_allowable - total_allowable_expenses;
    }

    total_expenses = total_allowable_expenses + total_personally_cover_expenses;

    cout << "Total expenses incurred by the businessperson: " << total_expenses << endl
         << "Total allowable expenses for the trip: " << total_allowable_expenses << endl
         << "Excess that must be reim-bursed by the businessperson: " << total_personally_cover_expenses << endl
         << "Amount saved by the businessperson: " << saved;
    return 0;
}
