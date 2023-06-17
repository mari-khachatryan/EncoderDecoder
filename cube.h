#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include <string>

class Cube {
public:
	Cube();
	Cube(const std::string&);
	void setCube(const std::string&);
	std::string getCube() const;
	void upRotate(int);
	void downRotate(int);
	void leftRotate(int);
	void rightRotate(int);
private:
	std::string cube;
};

#endif //CUBE_H