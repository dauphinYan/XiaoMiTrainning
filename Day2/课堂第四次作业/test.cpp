#include <iostream>
using namespace std;

class Book
{
private:
    string authorName;

protected:
    string bookName="namebook";

public:
    void showInfo()
    {
        cout << "Book" << endl;
    }
};

class ScienceBook : protected Book
{
public:
    void showInfo()
    {
        cout << "ScienceBook" << endl;
    }

    void getBookName()
    {
        cout<<"BookName:"<<bookName<<endl;
    }
};

class ChildBook : public Book //这里如果将pulic修改为protected或private则主函数的childBook.showInfo()会发生错误
{
public:
};

int main()
{
    Book book;
    ScienceBook scienceBook;
    ChildBook childBook;
    book.showInfo();
    scienceBook.showInfo();
    scienceBook.getBookName();
    childBook.showInfo();
    return 0;
}