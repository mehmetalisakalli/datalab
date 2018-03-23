




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
