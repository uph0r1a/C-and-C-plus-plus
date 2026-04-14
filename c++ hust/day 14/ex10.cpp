#include <iostream>
#include <fstream>
using namespace std;

class FileFilter
{
public:
    virtual char transform(char ch) = 0;

    void doFilter(ifstream &in, ofstream &out)
    {
        char ch;
        while (in.get(ch))
        {
            out.put(transform(ch));
        }
    }

    virtual ~FileFilter() {}
};

class DoubleSpaceFilter : public FileFilter
{
public:
    char transform(char ch) override
    {
        return ch;
    }

    void doFilter(ifstream &in, ofstream &out)
    {
        char ch;
        while (in.get(ch))
        {
            out.put(ch);

            if (ch == '\n')
            {
                out.put('\n');
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    ifstream inFile("files/input.txt");
    ofstream outFile("files/output4.txt");

    if (!inFile || !outFile)
    {
        cout << "Error opening file.\n";
        return 1;
    }

    DoubleSpaceFilter filter;
    filter.doFilter(inFile, outFile);

    inFile.close();
    outFile.close();

    cout << "Double spacing complete.\n";
    return 0;
}
