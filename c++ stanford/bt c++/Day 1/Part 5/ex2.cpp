#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double totalFood, vatPct, tip;
    int numPeople;

    do
    {
        cout << "Tong tien an (>= 0): ";
        cin >> totalFood;
    } while (totalFood < 0);
    do
    {
        cout << "So nguoi (>= 1): ";
        cin >> numPeople;
    } while (numPeople < 1);
    do
    {
        cout << "Ti le VAT (%, 0-100): ";
        cin >> vatPct;
    } while (vatPct < 0 || vatPct > 100);
    do
    {
        cout << "Tien bo (>= 0): ";
        cin >> tip;
    } while (tip < 0);

    double vat = totalFood * vatPct / 100.0;
    double totalAfterVAT = totalFood + vat + tip;
    double perPerson = totalAfterVAT / numPeople;

    cout << fixed << setprecision(2) << "\n";
    cout << "Tong truoc VAT: " << totalFood << "\n";
    cout << "Tien VAT (" << vatPct << "%): " << vat << "\n";
    cout << "Tien bo: " << tip << "\n";
    cout << "Tong sau VAT + bo: " << totalAfterVAT << "\n";
    cout << "Moi nguoi tra: " << perPerson << "\n";

    return 0;
}
