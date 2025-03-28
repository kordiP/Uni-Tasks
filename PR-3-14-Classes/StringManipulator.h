#pragma once

class StringManipulator
{
private:
	char* str;
	bool errorState;

	void remove();
	void copy(const StringManipulator& other);
public:
	StringManipulator();
	StringManipulator(const char* str);
	StringManipulator(const char* str, unsigned multTimes);

	StringManipulator(const StringManipulator& other);
	StringManipulator& operator=(const StringManipulator& other);
	~StringManipulator();

	const char* getString() const;
	bool getState() const;
	int getStringLength() const;

	StringManipulator& resetState();

	StringManipulator& setString(const char* str);
	const StringManipulator& printString() const;
	StringManipulator& concatString(StringManipulator& strMan);
	StringManipulator& insertString(const char* str, int position = -1);

	StringManipulator& replaceSymbol(char toRep, char repWith, int replaceCount = -1);
	StringManipulator& deleteStrAfterIndex(int numberOfChars, unsigned position);

	StringManipulator upperCase();
	StringManipulator lowerCase();

	const StringManipulator& saveToFile(const char* fileName) const;
	StringManipulator& readFromFile(const char* fileName);
};