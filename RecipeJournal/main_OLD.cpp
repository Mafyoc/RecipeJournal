#include<iostream>
#include<fstream>
#include"recipe.h"
#include<string>
#include<vector>
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
		inputFile.open("recipes/recipeNames.csv");
		while (getline(inputFile, inputRecipeData)) {
			inputFile >> inputRecipeData;
			cout << inputRecipeData << endl;
		}
		cout << endl;
		inputFile.close();

		cout << "Please enter the name of the recipe you would like to load" << endl;
		getline(cin, recipeName);
		cout << endl;

		inputFile.open("recipes/" + recipeName + "_ingredients.csv");
		while (inputFile.good()) {
			inputFile >> inputRecipeData;
			cout << inputRecipeData << endl;
		}
		inputFile.close();

		inputFile.open("recipes/" + recipeName + "_steps.csv");
		while (inputFile.good()) {
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
	outfile.open("recipes/"+recipeName+"_ingredients.csv");

	for (int i = 0; i < ingredients.size(); i++) {
		outfile << ingredients[i] << " " << amounts[i] << endl;
	}
	outfile.close();
	
	outfile.open("recipes/" + recipeName + "_steps.csv", ios::app);
	for (int i = 0; i < steps.size(); i++) {
		outfile << steps[i]<<endl;
	}

	outfile.close();

	outfile.open("recipes/recipeNames.csv", ios_base::app);
	outfile<<recipeName<<endl;
	outfile.close();
}

void LoadRecipeFromFile(string recipeName, string inputRecipeName) {
	ifstream inputFile;
	inputFile.open("recipes/" + recipeName + ".csv");

	while (!inputFile.eof()) {
		inputFile >> inputRecipeName;
		cout << inputRecipeName << endl;
	}
}