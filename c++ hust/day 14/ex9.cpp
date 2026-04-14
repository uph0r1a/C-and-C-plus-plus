#include <iostream>
#include <fstream>
#include <cctype>
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

class EncryptionFilter : public FileFilter
{
private:
    int key;

public:
    EncryptionFilter(int k) : key(k) {}

    char transform(char ch) override
    {
        return ch + key;
    }
};

class UppercaseFilter : public FileFilter
{
public:
    char transform(char ch) override
    {
        return toupper(ch);
    }
};

class CopyFilter : public FileFilter
{
public:
    char transform(char ch) override
    {
        return ch;
    }
};

int main(int argc, char const *argv[])
{
    ifstream inFile1("files/input.txt");
    ofstream outFile1("files/output1.txt");

    if (!inFile1 || !outFile1)
    {
        cout << "Error opening file for encryption.\n";
        return 1;
    }

    EncryptionFilter encFilter(3);
    encFilter.doFilter(inFile1, outFile1);

    inFile1.close();
    outFile1.close();

    ifstream inFile2("files/input.txt");
    ofstream outFile2("files/output2.txt");

    if (!inFile2 || !outFile2)
    {
        cout << "Error opening file for uppercase.\n";
        return 1;
    }

    UppercaseFilter upperFilter;
    upperFilter.doFilter(inFile2, outFile2);

    inFile2.close();
    outFile2.close();

    ifstream inFile3("files/input.txt");
    ofstream outFile3("files/output3.txt");

    if (!inFile3 || !outFile3)
    {
        cout << "Error opening file for copy.\n";
        return 1;
    }

    CopyFilter copyFilter;
    copyFilter.doFilter(inFile3, outFile3);

    inFile3.close();
    outFile3.close();

    cout << "All filtering complete.\n";
    return 0;
}
