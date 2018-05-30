#include <stdio.h>

int user_input_n_jumlah(){
    int n_jumlah;
    printf ("Masukan jumlah n: ");
    scanf ("%d",&n_jumlah);
    if (n_jumlah<1){
        puts ("Jumlah tidak dapat lebih kecil dari 1");
        n_jumlah = user_input_n_jumlah();
    }
    return n_jumlah;
}
// untuk memasukan nilai kedalam array
void user_input_n(int arr[], int n_jumlah){
    if (n_jumlah>0){
        int n;
        --n_jumlah;
        printf ("Masukan nilai: ");
        scanf ("%d",&n);
        arr[n_jumlah] = n;
        user_input_n(arr, n_jumlah);
    }
}
// tidak mereturn value dari array karena di c jika menggunakan array sebagai argument
// maka function akan menggunakan variable asli dari array di address yang sama


// untuk mengkomparasi nilai dari 2 nilai array di lokasi [indeks] dan [indeks-1], jika array[indeks] lebih kecil dari array[indeks-1] maka valuenya akan ditukar
int array_compare(int arr[], int indeks){
    if (arr[indeks]<arr[indeks-1] && indeks>0){ // < untuk kecil ke besar dan > untuk besar ke kecil
        int tmp = arr[indeks];
        arr[indeks] = arr[indeks-1];
        arr[indeks-1] = tmp;
        return 1;
    }
    return 0;
}

// untuk melihat apakah suatu value sudah berada pada tempatnya
void array_sort(int arr[], int indeks){
    int status = array_compare(arr, indeks+1);
    if (status == 1){ // satus == 1 bearti value belum berada pada tempatnya
        array_sort(arr, indeks-1);
    }
}

void insertion_sort(int arr[], int indeks, int n_jumlah){
    if (indeks<n_jumlah){
        array_sort(arr, indeks-1);
        ++indeks;
        insertion_sort(arr, indeks, n_jumlah);
    }
}

void main(){
    int n_jumlah = user_input_n_jumlah();
    int arr[n_jumlah], indeks = 0;
    user_input_n(arr, n_jumlah);
    insertion_sort(arr, indeks, n_jumlah);

    for (int i=0; i<n_jumlah; ++i){
        printf ("%d ",arr[i]);
    }
    puts ("");
}