#ifndef RECIPE_H
#define RECIPE_H
#include<vector>
#include<string>
using namespace std;

class Recipe {
	public:
		void loadRecipe();
		void saveRecipe(string recipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps);
	private:
		int recipeID;
		string recipeName;
		vector<string> ingredients;
		vector<string> amounts;
		vector<string> steps;
};

#endif