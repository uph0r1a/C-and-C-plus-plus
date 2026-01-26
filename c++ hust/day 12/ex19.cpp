#include <iostream>
#include <string>
using namespace std;

class Question
{
public:
    Question(string q, string a1, string a2, string a3, string a4, int ca)
    {
        triviaQuestion = q;
        answer1 = a1;
        answer2 = a2;
        answer3 = a3;
        answer4 = a4;
        correctAnswer = ca;
    }

    string getQuestion() const
    {
        return triviaQuestion;
    }

    string getAnswer1() const
    {
        return answer1;
    }

    string getAnswer2() const
    {
        return answer2;
    }

    string getAnswer3() const
    {
        return answer3;
    }

    string getAnswer4() const
    {
        return answer4;
    }

    int getCorrectANswer() const
    {
        return correctAnswer;
    }

    bool checkAnswer(int a)
    {
        if (correctAnswer == a)
        {
            return true;
        }
        return false;
    }

private:
    string triviaQuestion, answer1, answer2, answer3, answer4;
    int correctAnswer;
};

int main(int argc, char const *argv[])
{
    int score1 = 0, score2 = 0, answer;
    Question question[10] = {
        Question("What planet has the most moons in our solar system?", "Jupiter", "Saturn", "Uranus", "Neptune", 2),
        Question("Which country invented paper?", "Egypt", "Greece", "China", "India", 3),
        Question("What is the smallest bone in the human body?", "Femur", "Ulna", "Stapes", "Patella", 3),
        Question("In what year did the Titanic sink?", "1905", "1912", "1918", "1923", 2),
        Question("What is the hardest natural substance on Earth?", "Quartz", "Diamond", "Obsidian", "Granite", 2),
        Question("Which language has the most native speakers worldwide?", "English", "Spanish", "Hindi", "Mandarin Chinese", 4),
        Question("What animal can't jump?", "Hippo", "Elephant", "Rhino", "Giraffe", 2),
        Question("Who painted the Mona Lisa?", "Michelangelo", "Raphael", "Leonardo da Vinci", "Van Gogh", 3),
        Question("What is the capital of New Zealand?", "Auckland", "Christchurch", "Wellington", "Hamilton", 3),
        Question("How many hearts does an octopus have?", "One", "Two", "Three", "Four", 3),
    };

    for (int i = 0; i < 10; i++)
    {
        system("cls");
        cout << question[i].getQuestion() << endl
             << "1) " << question[i].getAnswer1() << endl
             << "2) " << question[i].getAnswer2() << endl
             << "3) " << question[i].getAnswer3() << endl
             << "4) " << question[i].getAnswer4() << endl
             << "Enter your answer: ";
        while (1)
        {
            cin >> answer;
            if (answer >= 1 && answer <= 4)
            {
                break;
            }
            cout << "Incorrect answer\nRe-enter your answer: ";
        }

        if (question[i].checkAnswer(answer))
        {
            if (i % 2 == 0)
            {
                score1++;
            }
            else
            {
                score2++;
            }
        }
        else
        {
            cout << "Incorrect";
        }
        cout << "Player 1: " << score1 << endl
             << "Player 2: " << score2 << endl;
        system("pause");
    }

    system("cls");

    if (score1 > score2)
    {
        cout << "Congratulation\nPlayer 1 win";
    }
    else if (score2 > score1)
    {
        cout << "Congratulation\nPlayer 2 win";
    }
    else
    {
        cout << "Draw";
    }

    return 0;
}
