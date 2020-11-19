#include <iostream>
#include <random>

class SymmetricMatrix
{

    /*
     *Case index(A[i][j]) Insert a non-zero element olny if i >= j.
     *Caso index(A[i][j]) Inserir um elemento diferente de zero, somente se i >= j.  
     */
private:
    int *A;
    size_t size;

private:
    int GetIndex(int x, int y)
    {
        return x * (x - 1) / 2 + (y - 1);
    }

    size_t GetSize()
    {
        return size;
    }

    void SetSize(size_t size)
    {
        this->size = size;
    }

    void InitializeArray()
    {
        A = new int[size * (size + 1) / 2];
        if (nullptr == A)
        {
            std::cerr << "New operator failed";
            return;
        }
    }

    int GetRandom()
    {
        std::random_device rng;
        std::mt19937 prng(rng());
        std::uniform_int_distribution<int> dist(3, 9);
        return dist(prng);
    }

public:
    SymmetricMatrix(/* args */);
    SymmetricMatrix(size_t size);

    ~SymmetricMatrix();

    // Use the formula: A[i*(i-1)/2 + j-1]
    void Create();
    void Set(int x, int y, int value);
    int Get(int x, int y);
    void Display();
};

SymmetricMatrix::SymmetricMatrix(/* args */)
{
    SetSize(5);
    InitializeArray();
}
SymmetricMatrix::SymmetricMatrix(size_t size)
{
    SetSize(size);
    InitializeArray();
}

void SymmetricMatrix::Create()
{
    std::cout << "Generating a matrix of size " << GetSize() << "x" << GetSize() << std::endl;
    for (size_t i = 1; i <= GetSize(); i++)
    {
        for (size_t j = 1; j <= GetSize(); j++)
        {
            Set(i, j, GetRandom());
        }
    }
}
void SymmetricMatrix::Set(int x, int y, int value)
{
    if (x >= y)
    {
        A[GetIndex(x, y)] = value;
    }
}
int SymmetricMatrix::Get(int x, int y)
{
    if (x >= y)
    {
        return A[GetIndex(x, y)];
    }
    else
    {
        return A[GetIndex(y, x)];
    }
}
void SymmetricMatrix::Display()
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
SymmetricMatrix::~SymmetricMatrix()
{
    delete[] A;
    A = nullptr;
}

//Symmetric Matrix end

int main(int argc, char const *argv[])
{
    std::random_device rnd;
    size_t size = rnd() % 7 + 2;

    SymmetricMatrix symatrix(size);

    std::cout << "\nLower Tringular Matrix test\nRow major\n";
    symatrix.Create();
    symatrix.Display();
    return 0;
}
