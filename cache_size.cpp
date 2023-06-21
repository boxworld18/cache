#include <iostream>
#include <ctime>

const int op_rnd = 1 << 27;
const int stride = 64;
int main() {
    for (int t_size = 1; t_size <= 2048; t_size <<= 1) { // t_size KB
        int size = t_size * 1024;
        uint8_t *arr = new uint8_t[size];
        int mask = size - 1;

        // reset and warmup
        memset(arr, 0, sizeof(uint8_t) * size);

        clock_t start = clock();
        
        for (int i = 0; i < op_rnd; i++)
            arr[(i * stride) & mask]++;

        clock_t end = clock();

        std::cout << t_size << " " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

        delete[] arr;
    }
    return 0;
}