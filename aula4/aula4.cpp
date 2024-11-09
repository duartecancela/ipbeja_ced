#include <iostream>
#include <omp.h>

int main()
{
  {
    int tid = omp_get_thread_num;:q
  
    std::out<<"Thread identifier" << tid 
      << std::endl;
  }
}
