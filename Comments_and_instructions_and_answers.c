/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
    <Anh Nguyen>
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
      not allowed to use big constants such as 0xffffffff. *******************************************************************
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
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/*





 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */



 //BitAnd works because of DeMorgan's Law
 int bitAnd(int x, int y) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 1
  int z = (~x) | (~y); //DeMorgan's Law states ~(a & b) is the same as ~a or ~b, so to get around not using And, I
  //OR ~x and ~y to get the same result as ~(x & y). I then assigned the result to z.
  return ~z; //But I want to equal x & y, so I flip ~(x & y) by returning the ~ operator (the 1's complement operator) on z.
}
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
//BitNor works because of DeMorgan's Law
int bitNor(int x, int y) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 1
  return (~x)&(~y); // By DeMorgan's Law states that ~(a & b) is the same as ~a or ~b, so I applied that to the variables x and y.
  //Thus, by DeMorgan's Law ~(x | y) is equivalent to ~x & ~y
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return ~(x & 1) + 1; //I isolate the LSB by AND 1 with x since the binary of 1 is just whoever many 0's and 1 at the very end on the right.
} // Then I NOT (x & 1) to mask everything that isn't the LSB.
//Then I add 1 because I want to copy LSB to all the other positions

/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return (x >> (n << 3))&0xff; //I first shift n to the left 3 because this causes n to be multiplied by 8
  //That way, the mask can cover more memory. And I can manipulate bytes instead of bits.
} //I then shifted x right that sum to get rid of the least significant byte.
    // Then I and this answer with 0xff to mask everything but the least significant byte. That way I get rid of everything else but that and get my answer.
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
    int p = m<<3; //Multiply m by 8 since I want to move bytes and not bits. In its current form, m will only move bits, so I have to multiply by 8 since 1 byte is 8 bits.
    // I'm not allowed to use the * operator, so I do the equivalent of *8 and shift left by 3. Since 2 to the power of 3 is 8.
    int q = n<<3; // I do the same thing for n.
    int masked = (x & (~(0xff<<p))) & (~(0xff<<q)); // then I create the masks. To do that, I shift 0xff left p (m<<3) spaces to cover the byte where m is.
    // After that I NOT it using the ~ because I only want to move the byte where m is while everything else remains in place.
    // I then AND this m mask to x to isolate the m area over x. Then I do the same things with n, by making the mask and applying it to x.
    int mbyte = (((x>>q) & 0xff)<<p); //mbyte switches m to the n position. First what happens is the m byte of x gets shifted right q times.
    //Then x>>p gets ANDed to 0xff. That way I can isolate whatever is at n. After that I shift the entire quantity left p positions. That way, I
    // successfully switched m to the n position.
    int nbyte = (((x>>p) & 0xff)<<q); // I do the same thing to nbyte what I did to mbyte expect I want to switch n to the m position.
    int newMask = masked | mbyte | nbyte; //Then I OR masked, mbyte, and n byte to add everything together. That way, I bring everything together to
    //to get a new value I put in a variable (where byte m and n are switched) called newMask
    return newMask;
}



/*
 * allEvenBits - return
  1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int m8 = 0xAA;
  int m16 = (m8<<8)| m8;
  int m32 = (m16<<16)| m16;
  return !(~(x | m32));
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return ((~x)+1)&x; //To find the least significant bit, I first found the 2's complement of x by NOTing x and adding 1 to it.
  //That way,  I can isolate the least bit 1 and everything to the right of it.
  //Now I see that everything to the left of the least significant 1 is a complement to the corresponding bits in x. So to get rid of that. I and what I currently have with x.
  //That will give me the 1 in the least bit position, thus giving me my desired answer.
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */


 int minusOne(void) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 1
  return ~(0);// 0 in 2's complement form is a series of zeros. I want the opposite. So I NOT it giving me a series of 1s, which is the 2's complement form of -1.
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {//()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 1
  return ~(1<<31); // Because the size of ints is usually 4 bytes (or 32 bits), the maximum an int can be is 2147483647 in base 10,
  //which equals 1111111111111111111111111111111 in base 2.
  //The two's complement integer to that is thus returned as 01111111111111111111111111111111 in base 2 (or 7fffffff as a hex number).
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */



 int isEqual(int x, int y) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return !(x^y) // the XOR operator 0 if the bit examined from x and the bit examined from y are the same and 1 if both are not equal. So I negated x^y with ! to get my answer
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {// ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return !!(x>>31); // The !! treats a given value as a boolean value and looks for any non zeros.
  //So shifting left x 31 bits allows us to check if the number is negative because if the MSB of a number in base 2 is 1 it is negative,
  // and shifting left will copy the MSB to all other bit positions, ensuring the function will return 1 if x is negative.
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */





 int negate(int x) {// ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 2
  return (~x)+1;// To negate x, I just had to first flip the bits using the ~ operator and add 1.
  //That gives me the two's complement and thus also gives me the answer I want.
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {// ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 3
  int checker = (x+y)>>31;// checker adds x and y together because that's what the prompt is asking. checker then shifts that sum by 31
  //This helps isolate the MSB.
  xS = x>>31; // shifting x right 31 helps check what sign x is.
  yS = y>>31; // shifting y right 31 helps check what sign y is.
  return !!((~((~checker)|x|y)^(checker|(~x)|(~y)))); //NOTing checker then ORing it to x then y isolates x and y because x and y get combined with
  // a NOTted checker. All this gets XORed to an ORed checker, NOTted x, and NOTted y. I XORed one to the other because both are opposites, and
  // will either give me one or zero.

}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 3
    int xIsPositive = !((x>>31) & 1); // I do this to check  the sign of x and isolate the LSB
    int yIsPositive = !((y>>31) & 1);// I do this to check the sign of y and isolate the LSB
    int xISLESS_Equal_NoOverflow = !(((y+(~x)+1)>>31) & 1);// I do this to make sure there is no overflow and to make sure x is INDEED less or equal to y
    return (((!xIsPositive) & yIsPositive) | xISLESS_Equal_NoOverflow) & (!(xIsPositive & (!yIsPositive)));//This examines the two cases of whether both
    //x and y being the same sign or whether x and y have different signs. The AND between both cases ensures I get either 1 or 0 as an answer and for the
    //correct cases too
}


/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) { // ()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()() 4
  int shifted = x >> 31; //I shift x left 31 to get the MSB to the LSB position and also to copy the MSB to all other positions. Then I put that value
  // in a variable to call upon it later.
  x = (~shifted & x)|(shifted & (~x+1)): // I NOT shifted and AND it to x to isolate x. I then AND shifted with the (~x+1) which is the negative version of x
  return x;// Then I OR the two to combine them, ensuring I get the absolute value of x
}


