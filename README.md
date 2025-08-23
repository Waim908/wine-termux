# wine-termux

通过补丁使x86_64 wine在termux glibc box64环境可以正常运行，并修复一些问题

## About some patch files

```wine_do_not_create_dxgi_manager.patch``` 此补丁通过新增变量```WINE_DO_NOT_CREATE_DXGI_MANAGER```修复了  gstreamer unity游戏 h264解码问题， <u>注意这依旧不是一个有效方案，且此变量必须赋值1，如果为0部分游戏运行可能出现无法运行等问题</u>

```esync2.patch``` 方案来自<u>hotei33</u>的说明具体可以去看仓库 [wine-tkg glibc分支](https://github.com/hostei33/wine-tkg)

<u>```esync.patch```和```esync2.patch```只能二选一</u>

## About Proton wine

### 关于proton构建失败

``` git show 下面的对应序号 | git apply -R ```或者应用补丁文件```fix-build_opencl.patch``` 和 ```fix-build_ffmpeg.patch```

#### opencl
```dd8d73ba895``` opencl: HACK: Build a stub dll if Unix headers are missing.
#### ffmpeg 
```063a29bc8ba``` winedmo: Handle PCM audio big-endian formats.

### 补丁文件应用失败 "path-patch-universal.patch" => unixlib.c

[a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1)

修复

## 构建参数

关于 `--without-piper` 参数不存在之类的报错可以无视，此选项不会影响非proton版本的wine构建

应用 "对应版本的文件夹/XXX.patch"

```patch -p1 < /path/to/proton/XXX.patch```

```. /path-to/proton/x64.sh``` or ```source``` 这个文件

```./configure ${arg[@]}  --prefix=/xxx/```

```make -j$(nproc) && make install```

# Thanks
[airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)