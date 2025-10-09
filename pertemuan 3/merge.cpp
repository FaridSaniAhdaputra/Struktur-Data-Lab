#include <iostream>  //library untuk input output bahasa c++
#include <vector>    //library untuk menggunakan vector
using namespace std; // agar tidak perlu menulis std:: sebelum fungsi standar

void merge(vector<int>& arr, int left, int mid, int right) { //fungsi untuk menggabungkan dua subarray yang sudah diurutkan
   
    int n1 = mid - left + 1;  // ukuran subarray kiri
    int n2 = right - mid;     // ukuran subarray kanan

    vector<int> L(n1), R(n2); // membuat dua vektor sementara untuk menyimpan elemen subarray kiri dan kanan

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];     // menyalin data ke subarray kiri
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // menyalin data ke subarray kanan


    int i = 0;    // indeks awal subarray kiri
    int j = 0;    // indeks awal subarray kanan
    int k = left; // indeks awal subarray gabungan / array utama


    while (i < n1 && j < n2) { // menggabungkan dua bagian yang sudah diurutkan 
        if (L[i] <= R[j]) {    // jika elemen di subarray kiri lebih kecil atau sama dengan elemen di subarray kanan
            arr[k] = L[i];     // masukkan elemen dari subarray kiri ke array utama
            i++;               //increment indeks subarray kiri 
        } else {               // jika elemen di subarray kanan lebih kecil maka
            arr[k] = R[j];     // masukkan elemen dari subarray kanan ke array utama
            j++;               //increment indeks subarray kanan
        }
        k++;                   //increment indeks array utama
    }


    while (i < n1) {   // menyalin elemen yang tersisa dari subarray kiri jika ada
        arr[k] = L[i]; // masukkan elemen dari subarray kiri ke array utama
        i++;           //increment indeks subarray kiri
        k++;           //increment indeks array utama
    }


    while (j < n2) {   // menyalin elemen yang tersisa dari subarray kanan jika ada
        arr[k] = R[j]; // masukkan elemen dari subarray kanan ke array utama
        j++;           //increment indeks subarray kanan
        k++;           //increment indeks array utama
    }
}

// Fungsi utama merge sort
void mergeSort(vector<int>& arr, int left, int right) {      // fungsi untuk mengurutkan array menggunakan algoritma mergesort
   
    if (left >= right)     
        return;       // basis rekursi: jika array memiliki satu elemen atau kosong 

    int mid = left + (right - left) / 2; // mencari titik tengah array

    mergeSort(arr, left, mid);         // mengurutkan bagian kiri array
    mergeSort(arr, mid + 1, right);    // mengurutkan bagian kanan array
   
    merge(arr, left, mid, right);       // menggabungkan dua bagian yang sudah diurutkan
}


void printArray(const vector<int>& arr) {   // fungsi untuk mencetak elemen-elemen array
    for (int i = 0; i < arr.size(); i++) {  // iterasi melalui setiap elemen array
        cout << arr[i] << " ";              // mencetak elemen diikuti oleh spasi
    }
    cout << endl;                           
}

int main() {            // fungsi utama program
    int n;              // deklarasi variabel untuk menyimpan jumlah elemen data
    cout << "Masukkan jumlah elemen data: ";       // meminta pengguna memasukkan jumlah elemen data
    cin >> n;                                      // membaca jumlah elemen data dari input pengguna
    
    vector<int> data(n);                            // membuat vektor untuk menyimpan elemen-elemen data
    cout << "Masukkan elemen-elemen data: ";        // meminta pengguna memasukkan elemen-elemen data
    for (int i = 0; i < n; i++) {                   // iterasi untuk membaca setiap elemen data
        cin >> data[i];                             // membaca elemen data dari input pengguna dan menyimpannya dalam vektor
    }
   
    cout << "Array sebelum diurutkan: ";            // menampilkan array sebelum diurutkan
    printArray(data);                               // mencetak elemen-elemen array sebelum diurutkan 
   
    mergeSort(data, 0, n - 1);                      // memanggil fungsi mergeSort untuk mengurutkan array   
   
    cout << "Array setelah diurutkan: ";            // menampilkan array setelah diurutkan
    printArray(data);                               // mencetak elemen-elemen array setelah diurutkan
   
    return 0;                                       //akhir program /selesai

}