#include "InputOutput.h"
#include "ItemVector.h"

ItemVector itemList;   // Global class object to store a list of items in a vector

// Function to open input file:
int InputOutput::openInputFile() {
    m_inFS.open("CS210_Project_Three_Input_File.txt");
    if (!m_inFS.is_open()) {
        cout << "Could not open file CS210_Project_Three_Input_File.txt." << endl;
        return 1; // 1 indicates error
    }
}

// Function to begin reading input file:
void InputOutput::readInputFile() {
    // Begin reading from the input file:
    m_inFS >> m_fileItem;
    
}

// This function continues to read input file until the end,
// then adds unique produce items to itemList vector,
// then emplaces the item name as key with frequency as value in the itemMap.
void InputOutput::setMapValue() {
    // Loop thru input file while not at end of input file stream and stream is in an error free state:
    while (!m_inFS.eof() && m_inFS.good()) {
        if (m_itemMap.count(m_fileItem) == 1) {   // If the fileItem key does exist in the map:
            m_itemMap[m_fileItem] += 1;           // increase the entry value by 1 (item counter)
        }
        else {                                    // If the fileItem key does not exist in the map:
            m_itemMap.emplace(m_fileItem, 1);     // add the key and the associated count value 1 to the map, and,
            itemList.setVectorValue(i, m_fileItem);
            i += 1;
        }
        // Read next line of input file and loop:
        InputOutput::readInputFile();
    }
    itemList.sortVector();                        // Call sort function to sort itemList vector alphabetically
}

// Function to get a value from a map using a string parameter as key:
int InputOutput::getMapValue(string item) {
    return m_itemMap.at(item);
}

// Function to close input file after finished with reading
void InputOutput::closeInputFile() {
    m_inFS.close();   // Close input file after reading
}

// Function to open output file:
void InputOutput::openOutputFile() {
    m_outFS.open("frequency.dat");
}

// Function to write all unique items and associated item frequency to file by looping thru itemList vector:
void InputOutput::writeOutputFile() {
    for (unsigned int i = 0; i < itemList.vectorSize(); ++i) {
        m_outFS << itemList.getVectorValue(i) << " ";
        m_outFS << getMapValue(itemList.getVectorValue(i)) << endl;   // From the map, get item counter value associated with the item key obtained from vector
    }
}

// Function to close output file after finished writing:
void InputOutput::closeOutputFile() {
    m_outFS.close();   // Done with file, so close
}

// Function to print the vector storing names of unique produce items along with associated frequency values from the itemMap:
void InputOutput::printList() {
    for (unsigned int i = 0; i < itemList.vectorSize(); ++i) {
        cout << setw(11) << left << itemList.getVectorValue(i) << " " << getMapValue(itemList.getVectorValue(i)) << endl;
    }
}

// Function to print histogram of unique produce items and sales count:
void InputOutput::printHist() {
    for (unsigned int i = 0; i < itemList.vectorSize(); ++i) {
        int count = 0;
        cout << setw(12) << left << itemList.getVectorValue(i) << " ";
        for (unsigned int j = 0; j < getMapValue(itemList.getVectorValue(i)); ++j) {
            cout << "[]";
            count += 1;
        }
        cout << " " << count << endl;
    }
}