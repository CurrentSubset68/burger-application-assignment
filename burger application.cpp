#include <iostream>
using namespace std;
// constants for the arrays in this assignment
const int burgerSize = 3;
const int toppingsSize = 6;
const int toppingDisplay = 20;
const int orderDisplay = 10;
// constants for the burger price function
const double smallPrice = 3.0;
const double mediumPrice = 5.50;
const double largePrice = 7.25;
// constants for the topping price function
const double cheesePrice = 0.80;
const double saladPrice = 0.50;
const double baconPrice = 1.0;
const double ketchupPrice = 0.30;
const double mayoPrice = 0.30;
const double extraBurgerPrice = 1.50;

string ToLower(string mystring)
{ // for each character in the string that is parsed, it makes it lower case.
	// not mine, taken from the uclan lecture presentation on functions
	string lowerString;
	for (auto c : mystring)
		lowerString += tolower(c);
	return lowerString;
}

double BurgerSelection(string functionInput)
{ // function for outputting the price of the chosen size
	double sizePrice = 0;

	if (functionInput == "small")
	{
		sizePrice += smallPrice;
	}
	else if (functionInput == "medium")
	{
		sizePrice += mediumPrice;
	}
	else if (functionInput == "large")
	{
		sizePrice += largePrice;
	}
	return sizePrice;
}

double ToppingSelection(string functionInput)
{ // function for outputting the chosen topping
	double toppingPrice = 0;
	if (functionInput == "cheese")
	{
		toppingPrice += cheesePrice;
	}
	else if (functionInput == "salad")
	{
		toppingPrice += saladPrice;
	}
	else if (functionInput == "bacon")
	{
		toppingPrice += baconPrice;
	}
	else if (functionInput == "ketchup")
	{
		toppingPrice += ketchupPrice;
	}
	else if (functionInput == "mayo")
	{
		toppingPrice += mayoPrice;
	}
	else if (functionInput == "extraburger")
	{
		toppingPrice += extraBurgerPrice;
	}
	return toppingPrice;
}

double Credits()
{ // function for validating and then outputing the chosen credits amount
	double creditsAmount = 0.0;
	cout << "enter at least 3 credits to buy" << endl;
	while (!(cin >> creditsAmount) || creditsAmount < 3.0)
	{
		cout << "invalid input, enter credit amounts again(at least 3)" << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}
	return creditsAmount;
}

bool YesNoResponse(string functionInput) /* this function only gets called after YesNoValidation,
 so both return paths are fulfilled, since the only input is "y" or "n" 
the purpose of this function is to return true or false, depending on the answer to the question.*/
{
	if (functionInput == "y")
	{
		return true;
	}
	else if (functionInput == "n")
	{
		return false;
	}
}

string YesNoValidation(string functionInput) // makes sure that any input for a y/n question will always be "y" or "n"
{
	bool yesNoLoop = false;
	do
	{
		cout << "enter y or n" << endl;
		cin >> functionInput;
		if (functionInput != "y" && functionInput != "n")
		{
			yesNoLoop = true;
		}

	} while (yesNoLoop == true);
	return functionInput;
}

string YesNoSkipValidation(string functionInput) // makes sure that any input for a y/n question will always be "y" or "n"
{
	bool yesNoLoop = false;
	do
	{
		cout << "enter y or n or s" << endl;
		cin >> functionInput;
		if (functionInput != "y" && functionInput != "n" && functionInput != "s")
		{
			yesNoLoop = true;
		}

	} while (yesNoLoop == true);
	return functionInput;
}

bool yesNoCombinaton(string functionInput) 
{
	bool functionOutput;
	functionInput = ToLower(functionInput);
	functionInput = YesNoValidation(functionInput);	// this combination of functions allows to error check y/n input
	functionOutput = YesNoResponse(functionInput);
	return functionOutput;
}

int main()
{
	double creditsAmount = 0.0;
	double currentPrice = 0.0;
	string TextInput;
	string toppingName;
	string burgerList[burgerSize] = { "small(3.0) Credits", "medium(5.50) Credits",
		"large(7.25) Credits" }; // the two arrays for the list of options

	string toppings[toppingsSize] = { "cheese(0.80) Credits", "salad(0.50) Credits", "bacon(1.0) Credits",
		"ketchup(0.30) Credits", "mayo(0.30) Credits", "extra Burger(1.50) Credits(one word)" };

	string chosenToppings[toppingDisplay] = {}; // stores toppings for the final order output
	bool continueValidation = false;
	string burgerOrderSize[orderDisplay] = {}; // stores the size for the final order output
	string creditConfirmation = " ";
	string nextOrderChoice;
	bool secondCheck = false;
	bool nextOrderFlag = false;
	bool skip = false;
	creditsAmount = Credits();
	int orderIndex = 0;
	int toppingIndex = 0;
	bool yesNoLoop = false;
	int creditcheckpointindex = 0;

	do
	{
		nextOrderFlag = false;

		do
		{
			continueValidation = false;
			cout << "Select a burger Size:" << endl;

			for (int i = 0; i < burgerSize; i++)
			{ // outputs the list of burger sizes
				cout << burgerList[i] << endl;
			}

			cin >> TextInput;
			TextInput = ToLower(TextInput);

			while (TextInput != "small" && TextInput != "medium" && TextInput != "large")
			{ // validates the size choice
				cout << "incorrect input, please enter again" << endl;
				cin >> TextInput;
				TextInput = ToLower(TextInput); // converts the size into lower case for useability
			}

			burgerOrderSize[orderIndex] = TextInput;
			currentPrice += BurgerSelection(TextInput); // calls the function to retreive the price of the chosen size.
			cout << currentPrice << endl;

			if (secondCheck == true)
			{ // checks if it is a second order

				if (currentPrice > creditsAmount)
				{ // checks if current order exceeds overall budget
					cout << "not enough funds.  add more funds and retry(y), choose another size(n) or skip(s)";
					cin >> creditConfirmation;
					creditConfirmation = ToLower(creditConfirmation);

					do
					{
						yesNoLoop = false;

						if (creditConfirmation == "y")
						{
							creditsAmount += Credits(); // adds additional credits
							continueValidation = true;	// flag for looping
						}
						else if (creditConfirmation == "s")
						{ // sets the skip flag and the loop flag
							continueValidation = true;
							skip = true;
						}
						else if (creditConfirmation == "n")
						{
							continueValidation = true; // sets the loop flag
						}
						else
						{
							creditConfirmation = YesNoSkipValidation(creditConfirmation);

							yesNoLoop = true; // loops for getting the next input
						}
					} while (yesNoLoop);
				}
			}
			else if (currentPrice > creditsAmount)
			{ // checks of current order price exceeds the current budget
				cout << "not enough funds.  add more funds and retry(y) or choose another size(n)" << endl;
				cin >> creditConfirmation;
				creditConfirmation = ToLower(creditConfirmation);

				do /* this isn't the three function solution that is implemented later on,
				   because there's some secondary flags that need to be set inside what would be StringValidation */
				{
					yesNoLoop = false;

					if (creditConfirmation == "y")
					{
						creditsAmount += Credits(); // adds credits
						continueValidation = true;

						if (secondCheck == false)
						{
							currentPrice = 0; /* resets current price so invalid order price isn't added on as well.
							Can't be put in a function because i don't always need a returned value*/
						}
					}
					else if (creditConfirmation == "n")
					{
						continueValidation = true; // loop again

						if (secondCheck == false)
						{
							currentPrice = 0; /* resets current price so invalid order price isn't added on as well.
							Can't be put in a function because i don't always need a returned value*/
						}
					}
					else
					{
						creditConfirmation = YesNoValidation(creditConfirmation);
						yesNoLoop = true; // resets to gain another input
					}
				} while (yesNoLoop);
			}
		} while (continueValidation); // loops if the looping flag is yes

		TextInput = " ";					  // resets for toppings
		continueValidation = false;			  // resets for toppings
		string continueChoice;
		if (creditcheckpointindex == 0) // executes if 
		{
			double creditCheckpoint = currentPrice; // in case the topping can't be afforded
			creditcheckpointindex++; // increments so that the value isn't overwritten at a bad point
		}
		double creditCheckpoint = currentPrice; // in case the topping can't be afforded
		bool toppingindexvalidation = true;

		do
		{
			continueValidation = false;
			continueChoice = " ";
			toppingindexvalidation = true;

			if (skip == true)
			{ // checks if it's the second and beyond order
				continueValidation = false;
			}
			else
			{
				cout << "Select a burger topping, or enter n to continue:" << endl;

				for (int i = 0; i < toppingsSize; i++)
				{ // lists toppings
					cout << toppings[i] << endl;
				}
				cin >> TextInput;

				while (TextInput != "cheese" && TextInput != "salad" && TextInput != "bacon" && TextInput != "ketchup"
					&& TextInput != "mayo" && TextInput != "extraburger" && TextInput != "n")
				{ // validates the size choice
					cout << "incorrect input, please enter a topping again:" << endl;
					for (int i = 0; i < toppingsSize; i++)
					{ // lists toppings
						cout << toppings[i] << endl;
					}
					cin >> TextInput;
					TextInput = ToLower(TextInput); // converts the size into lower case for useability
				}

				if (TextInput == "n")
				{ // if n skips toppings
					continueValidation = false; // makes sure that the flag is false by default so it doesn't loop by accedent
					toppingindexvalidation = false; // makes sure that topping index is not triggered when a topping is not being added
				}
				else
				{
					currentPrice += ToppingSelection(TextInput); // adds to toppings
					cout << currentPrice << endl;
					creditcheckpointindex = 0;

					if (currentPrice < creditsAmount)
					{ // checks if purchase is valid
						chosenToppings[toppingIndex] = TextInput;
						cout << currentPrice << endl;
						cout << "want another topping?(y/n)" << endl;
						cin >> continueChoice; 
						continueChoice = ToLower(continueChoice);

						if (continueChoice == "y")
						{
							continueValidation = true; // so you can pick another topping
						}
						else if (continueChoice == "n")
						{
							continueValidation = false; // so another topping isn't picked
						}
						else
						{
							continueValidation = yesNoCombinaton(continueChoice);
						}
					}
					else
					{
						currentPrice = creditCheckpoint; // reverts currrentprice
						cout << "not enough money. add credits and retry(y) or continue(n)";
						cin >> continueChoice;

						if (continueChoice == "y")
						{
							creditsAmount = Credits();
							continueValidation = true;
							toppingindexvalidation = false; // makes sure that topping index is not triggered when a topping is not being added
						}
						else if (continueChoice == "n") 
						{
							continueValidation = false; // flag to make sure that the topping loop is not called 
						}
						else
						{
							continueValidation = yesNoCombinaton(continueChoice);
						}

					}
				}
				if (toppingindexvalidation == true)
				{
					toppingIndex++; // indexes in the  output array
				}
				
			}
		} while (continueValidation); // loops if flag is yes

		cout << "your order is" << endl;

		for (int j = 0; j <= orderIndex; j++)
		{
			cout << burgerOrderSize[j] << endl; // lists size
		}
		for (int k = 0; k < toppingIndex; k++)
		{ // lists toppings
			cout << chosenToppings[k] << endl;
		}
		// index for each order
		/* unless i figure out how to do lists or somthing complicated with functions,
		this loop will be broken and only list all sizes and then all toppings */

		cout << "make another order?(y/n)" << endl;
		cin >> nextOrderChoice;
		nextOrderChoice = ToLower(nextOrderChoice);

		if (nextOrderChoice == "y")
		{ // repeats process if true
			nextOrderFlag = true;
			secondCheck = true; // indicates to the program that this is not the first order, so it can change accordingly
		}
		else if (nextOrderChoice == "n")
		{
			return 0; // if not then exits
		}
		else
		{
			nextOrderChoice = yesNoCombinaton(nextOrderChoice); // calls a funcion to call three seperate functions
		}

		orderIndex++; // increments so that the number of orders can be tracked

	} while (nextOrderFlag); // repeats of loop flag is true
}