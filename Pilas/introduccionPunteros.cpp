#include <iostream>//dependen de lo  que estemos trabajando


using namespace std;


int main(){
    int num , numero2 ,*puntNum,*pun2;
    num = 30;
    numero2 = 10;
    pun2 = &numero2;
    puntNum = &num;// apunta a la direccion de memoria
    cout<<puntNum<<endl; // imprimame el dato que esta en ese espacio de memoria
    cout<<*puntNum;
    return 0;
}
