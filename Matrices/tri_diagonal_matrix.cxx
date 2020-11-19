#include <iostream>
#include <random>
#include <cmath>

//TriDiagonal Matrix start
class TriDiaMatrix
{
private:
    /* data */
    int *A;
    size_t size;

    //if i-j = i
    // int GetIndex(int x, int y)
    // {
    //     if ((x - y) == 1)
    //     {
    //         return x - 1;
    //     }
    //     else if ((x - y) == 0)
    //     {
    //         return (size - 1) + (x - 1);
    //     }
    //     else if ((y - x) == 1)
    //     {
    //         return (2 * size - 1) + (x - 1);
    //     }
    //     return x;
    // }
    size_t GetSize();
    void SetSize(size_t size);

private:
    int GetRandom()
    {
        std::random_device rng;
        std::mt19937 prng(rng());
        std::uniform_int_distribution<int> dist(3, 9);
        return dist(prng);
    }
    void InitializeArray()
    {
        A = new int[3 * size - 2];
        if (nullptr == A)
        {
            std::cerr << "New operator failed";
            return;
        }
    }

public:
    TriDiaMatrix(/* args */);
    TriDiaMatrix(size_t size);
    ~TriDiaMatrix();

    void Create();
    void Set(int x, int y, int value);
    int Get(int x, int y);
    void Display();
};

TriDiaMatrix::TriDiaMatrix(/* args */)
{
    SetSize(6);
    InitializeArray();
}
TriDiaMatrix::TriDiaMatrix(size_t size)
{
    SetSize(size);
    InitializeArray();
}

TriDiaMatrix::~TriDiaMatrix()
{
    delete[] A;
}

void TriDiaMatrix::Create()
{
    std::cout << "Creating the random matrix of size " << GetSize() << "x" << GetSize() << std::endl;
    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            Set(x, y, GetRandom());
        }
    }
}
void TriDiaMatrix::Set(int x, int y, int value)
{
    if (x - y == 1)
    {
        A[x - 1] = value;
    }
    else if (x - y == 0)
    {
        A[(size - 1) + (x - 1)] = value;
    }
    else if ((y - x) == 1)
    {
        A[(2 * size - 1) + (x - 1)] = value;
    }
}
int TriDiaMatrix::Get(int x, int y)
{

    if (x - y == 1)
    {
        return A[x - 1];
    }
    else if (x - y == 0)
    {
        return A[(size - 1) + (x - 1)];
    }
    else if ((y - x) == 1)
    {
        return A[(2 * size - 1) + (x - 1)];
    }

    else
    {
        return 0;
    }
}
void TriDiaMatrix::Display()
{
    std::cout << std::endl;
    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            std::cout << Get(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

size_t TriDiaMatrix::GetSize()
{
    return size;
}
void TriDiaMatrix::SetSize(size_t size)
{
    this->size = size;
}

int main(int argc, char const *argv[])
{
    std::random_device rnd;
    size_t size = rnd() % 6 + 3;
    std::cout << "Generating random size [3, 9]: ";
    std::cout << "Size = " << size << "\n";
    TriDiaMatrix trdimatrix(size);
    trdimatrix.Create();
    trdimatrix.Display();
    return 0;
}
