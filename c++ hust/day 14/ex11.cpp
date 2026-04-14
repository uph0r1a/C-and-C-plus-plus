#include <iostream>
using namespace std;

class GradedActivity
{
protected:
    double score;

public:
    GradedActivity(double s = 0.0)
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
        if (score > 89) return 'A';
        else if (score > 79) return 'B';
        else if (score > 69) return 'C';
        else if (score > 59) return 'D';
        else return 'F';
    }
};

class PassFailExam : public GradedActivity
{
private:
    int numQuestions;
    int numMissed;
    double pointsEach;
    double minPassing;

public:
    PassFailExam(int q, int m, double minPass)
    {
        numQuestions = q;
        numMissed = m;
        minPassing = minPass;

        pointsEach = 100.0 / numQuestions;
        score = 100.0 - (numMissed * pointsEach);
    }

    char getLetterGrade() const override
    {
        if (score >= minPassing)
            return 'P';
        else
            return 'F';
    }
};

class FinalExam : public GradedActivity
{
private:
    int numQuestions;
    int numMissed;

public:
    FinalExam(int q, int m)
    {
        numQuestions = q;
        numMissed = m;

        double pointsEach = 100.0 / numQuestions;
        score = 100.0 - (numMissed * pointsEach);
    }
};

class Essay : public GradedActivity
{
public:
    Essay(int g, int s, int l, int c)
    {
        setScore(g + s + l + c);
    }
};

class CourseGrades
{
private:
    GradedActivity* grades[4];

public:
    void setLab(GradedActivity* lab)
    {
        grades[0] = lab;
    }

    void setPassFailExam(PassFailExam* exam)
    {
        grades[1] = exam;
    }

    void setEssay(Essay* essay)
    {
        grades[2] = essay;
    }

    void setFinalExam(FinalExam* finalExam)
    {
        grades[3] = finalExam;
    }

    void print() const
    {
        const char* names[4] = {
            "Lab",
            "Pass/Fail Exam",
            "Essay",
            "Final Exam"
        };

        for (int i = 0; i < 4; i++)
        {
            cout << names[i] << ": ";
            cout << "Score = " << grades[i]->getScore();
            cout << ", Grade = " << grades[i]->getLetterGrade() << endl;
        }
    }
};

int main()
{
    GradedActivity lab(85);
    PassFailExam passFail(10, 2, 70);
    Essay essay(25, 18, 18, 25);
    FinalExam finalExam(50, 5);

    CourseGrades course;

    course.setLab(&lab);
    course.setPassFailExam(&passFail);
    course.setEssay(&essay);
    course.setFinalExam(&finalExam);

    course.print();

    return 0;
}