#include <bits/stdc++.h>

// https://medium.com/@lucianoalmeida1/a-little-bit-about-std-move-efd9d554c09a
// https://stackoverflow.com/questions/3582001/what-are-the-main-purposes-of-using-stdforward-and-which-problems-it-solves

// Calculated at compile time
constexpr int factorial(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
};

// Universal reference rvalue only!? Nope it can be both and so we use it to 
// avoid 2^N override methods to take in rvalue and lvalue as function input
// 
void foo(int&& a)
{
   //Some magical code...
}

int main()
{
    // move MoveExample
    
   int b;
//   foo(b);       //Error. An rValue reference cannot be pointed to a lValue.
  foo(5);       //Compiles with no error.
  foo(b+3);     //Compiles with no error.
//   int&& c = b;  //Error. An rValue reference cannot be pointed to a lValue.
  int&& d = 5;  //Compiles with no error.
  
  // constexpr compile time run
  std::cout << factorial(5) << std::endl;
  
  // Malloc 
  int *a = NULL;
  if (a == NULL) {
      std::cout << "Memory not allocated.\n";
  }
  a = (int *)malloc(100 * sizeof(int));
  if (a != NULL) {
      std::cout << "Memory allocated successfully.\n";
  }

  for(int i=0; i<100; i++)
  {
      a[i] = 0;
      std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  free(a);
  
  // Calloc 
  a = NULL;
  a = (int *)calloc(100, sizeof(int));
  if (a != NULL) {
      std::cout << "Calloc Memory allocated successfully.\n";
  }
  for(int i=0; i<100; i++)
  {
      a[i] = 0;
      std::cout << a[i] << " ";
  }
  free(a);
//   delete calls destructor of the object whereas free() doesnt. !!!!
//   delete[] a;
  return 0;
}

