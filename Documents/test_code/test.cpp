#include <iostream>
using namespace std;

void input2dArr(int mang2d[][100], int &cot, int &dong )
{
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            cout<<"nhap phan tu vi tri ["<<i<<"]["<<j<<"]: ";
            cin>>mang2d[i][j];
        }
    }
}
void output2dArr(int mang2d[][100], int cot, int dong)
{
    for(int i=0; i<dong;i++)
    {
        for(int j=0; j<cot; j++)
        {
            cout<<"["<<mang2d[i][j]<<"] ";
        }
        cout<<" "<<endl;
    }
}
void sumarray(int mang1[][100], int cot,int dong,int mang2[][100])
{
    for(int i=0; i<dong;i++)
    {
        for(int j=0; j<cot; j++)
        {
            mang1[i][j] += mang2[i][j];
        }
        
    }
}
void ticharray(int mang1[][100], int cot,int dong,int mang2[][100])
{
    for(int i=0; i<dong;i++)
    {
        for(int j=0; j<cot; j++)
        {
            mang1[i][j] *= mang2[i][j];
        }
        
    }
}
void timx(int mang[][100],int cot, int dong)
{
    int x;
    cout<<"nhap x: ";cin>>x;
    for(int i=0; i<dong;i++)
    {
        for(int j=0; j<cot; j++)
        {
            if(mang[i][j]==x)
                cout<<"tim thay x o vi tri ["<<i<<"]["<<j<<"]"<<endl;
        }
        
    }
}
int main()
{
    int mang1[100][100];
    int mang2[100][100];
    int cot,dong;
    cout<<"nhap so luong dong: ";cin>>dong;
    cout<<"nhap so luong cot: ";cin>>cot;
    input2dArr(mang1, cot, dong);
    output2dArr(mang1, cot, dong);
    
    return 0;
}