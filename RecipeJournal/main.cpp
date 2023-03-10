#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void LoadOrCreate();
void loadRecipe();
void newRecipe();

int main() {

	LoadOrCreate(); //initial request from user if they wish to create a new recipe or load an existing one

	return 0;
}

void LoadOrCreate() {
	string loadOrCreate;
	cout << "type 'new' to create a recipe, type 'load' to load an existing recipe" << endl;
	getline(cin, loadOrCreate);
	if (loadOrCreate == "new") {
		newRecipe();
	}
	else if (loadOrCreate == "load") {
		loadRecipe();
	}
	else if (loadOrCreate != "load" && loadOrCreate != "new")
		LoadOrCreate();
}
//Prompts the user if they would like to load a recipe or create a new one

void loadRecipe() {
	string recipeName;
	string inputRecipeData;
	ifstream inputFile;

	cout << endl;
	inputFile.open("recipes/recipeNames.txt");
	while (getline(inputFile, inputRecipeData)) {
		cout << inputRecipeData << endl;
	}
	inputFile.close();

	cout << endl;
	cout << "Please enter the name of the recipe you would like to load" << endl;
	getline(cin, recipeName);
	cout << endl;

	inputFile.open("recipes/" + recipeName + ".txt");
	while (getline(inputFile, inputRecipeData)) {
		cout << inputRecipeData << endl;
	}
	inputFile.close();
	cout << endl;
	LoadOrCreate();
}
//requests the name of a recipe and outputs its details

void newRecipe() {
	bool loopBreak = false;
	string isCorrectIngredients;
	string recipeName;
	string currentIngredient;
	string currentAmount;
	string currentStep;
	vector<string> ingredients;
	vector<string> amounts;
	vector<string> steps;

	cout << "Please enter the name of your recipe." << endl;
	getline(cin, recipeName);

	while (loopBreak == false) {

		cout << "Please add an ingredient or type 'end' to continue." << endl;
		getline(cin, currentIngredient);

		if (currentIngredient == "end") {
			cout << endl;
			if (ingredients.size() >= 1) {
				for (int i = 0; i < ingredients.size(); i++) {
					cout << ingredients[i] << " " << amounts[i] << endl;
				}
				cout << "Are these ingredients correct?" << endl;
				getline(cin, isCorrectIngredients);
				if (isCorrectIngredients == "y") {
					loopBreak = true;
					cout << endl;
				}
				else {
					ingredients.clear();
					cout << "Please re-enter the list of ingredients for " + recipeName;
				}
			}
		}
		else {
			ingredients.push_back(currentIngredient);
			cout << "Please enter the amount of " << currentIngredient << "." << endl;
			getline(cin, currentAmount);
			amounts.push_back(currentAmount);
		}

	}
	//create list of ingredients and amounts

	loopBreak = false;

	while (loopBreak == false)
	{
		cout << "Please enter the directions for step " << steps.size() + 1 << " of " << recipeName << ". Or type 'end' to finish." << endl;
		getline(cin, currentStep);
		if (currentStep == "end") {
			cout << endl;
			if (steps.size() >= 1) {
				for (int i = 0; i < steps.size(); i++) {
					cout << steps[i] << endl;
				}
				cout << "Are these instructions correct?" << endl;
				getline(cin, isCorrectIngredients);
				if (isCorrectIngredients == "y") {
					loopBreak = true;
					cout << endl;
				}
				else {
					steps.clear();
					cout << "Please re-enter the list of steps for " + recipeName;
				}
			}
		}
		else {
			steps.push_back(currentStep);
		}
	}
	//create list of directions

	ofstream outfile;
	outfile.open("recipes/" + recipeName + ".txt");
	outfile << "ingredients" << endl;
	for (int i = 0; i < ingredients.size(); i++) {
		outfile << ingredients[i] << " " << amounts[i] << endl;
	}
	outfile << endl;
	outfile.close();

	outfile.open("recipes/" + recipeName + ".txt", ios::app);
	outfile << "Instructions" << endl;
	for (int i = 0; i < steps.size(); i++) {
		outfile << steps[i] << endl;
	}
	outfile.close();

	outfile.open("recipes/recipeNames.txt", ios_base::app);
	outfile << recipeName << endl;
	outfile.close();

	LoadOrCreate();
}
//requests infromation from the user about the new recipe then saves it to file when complete