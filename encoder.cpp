#include "encoder.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <random>

Encoder::Encoder() = default;

Encoder::Encoder(const std::string& input) {
	inputStr = input;
	int n = input.size();
	int cubeSize = 8;
	int cubesCount = (n + cubeSize - 1) / cubeSize;

	for(int i = 0; i < cubesCount; ++i) {
		int startPos = i * cubeSize;
		int length = std::min(cubeSize, n - startPos);
		std::string cubeString = input.substr(startPos, length);
		if(length < cubeSize) {
			cubeString += std::string(cubeSize - length, '\0');
		}
		Cube cube(cubeString);
		cubes.push_back(cube);
	}
}
std::string Encoder::getInputStr() const {
	return inputStr;
}

std::vector<Cube> Encoder::getCubes() const {
	return cubes;
}

void Encoder::setInputStr(const std::string& s) {
	inputStr = s;
}

void Encoder::setCubes(const std::vector<Cube>& c) {
	cubes = c;
}
void Encoder::printCube() const {
	for(int i = 0; i < cubes.size(); ++i) {
		std::cout << cubes[i].getCube() << " ";
	}
	std::cout << std:: endl;
}
std::string Encoder::generateKey() {
	std::string key;
    std::random_device rd; 
    std::mt19937 eng(rd());
    
    std::uniform_int_distribution<> distr(0, 9); 
    
    for (const Cube& cube : cubes) {
        std::ostringstream cubeKey;
        int u = distr(eng); 
        int d = distr(eng); 
        int l = distr(eng); 
        int r = distr(eng); 
        
        cubeKey << "U" << u << ",D" << d << ",L" << l << ",R" << r;
        
        if (!key.empty()) {
            key += ":";
        }
        
        key += cubeKey.str();
    }
    
    return key;
}

std::string Encoder::encodedText(const std::string& key) {
	std::vector<std::string> cubePart = split(key, ':');
	std::string encodedText = "";
	for(int i = 0; i < cubePart.size(); ++i) {
		Cube tempCube = getCubes()[i];
		std::vector<std::string> rotatepart = split(cubePart[i], ',');
		for(int j = 0; j < rotatepart.size(); ++j) {
			char rotate = rotatepart[j][0];
			int roateCount = std::stoi(rotatepart[j].substr(1)); //[1]
			if(rotate == 'U') {
				tempCube.upRotate(roateCount);
			} else if(rotate == 'D') {
				tempCube.downRotate(roateCount);
			} else if(rotate == 'L') {
				tempCube.leftRotate(roateCount);
			} else if(rotate == 'R') {
				tempCube.rightRotate(roateCount);
			}
		}
		encodedText += tempCube.getCube();
	}
	return encodedText;
}

std::vector<std::string> Encoder::split(const std::string& str, char ch) {
	std::vector<std::string> newV;
	std::stringstream ss(str);
	std::string part;
	while(std::getline(ss, part, ch)) {
		newV.push_back(part);
	}
	return newV;
}










