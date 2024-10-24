#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>

#define TUPEL_LEN 5

char* splitByIndex(char* inputString, int index) {

  char* output = new char[index];

  for(int i = 0; i < index; i++) {

    output[i] = inputString[i];

  }

  return output;
    
}

void drawBar() {std::cout << "------"; return;}

std::string* newHypothesis(int length) {

  std::string* hypo = new std::string[length];

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

  std::string delimiter = "\n";
  std::string tuple = input.substr(0, input.find(delimiter));

  drawBar();

  std::cout << tuple;
  
  std::string* hypo = newHypothesis(TUPEL_LEN);

  for(int i = 0; i<TUPEL_LEN; i++) {
    std::cout <<  hypo[1] << ",\n";
  }
  
  return 0;

}