#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class MyException
{
protected:
    std::string message;

public:
    MyException(std::string msg) : message(msg) {}
    std::string what() { return message; }
};


// class DivisionByZeroException : public MyException
// {
// public:
//     DivisionByZeroException(std::string msg) : MyException(msg)
//     { message = "\033[91mDivisionByZeroException: \033[0m" + msg; }
// };


// int divide(int a, int b)
// {
//     if (b == 0) 

//     { throw DivisionByZeroException("Expression results in undefined behaviour."); }

//     return (a / b);
// }

class FileNotFoundException : public MyException
{
public:
    FileNotFoundException(std::string msg) : MyException("\033[91mFileNotFoundException: \033[0m" + msg) {}
};


class FileReader
{
public:
    void readFirstLine(std::string filename)
    {
        try
        {
            std::ifstream file(filename);
            if (!file.is_open())
            {
                throw FileNotFoundException("Unable to open file.");
            }

            std::string line;
            std::getline(file, line);
            std::cout << line << std::endl;
        }
        catch (FileNotFoundException& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
};


int main()
{

    FileReader reader;

    std::cout << "Opening file.txt..." << std::endl;
    reader.readFirstLine("assets/file.txt");

    std::cout << std::endl;

    std::cout << "Opening file-1.txt..." << std::endl;
    reader.readFirstLine("assets/file-1.txt");

    return 0;
}