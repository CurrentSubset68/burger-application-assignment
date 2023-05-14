#include <iostream>
using namespace std;

const int arraysize = 5;

void rating1()
{ // executes when called
    int rating;
    cout << "rate the film out of 5 stars" << endl;
    while (!(cin >> rating))
    { // repeats the loop if the input is invallid
        cout << "enter again" << endl;
        cin >> rating;
        cin.clear();
        cin.ignore(80, '\n');
    }
    if (rating == 5)
    {
        cout << "Amazing" << endl;
    }
    if (rating == 4)
    {
        cout << "sounds great" << endl; // responds to the rating given
    }
    if (rating == 3)
    {
        cout << "sounds ok then" << endl;
    }
    if (rating < 3)
    {
        cout << "sounds rubbish" << endl;
    }
}

int main()
{
    string moviearray[arraysize] = {"(t)opgun: maverick", "(s)tar wars: the last jedi", "(m)inions: rise of gru"}; // declares array
    char choice;
    int rating = 0;
    do
    {
        cout << "rate a film!" << endl;
        cout << endl;
        for (int i = 0; i < arraysize; i++)
        {
            cout << moviearray[i] << endl; // outputs the contents of the array
        }
        cin >> choice;
        choice = tolower(choice); // allows for capitalisations to work in input

        if (choice == 't')
        {
            rating1();
        }
        if (choice == 's')
        { // triggers the function on a correct film entry
            rating1();
        }
        if (choice == 'm')
        {
            rating1();
        }
    } while (choice != 't' && choice != 's' && choice != 'm'); // repeats the loop if the input was not valid
}