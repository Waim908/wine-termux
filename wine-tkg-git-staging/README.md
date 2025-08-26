# [wine-tkg-git project](https://github.com/Frogging-Family/wine-tkg-git)

### copy XXX.mylatepatch to ```wine-tkg-userpatches``` <= Use ```esync.mylatepatch``` or ```esync2.mylatepatch```

### commit must ```https://github.com/Frogging-Family/wine-tkg-git/commit/64580ba53112039dfeb21d3378506388da33eb69``` 

### System: ```deabin 13```

## configure ffmpeg 7.1.1 and make & make install

## Mainline Tkg ```wine-10.13``` Config files set

### customization.cfg

```bash
_GE_WAYLAND="falas" 

_plain_version="wine-10.13" 

_use_staging="true" 

_staging_version="a8a6d7b"

_wayland_driver="false"

_proton_battleye_support="false" 

_proton_eac_support="false"

_mk11_fix="false"
```

***```_community_patches_auto_update="false"```*** <= ***Important***

## wine-tkg-profiles/advanced-customization.cfg

```bash
# enable O3
_GCC_FLAGS="-O3 -pipe -msse3 -mfpmath=sse -ftree-vectorize -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types"
_LD_FLAGS="-Wl,-O3,--sort-common,--as-needed"
_CROSS_FLAGS="-O3 -pipe -msse3 -mfpmath=sse -ftree-vectorize -Wno-error=implicit-function-declaration -Wno-error=incompatible-pointer-types"
_CROSS_LD_FLAGS="-Wl,-O3,--sort-common,--as-needed"
# enable wow64
_NOLIB32="wow64"
# configure arg
_configure_userargs64="--disable-winemenubuilder --disable-win16 --enable-win64 --disable-tests --without-capi --without-coreaudio --without-cups --without-gphoto --without-osmesa --without-oss --without-pcap --without-pcsclite --without-sane --without-udev --without-unwind --without-usb --without-v4l2 --without-wayland --without-xinerama --without-piper"
```

## script (CUSTOM)

run ```./condigure --disable-winemenubuilder --disable-win16 --enable-win64 --disable-tests --without-capi --without-coreaudio --without-cups --without-gphoto --without-osmesa --without-oss --without-pcap --without-pcsclite --without-sane --without-udev --without-unwind --without-usb --without-v4l2 --without-wayland --without-xinerama --without-piper``` check

apt install git sudo wget

```bash
debian_pkgs_64=(gcc-multilib gcc-mingw-w64 libasound2-dev libpulse-dev libdbus-1-dev libfontconfig-dev libfreetype-dev libgnutls28-dev libgl-dev libunwind-dev libx11-dev libxcomposite-dev libxcursor-dev libxfixes-dev libxrandr-dev libxrender-dev libxext-dev libwayland-bin libwayland-dev libegl-dev libwayland-dev libxkbcommon-dev libxkbregistry-dev libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libosmesa6-dev libsdl2-dev libudev-dev libvulkan-dev libcapi20-dev libcups2-dev libgphoto2-dev libsane-dev libkrb5-dev samba-dev ocl-icd-opencl-dev libpcap-dev libusb-1.0-0-dev libv4l-dev libxxf86vm-dev libxinerama-dev gettext bison flex libgcrypt20-dev)
```
