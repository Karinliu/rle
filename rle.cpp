#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void printRLE(std::vector<int> RUN_LENGTH, std::vector<char> INPUT_CHAR){
    const int NUM_VALS = RUN_LENGTH.size();
    std::vector<int> runLength(NUM_VALS);
    std::vector<char> inputChar(NUM_VALS);

    for (int i = 0; i < RUN_LENGTH.size(); i++){
        runLength.push_back(RUN_LENGTH[i]);
    }

    for (int i = 0; i < INPUT_CHAR.size(); i++){
        inputChar.push_back(INPUT_CHAR[i]);
    }

    std::cout << "The compressed data is: ";

    for (int i = NUM_VALS; i < runLength.size(); i++) {
            std::cout << runLength.at(i) << inputChar.at(i);  
    }

}
 
void compressRLE(const std::string INPUT_DATA){
    std::vector<int> runLength;
    std::vector<char> inputChar;

    for (int i = 0; i < INPUT_DATA.length(); i++) {
        int count = 1;
       
        while (INPUT_DATA[i] == INPUT_DATA[i + 1]) {
            count++;
            i++;  
        }

        inputChar.push_back(INPUT_DATA[i]);
        runLength.push_back(count);
    }

    printRLE(runLength, inputChar);
}

void isUpperCase(const std::string &INPUT_DATA){
    for (int i = 0; i < INPUT_DATA.size(); i++){
         if((INPUT_DATA[i] >= 65 && INPUT_DATA[i] <= 90) !=false ){
            throw std::runtime_error("invalid input");
        }
    }
}

void isNumber(const std::string &INPUT_DATA){
    for (int i = 0; i < INPUT_DATA.size(); i++){

        if((INPUT_DATA[i] >= 48 && INPUT_DATA[i] <= 57) !=false ){
            throw std::runtime_error("invalid input");
        }
    }
}
 
void validateInput(){
    std::string inputData;
    getline(std::cin, inputData);

    isNumber(inputData);
    isUpperCase(inputData);
    compressRLE(inputData);
}

int main(){
    try{
        std::cout << "Enter the data to be compressed: " <<std::endl;
        validateInput();
    }
    catch (std::runtime_error &excpt){
        std::cout << "error: " << excpt.what() << std::endl;
    }

    return 0;
}