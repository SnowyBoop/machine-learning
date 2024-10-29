#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define TUPEL_LEN 5
#define DATASET_SIZE 14

//global Variables
std::vector<std::vector<std::string>> globalDataset;

struct chunkedString{
  std::string grabPart;
  std::string rest;
};

//helper functions

char* splitByIndex(char* inputString, int index) {

  char* output = new char[index];

  for(int i = 0; i < index; i++) {

    output[i] = inputString[i];

  }

  return output;
    
}

std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void drawBar() {std::cout << "------\n"; return;}

int findFirstOccurenceOfChar(char* inputArray, char toCheck, int length) {

  for(int i = 0; i<length; i++) {

    if(inputArray[i] == toCheck) { return i; }
    if(i == length - 1 )         { return i; } 
    
  }

  return 0;
  
}

std::string* newHypothesis(int length) {

  std::string* hypo = new std::string[length];
  for(int i = 0; i < length; i++) {
    //hypo[i] = "test" + std::to_string(i) + "\n";
    hypo[i] = "?";
  }  return hypo;
}

// machine learning part

std::vector<std::vector<std::string>>* deserializeData(char* datasetInput, int length) {

  std::vector<std::vector<std::string>>* outputDataset = new std::vector<std::vector<std::string>>;
  
  while(findFirstOccurenceOfChar(datasetInput,'\n',length) != 0) {

    std::cout << "hi";

  }

  return outputDataset;

}


int main() {

  std::cout << "started \n";

  std::string input = readFileToString("PlayTennis.csv");
  char* inStr = input.data();
  int inputDataLength = input.size();
  
  std::cout << inStr << "\n";
  std::cout << inputDataLength << "\n";
  std::cout << "First , is: " << findFirstOccurenceOfChar(inStr , ',' , inputDataLength) << "\n";
  drawBar();
  
  std::string* hypo = newHypothesis(TUPEL_LEN);

  for(int i = 0; i<TUPEL_LEN; i++) {
    std::cout <<  hypo[1] << ",\n";
  }
  
  return 0;

}
