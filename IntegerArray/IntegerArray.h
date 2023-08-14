#pragma once

class IntegerArray

{
public:
	IntegerArray();
	IntegerArray(int lenght);
	IntegerArray(const IntegerArray& a);

	~IntegerArray();


	
	int& operator[](int i);
	IntegerArray& operator=(const IntegerArray& a);

	int getLenght() const;
	int getSearch(int s) const;

	void erase();
	void reallocate(int newLenght);
	void resize(int newLenght);
	void insert(int value, int index);
	void insertAtBeginning(int val);
	void insertAtEnd(int val);
	void remove(int i);
	




private:
	int _lenght{};
	int* _data{};
};
