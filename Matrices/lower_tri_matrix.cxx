#include <iostream>
#include <random>

//Lower Triangular Matrix start
class LowTriMatrix
{

    /*
     *Case index(A[i][j]) Insert a non-zero element olny if i >= j.
     *Caso index(A[i][j]) Inserir um elemento diferente de zero, somente se i >= j.  
     */
private:
    int *A;
    size_t size;

    size_t GetSize();

    int GetRandom()
    {
        std::random_device rng;
        std::mt19937 prng(rng());
        std::uniform_int_distribution<int> dist(3, 9);
        return dist(prng);
    }
    void SetSize(size_t size);

    int GetColIndex(int x, int y)
    {
        return size * (y - 1) - (y - 2) * (y - 1) / 2 + (x - y);
    }

    int GetRowIndex(int x, int y)
    {
        return x * (x - 1) / 2 + (y - 1);
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

public:
    LowTriMatrix(/* args */);
    LowTriMatrix(size_t size);

    ~LowTriMatrix();

    // Use the formula: A[i*(i-1)/2 + j-1]
    void CreateRow();
    void SetRow(int x, int y, int value);
    int GetRow(int x, int y);
    void DisplayRow();
    // Use the formula: A[size * (y - 1) - (y - 2) * (y - 1) / 2 + (x - y)]
    void CreateCol();
    void SetCol(int x, int y, int value);
    int GetCol(int x, int y);
    void DisplayCol();
};

LowTriMatrix::LowTriMatrix(/* args */)
{
    SetSize(5);
    InitializeArray();
}
LowTriMatrix::LowTriMatrix(size_t size)
{
    SetSize(size);
    InitializeArray();
}

void LowTriMatrix::CreateRow()
{
    std::cout << "Generating a matrix of size " << GetSize() << "x" << GetSize() << std::endl;
    for (size_t i = 1; i <= GetSize(); i++)
    {
        for (size_t j = 1; j <= GetSize(); j++)
        {
            SetRow(i, j, GetRandom());
        }
    }
}
void LowTriMatrix::SetRow(int x, int y, int value)
{
    if (x >= y)
    {
        A[GetRowIndex(x, y)] = value;
    }
}
int LowTriMatrix::GetRow(int x, int y)
{
    if (x >= y)
    {
        return A[GetRowIndex(x, y)];
    }
    else
    {
        return 0;
    }
}
void LowTriMatrix::DisplayRow()
{
    std::cout << std::endl;

    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            std::cout << GetRow(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

void LowTriMatrix::CreateCol()
{
    std::cout << "Generating a matrix of size " << GetSize() << "x" << GetSize() << std::endl;
    for (size_t i = 1; i <= GetSize(); i++)
    {
        for (size_t j = 1; j <= GetSize(); j++)
        {
            SetCol(i, j, GetRandom());
        }
    }
}

void LowTriMatrix::SetCol(int x, int y, int value)
{
    if (x >= y)
    {
        A[GetColIndex(x, y)] = value;
    }
}

int LowTriMatrix::GetCol(int x, int y)
{
    if (x >= y)
    {
        return A[GetColIndex(x, y)];
    }
    else
    {
        return 0;
    }
}

void LowTriMatrix::DisplayCol()
{
    std::cout << std::endl;

    for (size_t x = 1; x <= GetSize(); x++)
    {
        for (size_t y = 1; y <= GetSize(); y++)
        {
            std::cout << GetCol(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

size_t LowTriMatrix::GetSize()
{
    return size;
}
void LowTriMatrix::SetSize(size_t size)
{
    this->size = size;
}

LowTriMatrix::~LowTriMatrix()
{
    delete[] A;
    A = nullptr;
}

//Lower Triangular Matrix end

int main(int argc, char const *argv[])
{
    std::random_device rnd;
    size_t size = rnd() % 7 + 2;

    LowTriMatrix lmatrix(size);

    std::cout << "\nLower Tringular Matrix test\nRow major\n";
    lmatrix.CreateRow();
    lmatrix.DisplayRow();
    std::cout << "\nLower Tringular Matrix test\nRow major\n";
    lmatrix.CreateCol();
    lmatrix.DisplayCol();
    return 0;
}
