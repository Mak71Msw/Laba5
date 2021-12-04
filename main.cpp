#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;


void ROW(string *AS, int count)
{
    char *pieceStr;

    pieceStr = new char[100];

    for(int i = 0; i < count; i++)
    {

        int k = 0;
        int S = 0;
        strcpy(pieceStr, AS[i].c_str());

        char* piece = strtok(pieceStr, " ");

        while(piece != NULL)
        {
            k++;
            piece = strtok(NULL, " ");
        }
        int Length = AS[i].length();
        for(int j=0; j < Length; j++){
            if(islower(AS[i][j]) == 1)
                S++;
        }
        cout << "Кол-во строчных: " << S << endl;
        cout << "Кол-во прописных: " << Length-S-(k-1) << endl;
        cout << "Длина: " << Length << endl;
        cout << "Количество слов: " << k << endl << endl;
    }

    delete[] pieceStr;
}

void Putin(){
    string* AS;
    string* AS2;
    int count;
    string s;
    char buf[100];

    cout << "Enter strings:\n";
    count = 0;
    AS = nullptr;

    do
    {
        cout << "=> ";
        cin.getline(buf, 80, '\n');
        s = buf;

        if (strcmp(buf, "and") != 0)
        {
            count++;

            AS2 = new string[count];

            for (int i = 0; i < count - 1; i++)
                AS2[i] = AS[i];

            AS2[count - 1] = s;

            if (AS != nullptr)
                delete[] AS;

            AS = AS2;
        }
    } while (strcmp(buf, "and") != 0);

    cout << "\nArray AS:" << ::endl;
    for (int i = 0; i < count; i++)
        cout << "A[" << i << "] = " << AS[i] << ::endl;

    for (int i = 0; i < count - 1; i++)
        for (int j = i; j >= 0; j--)
            if (AS[j] > AS[j + 1])
            {
                s = AS[j];
                AS[j] = AS[j + 1];
                AS[j + 1] = s;
            }

    cout << "\nSorted array AS:\n";
    for (int i = 0; i < count; i++)
        cout << "AS[" << i << "] = " << AS[i] << endl;

    cout << endl;
    cout << "After function:" << endl;
    ROW(AS, count);

    delete[] AS;

}

void IniArray(float *arr,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            *(arr+(rows*i+j))=float(rand()%20-10)/2;
        }
    }
}

void ShowArray(float *arr,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<setw (8)<<setprecision(3)<<*(arr+(rows*i+j))<<' ';
        }
        cout<<endl;
    }
}

void Task(float *arr,int rows,int cols)
{
    int counter = 0;
    for(int i=0;i<rows/2;i++)
    {
        for(int j=0;j<cols/2;j++)
        {
            if(*(arr+(rows*i+j))>0)
                counter++;

        }
    }

    for(int i=rows/2;i<rows;i++)
    {
        for(int j=cols/2;j<cols;j++)
        {
            if(*(arr+(rows*i+j))>0)
                counter++;
        }
    }
    float **positiveptr = new float* [counter];

    int l = 0;
    for(int i=0;i<rows/2;i++)
    {
        for(int j=0 ;j<cols/2;j++)
        {
            if(*(arr+(rows*i+j))>0)
            {
                positiveptr[l]=(arr+(rows*i+j));
                cout << positiveptr[l] << '\t';
                l++;
            }
        }
    }

    for(int i=rows/2;i<rows;i++)
    {
        for(int j=cols/2;j<cols;j++)
        {
            if(*(arr+(rows*i+j))>0)
            {
                positiveptr[l]=(arr+(rows*i+j));
                cout << positiveptr[l] << '\t';
                l++;
            }
        }
    }
    delete [] positiveptr;
    positiveptr=nullptr;
}


void Lukashenko()
{
    srand(time(0));
    cout<<"Введите количество строк:"<<endl;
    int rows;
    cin>>rows;
    cout<<"Введите количество столбцов:"<<endl;
    int cols;
    cin>>cols;
    if (rows<0 or cols<0)
    {
        cout << "Введите положительные" << endl;
        cout<<"Введите количество строк:"<<endl;
        int rows;
        cin>>rows;
        cout<<"Введите количество столбцов:"<<endl;
        int cols;
        cin>>cols;
        cout << endl;
        float *arr = new float[rows * cols];
        IniArray(arr, rows, cols);
        ShowArray(arr, rows, cols);
        cout << endl;
        Task(arr, rows, cols);
        cout << endl;
        delete[] arr;
        arr = nullptr;
    }
    else {
        cout << endl;
        float *arr = new float[rows * cols];
        IniArray(arr, rows, cols);
        ShowArray(arr, rows, cols);
        cout << endl;
        Task(arr, rows, cols);
        cout << endl;
        delete[] arr;
        arr = nullptr;
    }
}

int main()
{
    cout << "Первое задание: " << endl;
    Putin();
    cout << "Второе задание: " << endl;
    Lukashenko();
    return 0;
}
