#include <iostream>
#include <math.h>
#include <chrono>

// function to add the elements of two arrays
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
  {
    

    y[i] = x[i] + y[i];

  }
}

int main(void)
{
  int N = 1<<26; // 64M elements

  float *x = new float[N];
  float *y = new float[N];

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }
  // insert start timer code here
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

  // Run kernel on 64M elements on the CPU
  add(N, x, y);

  // insert your end timer code here, and print out elapsed time for this problem size
  std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
  
  std::chrono::duration<double> elapsed = end_time - start_time;
  std::cout << "Elapsed time = " << elapsed.count() << " seconds" << std::endl;


 // Calculate MFLOP/s
  double total_flops = static_cast<double>(N);
  double mflops = total_flops / elapsed.count() / 1048576;

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  delete [] x;
  delete [] y;

// Print MFLOP/s
  std::cout << "MFLOP/s: " << mflops << std::endl;
  std::cout << "total_flops: " << total_flops << std::endl;

  return 0;

}