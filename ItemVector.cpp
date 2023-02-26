#include <iostream>
#include "ItemVector.h"
using namespace std;

vector<string> m_itemList;   // Vector to store unique produce items. Default size 0 at declaration. See setVector function below.

// Function to add new produce item string to the vector:
void ItemVector::setVectorValue(int i, string fileItem) {
	m_itemList.resize(i + 1);             // resize vector to be current size plus 1 to allocate new element
	m_itemList.at(i) = fileItem;
}

// Function that returns a vector value at the index parameter:
string ItemVector::getVectorValue(int i) {
	return m_itemList.at(i);
}

// Function to alphabetically sort the vector of unique produce items:
void ItemVector::sortVector() {
	sort(m_itemList.begin(), m_itemList.end());
}

// Function that returns the size of the vector of unique produce items:
int ItemVector::vectorSize() {
	return m_itemList.size();
}