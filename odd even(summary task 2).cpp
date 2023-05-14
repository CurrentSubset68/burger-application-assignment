#include <iostream>
using namespace std;

int main()
{
    int counter;
    counter = 0;
    char choice;
    int startcounter;
    bool validation = false;
    cout << "enter a number to start from" << endl;
    while (!(cin >> startcounter))
    { // if input fails it will loop asking for input again
        cout << "enter a valid number" << endl;
        cin >> startcounter;
        cin.clear();
        cin.ignore(80, '\n');
    }
    cout << "enter a number to count up to" << endl;
    while (!(cin >> counter))
    { // if input fails it will loop asking for input again
        cout << "enter a valid number" << endl;
        cin >> counter;
        cin.clear();
        cin.ignore(80, '\n');
    }
    do
    {
        validation = false cout << "enter whether to count (e)ven or (o)dd numbers" << endl;
        cin >> choice;
        choice = tolower(choice); // makes input lowercase
        if (choice == 'o')
        { // executes if choice is odd
            for (int i = startcounter; i < counter; i++)
            { // counts between the value of startcounter and endcounter

                if (i % 2 != 0)
                {
                    cout << i << endl; // outputs the current number if odd
                }
            }
        }
        if (choice == 'e')
        { // executes if choice is even
            for (int i = startcounter; i < counter; i++)
            { // counts between the values of startcount and endcount

                if (i % 2 == 0)
                { // outputs current number if even
                    cout << i << endl;
                }
            }
        }
        if (choice != 'o' && choice != 'e')
        {
            cout << "incorrect input, please enter a valid input" << endl : // outputs an error message and sets a validation boolean if the output is not one of the inputs it was supposed to be.
             validation = true;
        }
    } while (validation == true); // loops if invalid choices are inputed.
}