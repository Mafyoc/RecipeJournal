#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
#include<vector>
using namespace std;

int main() {
	Recipe recipe;
	int loadOrCreate;
	string recipeName;
	vector<string> ingredients;
	vector<string> amounts;
	string currentIngredient;
	string currentAmount;
	string isLastIngredientAnswer;
	int numIngredients = 0;
	bool loopBreak = false;
	int stepNum = 0;
	string currentStep;
	string isLastStepAnswer;

	cout << "Enter '1' to add a new recipe. Enter '0' to load an existing recipe." << endl;
	cin >> loadOrCreate;

	switch (loadOrCreate){
	case 1: //create new recipe
		cout << "Please enter the name of your recipe." << endl;
		cin >> recipeName;

		while(loopBreak == false) {
			
			cout << "Please add an ingredient." << endl;
			cin >> currentIngredient;
			cout << "Please enter the amount of ingredient." << endl;

			ingredients[numIngredients] = currentIngredient;
			amounts[numIngredients] = currentAmount;

			cout << "Is there another ingredient? y/n" << endl;
			cin >> isLastIngredientAnswer;
			if (isLastIngredientAnswer == "n") {
				loopBreak = true;
			}
			else {
				numIngredients += 1;
			}
			/*recipe.setIngredients() ;
			if (isLastIngredient == "n") {
				break;

			}*/
		}
		//Create list of ingredients
		
		loopBreak = false;

		while (loopBreak == false)
		{
			stepNum += 1;
			cout << "Please enter the directions for step " << stepNum << " for "<< recipeName << "." << endl;
			cin >> currentStep;
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


	return 0;
	}
}