// METHOD 1
#include <iostream>
#include <ctime>

const int op_rnd = 1 << 20;
const int t_size = 32 * 2; // 2 * (L1 Dcache = 32KB)

int main() {
    for (int n = 1; n <= 8; n++) { // test associativity
        int size = t_size * 1024;
        uint8_t *arr = new uint8_t[size];
        int block_cnt = 1 << n;
        int block_size = size / block_cnt;

        // reset and warmup
        memset(arr, 0, sizeof(uint8_t) * size);

        clock_t start = clock();
        
        for (int i = 0; i < op_rnd; i++) {
            for (int i = 1; i < block_cnt; i += 2) {
                int base = i * block_size;
                for (int j = 0; j < block_size; j++)
                    arr[base + j]++;
            }
        }

        clock_t end = clock();
  
        std::cout << n << " " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

        delete[] arr;
    }
    return 0;
}

// METHOD 2
// #include <iostream>
// #include <ctime>

// const int op_rnd = 1 << 27;
// const int t_size = 32 * 2; // 2 * (L1 Dcache = 32KB)

// int main() {
//     for (int n = 1; n <= 128; n <<= 1) { // t_size KB
//         int size = t_size * 1024;
//         uint8_t *arr = new uint8_t[size];
//         int mask = size - 1;
//         int stride = 512 * 64 / n;

//         // reset and warmup
//         memset(arr, 0, sizeof(uint8_t) * size);

//         clock_t start = clock();
        
//         for (int i = 0; i < op_rnd; i++)
//             arr[(i * stride) & mask]++;

//         clock_t end = clock();

//         std::cout << n << " " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

//         delete[] arr;
//     }
//     return 0;
// }

