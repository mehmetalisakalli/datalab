//Mehmet Ali Sakallý 150114080




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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
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

/*
 * modPower2 - x mod pow(2,n)
 *   Example: modPower2(40, 5) = 8
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int modPower2(int x,int n){
    return x & ((1 << n) + ( 1 + ~1 ));
}
/*
 * countzeros - returns count of number of 0's in word
 *   Examples: countzeros(5) = 30, countzeros(7) = 29
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int countzeros(int x) {
        
	int y= ~x;	
		int line1 = 0x11 | (0x11 << 8);
        int line2 = line1 | (line1 << 16);

        int sum = y & line2;
        sum = sum + ((y >> 1) & line2);
        sum = sum + ((y >> 2) & line2);
        sum = sum + ((y >> 3) & line2);

        sum = sum + (sum >> 16);

        line1 = 0xF | (0xF << 8);

        sum = (sum & line1) + ((sum >> 4) & line1);

        return((sum + (sum >> 8)) & 0x3F);
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 4
 */
int isTmax(int x) {
  return !(x ^ 0x7FFFFFFF);
}
/*
 * isGreaterOrEqual - if x >= y  then return 1, else return 0
 *   Example: isGreaterOrEqual(8,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 4
 */
int isGreaterOrEqual(int x, int y) {
   int negY = ~y+1;
  int addX = negY +x;
  int checkSign = addX >> 31 & 1;
  int leftBit = 1;
  int yLeft = leftBit & y>>31;
  int xLeft = leftBit & x>>31;
  int yOrd = yLeft ^ xLeft;
  yOrd = yOrd & 1;
 return (yOrd & yLeft) | (!checkSign & !yOrd);
}
/*
 * findHammingDistance - Count the number of positions at which the corresponding bits of x and y are different
 *   Example: findHammingDistance(5,10) = 4.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int findHammingDistance(int x, int y) {
    
	int hamming= x^y;
        int line1 = 0x11 | (0x11 << 8);
        int line2 = line1 | (line1 << 16);

        int sum = hamming & line2;
        sum = sum + ((hamming >> 1) & line2);
        sum = sum + ((hamming >> 2) & line2);
        sum = sum + ((hamming >> 3) & line2);

        sum = sum + (sum >> 16);

        line1 = 0xF | (0xF << 8);

        sum = (sum & line1) + ((sum >> 4) & line1);

        return((sum + (sum >> 8)) & 0x3F);
}
/*
 * isOne - return 1 if the nth bit of x is a 1
 *   Example: isOne(4,0) = 0.
 *            isOne(-100,31) = 1.
 *            isOne(5,2) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 26
 *   Rating: 4
 */
int isOne(int x, int n) {
  int nthbit= x >> n;
  int result= nthbit & 1;
  return result;
}
/*
 * smallerPower - Compute the largest power of 2, which is less than or equal to x
 *   Example: smallerPower(24) = 16, smallerPower(4) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int smallerPower2(int x) {
    x = x | (x>>1);
    x = x | (x>>2);
    x = x | (x>>4);
    x = x | (x>>8);
    x = x | (x>>16);
    return (x>>1)+1;
}

//float
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  
   int x = (uf >> 23) & 0xFF;
  if(!x) { 
      x = 0xFF;
      uf = (uf & 0x80000000) | (uf << 1);
  }
  if(!(x ^ 0xFE)) { 
    x = 0xFF;
    uf = (uf & 0x80000000) | (x << 23);
  }
  if(x ^ 0xFF) {
    uf = uf + (1 << 23);
  }
  return uf;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
   int e = 158;
    int mask = 1<<31;
    int sign = x&mask;
    int fraction;
    if (x == mask)
        return mask | (158<<23);
    if (!x)
        return 0;
    if (sign)
        x = ~x + 1;
    while (!(x&mask)) {
        x = x<<1;
        e = e -1;
    }
    fraction = (x&(~mask)) >> 8;
    if (x&0x80 && ((x&0x7F) > 0 || fraction&1))
        fraction = fraction + 1;
    return fraction + sign + (e<<23);
}
/*
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  return 2;
  }
