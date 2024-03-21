if [ -d "build" ]; then
    rm -rf build
fi

if [ -d "json"]; then
    git clone https://github.com/nlohmann/json/
fi

mkdir build
cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
make

sudo chmod +x komaru_the_game
./komaru_the_game