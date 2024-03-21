#include "String.h"
#include <iostream>

String::String()
{
	m_string = new char[1];
	m_string[0] = '\0';
}

// Function to allow setting the string
String::String(const char* _str)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_str) + 1;

	// Make a new char array with the length
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_str
	);
}

// Allows setting the string using another string as it's input
String::String(const String& _other)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_other.CStr()) + 1;

	// Make a new char array with the length
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_other.CStr()
	);
}

String::String(String&& other)
{
	//// Get the length of the inputted string + 1 to store \0
	//int length = strlen(other.CStr()) + 1;

	//// Make a new char array with the length
	//m_string = new char[length];

	//// Copy it to the new array
	//strcpy_s(
	//	m_string,
	//	length,
	//	other.CStr()
	//);

	m_string = other.m_string;
	other.m_string = nullptr;

}

// Destructor
String::~String()
{
	delete[] m_string;
}

// Returns the length of the string
size_t String::Length() const
{
	return strlen(m_string); // Uses strlen to get the length of the current string (m_string)
}

// Returns the character in the area of the array thats requested
char& String::CharacterAt(size_t _index)
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}


// Returns the character in the area of the array thats requested
const char& String::CharacterAt(size_t _index) const
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}

// Checks if the string is equal to another
bool String::EqualTo(const String& _other) const
{
	// Returns 0 if it's equal
	if (strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Appends the provided string to the end of the string
String String::Append(const String& _str)
{
	int totalSize = strlen(m_string) + strlen(_str.CStr()) + 1;

	// Create a temporary table to store char data in
	char* tmp = new char[totalSize];

	// Add the 2 strings together
	strcpy_s(tmp, totalSize, m_string);
	strcat_s(tmp, totalSize, _str.CStr());

	// Convert to a string object and delete the temp array
	String tmpString = tmp;
	delete[] tmp;
	return tmpString;
}

// Prepends the provided string to the end of the string
String String::Prepend(const String& _str)
{
	int totalSize = strlen(m_string) + strlen(_str.CStr()) + 1;

	// Create a temporary table to store char data in
	char* tmp = new char[totalSize];

	// Add the 2 strings together
	strcpy_s(tmp, totalSize, _str.CStr());
	strcat_s(tmp, totalSize, m_string);

	// Convert to a string object and delete the temp array
	String tmpString = tmp;
	delete[] tmp;
	return tmpString;
}

// Responds with the string
const char* String::CStr() const
{
	return m_string;
}

// Writes the string to console
void String::WriteToConsole()
{
	std::cout << m_string << "\n";
}

// Converts the string to lower-case
String String::ToLower()
{
	// Get the length of the string
	int stringLength = strlen(m_string);

	// Create a temporary table to store char data in
	char* tmp = new char[stringLength + 1];

	// Loop through all the letters and check if they're lower case
	for (int i = 0; i <= stringLength; i++) {
		if (m_string[i] >= 65 && m_string[i] <= 90) {
			tmp[i] = m_string[i] + 32; // If it's lower case take 32 which'll make it upper case
		}
		else {
			tmp[i] = m_string[i];
		}
	}

	String tmpString = tmp; // Convert the char array to a string object
	delete[] tmp;
	return tmpString;
}

// Responds with an upper-case version of the string
String String::ToUpper()
{
	// Get the length of the string
	int stringLength = strlen(m_string);

	// Create a temporary table to store char data in
	char* tmp = new char[stringLength + 1];

	// Loop through all the letters and check if they're lower case
	for (int i = 0; i <= stringLength; i++) {
		if (m_string[i] >= 97 && m_string[i] <= 122) {
			tmp[i] = m_string[i] - 32; // If it's lower case take 32 which'll make it upper case
		}
		else {
			tmp[i] = m_string[i];
		}
	}

	String tmpString = tmp; // Convert the char array to a string object
	delete[] tmp;
	return tmpString;
}

// Checks if the string contains the same contents as another
size_t String::Find(const String& _str)
{
	// Sets up required variables
	int stringSize = strlen(m_string);
	int letterToLookFor = 0;
	int sizeOfStr = strlen(_str.CStr());

	// Loops through every array of the string
	for (int i = 0; i < stringSize; i++) {
		// Checks if the char matches up with the char to check on the other array
		if (m_string[i] == _str.CStr()[letterToLookFor]) {
			// if it is matching, move on to the next char to look for
			letterToLookFor++;
			if (letterToLookFor >= sizeOfStr) {
				// return the position of the char
				return i - (letterToLookFor - 1);
			}
		}
		else {
			// if it doesn't match reset to the first char
			letterToLookFor = 0;
		}
	}
	return -1; // This will only be called if it doesn't contain the string
}

// Find a certain word/phrase inside a string, responds with the location of the char in the array
size_t String::Find(size_t _startIndex, const String& _str)
{
	// Sets up required variables
	int stringSize = strlen(m_string);
	int letterToLookFor = 0;
	int sizeOfStr = strlen(_str.CStr());

	if (_startIndex >= stringSize) {
		return -1;
	}

	// Loops through every array of the string
	for (int i = _startIndex; i < stringSize; i++) {
		// Checks if the char matches up with the char to check on the other array
		if (m_string[i] == _str.CStr()[letterToLookFor]) {
			// if it is matching, move on to the next char to look for
			letterToLookFor++;
			if (letterToLookFor >= sizeOfStr) {
				// return the position of the char
				return i - (letterToLookFor - 1);
			}
		}
		else {
			// if it doesn't match reset to the first char
			letterToLookFor = 0;
		}
	}
	return -1; // This will only be called if it doesn't contain the string
}

// Replaces a certain word/phrase in the string with another
String String::Replace(const String& _find, const String& _replace)
{
	// Setup the tempoarary variables required for this
	String tmp = m_string;
	char tmpArray[2001];
	int locationToCheck = 0;
	int replacingLoc = 0;

	// Loop through and check for all instances of the string and add the word to replace to the temp array instead
	while (true) {
		int strLocation = Find(locationToCheck, _find);
		if (strLocation != -1) {
			locationToCheck = strLocation + _replace.Length();

			for (int i = replacingLoc; i < strLocation; i++) {
				tmpArray[replacingLoc] = m_string[i];
				replacingLoc++;
			}
			for (int i = 0; i < _replace.Length(); i++) {
				tmpArray[replacingLoc] = _replace.CStr()[i];
				replacingLoc++;
			}
			for (int i = strLocation + strlen(_find.m_string); i <= Length(); i++)
			{
				tmpArray[replacingLoc] = m_string[i];
				replacingLoc++;
			}

			//write rest of data after replace string written (everything in m_string after find)
			delete[] m_string;
			m_string = new char[strlen(tmpArray) + 1];
			strcpy_s(m_string, strlen(tmpArray) + 1, tmpArray);
			replacingLoc = 0;
		}
		else {
			break;
		}
	}

	//for (int i = replacingLoc; i < strlen(m_string); i++) {
	//	tmpArray[replacingLoc] = m_string[replacingLoc];
	//	replacingLoc++;

	//}

	tmpArray[replacingLoc] = '\0';

	String convertedStr(m_string);
	delete[] m_string;
	m_string = new char[tmp.Length() + 1];
	strcpy_s(m_string, tmp.Length() + 1, tmp.m_string);

	return convertedStr;


}

// Prompts the user to type a string (limited to 2000 chars)
String String::ReadFromConsole()
{
	// Create a char array that can store 2000 characters and then request input from the user
	char input[2001];
	std::cin.getline(input, 2001);

	//std::getline(std::cin, input)

	// Convert it into a string then return it
	String tmp = input;
	return tmp;
}

// Checks if the strings are equal and returns the results
bool String::operator==(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the 2 strings aren't the same then returns the results
bool String::operator!=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 0) {
		return false;
	}
	else {
		return true;
	}
}

// Checks if the string is smaller than the compared string
bool String::operator<(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 1) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the string is smaller or equal to the compared string
bool String::operator<=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == 1 || strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the string is bigger than the compared string
bool String::operator>(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == -1) {
		return true;
	}
	else {
		return false;
	}
}

// Checks if the string is bigger or equal to the compared string
bool String::operator>=(const String& _other)
{
	if (strcmp(m_string, _other.CStr()) == -1 || strcmp(m_string, _other.CStr()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Allows setting the string after being set previously
String& String::operator=(const String& _str)
{
	// Get the length of the inputted string + 1 to store \0
	int length = strlen(_str.CStr()) + 1;

	// Remove the old string
	delete[] m_string;

	// Setup a new array
	m_string = new char[length];

	// Copy it to the new array
	strcpy_s(
		m_string,
		length,
		_str.CStr()
	);

	// Convert the array to a string
	//String tmpString = m_string;

	return *this;
}

String& String::operator=(String&& _str)
{
	//// Get the length of the inputted string + 1 to store \0
	//int length = strlen(_str.CStr()) + 1;

	//// Remove the old string
	//delete[] m_string;

	//// Setup a new array
	//m_string = new char[length];

	//// Copy it to the new array
	//strcpy_s(
	//	m_string,
	//	length,
	//	_str.CStr()
	//);

	//// Convert the array to a string
	//String tmpString = m_string;

	//return tmpString;

	delete[] m_string;
	m_string = _str.m_string;
	_str.m_string = nullptr;

	return *this;
}


// Returns the character in the area of the array thats requested
char& String::operator[](size_t _index)
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}

// Returns the character in the area of the array thats requested
const char& String::operator[](size_t _index) const
{
	int sizeOfArray = strlen(m_string) + 1;
	if (_index < sizeOfArray || _index < 0) {
		return m_string[_index]; // Returns the char at the location requested
	}
	else {
		return m_string[sizeOfArray]; // Returns the section of the array with \0 to avoid a buffer overflow
	}
}
