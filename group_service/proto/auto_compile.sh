cd `dirname $0`
protoc *.proto --cpp_out=./
mv *.h ../include/proto
mv *.cc ../src/proto