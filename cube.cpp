#include "cube.h"

Cube::Cube() = default;

Cube::Cube(const std::string& c) : cube{c} {}

void Cube::setCube(const std::string& c) {
	cube = c;
}

std::string Cube::getCube() const {
	return cube;
}

void Cube::upRotate(int n) {
	std::string res = "";
	for(int i = 0; i < n; ++i) {
		res += cube[3];
		res += cube[2];
		res += cube[6];
		res += cube[7];
		res += cube[0];
		res += cube[1];
		res += cube[5];
		res += cube[4];
	}
	setCube(res);
}

void Cube::downRotate(int n) {
	std::string res = "";
	for(int i = 0; i < n; ++i) {
		res += cube[4];
		res += cube[5];
		res += cube[1];
		res += cube[0];
		res += cube[7];
		res += cube[6];
		res += cube[2];
		res += cube[3];
	}
	setCube(res);
}

void Cube::leftRotate(int n) {
	std::string res = "";
	for(int i = 0; i < n; ++i) {
		res += cube[1];
		res += cube[5];
		res += cube[6];
		res += cube[2];
		res += cube[0];
		res += cube[4];
		res += cube[7];
		res += cube[3];
	}
	setCube(res);
}

void Cube::rightRotate(int n) {
	std::string res = "";
	for(int i = 0; i < n; ++i) {
		res += cube[4];
		res += cube[0];
		res += cube[3];
		res += cube[7];
		res += cube[5];
		res += cube[1];
		res += cube[2];
		res += cube[6];
	}
	setCube(res);
}