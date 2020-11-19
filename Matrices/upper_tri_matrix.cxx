#include <iostream>
#include <random>

//Upper Triangular Matrix start
class UpperTriMatrix
{

    /*
     *En: Case index(A[i][j]) Insert a non-zero element olny if i <= j.

     *Pt: Caso index(A[i][j]) Inserir um elemento diferente de zero, somente se i <= j.  
     */
private:
    int *A;
    size_t size;
    int GetRandom()
    {
        std::random_device rng;
        std::mt19937 prng(rng());
        std::uniform_int_distribution<int> dist(3, 9);
        return dist(prng);
    }
    int GetRowIndex(int x, int y)
    {
        return (x - 1) * size - (x - 2) * (x - 1) / 2 + (y - x);
    }

    int GetColIndex(int x, int y)
    {
        return y * (y - 1) / 2 + (x - 1);
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
    UpperTriMatrix(/* args */);
    UpperTriMatrix(size_t size);

    ~UpperTriMatrix();

    // Use the formula: A[(x - 1) * size - (x - 2) * (x - 1) / 2 + (y - x)]
    void CreateRow();
    void SetRow(int x, int y, int value);
    int GetRow(int x, int y);
    void DisplayRow();

    // Use the formula: A[y*(y-1)/2 + (x-1)]
    void CreateCol();
    void SetCol(int x, int y, int value);
    int GetCol(int x, int y);
    void DisplayCol();
    size_t GetSize();
    void SetSize(size_t size);
};

UpperTriMatrix::UpperTriMatrix(/* args */)
{
    SetSize(5);
    InitializeArray();
}
UpperTriMatrix::UpperTriMatrix(size_t size)
{
    SetSize(size);
    InitializeArray();
}

void UpperTriMatrix::CreateRow()
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
void UpperTriMatrix::SetRow(int x, int y, int value)
{
    if (x <= y)
    {
        A[GetRowIndex(x, y)] = value;
    }
}
int UpperTriMatrix::GetRow(int x, int y)
{
    if (x <= y)
    {
        return A[GetRowIndex(x, y)];
    }
    else
    {
        return 0;
    }
}
void UpperTriMatrix::DisplayRow()
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

void UpperTriMatrix::CreateCol()
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
void UpperTriMatrix::SetCol(int x, int y, int value)
{
    if (x <= y)
    {
        A[GetColIndex(x, y)] = value;
    }
}
int UpperTriMatrix::GetCol(int x, int y)
{
    if (x <= y)
    {
        return A[GetColIndex(x, y)];
    }
    else
    {
        return 0;
    }
}
void UpperTriMatrix::DisplayCol()
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
size_t GetSize();

size_t UpperTriMatrix::GetSize()
{
    return size;
}
void UpperTriMatrix::SetSize(size_t size)
{
    this->size = size;
}

UpperTriMatrix::~UpperTriMatrix()
{
    delete[] A;
    A = nullptr;
} //Upper Triangular Matrix end

int main(void)
{
    std::random_device rnd;
    size_t size = rnd() % 7 + 2;

    UpperTriMatrix upmatrix(size);

    std::cout << "\nUpper Tringular Matrix test\nRow major\n";
    upmatrix.CreateRow();
    upmatrix.DisplayRow();
    std::cout << "\nUpper Tringular Matrix test\nColumn major\n";
    upmatrix.CreateCol();
    upmatrix.DisplayCol();
    return 0;
}
