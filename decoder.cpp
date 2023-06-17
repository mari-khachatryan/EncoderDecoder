#include "decoder.h"

Decoder::Decoder(const std::string& t, const std::string& k)
	:text{t}
	,key{k}
{}

std::string Decoder::getText() const {
	return text;
}

std::string Decoder::getKey() const {
	return key;
}

void Decoder::setText(const std::string& t) {
	text = t;
}

void Decoder::setKey(const std::string& k) {
	key = k;
}

std::string Decoder::decode(Encoder& e) {
	std::vector<std::string> cubePart = e.split(key, ':');
	std::string decodedText = "";
	for(int i = 0; i < cubePart.size(); ++i) {
		//Cube tempCube = getCubes()[i];
		std::vector<std::string> rotatepart = e.split(cubePart[i], ',');
		bool reverseRotation = (i == cubePart.size() - 1);
		for(int j = 0; j < rotatepart.size(); ++j) {
			char rotate = rotatepart[j][0];
			int roateCount = std::stoi(rotatepart[j].substr(1)); //[1]
			if(rotate == 'U') {
				e.getCubes()[i].downRotate(roateCount);
			} else if(rotate == 'D') {
				if(reverseRotation) {
					e.getCubes()[i].upRotate(roateCount);
				} else {
					e.getCubes()[i].downRotate(roateCount);
				}
			} else if(rotate == 'L') {
				e.getCubes()[i].rightRotate(roateCount);
			} else if(rotate == 'R') {
				e.getCubes()[i].leftRotate(roateCount);
			}
		}
		decodedText += e.getCubes()[i].getCube();
	}
	return decodedText;
}






