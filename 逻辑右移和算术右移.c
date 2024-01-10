#include <stdio.h>

/*
* 逻辑右移和算术右移的区别在于对有符合数的处理。
* 逻辑右移对数据只进行向右移位，高位补0。
* 算术右移对数据进行移位，高位是补符号位，正数补0，负数补1。
* 如果要把一个数进行逻辑右移，直接将该数定义成无符号数，因为无符号数的右移就是逻辑右移。
* 有符合逻辑右移时还和数据本身字节数有关。
*
* 5的二进制：0000 0000 0000 0101
* 取反加1即是-5的二进制：1111 1111 1111 1011
* -5逻辑右移1位，高位补0，得到：0 1111 1111 1111 101 即32765。
* -5算术右移1位，高位补1，得到：1 1111 1111 1111 101，对应取反加1得到：1 0000 0000 0000 011，即-3。
*/
#include <stdio.h>

// 逻辑右移
unsigned int logicalRightShift(unsigned int num, int shift) {
    return num >> shift;
}

// 算术右移
int arithmeticRightShift(int num, int shift) {
    return num >> shift;
}

int main() {
    printf("test num > 0\n");
    // 逻辑右移测试用例
    unsigned int logicalNum = 1000;  
    int logicalShift = 4;
    unsigned int logicalResult; 
    logicalResult = logicalRightShift(logicalNum, logicalShift);
    printf("Logical Right Shift: %d\n", logicalResult);  //62

    // 算术右移测试用例
    int arithmeticNum = 1000;  
    int arithmeticShift = 4;
    int arithmeticResult;
    arithmeticResult = arithmeticRightShift(arithmeticNum, arithmeticShift);
    printf("Arithmetic Right Shift: %d\n", arithmeticResult);  //62

    printf("test num < 0\n");
    // 逻辑右移测试用例
    logicalNum = -5;  
    logicalShift = 1;
    logicalResult = logicalRightShift(logicalNum, logicalShift);
    printf("Logical Right Shift: %d\n", logicalResult);  //2147483645

    // 算术右移测试用例
    arithmeticNum = -3;  
    arithmeticShift = 1;
    arithmeticResult = arithmeticRightShift(arithmeticNum, arithmeticShift);
    printf("Arithmetic Right Shift: %d\n", arithmeticResult);  //-2

    getchar();
    return 0;
}


