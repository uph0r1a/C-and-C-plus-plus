#include <iostream>
using namespace std;

class GradedActivity
{
protected:
    double score;

public:
    GradedActivity()
    {
        score = 0.0;
    }

    GradedActivity(double s)
    {
        score = s;
    }

    void setScore(double s)
    {
        score = s;
    }

    double getScore() const
    {
        return score;
    }

    virtual char getLetterGrade() const
    {
        char letterGrade;

        if (score > 89)
            letterGrade = 'A';
        else if (score > 79)
            letterGrade = 'B';
        else if (score > 69)
            letterGrade = 'C';
        else if (score > 59)
            letterGrade = 'D';
        else
            letterGrade = 'F';

        return letterGrade;
    }
};

class Essay : public GradedActivity
{
private:
    int grammar, spelling, correctLength, content;

public:
    Essay(int g = 0, int s = 0, int l = 0, int c = 0)
    {
        if (g <= 30 && g >= 0 && s <= 20 && s >= 0 && l <= 20 && l >= 0 && c <= 30 && c >= 0)
        {
            grammar = g;
            spelling = s;
            correctLength = l;
            content = c;

            setScore(grammar + spelling + correctLength + content);
        }
        else
        {
            cout << "Invalid score";
            exit(0);
        }
    }
};

int main(int argc, char const *argv[])
{
    int g, s, l, c;

    cout << "Enter grammar score (max 30): ";
    cin >> g;

    cout << "Enter spelling score (max 20): ";
    cin >> s;

    cout << "Enter length score (max 20): ";
    cin >> l;

    cout << "Enter content score (max 30): ";
    cin >> c;

    Essay essay(g, s, l, c);

    cout << "Total Score: " << essay.getScore() << endl;
    cout << "Letter Grade: " << essay.getLetterGrade() << endl;

    return 0;
}
