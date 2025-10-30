/*Nama: Farid Sani Ahdaputra
NIM: 241401127*/

#include <iostream>
#include <vector>

using namespace std;

//fungsi untuk mencetak papan Sudoku
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) {
                cout << " ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Fungsi untuk memeriksa apakah sebuah angka itu valid di posisi tertentu
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Periksa baris dan kolom
    for (int i = 0; i < 9; i++) {
        // Cek apakah 'num' sudah ada di baris 'row' ATAU di kolom 'col'
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Periksa sub-kotak 3x3
    // Tentukan baris dan kolom awal dari sub-kotak
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    
    // Iterasi melalui sub-kotak 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Cek sel di [baris_awal + i][kolom_awal + j]
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    // Jika lolos semua pengecekan, angka tersebut valid
    return true;
}

// Fungsi utama pemecah Sudoku menggunakan rekursif DFS (Backtracking)
bool solveSudoku(vector<vector<int>>& board) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Langkah ke-1: Cari sel kosong pertama (bernilai 0)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // Langkah ke-2: Basis Rekursi (Base Case)
    // Jika tidak ada lagi sel kosong (isEmpty == false), berarti papan sudah terisi penuh
    if (!isEmpty) {
        return true; // Solusi ditemukan
    }

    // Langkah ke-3: Rekursi dan Backtracking
    // Coba masukkan angka dari 1 sampai 9 ke sel kosong (row, col)
    for (int num = 1; num <= 9; num++) {
        
        // Periksa apakah angka 'num' valid di posisi ini
        if (isValid(board, row, col, num)) {
            
            // "Pilih" (Choose): Letakkan angka di papan
            board[row][col] = num;

            // "Jelajahi" (Explore): Panggil rekursi untuk sisa papan
            if (solveSudoku(board)) {
                return true; // Jika rekursi berhasil, teruskan 'true' ke atas
            }

            // "Batalkan Pilihan" (Unchoose / Backtrack):
            // Jika rekursi kembali 'false', hapus angka (setel kembali ke 0)
            // dan coba angka 'num' berikutnya
            board[row][col] = 0;
        }
    }

    // Jika semua angka (1-9) sudah dicoba dan tidak ada yang berhasil,
    // kembalikan 'false' untuk memicu backtrack di pemanggilan sebelumnya
    return false;
}

int main() {
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    

    cout << "Papan Sudoku awal:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "Papan Sudoku terpecahkan:" << endl;
        printBoard(board);
    } else {
        cout << "Tidak ada solusi yang ditemukan." << endl;
    }

    return 0;
}