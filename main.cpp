#include "decoder.h" 
#include <iostream>

int main() {
	Encoder encoder("hello world");
	std::string key = encoder.generateKey();
	std::cout << "Generated key - " << key << std::endl;
	std::string encodedText = encoder.encodedText(key);
	std::cout << "Encoded text - " << encoder.encodedText(key) << std::endl;
	Decoder decoder(encodedText, key);
	std::cout << "Decoded text - " << decoder.decode(encoder) << std::endl;

	return 0;
}