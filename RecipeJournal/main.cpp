#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
#include<vector>
using namespace std;

int main() {
	Recipe recipe;
	string loadOrCreate;
	int loadOrCreateSwitch;
	string recipeName;
	vector<string> ingredients;
	vector<string> amounts;
	vector<string> steps;
	string currentIngredient;
	string currentAmount;
	bool loopBreak = false;
	string currentStep;

	cout << "Enter 'new' to add a new recipe. Enter 'load' to load an existing recipe." << endl;
	cin >> loadOrCreate;
	if (loadOrCreate == "new") {
		loadOrCreateSwitch = 1;
	}
	else if (loadOrCreate == "load") {
		loadOrCreateSwitch = 2;
	}
	else {
		loadOrCreateSwitch = 0;
	}

	switch (loadOrCreateSwitch){
	case 1: //create new recipe
		cout << "Please enter the name of your recipe." << endl;
		cin >> recipeName;

		while(loopBreak == false) {
			
			cout << "Please add an ingredient or type 'end' to continue." << endl;
			cin >> currentIngredient;
			if (currentIngredient == "end") {
				cout << endl;
				if (ingredients.size() >= 1) {
					for (int i = 0; i < ingredients.size(); i++) {
						cout << ingredients[i] << " " << amounts[i] << endl;
					}
					cout << "Are these ingredients correct?" << endl;
				}
				loopBreak = true;
				cout << endl;
			}
			else {
				cout << "Please enter the amount of " << currentIngredient <<"." << endl;
				cin >> currentAmount;
			}

			ingredients.push_back(currentIngredient);
			amounts.push_back(currentAmount);
		}
		//Create list of ingredients and amounts
		
		loopBreak = false;

		while (loopBreak == false)
		{
			cout << "Please enter the directions for step " << steps.size() + 1 << " of "<< recipeName << ". Or type 'end' to finish." << endl;
			cin >> currentStep;
			if (currentStep == "end") {
				recipe.saveRecipe(recipeName, ingredients, amounts, steps);
				loopBreak = true;
			}
			else {
				steps.push_back(currentStep);
			}
		}
		//create list of directions

		Recipe::saveRecipe(recipeName, ingredients, amounts, steps);

		break;
	case 2://Load an existing recipe
		// eventual loading code here
		break;
	default:	
		cout << "Enter 'new' to add a new recipe. Enter 'load' to load an existing recipe." << endl;
		cin >> loadOrCreate;
	return 0;
	}
}