#include <iostream>
#include <string.h>
#include <ctime>

const int op_rnd = 1 << 27;
const int t_size = 64; // 64KB
int main() {
    for (int stride = 1; stride <= 256; stride <<= 1) { // stride (B)
        int size = t_size * 1024;
        uint8_t *arr = new uint8_t[size];
        int mask = size - 1;

        // reset and warmup
        memset(arr, 0, sizeof(uint8_t) * size);

        clock_t start = clock();
        
        for (int i = 0; i < op_rnd; i++)
            arr[(i * stride) & mask]++;

        clock_t end = clock();

        std::cout << stride << " " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

        delete[] arr;
    }
    return 0;
}