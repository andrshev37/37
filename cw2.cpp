
#include <iostream>
using namespace std;

void deleteMatrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

int** createMatrix(int n, int m)
{
    int** matrix;

    matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    return matrix;
}

int** inputMatrix(int n, int m)
{
    int** matrix = createMatrix(n, m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            cout << "Element [" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*int** addMatrices(int** matrix1, int** matrix2, int n, int m)
{
    int** resultMatrix = createMatrix(n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];

    return resultMatrix;
}*/
int** Mxlnth(int** matr,int n) {
    int** matrix;

    matrix = new int* [n];
    int last=0;//0~lover then 0 1~more than 0
    if (matr[0][0] >= 0) { last = 1; }
    int j=0,k = 0;
    matrix[j] = new int[n];
    for (int i = 1; i < n; i++) {
        if ((last && matr[0][i]<0)||(!last && matr[0][i]>0)) {
            matrix[j][k]=matr[0][i];
            k++;
        }else{
            j++;
            k = 0;
            matrix[j] = new int[n];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {

        }
            
        
    }
    deleteMatrix(matrix, n);
}

void Sidla( int n, int m) {
    int** matr=inputMatrix(n,m);
    //n=rows m=cols
    //min/max in row
    int* lovarr = new int [n];
    int* hiarr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int min = matr[i][0];
        int max = matr[i][0];
        for (int j = 0; j < m; j++) {
            if (min > matr[i][j]) {
                min = matr[i][j];
                lovarr[i] = j;
            }
            if (max < matr[i][j]) {
                max = matr[i][j];
                hiarr[i] = j;
            }
        }  
        
        
            
    }
    //min/max in col
    int* lovcol = new int[m];
    int* hicol = new int[m];
    for (int i = 0; i < n; i++)
    {
        int min = matr[i][0];
        int max = matr[i][0];
        for (int j = 0; j < m; j++) {
            if (min > matr[j][i]) {
                min = matr[j][i];
                
            }
            if (max < matr[j][i]) {
                max = matr[j][i];
                
            }
        }
        lovcol[i] = min;
        hicol[i] = max;
        

    }
    for (int i = 0; i < n; i++) {
        if (matr[i][hiarr[i]] == lovcol[hiarr[i]]) {
            cout << matr[i][hiarr[i]]<<"i|j=="<<i<<"|"<< hiarr[i] <<endl;
        }
        if (matr[i][lovarr[i]] == hicol[lovarr[i]]) {
            cout << matr[i][lovarr[i]] << "i|j==" << i << "|" << lovarr[i] << endl;
        }
    }

    delete[] hiarr;
    delete[] lovarr;
    delete[] hicol;
    delete[] lovcol;
}

void First()
{
    int** matrix1;
    int n = 1, m = 0;
    cout << "m=";
    cin >> m;
    matrix1 = inputMatrix(n, m);
    Mxlnth(matrix1, n);
    deleteMatrix(matrix1, n);
}
void Thirsd(int l, int n) {
    int** matr = inputMatrix(1, l);
    int skl = l / n;
    int** minimatr = createMatrix(skl, n);
    for (int i = 0; i < skl; i++) {
        int t = i * n;
        for (int j = 0; j < n; j++) {
            minimatr[i][j] = matr[0][t + j];
        }

    }
    delete[] matr;
    deleteMatrix(minimatr, skl);
}
int main()
{
    First();
    cout << "n=,m=";
    int k, m;
    cin >> k >> m;
    Sidla(k, m);
    cout << "l=,n=";
    int l=0, n=0;
    cin >> l >> n;
    Thirsd(l, n);
    system("pause");
    return 0;
}