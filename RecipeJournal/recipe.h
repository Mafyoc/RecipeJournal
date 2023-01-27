#ifndef RECIPE_H
#define RECIPE_H
#include<vector>
#include<string>
using namespace std;

class Recipe {
	public:
		void loadRecipe();
		void addIngredient(string ingredients);
		void addAmount(string amounts);
		void setSteps(string steps);
	private:
		int recipeID;
		string recipeName;
		string ingredients;
		string amounts;
		string steps;
};

#endif