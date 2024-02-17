# https://stackoverflow.com/questions/7081820/setting-default-compiler-in-cmake

$Env:CMAKE_GENERATOR = 'MinGW Makefiles'
cd build
# cmake ..
cmake -G Ninja -DCMAKE_MAKE_PROGRAM=make -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..

cmake -DCMAKE_MAKE_PROGRAM=make -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..

# cmake -G Ninja ..
