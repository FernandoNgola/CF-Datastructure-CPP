#include <iostream>
#include <iomanip>

class Array
{
private:
	int *A;
	int size;
	int length;
	void Initialize()
	{
		length = 0;
		A = new int[size];
	}

public:
	Array()
	{
		size = 10;
		Initialize();
	}

	Array(std::size_t size)
	{
		this->size = size;
		Initialize();
	}
	~Array()
	{
		delete[] A;
	}

	void Display()
	{
		for (int i = 0; i < length; ++i)
		{
			std::cout << i << ": " << A[i] << std::endl;
		}
	}

	void Append(int value)
	{
		if (length == size)
		{
			return;
		}
		A[length] = value;
		length++;
	}

	void Insert(int index, int value)
	{
		if (index >= 0 && index <= length)
		{
			for (int i = length; i >= index; --i)
			{
				A[i + 1] = A[i];
			}
			A[index] = value;
			length++;
		}
	}

	int Delete(int index)
	{
		int deletedValue = 0;
		if (index >= 0 && index < length)
		{
			deletedValue = A[index];
			for (int i = index; i < length - 1; ++i)
			{
				A[i] = A[i + 1];
			}
			length--;
		}
		return deletedValue;
	}
};

int main(int argc, char const *argv[])
{
	Array arr1;
	arr1.Append(45);
	arr1.Append(23);
	arr1.Insert(0, 1);
	std::cout << arr1.Delete(0) << std::endl;
	arr1.Display();
	return 0;
}