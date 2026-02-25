if [ "${USE_CACHE}" = "1" ]; then
  export CROSSCC="ccache x86_64-w64-mingw32-gcc"
  export CROSSCXX="ccache x86_64-w64-mingw32-g++"
else
  export CROSSCC="x86_64-w64-mingw32-gcc"
  export CROSSCXX="x86_64-w64-mingw32-g++"
fi

# Custom GCC flags（基础 + 激进优化）
_GCC_FLAGS="-O3 -pipe -msse3 -mfpmath=sse -ftree-vectorize -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types"
# Custom LD flags（带 strip）
_LD_FLAGS="-Wl,-O3,-s,--sort-common,--as-needed"
# Cross-compiled GCC flags（与本机保持一致）
_CROSS_FLAGS="-O3 -pipe -msse3 -mfpmath=sse -ftree-vectorize -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types"
# Cross-compiled LD flags
_CROSS_LD_FLAGS="-Wl,-O3,-s,--sort-common,--as-needed"

# 本机与交叉编译统一加上 -march=x86-64
export CFLAGS="-march=x86-64 ${_GCC_FLAGS}"
export CXXFLAGS="-march=x86-64 ${_GCC_FLAGS}"
export CROSSCFLAGS="-march=x86-64 ${_CROSS_FLAGS}"
export CROSSCXXFLAGS="-march=x86-64 ${_CROSS_FLAGS}"

export LDFLAGS="${_LD_FLAGS}"
export CROSSLDFLAGS="${_CROSS_LD_FLAGS}"

export arg=(--enable-win64 --enable-archs=i386,x86_64 --disable-winemenubuilder --disable-win16 --disable-tests --without-capi --without-coreaudio --without-cups --without-gphoto --without-osmesa --without-oss --without-pcap --without-pcsclite --without-sane --without-udev --without-unwind --without-usb --without-v4l2 --without-wayland --without-xinerama --without-piper)