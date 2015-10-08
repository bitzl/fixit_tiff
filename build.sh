#!/bin/bash

# Setup folders
rm -rf build
mkdir build
mkdir build/static

#cd build

printf "\n### Building libtiff..."; pwd

# Build libtiff
wget ftp://ftp.remotesensing.org/pub/libtiff/tiff-4.0.6.tar.gz
tar xzf tiff-4.0.6.tar.gz
cd tiff-4.0.6
./configure
make -j 2
cd ..

printf "\n### Building libpcre..."; pwd

# Build libpcre
wget ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/pcre-8.37.tar.gz
tar xzf pcre-8.37.tar.gz
cd pcre-8.37
autoconf
./configure --disable-shared --enable-static
make
cd ..

printf "\n"; pwd

# Build fixit_tiff and checkit_tiff
# git clone "https://github.com/SLUB-digitalpreservation/fixit_tiff.git"
#cd fixit_tiff

printf "\n### Building fixit_tiff..."; pwd

cd fixit
INC="-I ../tiff-4.0.6/libtiff/ -L ../tiff-4.0.6/libtiff/.libs/ -static" make
mv fixit_tiff ../build/static/
cd ..

printf "\n### Building checkit_tiff..."; pwd

cd checkit
SANITIZE="" INC="-DPCRE_STATIC -I../tiff-4.0.6/libtiff/ -I../pcre-8.37/" LIB="-fPIC -static -L../tiff-4.0.6/libtiff/.libs/ -L../pcre-8.37/.libs/"  make checkit_tiff
cp checkit_tiff ../build/static
cd ..

printf "\n"; pwd

echo "Done."