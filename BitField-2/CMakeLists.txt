cmake_minimum_required(VERSION 3.2)

project(TSet)


add_executable(set main.cpp BitField.cpp Set.cpp)

target_compile_options(main PRIVATE
-ftree-vectorize
# -O3     
-Ofast             
-march=native      
-funroll-loops     
-fprefetch-loop-arrays  
-flto              
-ffast-math
-fno-exceptions
-fno-rtti
-fomit-frame-pointer
-floop-block
-floop-parallelize-all
-ftree-loop-distribution
-fpeel-loops
-fvect-cost-model=dynamic                             
-fno-stack-protector          
-DNDEBUG                   
-mavx2                  
-fprofile-generate   
-fprofile-use  
)