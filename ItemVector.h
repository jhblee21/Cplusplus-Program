#pragma once
#ifndef ITEMVECTOR_H
#define ITEMVECTOR_H

#include <string>
#include <vector>
#include <algorithm>   // For sort function
using namespace std;

class ItemVector {

public:
	void   setVectorValue(int i, string fileItem);
	string getVectorValue(int i);
	void   sortVector();
	int    vectorSize();

private:
	vector<string> m_itemList;   // Vector to store unique grocery items. Default size 0 at declaration. See setVector function below.
};
#endif