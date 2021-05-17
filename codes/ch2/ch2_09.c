/*  declare 'a' an object of type 'int'   */
int a; 
 
/*  'a' is an expression referring to an 'int' object as l-value  */ 
a = 1; 
  
int b = a;  /*  Ok, as l-value can appear on right  */
 
/*  Switch the operand around '=' operator  */
9 = a; 
/*
 * Compilation error: 
 * as assignment is trying to change the value of assignment operator
 */

a + 1 = b;  /* Error, left expression is not variable(a + 1)    */
