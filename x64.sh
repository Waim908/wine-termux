export CROSSCC="x86_64-w64-mingw32-gcc"
export CROSSCXX="x86_64-w64-mingw32-g++"
export CFLAGS="-march=x86-64 -msse3 -mfpmath=sse -O3 -ftree-vectorize -pipe"
export CXXFLAGS="-march=x86-64 -msse3 -mfpmath=sse -O3 -ftree-vectorize -pipe"
export CROSSCFLAGS="-march=x86-64 -msse3 -mfpmath=sse -O3 -ftree-vectorize -pipe"
export CROSSCXXFLAGS="-march=x86-64 -msse3 -mfpmath=sse -O3 -ftree-vectorize -pipe"
export arg=(--enable-archs=i386,x86_64 --disable-winemenubuilder --disable-win16 --enable-win64 --disable-tests --without-capi --without-coreaudio --without-cups --without-gphoto --without-osmesa --without-oss --without-pcap --without-pcsclite --without-sane --without-udev --without-unwind --without-usb --without-v4l2 --without-wayland --without-xinerama --without-piper)