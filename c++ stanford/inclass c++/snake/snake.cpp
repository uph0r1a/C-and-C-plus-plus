#include <iostream>
#pragma GCC diagnostic ignored "-Wunused-result"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
using namespace std;

static termios g_oldTerm;

static void enableRawMode()
{
    termios t;
    tcgetattr(STDIN_FILENO, &g_oldTerm);
    t = g_oldTerm;
    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 0;
    t.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

static void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &g_oldTerm);
}

static bool kbhit()
{
    int bytes = 0;
    ioctl(STDIN_FILENO, FIONREAD, &bytes);
    return bytes > 0;
}

static int readKey()
{
    char c = 0;
    if (read(STDIN_FILENO, &c, 1) <= 0)
        return 0;
    if (c == 27)
    {
        char seq[2] = {};
        (void)read(STDIN_FILENO, &seq[0], 1);
        (void)read(STDIN_FILENO, &seq[1], 1);
        if (seq[0] == '[')
        {
            switch (seq[1])
            {
            case 'A':
                return 'U';
            case 'B':
                return 'D';
            case 'C':
                return 'R';
            case 'D':
                return 'L';
            }
        }
        return 27;
    }
    return c;
}

static const int BORDER_W = 50;
static const int BORDER_H = 24;
static const int FRAME_US = 120'000;

class Snake
{
    struct Point
    {
        int x, y;
    };

    string name;
    int score;
    int dir;
    Point head;
    Point food;
    vector<Point> tail;
    bool alive;

    void spawnFood()
    {
        do
        {
            food.x = 1 + rand() % (BORDER_W - 2);
            food.y = 1 + rand() % (BORDER_H - 2);
        } while (isSnakeAt(food.x, food.y));
    }

    bool isSnakeAt(int x, int y) const
    {
        if (head.x == x && head.y == y)
            return true;
        for (const auto &s : tail)
            if (s.x == x && s.y == y)
                return true;
        return false;
    }

public:
    Snake(const string &playerName)
        : name(playerName),
          score(0),
          dir('R'),
          alive(true)
    {
        head = {BORDER_W / 2, BORDER_H / 2};
        srand(static_cast<unsigned>(time(nullptr)));
        spawnFood();
    }

    void setDirection(int key)
    {
        if (key == 'U' && dir != 'D')
            dir = 'U';
        if (key == 'D' && dir != 'U')
            dir = 'D';
        if (key == 'L' && dir != 'R')
            dir = 'L';
        if (key == 'R' && dir != 'L')
            dir = 'R';
    }

    void update()
    {
        if (!alive)
            return;

        if (!tail.empty())
        {
            for (int i = (int)tail.size() - 1; i > 0; i--)
                tail[i] = tail[i - 1];
            tail[0] = head;
        }

        if (dir == 'U')
            head.y--;
        else if (dir == 'D')
            head.y++;
        else if (dir == 'L')
            head.x--;
        else if (dir == 'R')
            head.x++;

        if (head.x <= 0 || head.x >= BORDER_W - 1 || head.y <= 0 || head.y >= BORDER_H - 1)
        {
            alive = false;
            return;
        }

        for (const auto &s : tail)
            if (s.x == head.x && s.y == head.y)
            {
                alive = false;
                return;
            }

        if (head.x == food.x && head.y == food.y)
        {
            score += 5;
            tail.push_back(tail.empty() ? head : tail.back());
            spawnFood();
        }
    }

    void render() const
    {
        cout << "\033[H";

        cout << "  SNAKE GAME   |  Player: " << name << "   |  Score: " << score << "   |  (E=Exit)\033[K\n\n";

        for (int row = 0; row < BORDER_H; row++)
        {
            cout << "  ";
            for (int col = 0; col < BORDER_W; col++)
            {
                bool border = (row == 0 || row == BORDER_H - 1 || col == 0 || col == BORDER_W - 1);
                if (border)
                {
                    cout << '#';
                }
                else if (col == head.x && row == head.y)
                {
                    cout << '@';
                }
                else if (col == food.x && row == food.y)
                {
                    cout << '*';
                }
                else
                {
                    bool isTail = false;
                    for (const auto &s : tail)
                        if (s.x == col && s.y == row)
                        {
                            isTail = true;
                            break;
                        }
                    cout << (isTail ? 'o' : ' ');
                }
            }
            cout << "\033[K\n";
        }
        cout.flush();
    }

    bool isAlive() const
    {
        return alive;
    }

    int getScore() const
    {
        return score;
    }
};

int main(int argc, char const *argv[])
{
    system("clear");

    write(STDOUT_FILENO, "\033[2J\033[H", 7);
    cout << "╔════════════════════════╗\n"
         << "║       SNAKE GAME       ║\n"
         << "╠════════════════════════╣\n"
         << "║  Control: arrow key    ║\n"
         << "║  Exit: E               ║\n"
         << "╚════════════════════════╝\n\n";

    cout << "Enter player name: ";
    string name;
    cin >> name;
    write(STDOUT_FILENO, "\033[2J\033[H", 7);

    enableRawMode();

    system("clear");

    Snake game(name);
    game.render();

    while (game.isAlive())
    {
        while (kbhit())
        {
            int k = readKey();
            if (k == 'e' || k == 'E' || k == 27)
            {
                disableRawMode();

                system("clear");
                write(STDOUT_FILENO, "\033[2J\033[H", 7);
                cout << "\nThank you for playing! Score: " << game.getScore() << "\n";
                return 0;
            }
            game.setDirection(k);
        }

        game.update();
        game.render();
        usleep(FRAME_US);
    }

    disableRawMode();

    system("clear");
    write(STDOUT_FILENO, "\033[2J\033[H", 7);
    cout << "\n  *** GAME OVER ***\n"
         << "  Player: " << name << "\n"
         << "  Score: " << game.getScore() << "\n\n";
    return 0;
}