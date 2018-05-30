#include <stdio.h>

int user_input_amount(){

}

int user_input_n(int arr[], int amount){
    if (amount>0){
        int n;
        printf ("Masukan nilai n = ");
        scanf ("%d",&n);
        user_input_n(arr, amount-1);
    }
}

int sequential(int arr[], int n, int amount, int indeks){
    if (arr[indeks] == n){
        return indeks+1;
    }

    else if (indeks == amount){
        return -1;
    }

    else{
        return sequential(arr, n, amount, indeks+1);
    }
}

void main(){
    int amount = 5, n = 9;
    int arr[amount];
    user_input_n(arr, amount);
    int hasil = sequential(arr, n, amount, 0);

    if (hasil == -1){
        puts ("Data tidak ditemukan");
    }
    else{
        printf ("Data di temukan di index %d\n",hasil);
    }
}
