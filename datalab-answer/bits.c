/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
//这个可以根据电路的基本知识得到
//A xor B = (~A)&B or A(~B)
//~(AB)=~A or ~B
int bitXor(int x, int y) {

  return (~(x&y))&(~(~x&~y));;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
//难度主要是英文太差 想了好长时间才记起来complement integer是补码的意思
//只要最高位为1就好了，这样其他的为1的话补码最高位为1，肯定比这个数大
int tmin(void) {
  
  return (1<<31);

}
//2
/*
 * isTmax - returns 1 if x is the maximum two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
//可以使用电路里的同或公式
//只要和0x10000001一样就可以了
//但这样就不满足题意了 我干
//于是只好将对应位数移到第一位进行与操作
int isTmax(int x) {
  return(!(x>>31))&((x+1)>>31);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
//将x所有偶数位变成0，不改变奇数位:x=x&0xAAAAAAAA
//先将x和1进行或运算，值修改第0位，把第0位加上一个1
//再将x和0xAAAAAAAA抑或并且返回结果
//但是不符合(only 0x0 - 0xff allowed)的要求，采用了网上的方法 这个真没想到
int allOddBits(int x) {
    x = (x>>16) & x;    
    x = (x>>8) & x;     
    x = (x>>4) & x;     
    x = (x>>2) & x;     
    return (x>>1)&1;  
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
//标准的负数求法：取反+1
int negate(int x) {

  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
//就是根据减法的结果 然后取个符号位就行
//标准的考研题
int isAsciiDigit(int x) {
  int temp1=x+(~(0x30)+1);
  int temp2=x+(~(0x3A)+1);
  return !(temp1>>31)&((temp2>>31));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return ((!x+~1+1)&y)|((~!x+1)&z);


}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
//尽管直接减可以根据符号位获得，但是如果一个正数一个负数会超出int的范围
//因此需要特殊处理一下
int isLessOrEqual(int x, int y) {
    int z,s,sx,sy;
    sx = (x>>31)&1; //  取x的符号位
    sy = (y>>31)&1; //  取y的符号位
    z = x + ~y + 1; //  z = x-y
    s =  ((z>>31) & 1) | (!(z^0));
    // 取z的符号位，s为真时x<y或者z全0（x==y）
    return  ((!(sx^sy))&s) | (sx&(!sy));
    // xy同号且z<=0 或 x<=0 y>=0
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
   return((~x&~(~x+1))>>31)&1;
  return 2;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
//这个题不会
//我抄的
int howManyBits(int x) {
    int p = x >>31;
    int y =((~x)&p) + (x&(~p));//若x为负数，则取其补码
    int c1 = !!(y>> 16);//判断是否大于16位
    int d1 = 8 + (c1<< 4);//大于16位时为24，小于16位时为8
    int c2 = !!(y>> d1);//大于16位的平移24位，小于16位的平移8位，大于24位或8<<16为1;16< <24和<8为0
    int d2 = d1 + (~3)+ (c2 << 3);//多-4，少+4
    int c3 = !!(y>> d2);
    int d3 = d2 + (~1)+ (c3 << 2);
    int c4 = !!(y>> d3);
    int d4 = d3 + (~0)+ (c4 << 1);
    int c5 = !!(y>> d4);
    int d5 = d4 + c5 +!!y;
    return d5;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
   unsigned f = uf;
    if ((f & 0x7f800000) == 0)// 如果阶码为0
        f = ((f & 0x007fffff) << 1) | (0x80000000 & f); 
        // 尾数不为0则尾数左移1位，尾数第1位为1则阶码加1，尾数为0则uf为0返回0
    else if ((f & 0x7f800000) != 0x7f800000)// 如果阶码不为0，且非全1
        f = f + 0x00800000;// 阶码加1
    return f;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    unsigned inf = 1<<31;   // inf = maxint+1
    int e = (uf>>23) & 0xff;// 阶码
    int s = (uf>>31) & 1;   // 符号位
    if (uf == 0) return 0;
    uf <<= 8;       // 左移保留至阶码最后1位
    uf |= 1<<31;    // 阶码最后一位设为1
    uf >>= 8;       // 高八位全0
    e -= 127;       // 阶数
    if ((uf & 0x7f80000) == 0x7f80000 || e >= 32)
        return inf; // 超过int范围返回inf
    if (e < 0) // 小数返回0
        return 0;
    if (e <= 22) // 位数小于等于22位，尾数位右移
        uf >>= 23-e;
    else 
        uf <<= e-23; // 尾数大于22位，尾数为左移
    if (s) 
        uf = ~uf + 1;// 若原uf为负数，则对此处的正数uf取反加1得其相反数
    return uf;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    unsigned inf = 0xff << 23; // 阶码全1
    int e = 127 + x;    // 得到阶码
    if (x < 0) // 阶数小于0直接返回0
        return 0;
    if (e >= 255) // 阶码>=255直接返回inf
        return inf;
    return e << 23;
}
