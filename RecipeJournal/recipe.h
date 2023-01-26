#ifndef RECIPE.H
#define RECIPE.H
#include<vector>
#include<string>
using namespace std;

class Recipe {
	public:
		void setIngredients(vector<string> ingredients);
		void setAmounts(vector<string> amounts);
		void setSteps(vector<string> steps);
	private:
		vector<string> ingredients;
		vector<string> amounts;
		vector<string> steps;
};

#endif