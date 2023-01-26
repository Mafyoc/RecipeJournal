#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
using namespace std;

int main() {

	string loadOrCreate;
	string recipeName;
	bool loopBreak;

	cout << "Enter 'create' to add a new recipe. Enter 'search' to load an existing recipe." << endl;
	cin >> loadOrCreate;

	if (loadOrCreate == "create"){
		cout << "Please enter the name of your recipe." << endl;
		cin >> recipeName;
		Recipe recipeName;

		string currentIngredient;
		string currentAmount;
		string isLastIngredient;
		while (loopBreak == false) {
			cout << "Please add an ingredient." << endl;
			cin >> currentIngredient;
			cout << "Please enter the amount of ingredient in grams." << endl;
			cin >> currentAmount;
			cout << "Is there another ingredient? y/n";
			cin >> isLastIngredient;

			recipeName.setIngredients() ;
			if (isLastIngredient == "n") {
				break;

			}
		}

	}

	return 0;
}