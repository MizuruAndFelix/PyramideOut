#include <iostream>
using namespace std;



void PrintArray(int* arr, const int arrSize)
{
    cout << "Source array:";

    for (int i = 0; i < arrSize; i++)
    {
        cout << " ";
        cout << arr[i];
    };
    cout << endl;
};


int PyramideLevelRN(int* levelOfpyramide, const int countLevelsOfPyramide, int i)
{
    for (int j = 0; j < countLevelsOfPyramide; j++)
    {
        if (i < levelOfpyramide[j])
        {
            return j + 1;
        }
    };
    return 1;
};


void PrintPyramide(int* arr, const int arrSize)
{
    cout << "Pyramyde:\n";
    cout << " 0 Root: " << arr[0] << "\n";

    int countLevelsOfPyramid = log2(arrSize) + 1;
    int* levelOfpyramid = new int[countLevelsOfPyramid];

    
    for (int i = 0; i < countLevelsOfPyramid; i++)
    {
        levelOfpyramid[i] = pow(2, i);
    }


    for (int i = 0; i < arrSize; i++)
    {
        int indexLeft = 2 * i + 1;
        if (indexLeft < arrSize)
        {
            cout << " " << PyramideLevelRN(levelOfpyramid, countLevelsOfPyramid, i) << " Left(" << arr[i] << ")" << " " << arr[2 * i + 1] << endl;
        }

        int indexRight = 2 * i + 2;
        if (indexRight < arrSize)
        {
            cout << " " << PyramideLevelRN(levelOfpyramid, countLevelsOfPyramid, i) << " Right(" << arr[i] << ")" << " " << arr[2 * i + 2] << endl;
        }
    }
    cout << endl;

    delete[] levelOfpyramid;
    levelOfpyramid = nullptr;
};


int main()
{
    setlocale(LC_ALL, "Russian");


    srand(time(nullptr)); // start num

    int arrSize = 3 + rand() % 20;
    //int arr[] =
    //{1, 3, 6, 5, 9, 8};
    //{94, 67, 18, 44, 55, 12, 6, 42};
    //{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    

    //int arrSize = std::size(arr);



    //creaate dyn arr
    int* arr = new int[arrSize] {};


    for (int i = 0; i < arrSize; i++)
    {// fill random nums
        arr[i] = rand() % 50;
    }



    PrintArray(arr, arrSize);
    PrintPyramide(arr, arrSize);
    delete[] arr; 
    arr = nullptr;
}