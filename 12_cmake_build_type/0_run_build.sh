rm -rf build
rm -rf lib
rm -rf bin

mkdir -p build
cd build && cmake .. && make -j8
cd .. && ./bin/main