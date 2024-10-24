#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#define TUPEL_LEN 5
#define DATASET_SIZE 14

//helper functions

std::vector<std::string> split(std::string s, std::string delimiter) {
    
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    
    std::string token;
    
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        
        token = s.substr (pos_start, pos_end - pos_start);
        
        pos_start = pos_end + delim_len;
        
        res.push_back (token);
        
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::string** stringToDataset(std::string inputStr, std::string delimiter, int datasetSize) {

  std::string tuple = inputStr.substr(0, inputStr.find(delimiter));

  std::vector<std::string> splitVec = split(tuple, ",");
  
  std::string** outputDataset = new std::string[DATASET_SIZE][TUPEL_LEN];

  for(int i = 0; i<TUPEL_LEN; i++ ) {

    outputDataset[1][i] = splitVec[i];

  }
  
  return outputDataset;
  
}

char* splitByIndex(char* inputString, int index) {

  char* output = new char[index];

  for(int i = 0; i < index; i++) {

    output[i] = inputString[i];

  }

  return output;
    
}

void drawBar() {std::cout << "------"; return;
}
std::string* newHypothesis(int length) {

  std::string* hypo = new std::string[length]
;
  for(int i = 0; i < length; i++) {

    //hypo[i] = "test" + std::to_string(i) + "\n";
    hypo[i] = "?";
    
  }

  return hypo;

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

int main() {

  std::cout << "started \n";

  std::string input = readFileToString("PlayTennis.csv");
  char* inStr = input.data();

  std::cout << inStr;

  drawBar();
  
  std::string** dataset = stringToDataset(input, delimiter, DATASET_SIZE);

  drawBar();

  std::cout << tuple;
  
  std::string* hypo = newHypothesis(TUEL_LEN);

  for(int i = 0; i<TUPEL_LEN; i++) {
    std::cout <<  hypo[1] << ",\n";
  }
  
  return 0;

}
