#pragma once
#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <iostream>   
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>     // Output formatting

using namespace std;

class InputOutput {
	public:
        int  openInputFile();
        void readInputFile();
        void setMapValue();
        int  getMapValue(string item);   
        void closeInputFile();
        void openOutputFile();
        void writeOutputFile();
        void closeOutputFile();
        void printList();
        void printHist();
        
	private:
        ifstream m_inFS;             // Input file stream
        ofstream m_outFS;            // Output file stream
        string m_fileItem;           // Data value read from the input file
        map<string, int> m_itemMap;
        int i = 0;                   // Vector index
};

#endif