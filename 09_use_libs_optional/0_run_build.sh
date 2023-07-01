rm -rf build
rm -rf lib

mkdir -p build
cd build && cmake .. -DUSE_THIRDPARTY=ON && make -j8
cd .. && ./bin/main