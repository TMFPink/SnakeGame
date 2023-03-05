/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iomanip>
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    int Diem;
};
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Nhap(SinhVien &A)
{
    cout<<"\n";
    cout << "nhap MSSV: ";cin >> A.MASV;
    cout << "nhap ten: ";
    cin.ignore();
    cin.getline(A.HoTen,99);
    cout << "nhap ngay thang nam sinh: ";cin >> A.NgaySinh;
    cout << "nhap diem: ";cin >> A.Diem;
}
void Xuat(SinhVien A)
{
    cout << A.MASV<<" || "<< A.HoTen<<" || "<< A.Diem<<endl;
 
}
void NhapDSSV(SinhVien DS[], int n)
{
    for(int i=0;i<n;i++)
    {
        Nhap(DS[i]);
    }
}
void XuatDSSV(SinhVien DS[],int n)
{
    for(int i=0;i<n;i++)
    {
        Xuat(DS[i]);
    }
}
void sapxep(SinhVien DS[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        if(DS[i].Diem<DS[j].Diem)
        {
            swap(DS[i],DS[j]);
        }
    }
}
//###INSERT CODE HERE -

int main() {
    SinhVien DS[100];
    int n;
    cout << "nhập số lượng sinh viên: ";cin >> n;
    NhapDSSV(DS,n);
    // sapxep(DS,n);
    XuatDSSV(DS,n);
    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------------------

//XE

// struct xe
// {
//     char so_xe;
//     float so_km;
//     int hang_sx;
//     bool dong_co;
// };
// void nhap1xe(xe &a)
// {
//     char dongco;
//     cout<<"nhap so xe: ";cin>>a.so_xe;cin.ignore();
//     cout<<"nhap so km di duoc: ";cin>>a.so_km;
//     cout<<"nhap so cua hang sx (0-Honda 1-Yamaha 2-Vespa 3-Suzuki): ";cin>>a.hang_sx;  //0-honda 1-yamaha 2-vespa 3-suzuki
//     cout<<"nhap kieu dong co xang (Y/N): ";cin>>dongco; // true-xang false-xang pha nhot
//     if(dongco=='Y' || dongco=='y')
//     {
//         a.dong_co=true;
//     }
//     else
//         a.dong_co=false;
//     cin.ignore();
// }
// void xuat(xe a)
// {
    
//     cout<<"so xe: "<<a.so_xe<<endl;
//     cout<<"so km di duoc: "<<a.so_km<<endl;
//     if(a.hang_sx==0)
//     {
//         cout<<"ten hang sx: Honda";
//     }
//     else if(a.hang_sx==1)
//     {
//         cout<<"ten hang sx: Yamaha";
//     }
//     else if(a.hang_sx==2)
//     {
//         cout<<"ten hang sx: Vespa";
//     }
//     else if(a.hang_sx==3)
//     {
//         cout<<"ten hang sx: Suzuki";
//     }        
//     cout<<endl;
//     if(a.dong_co==true)
//     {
//         cout<<"dong co: dung xang";
//     }
//     else if(a.dong_co==false)
//     {
//         cout<<"dong co: dung xang pha nhot";
//     }
//     cout<<endl;
// }
// void nhapNxe(xe ds[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         nhap1xe(ds[i]);
//         cout<<endl;
//     }

// }
// void xuatNxe(xe ds[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         xuat(ds[i]);
//         cout<<endl;
//     }

// }
// void tim_xe(xe a[],int n)
// {
//     int x;
//     bool y;
//     cout<<"nhap hang sx can tim (0-Honda 1-Yamaha 2-Vespa 3-Suzuki):";cin>>x;
//     cout<<"nhap dong co can tim: ";cin>>y;
//     cout<<endl;
//     for(int i=0;i<n;i++)
//     {
//         if(a[i].hang_sx==x)
//         {
//             if(a[i].dong_co==y)
//             {
//                 xuat(a[i]);
//             }
//         }
//     }
// }
// int main()
// {
//     xe ds[100];
//     xe A;
//     int n;
    
//     cout<<"nhap so luong xe: ";cin>>n;
//     cout<<endl;
//     nhapNxe(ds,n);
//     xuatNxe(ds,n);
//     // tim_xe(ds,n);


//     return 0;
// }

// -----------------------------------------------------------------------------------------------------------------------------------------------------

//PHANSO


// struct phanso
// {
//     int tu,mau;
// };
// int ucln(phanso a)
// {
//     int z;
//     int temp;
//     if(a.tu>a.mau)
//     {
//         z=a.mau;
//     }
//     else
//         z=a.tu;
//     for(int i=1;i<=z;i++)
//     {
//         if(a.tu%i==0)
//         {
//             for(int j=1;j<=z;j++)
//             {
//                 if(a.mau%j==0)
//                 {
//                     if(i==j)
//                     {
//                         temp=i;
//                     }
//                 }
//             }
//         }
//     }
//     return temp;
// }
// void rutgonps(phanso &a)
// {
//     int temp = ucln(a);
//     a.tu/=temp;
//     a.mau/=temp;
// }
// void nhap_ps(phanso &a)
// {
//     cout<<endl;
//     cout<<"nhap tu so: ";cin>>a.tu;
//     cout<<"nhap mau so: ";cin>>a.mau;
    
// }
// void xuat_ps(phanso a)
// {
//     rutgonps(a);
//     if(a.mau==1)
//     {
//         cout<<a.tu;
//     }
//     else
//         cout<<a.tu<<"/"<<a.mau;
// }


// void nhapNps(phanso a[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
        
//         nhap_ps(a[i]);
//     }
// }
// void xuatNps(phanso a[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         xuat_ps(a[i]);
//         cout<<endl;
//     }
    
// }
// int sosanh_ps(phanso a, phanso b)
// {
//     rutgonps(a);
//     rutgonps(b);
    
//     if(a.tu*b.mau-b.tu*a.mau>0)
//     {
//         return 1;
//     }                     //return 1 nếu a>b và 0 nếu b>a;
//     else
//         return 0;
// }
// void swap(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void sortPS(phanso arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(sosanh_ps(arr[i],arr[j])==1)
//             {
//                 swap(arr[i],arr[j]);
//             }
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"nhap so luong phan so: ";cin>>n;
//     phanso a;
//     phanso arr[100];
//     nhapNps(arr,n);
//     sortPS(arr,n);
//     xuatNps(arr,n);
//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------

// struct phim
// {
//     char tenphim[50];
//     float doanhthu;
//     int theloai; /// 0-hinh su || 1-tinh cam || 2-hai
//     int namsx;
//     bool phimvn; //true-VN || false-nuoc ngoai
// };
// void nhap_phim(phim &a)
// {
//     cout<<endl;
//     char pvn;
//     cout<<"nhap ten phim: ";
//     cin.ignore();
//     cin.getline(a.tenphim,40);
//     cout<<"nhap doanh thu: ";cin>>a.doanhthu;
//     cout<<"nhap the loai (0-hinh su || 1-tinh cam || 2-hai): ";cin>>a.theloai;
//     cout<<"nhap nam san xuat: ";cin>>a.namsx;
//     cout<<"phim VietNam (Y/N): ";cin>>pvn;
//     if(pvn=='y' || pvn == 'Y')
//     {
//         a.phimvn=true;
//     }
//     else   
//         a.phimvn=false;
    
// }
// void xuat_phim(phim a)
// {
//     cout<<"ten phim: "<<a.tenphim<<endl;;
//     cout<<"doanh thu: "<<a.doanhthu<<endl;
//     if(a.theloai==0)
//     {
//         cout<<"the loai: hinh su";
//     }
//     if(a.theloai==1)
//     {
//         cout<<"the loai: tinh cam";
//     }
//     if(a.theloai==2)
//     {
//         cout<<"the loai: hai";
//     }
//     cout<<endl;
//     cout<<"nam san xuat: "<<a.namsx<<endl;
//     if(a.phimvn==true)
//     {
//         cout<<"phim VN";
//     }
//     else   
//         cout<<"phim nuoc ngoai";
//     cout<<endl;
// }
// void nhapNphim(phim a[],int n)
// {
    
//     for(int i=0;i<n;i++)
//     {
//         nhap_phim(a[i]);
        
//     }
// }
// void xuatNphim(phim a[],int n)
// {
    
//     for(int i=0;i<n;i++)
//     {
//         xuat_phim(a[i]);
//         cout<<endl;
//     }
// }
// void sortPhim(phim a[],int n)
// {
//     int temp;
//     cout<<"nhap the loai phim muon tim (0-hinh su || 1-tinh cam || 2-hai): ";cin>>temp;
//     for(int i = 0; i < n; i++)
//     {
//         if(a[i].theloai==temp)
//         {
//             cout<<" "<<endl;
//             xuat_phim(a[i]);
//         }
//     }
//     cout<<endl;
// }
// void sum_dt_vn(phim a[],int n)
// {
//     float sum=0;
//     for(int i=0;i<n;i++)
//     {
//         if(a[i].phimvn==true)
//         {
//             sum+=a[i].doanhthu;
//         }
//     }
//     cout<<"tong doanh thu phim VN = "<<sum;
// }
// void findphim(phim a[],int n)
// {
//     cout<<endl;
//     char temp[100];
//     cout<<"nhap ten phim can tim: ";
//     cin.ignore();
//     cin.getline(temp,100);
//     for(int i=0;i<n;i++)
//     {
//         if(a[i].tenphim==temp)
//         {
//             xuat_phim(a[i]);
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"nhap so luong phim: ";cin>>n;
//     phim a;
//     phim arr[100];
//     nhapNphim(arr,n);
//     findphim(arr,n);
//     return 0;
// }

// ----------------------------------------------------------------------------------------------------------------------------------------------------

//DIEM

// struct point
// {
//     int x;
//     int y;
// };
// struct triangle
// {
//     point p1,p2,p3;
// };
// void inputP(point &a)
// {
    
//     cout<<"\nnhap x: ";cin>>a.x;
//     cout<<"nhap y: ";cin>>a.y;
// }

// void outputP(point a)
// {
//     cout<<"("<<a.x<<","<<a.y<<")"<<endl;
// }
// void inputnP(point a[],int &n)
// {
//     cout<<"nhap so luong diem: ";cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         inputP(a[i]);
//     }
// }
// void inputTri(triangle &b)
// {
//     cout<<"diem thu 1: ";
//     inputP(b.p1);
//     cout<<"diem thu 2: ";
//     inputP(b.p2);
//     cout<<"diem thu 3: ";
//     inputP(b.p3);
// }
// int length(point a,point b)
// {
//     int Q=a.x;
//     int W=a.y;
//     int E=b.x;
//     int R=b.y;

//     return sqrt(((Q-E)*(Q-E)+(W-R)*(W-R)));
// }
// void CTri(triangle b)
// {
//     int C=0;
//     C+=length(b.p1,b.p2);
//     C+=length(b.p2,b.p3);
//     C+=length(b.p3,b.p1);
//     cout<<length(b.p1,b.p2)<<endl;
//     cout<<length(b.p2,b.p3)<<endl;
//     cout<<length(b.p3,b.p1);   
//     // cout<<"chu vi tam giac la: "<<C;
// }
// void outputnP(point a[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         outputP(a[i]);
//     }
// }

// int main()
// {
//     point I;
//     int n;
//     triangle T;
//     inputTri(T);
//     CTri(T);
//     return 0;
// }