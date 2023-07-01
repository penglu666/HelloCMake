rm -rf build
rm -rf lib
rm -rf bin

mkdir -p build
cd build && cmake .. -DUSE_THIRDPARTY=ON && make -j8
cd .. && ./bin/main