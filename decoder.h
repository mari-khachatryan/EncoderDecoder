#ifndef DECODER_H
#define DECODER_H

#include "encoder.h"
#include "string"

class Decoder {
public:
	Decoder(const std::string&, const std::string&); 
	std::string getText() const;
	std::string getKey() const;
	void setText(const std::string&);
	void setKey(const std::string&);
	std::string decode(Encoder&);
private:
	std::string text;
	std::string key;
};

#endif  //DECODER_H