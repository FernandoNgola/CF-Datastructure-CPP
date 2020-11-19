#include <iostream>
#include <random>

//Toeplitz Matrix start
class TroeplitzMatrix
{
private:
    /* data */
    int *A;
    size_t size;

private:
    int GetRandom()
    {
        std::random_device rng;
        std::mt19937 prng(rng());
        std::uniform_int_distribution<int> dist(3, 9);
        return dist(prng);
    }
    size_t GetSize()
    {
        return size;
    }
    void SetSize(size_t size)
    {
        this->size = size;
    }
    int GetIndex(int x, int y)
    {
        if (x <= y)
        {
            return y - x;
        }
        else
        {
            return size + (x - y - 1);
        }
    }
    void InitializeArray()
    {
        A = new int[2 * size - 1];
        if (nullptr == A)
        {
            std::cerr << "New operator failed";
            return;
        }
    }

public:
    TroeplitzMatrix(/* args */);
    TroeplitzMatrix(size_t size);

    ~TroeplitzMatrix();
    void Create();
    void Set(int x, int y, int value);
    int Get(int x, int y);
    void Display();
};

TroeplitzMatrix::TroeplitzMatrix(/* args */)
{
    SetSize(5);
    InitializeArray();
}
TroeplitzMatrix::TroeplitzMatrix(size_t size)
{
    SetSize(size);
    InitializeArray();
}
TroeplitzMatrix::~TroeplitzMatrix()
{
    delete[] A;
    A = nullptr;
}
void TroeplitzMatrix::Create()
{
    std::cout << "Creating a random matrix of " << GetSize() << "x" << GetSize() << std::endl;
    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            Set(x, y, GetRandom());
        }
    }
}
void TroeplitzMatrix::Set(int x, int y, int value)
{
    A[GetIndex(x, y)] = value;
}
int TroeplitzMatrix::Get(int x, int y)
{
    return A[GetIndex(x, y)];
}
void TroeplitzMatrix::Display()
{
    std::cout << "\n";
    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            std::cout << Get(x, y) << " ";
        }
        std::cout << std::endl;
    }
}
//Toeplitz Matrix end

int main(int argc, char const *argv[])
{
    std::random_device rnd;
    std::cout << "Generating a random size [0, 6] + 3: ";
    size_t size = rnd() % 6 + 3;
    std::cout << "Size = " << size << std::endl;
    TroeplitzMatrix tpmtx(size);
    tpmtx.Create();
    tpmtx.Display();
    return 0;
}
