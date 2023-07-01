rm -rf build
rm -rf lib

mkdir -p build
cd build && cmake .. && make -j8
cd .. && ./bin/main