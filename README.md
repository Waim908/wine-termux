[中文](README.md) [English](README-EN.md)

# wine-termux

通过补丁使x86_64 wine在termux glibc box64环境可以正常运行，并修复一些问题

## About some patch files

```wine_do_not_create_dxgi_manager.patch``` 此补丁通过新增变量```WINE_DO_NOT_CREATE_DXGI_MANAGER```修复了  gstreamer unity游戏 h264解码问题， <u>注意这依旧不是一个有效方案，且此变量必须赋值1，如果为0部分游戏运行可能出现无法运行等问题</u>

```esync2.patch``` 方案来自<u>hostei33</u>的说明具体可以去看仓库 [wine-tkg glibc分支](https://github.com/hostei33/wine-tkg)

<u>```esync.patch```和```esync2.patch```只能二选一</u>

## About mfplat patch

修复gstreamer无法解码问题

需要通过```get_latest_mfplat_patch.sh```来获取补丁文件，确保网络可以连接github并安装curl，确保你是最新版主线版本或tkg或tkg-staging的源码，且每次版本更新都需要运行此脚本，如果不备份补丁文件，可能不兼容老版本的源码


## 杂项

### 关于"wine-virtual-memory.patch" => mapping.c 补丁应用失败

已经迭代补丁 ```wine-virtual-memory.patch```

### Q/A

Q: ```patch -p1```命令打补丁后显示failed失败怎么办
A: 可以添加一个```-R```参数， ```patch -p1 -R``` ，如果弹出问题输入y可以应用补丁

Q: 更加保险的```patch```命令参数？
A: 有的， 可以添加```--dry-run```来试运行，或者替换```-p1```为```-Np1```来跳过已存在的修改

如果有其他问题请反馈issues，针对补丁迭代或修改的请提交拉去请求

## proton wine

### 关于proton构建失败

``` git show 下面的对应序号 | git apply -R ```或者应用补丁文件```fix-build_opencl.patch``` 和 ```fix-build_ffmpeg.patch```

#### opencl
```dd8d73ba895``` opencl: HACK: Build a stub dll if Unix headers are missing.
#### ffmpeg 
```063a29bc8ba``` winedmo: Handle PCM audio big-endian formats.

### 补丁文件应用失败 "path-patch-universal.patch" => unixlib.c

[a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1)

修复使用```unixlib.patch```

## 获取

```git clone https://github.com/Waim908/wine-termux.git```

## 构建参数

关于 `--without-piper` 参数不存在之类的报错可以无视，此选项不会影响非proton版本的wine构建

应用 "对应版本的文件夹/XXX.patch"

cd到你的源码目录

```patch -p1 < /path/to/proton/XXX.patch```

```. /path-to/proton/x64.sh``` or ```source``` 这个文件

```./configure ${arg[@]}  --prefix=/xxx/```

```make -j$(nproc) && make install```

# Thanks
[airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)

[Frogging-Family/wine-tkg-git](https://github.com/Frogging-Family/wine-tkg-git)