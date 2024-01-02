#pragma once
#include <string>
using namespace std;
class Book
{public:
	int code;
	string writerName;
	string bookName;

	Book(int code = 0, string writerName = "", string bookName = "") : code(code), writerName(writerName), bookName(bookName){}
	friend bool  operator<(const Book b1, const Book b2);
	friend bool  operator>(const Book b1, const Book b2);
	friend bool  operator<=(const Book b1, const Book b2);
	friend bool  operator>=(const Book b1, const Book b2);
	friend bool  operator==(const Book b1, const Book b2);
	friend bool  operator!=(const Book b1, const Book b2);
	friend std::ostream& operator <<(std::ostream& x, const Book b);
	friend 	std::istream& operator>>(std::istream& lsh, Book& b);

};

