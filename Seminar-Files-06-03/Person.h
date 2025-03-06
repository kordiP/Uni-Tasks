#pragma once

class Person {
private:
	char name[21];
	char EGN[11];
	char password[21];

public:
	const char* getName() const;
	const char* getEGN() const;
	const char* getPassword() const;

	void setName(const char* _name);
	void setEGN(const char* _EGN);
	void setPassword(const char* _password);

	bool signUp(const char* _name, const char* _EGN, const char* _password);
	bool login(const char* _EGN, const char* password) const;
	void displayPerson() const;
	int countPersont() const;
};