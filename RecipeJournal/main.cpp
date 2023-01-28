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
	string isLastIngredientAnswer;
	int numIngredients = 0;
	bool loopBreak = false;
	int stepNum = 0;
	string currentStep;
	string isLastStepAnswer;

	cout << "Enter 'new' to add a new recipe. Enter 'load' to load an existing recipe." << endl;
	cin >> loadOrCreate;
	if (loadOrCreate == "new") {
		loadOrCreateSwitch = 1;
	}
	else {
		loadOrCreateSwitch = 2;
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
				for (int i = 0; i < ingredients.size(); i++) {
					cout << ingredients[i] << " " << amounts[i] << endl;
				}
				loopBreak = true;
				cout << endl;
			}
			else {
				cout << "Please enter the amount of ingredient." << endl;
				cin >> currentAmount;
				ingredients.push_back(currentIngredient);
				amounts.push_back(currentAmount);
			}
			/*recipe.setIngredients() ;
			if (isLastIngredient == "n") {
				break;

			}*/
		}
		//Create list of ingredients and amounts
		
		loopBreak = false;

		while (loopBreak == false)
		{
			cout << "Please enter the directions for step " << stepNum + 1 << " for "<< recipeName << "." << endl;
			cout << endl;
			cin >> currentStep;
			steps.push_back(currentStep);
			
			cout << "Is there another step? y/n" << endl;
			cin >> isLastStepAnswer;
			if (isLastStepAnswer == "n") {
				loopBreak = true;
			}
		}
		//create list of directions

		break;
	case 2://Load an existing recipe
		//
		break;
	default:	
		cout << "Enter '1' to add a new recipe. Enter '0' to load an existing recipe." << endl;
		cin >> loadOrCreate;
	return 0;
	}
}