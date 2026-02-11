#include "LinkedList.hpp"
#include <string>

int main() {
    // call the constructor
    LinkedList<string> myList;

    // add elements to the list
    myList.append("Heart");
    myList.insert(0, "Your");
    myList.insert(0, "May");

    // try replacing as an invalid operation
    try {
        myList.replace(-3, "?");
    }
    catch (string& e) {
        cerr << e << endl;
    }

    // add another element
    myList.append("Citrus");

    // try inserting as an invalid operation
    try {
        myList.insert(5, "kweh");
    }
    catch (string& e) {
        cerr << e << endl;
    }

    // remove an element
    try {
        myList.remove(3);
    }
    catch (string& e) {
        cerr << e << endl;
    }

    // display the state of the list
    cout << myList;

    // get the second element and display it
    try {
        string word = myList.getElement(2);
        cout << "Element 2: " << word << endl;
    }
    catch (string& e) {
        cerr << e << endl;
    }
    
    // create a second list using the copy constructor
    LinkedList<string> secondList = myList;

    // modify the second list and display its state
    secondList.append("Beat");
    try {
    secondList.replace(2, "Drums");
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << secondList;

    // try removing an element as an invalid operation
    try {
        secondList.remove(4);
    }
    catch (string& e) {
        cerr << e << endl;
    }

    // create a third list using the default constructor (max size of 100)
    LinkedList<string> thirdList;

    // display the state of the list, should be empty
    cout << thirdList;

    // copy the first list to the third list using assignment overload
    thirdList = myList;

    // display the length and max size, should match the first list
    cout << "thirdList length: " << thirdList.getLength() << endl;

    // add elements to the list
    thirdList.append("Be A");
    thirdList.append("Yellow");
    thirdList.append("Banana");

    // display the state of the list
    cout << thirdList;

    // try getting elements as an invalid operation
    try {
        cout << thirdList.getElement(-7) << endl;
    }
    catch (string& e) {
        cerr << e << endl;
    }
    try {
        cout << thirdList.getElement(7) << endl;
    }
    catch (string& e) {
        cerr << e << endl;
    }

    // clear out the list and verify it is now empty
    myList.clear();
    if (myList.isEmpty()) {
        cout << "myList is empty!\n";
    }

    // terminate
    return 0;
}
