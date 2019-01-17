#include <iostream>

using std::cout;
using std::endl;

const int proc(int& input){input = input*2; return input;}
int proc(const int& input){ int output = input; return output;}

void swap(int& x, int& y){
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}
void swap(const int& x,const int& y){;}

int main() {
  int var1 = 1;
  int var2 = 2;

  int var3 = proc(var1);
  int var4 = proc(var2);
  // var1 = var3 = 2, var2 = var4 = 4

  const int var5 = proc(var1);
  const int var6 = proc(var2);
  // var1 = 4, var2 = 8
  // var5 = 4, var6 = 8

  int var7 = proc(proc(var1)); // proc returns const int
  int var8 = proc(proc(var2)); // daher proc(proc(x)) = proc(x)
  // var1 = 8 var2 = 16
  // var7 = 8 var8 = 16

  int& var9 = var1;
  int& var10 = var2;

  const int& var11 = proc(var1);
  const int& var12 = proc(var2);
  // var1 = 16, var2 = 32

  swap(var3,var4);
  swap(var5,var6); // keine Wirkung, da var5,var6 const
  swap(var7,var8);
  swap(var9,var10); // tauscht auch var1,var2
  swap(var11,var12); // keine Wirkung, da const

  cout << "var1 = " << var1 << " var2 = " << var2 << endl;
  cout << "var3 = " << var3 << " var4 = " << var4 << endl;
  cout << "var5 = " << var5 << " var6 = " << var6 << endl;
  cout << "var7 = " << var7 << " var8 = " << var8 << endl;
  cout << "var9 = " << var9 << " var10 = " << var10 << endl;
  cout << "var11 = " << var11 << " var12 = " << var12 << endl;

  return 0;
}
