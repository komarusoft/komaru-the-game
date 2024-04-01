if [ -d "build" ]; then
    rm -rf build
fi

if [ ! -d "json" ]; then
    git clone https://github.com/nlohmann/json/
fi

mkdir build

cp -r res build
chmod 644 /build/res

cd build

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Debug -DDEBUG=ON ..
make

