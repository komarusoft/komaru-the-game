if [ -d "build" ]; then
    rm -rf build
fi

mkdir build
cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
make

