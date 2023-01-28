#include "recipe.h"
using namespace std;

void Recipe::loadRecipe() {

}
void Recipe::saveRecipe(string recipeName, vector<string> ingredients, vector<string> amounts, vector<string> steps) {
	this->recipeName = recipeName;
	this->ingredients = ingredients;
	this->amounts = amounts;
	this->steps = steps;
}