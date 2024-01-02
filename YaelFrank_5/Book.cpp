#include "Book.h"
#include <istream>
#include <ostream>
#include <iostream>

bool operator<(const Book b1, const Book b2)
{
	return 	b1.writerName.compare(b2.writerName)<0 ? true : (b1.bookName.compare( b2.bookName)<0 ? true : b1.code < b2.code ? true : false);
}

bool operator>(const Book b1, const Book b2)
{
	return !(b1<b2)&&!(b1==b2);
}

bool operator<=(const Book b1, const Book b2)
{
	return b1<b2||b1==b2;
}

bool operator>=(const Book b1, const Book b2)
{
	return !(b1<b2);
}

bool operator==(const Book b1, const Book b2)
{
	return 	b1.writerName.compare(b2.writerName) != 0 ? false : (b1.bookName.compare(b2.bookName)!=0 ? false : b1.code != b2.code ? false : true);
}

bool operator!=(const Book b1, const Book b2)
{
	return !(b1 == b2);
}

std::ostream& operator<<(std::ostream& lsh, const Book b)
{
	lsh  << "Book writer name is: " << b.writerName << endl << "Book name is: " << b.bookName << endl << "Book code is: " << b.code << endl<<"------------"<< endl;
	return lsh;
}


std::istream& operator>>(std::istream& lsh, Book& b)
{
	cout << " enter code (number),  writer,and name of book, ";
	lsh >> b.code >> b.writerName >> b.bookName;
	return lsh;
}
