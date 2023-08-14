#include "IntegerArray.h"
#include <iostream>


    IntegerArray::IntegerArray() = default;
	IntegerArray::IntegerArray(int lenght) : _lenght{ lenght }
	{
		if (lenght < 0)
		{
			throw "bad_length";
		}
		_data = new int[lenght] {};
		
	}
	IntegerArray::IntegerArray(const IntegerArray& a)
	{
		reallocate(a.getLenght());
		for (int i = 0; i < _lenght; ++i)
			_data[i] = a._data[i];
	}

	IntegerArray::~IntegerArray()
	{
		delete[] _data;
	}


	int& IntegerArray:: operator[](int i)
	{
		if (i >= 0 && i < _lenght)
		{
			return _data[i];
		}
		else throw "bad_range";
	}

	IntegerArray& IntegerArray:: operator=(const IntegerArray& a)
	{
		if (&a == this)
			return *this;
		reallocate(a.getLenght());
		for (int i = 0; i < _lenght; ++i)
			_data[i] = a._data[i];
		return *this;
	}

	int IntegerArray :: getLenght() const
	{
		return _lenght;
	}

	int IntegerArray::getSearch(int s) const
	{
		int s_lenght = getLenght();
		for (int i = 0; i < s_lenght; ++i)
		{
			if (_data[i] == s) return i;
		}
		 throw "badSearch";
	}

	void IntegerArray::erase()
	{
		delete[] _data;
		_data = nullptr;
		_lenght = 0;
	}

	void IntegerArray::reallocate(int newLenght)
	{
		erase();
		if (newLenght <= 0)
			return;
		_data = new int[newLenght];
		_lenght = newLenght;
	}

	void IntegerArray::resize(int newLenght)
	{
		if (newLenght == _lenght)
			return;
		if (newLenght <= 0)
		{
			erase();
			return;
		}
		int* data{ new int[newLenght] };
		if (_lenght > 0)
		{
			int elementsCopy{ (newLenght > _lenght) ? _lenght : newLenght };
			for (int i = 0; i < elementsCopy; ++i)
				data[i] = _data[i];
		}
		delete[] _data;
		_data = data;
		_lenght = newLenght;
	}

	void IntegerArray::insert(int val, int i)
	{
		if (i >= 0 && i <= _lenght)
		{
			int* data{ new int[_lenght + 1] };
			for (int before = 0; before < i; ++before)
				data[before] = _data[before];
			data[i] = val;
			for (int after = i; after < _lenght; ++after)
				data[after + 1] = _data[after];
			delete[] _data;
			_data = data;
			++_lenght;
		}
		else throw "bad_range";
	}

	void IntegerArray::insertAtBeginning(int val) { insert(val, 0); }
	void IntegerArray::insertAtEnd(int val) { insert(val, _lenght); }

	void IntegerArray::remove(int i)
	{
		if (i >= 0 && i <= _lenght)
		{
			if (_lenght == 1)
			{
				erase();
				return;
			}
			int* data{ new int[_lenght - 1] };
			for (int before = 0; before < i; ++before)
				data[before] = _data[before];
			for (int after = (i + 1); after < _lenght; ++after)
				data[after - 1] = _data[after];
			delete[] _data;
			_data = data;
			--_lenght;
		}
		else throw "bad_range";
	}

