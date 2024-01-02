#include "QueueVector.h"
#include <iostream>
#include <time.h>
#include "SearchTree.h"
#include "Book.h"

using namespace std;

int main()
{//תרגיל 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

    //QueueVector<int>* q1 = new QueueVector<int>(5);
    //srand((unsigned)time(NULL));
    //int i = 5;
    //while (i > 0)
    //{
    //    i--;
    //    try
    //    {
    //        q1->enqueue(rand() % 100);//הכנסה רנדומלית...
    //        cout << "Element enqueued: "   << endl;
    //    }
    //    catch (const char* error)
    //    {
    //        cout << error << endl;
    //        break;
    //    }
    //}
    //cout << "Element dequeued: " << q1->dequeue() << endl;
    //while (!q1->isEmpty())
    //{
    //    try
    //    {
    //        cout << "Element dequeued: " << q1->dequeue() << endl;
    //    }
    //    catch (const char* error)
    //    {
    //        cout << error << endl;
    //        break;
    //    }
    //}
        //delete q1;



    //תרגיל 2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    SearchTree<Book> mylibrary;
       char c;
       cout << "enter a to add | b to remove | c to search | d to print | e to exit";
        cin >> c;
        while (c!='e')
        {
            switch (c)
            {
            case 'a':
            {
                Book* b = new Book();
                cout << " enter code (number),  writerName,and name of book ";
                cin >> *b;
                mylibrary.add(*b);
                break;
            }
            case 'b':
            {
                cout << "which book do you want to remove?" <<endl;
                Book* b=new Book();
                cin >> *b;
              if  (mylibrary.search(*b)==true)
                    mylibrary.remove(*b);
              else
                  cout << "book nat found" << endl;
                break;
            }
            case 'c':
            {
                cout << "which book do you want to find?" << endl;
                Book* b = new Book();
                cin >> *b;
                if (mylibrary.search(*b) == true)
                    cout << "book  found" << endl;

                else
                    cout << "book nat found" << endl;
                break;
            }
            case 'd':
            {
                cout << "in" << endl;
                mylibrary.inOrder(); // Call the inOrder() function to print the books in sorted order
                break;
            }
            default:
                break;
            }
            cout << "enter a to add | b to remove | c to search | d to print | e to exit";
            cin >> c;
        }
       


















    return 0;
}
