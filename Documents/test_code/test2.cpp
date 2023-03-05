#include <iostream>
#include <cstring>
using namespace std;

// void ky_tu_xuat_hien_nhieu_nhat(char chuoi[100]){
//     int dem = 0;
//     int max = dem;
//     char max_char ;
//     for(int i=0; i<strlen(chuoi); i++){
//         for(int j=0; j<strlen(chuoi); j++){
//             if(chuoi[j]==chuoi[i]){
//                 dem++;
//             }
//         }
//         if(dem >= max){
//             max = dem;
//             max_char = chuoi[i];
//         }
//         dem = 0;
//     }
//     cout << max_char;
// }

// int main()
// {
//    char chuoi[100];
//    cin.getline(chuoi,100);
//    ky_tu_xuat_hien_nhieu_nhat(chuoi);
//     return 0;
// }

int temp(int n,int &max)
{
    int m;
    if(n==0)
    {
        return max;
    }
    else
    {
        m = n%10;
        if(m>max)
        {
            max=m;
            return temp(n/10,max);
        }    
        else
            return temp(n/10,max);
    }
}
int main()
{
    int max=0;
    int n;
    cout<<"nhap n: ";cin>>n;
    cout<<temp(n,max);

    return 0;
}