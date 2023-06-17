#ifndef ENCODER_H
#define ENCODER_H

#include "cube.h"
#include <string>
#include <vector>

class Encoder {
public:
	Encoder();
	Encoder(const std::string&);
	std::string getInputStr() const;
	std::vector<Cube> getCubes() const;
	void setInputStr(const std::string&);
	void setCubes(const std::vector<Cube>&);
	void printCube() const;
	std::string generateKey();
	std::string encodedText(const std::string& key);
	std::vector<std::string> split(const std::string&, char);
private:
	std::string inputStr;
	std::vector<Cube> cubes;
};

#endif  //ENCODER_H