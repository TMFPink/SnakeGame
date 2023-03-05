#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int so_sach = 0;
    char dau_sach[100][250]; //250: do dai ten cua sach; 10: so sach
    for(int i=0; i<100; i++){
        cout << "Nhap sach: ";
        so_sach +=1;
        cin.getline(dau_sach[i],100);
        if(dau_sach[i][0]=='.'){
            break;
        }
    }
    char key[10];
    cout << "Nhap tu can tim: ";
    cin >> key;
    int length_key = strlen(key);
    int da_xuat_hien = false;
    for(int i=0; i<so_sach; i++){
        int do_dai_cua_moi_cuon_sach = strlen(dau_sach[i]);
        for(int k=0; k<do_dai_cua_moi_cuon_sach; k++){
            int status = true;
            if(dau_sach[i][k] == key[0]){
                int o = k;
                for(int u=1; u<length_key; u++){
                    if(key[u]==dau_sach[i][o+1]){
                        o+=1;
                    }
                    if(key[u]!=dau_sach[i][o+1]){
                        status = false;
                        break;
                    } 
                }
                int length_of_book_words = strlen(dau_sach[i]);
                if(status == false){
                    da_xuat_hien=true;

                    for(int y = length_of_book_words; y>k; y--){
                        dau_sach[i][y] = dau_sach[i][y-1];
                    }
                    dau_sach[i][k] = '[';
                    for(int t = length_of_book_words+1; t>(k+(length_key+1)); t--){
                        dau_sach[i][t] = dau_sach[i][t-1];
                    }
                    dau_sach[i][k+(length_key+1)] = ']';
                    cout << dau_sach[i] << endl;
                } 
            }
            if(da_xuat_hien==true){
                break;
            }
        }
    }
    return 0;
}