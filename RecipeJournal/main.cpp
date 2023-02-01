#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
#include<vector>

#include <cstdlib>
using namespace std;

void SaveRecipeToFile(string recipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps); 
void LoadRecipeFromFile(ifstream inputFile, string recipeName, string inputRecipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps);

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
	string inputRecipeName;
	string inputRecipeData;
	ifstream inputFile;

	cout << "Enter 'new' to add a new recipe. Enter 'load' to load an existing recipe." << endl;
	getline(cin, loadOrCreate);
	cout << endl;
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

		//cin.ignore();
		cout << "Please enter the name of your recipe." << endl;
		getline(cin, recipeName);
		
		while(loopBreak == false) {
			
			cout << "Please add an ingredient or type 'end' to continue." << endl;
			getline(cin, currentIngredient);

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
				ingredients.push_back(currentIngredient);
				cout << "Please enter the amount of " << currentIngredient <<"." << endl;
				getline(cin, currentAmount);
				amounts.push_back(currentAmount);
			}

		}
		//Create list of ingredients and amounts
		
		loopBreak = false;

		while (loopBreak == false)
		{
			cout << "Please enter the directions for step " << steps.size() + 1 << " of "<< recipeName << ". Or type 'end' to finish." << endl;
			getline(cin, currentStep);
			if (currentStep == "end") {
				loopBreak = true;
			}
			else {
				steps.push_back(currentStep);
			}
		}
		//create list of directions

		SaveRecipeToFile(recipeName, ingredients, amounts, steps);


		break;
	case 2://Load an existing recipe
		// eventual loading code here
		inputFile.open("recipes/recipeNames.txt");
		while (!inputFile.eof()) {
			inputFile >> inputRecipeName;
			cout << inputRecipeName << endl;
		}
		inputFile.close();

		cout << "Please enter the name of the recipe you would like to load" << endl;
		getline(cin, recipeName);

		inputFile.open("recipes/" + recipeName + ".txt");
		while (!inputFile.eof()) {
			inputFile >> inputRecipeData;
			cout << inputRecipeData << endl;
		}
		inputFile.close();

		break;
	default:	
		cout << "Enter 'new' to add a new recipe. Enter 'load' to load an existing recipe." << endl;
		cin >> loadOrCreate;
	return 0;
	}
}

void SaveRecipeToFile(string recipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps) {
	ofstream outfile;
	outfile.open("recipes/" + recipeName + ".txt");

	for (int i = 0; i < ingredients.size(); i++) {
		outfile << ingredients[i] << " " << amounts[i] << endl;
	}

	for (int i = 0; i < steps.size(); i++) {
		outfile << steps[i] << endl;
	}

	outfile.close();

	outfile.open("recipes/recipeNames.txt", ios_base::app);
	outfile<<recipeName<<endl;
	outfile.close();
}

void LoadRecipeFromFile(ifstream inputFile, string recipeName, string inputRecipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps) {
	inputFile.open(recipeName + ".txt");

	while (!inputFile.eof()) {
		inputFile >> inputRecipeName;
		cout << inputRecipeName << endl;
	}
}