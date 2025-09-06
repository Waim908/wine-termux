# [wine-tkg-git project](https://github.com/Frogging-Family/wine-tkg-git)

### copy XXX.mylatepatch to ```wine-tkg-userpatches``` <= Use ```esync.mylatepatch``` or ```esync2.mylatepatch```

### commit must ```https://github.com/Frogging-Family/wine-tkg-git/commit/64580ba53112039dfeb21d3378506388da33eb69``` 

### System: ```archlinux```

### customization.cfg

```bash
_GE_WAYLAND="falas" 

_plain_version="wine-10.13" 

_use_staging="true" 

_staging_version="a8a6d7b" <=自行调整，如果标记为release wine-版本号的的提交导致补丁失败，就用最新的master提交反之用release提交，还是补丁失败自行等待staging更新或者git pull 拉取最新版wine-tkg-git代码

_wayland_driver="false"

_proton_battleye_support="false" 

_proton_eac_support="false"

_proton_winevulkan="false"

_mk11_fix="false"
```

***```_community_patches_auto_update="false"```*** <= ***Important***

# 关于gstreamer解码问题
应用配置文件里面的```_proton_mf_patches="true"```
这依旧不是完美的方案，你也可以使用此仓库的```wine_do_not_create_dxgi_manager.patch```<＝(=<10.3)or ```wine_do_not_create_dxgi_manager2.patch``` (>=10.4+)在原版解码基础上允许禁用dxgi管理器
原版的解码方案和补丁解码方案以及proton和tkg解码方案存在一定差异

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

## 关于依赖
直接用archlinux系统构建让它自动安装就行了，```yes|./nomakepkg.sh```

## 其他
wine-tkg-git突然不拉取esync代码导致esync补丁应用失败，请删除wine-tkg-git重新拉取
