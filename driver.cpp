#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
	// Testing No.1 /////////////////////////////////////////////////////////////////////////////////
	cout << "//////////////////// Testing No.1 ////////////////////" << endl;
	LinkedList one_full, one_empty;
	one_full.insert(1, 0), one_full.insert(2, 1), one_full.insert(1, 2), one_full.insert(1, 3), one_full.insert(8, 4);

	cout << "The number of times 1 is in one_full list: " << one_full.count(1) << endl << endl;
	cout << "The number of times 5 is in one_full list: " << one_full.count(5) << endl << endl;

	cout << "The number of times 4 is in one_empty list: " << one_empty.count(4) << endl << endl;


	// Testing No.2 /////////////////////////////////////////////////////////////////////////////////
	cout << "//////////////////// Testing No.2 ////////////////////" << endl;
	LinkedList two_full, two_empty;
	two_full.insert(1, 0), two_full.insert(2, 1), two_full.insert(3, 2), two_full.insert(4, 3);

	//Testing full list
	cout << "The 2nd position in your list is: " << two_full.GetNth(2) << endl << endl;

	//Testing full list in an invalid position
	cout << "The 5th position in your list is: " << two_full.GetNth(5) << endl << endl;

	//Testing empty list
	cout << "The 3rd position in your list is: " << two_empty.GetNth(3) << endl << endl;


	// Testing No.3 /////////////////////////////////////////////////////////////////////////////////
	cout << "//////////////////// Testing No.3 ////////////////////" << endl;
	LinkedList three_full, three_empty, three_one;
	three_full.insert(1, 0), three_full.insert(2, 1), three_full.insert(3, 2), three_full.insert(4, 3);
	three_one.insert(7, 0);

	//Testing full list
	cout << "When you pop() three_full, you pop the value: " << three_full.Pop() << endl << endl;

	//Testing empty list
	cout << "When you pop() an empty list (three_empty), you return the value: " << three_empty.Pop() << endl << endl;

	//Testing a list with only one item, thus making the list empty
	cout << "When you pop() three_one, you pop the value: " << three_one.Pop() << endl << endl;


	// Testing No.4 /////////////////////////////////////////////////////////////////////////////////
	cout << "//////////////////// Testing No.4 ////////////////////" << endl;
	LinkedList foura, fourb, four_empty;
	foura.insert(1, 0), foura.insert(2, 1), foura.insert(3, 2), foura.insert(4, 3);
	fourb.insert(5, 0), fourb.insert(6, 1), fourb.insert(7, 2), fourb.insert(8, 3);

	cout << "foura before append: " << endl;
	foura.display(cout);
	foura.Append(fourb);

	cout << endl << "foura after append: " << endl;
	foura.display(cout);
	cout << endl << endl;

	//Testing an empty array
	cout << "Testing an empty array..." << endl;
	foura.Append(four_empty);
	cout << endl << endl;


	// Testing No.5 /////////////////////////////////////////////////////////////////////////////////
	LinkedList five_empty, five_one, five_full;
	five_one.insert(1, 0);
	five_full.insert(1, 0), five_full.insert(2, 1), five_full.insert(3, 2), five_full.insert(1, 3), five_full.insert(4, 4);

	//Testing one
	cout << "Testing with one item: ";
	five_one.Duplicates();
	five_one.display(cout);
	cout << endl;

	//Testing empty
	cout << "Testing empty list: ";
	five_empty.Duplicates();
	five_empty.display(cout);
	cout << endl;

	//Testing full
	cout << "Testing a full list: ";
	five_full.Duplicates();
	five_full.display(cout);
	cout << endl << endl;

	return 0;
}
