#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
#include<vector>
using namespace std;

int main() {
	Recipe recipe;
	string loadOrCreate;
	string recipeName;

	cout << "Enter 'create' to add a new recipe. Enter 'search' to load an existing recipe." << endl;
	cin >> loadOrCreate;

	if (loadOrCreate == "create"){
		cout << "Please enter the name of your recipe." << endl;
		cin >> recipeName;

		string currentIngredient;
		string currentAmount;
		string isLastIngredientAnswer;
		int numIngredients = 0;
		bool loopBreak = false;

		while(loopBreak == false) {
			vector<string> ingredients;
			vector<string> amounts;
			numIngredients += 1;
			cout << "Please add an ingredient." << endl;
			cin >> currentIngredient;
			ingredients[numIngredients - 1] = currentIngredient;
			cout << "Please enter the amount of ingredient." << endl;
			cin >> currentAmount;
			amounts[numIngredients - 1] = currentAmount;


			cout << "Is there another ingredient? y/n" << endl;
			cin >> isLastIngredientAnswer;
			if (isLastIngredientAnswer == "n") {
				loopBreak = true;
			}
			/*recipeName.setIngredients() ;
			if (isLastIngredient == "n") {
				break;

			}*/
		}

		loopBreak = false;
		int stepNum = 0;
		string currentStep;
		string isLastStepAnswer;

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

	}

	return 0;
}