# Wine for Termux

通过补丁使 x86_64 Wine 在 Termux glibc 和 Box64 环境中可以正常运行，并修复一些问题。

---

本项目基于 [LGPL 2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html) 协议开源。  
Wine_Builds 部分使用 MIT 协议。  
此处以 Wine 本身的开源协议 LGPL 2.1 为主。

~~[wine-tkg-custom 源码](https://github.com/Waim908/wine-tkg-custom-termux)~~<=弃用此仓库（仅保留历史代码），源码请查看此仓库tag

由于社区进展缓慢：

- 对于 **10.17+** 的版本，不得不停止 esync 与 fsync 支持。Wine 现已可在高版本内核上加载 ntsync 支持。
- 对于 **10.16+** 的版本，停止构建支持 Proton winevulkan 与 mf 的移植支持。
- Proton 10-3 进度放缓，因去 Steam 补丁进展缓慢。
- 不再对高版本 Wine 的编译完成版本在 Termux 上进行测试，NumBox 项目更新暂时停止，且未能找到方便测试的环境。

### 变量说明

启用 ESYNC：`WINEESYNC=1`  
启用 FSYNC：`WINEFSYNC=1`

- Wine **10.16-2** 的 fsync 添加了可配置的自旋计数，可能有助于性能，但也可能引入稳定性问题或挂起。可尝试设置环境变量：
  ```bash
  WINEFSYNC_SPINCOUNT=100
  ```

# 推荐的版本

proton 10-3

wine 10.15（已重置，虚拟内存修复）

由于虚拟内存补丁失误，如果遇到问题优先切换为推荐版本

## RELEASES

# 命名规则V2

之前的版本号过长不方便管理，这里较新的Release将版本号正式修改为

wineVer-N
proton-Ver-X-N

N代表第N次编译

X为proton的版本例如10.0-3

wine-wineVer-[mfdxgi]-N-tkg-stg-ge.tar.xz

现在对于只应用wine_do_not_create_dxgi_device_manager.patch的版本，命名为,mfdxgi

文件名过长的问题也进行解决,stg代表staging补丁已经应用


# 命名规则V1

使用 wine-tkg-git 作为主要构建版本，从 **wine 10.14** 开始，提供两种 GStreamer 解码方案以解决游戏解码问题：

1. 直接应用本仓库的 `do not create dxgi` 相关补丁。
2. 使用 `tkg-git-staging-ge` 并启用 `proton_mf_patch` 相关选项。

命名规则：

- part1 → tag 包含 `unityH264`
- part2 → 版本号 `-tkg-git-staging-ge`

新 tkg 版本使用 Proton 的 winevulkan 方案补丁。

版本号格式为：`版本号-重置次数`

重置版标准重新制定：

- `unityH264` 重置版本将不再包含 winevulkan 提速，而是使用原版 winevulkan（提高稳定性）。
- 常规重置版本继续包含正常的 mf 解码修复补丁以及 winevulkan 支持。

## 关于补丁文件

### `wine_do_not_create_dxgi_manager.patch`

此补丁通过新增环境变量 `WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER` 来修复使用 GStreamer 的 Unity 游戏的 H.264 解码问题。

> **注意**：
> - 这依旧不是一个完美的解决方案。
> - 此变量**必须**设置为 `1`（即 `export WINE_DO_NOT_CREATE_DXGI_MANAGER=1`）。如果设置为 `0`，部分游戏可能出现无法运行等问题。

### `esync.patch` 与 `esync2.patch`

- `esync2.patch` 方案源自 [hostei33 的 wine-tkg glibc 分支仓库](https://github.com/hostei33/wine-tkg)。
- **注意**：`esync.patch` 和 `esync2.patch` **只能二选一**应用。

~~`ntsync-fix-32-bit-processes.patch` —— 来自 Kron4ek。尚不清楚此补丁是否有用，需视后续安卓版本内核是否支持 ntsync（10.16+）。~~ <=不使用

## 关于 `wine-tkg-git`

[查看详情](README_TkG.md)

## 关于 GStreamer GL 头文件缺失

Arch Linux:
```bash
cp /lib/gstreamer-1.0/include/gst/gl/gstglconfig.h /usr/include/gstreamer-1.0/gst/
```

Ubuntu/Debian:
```bash
cp /lib/对应架构-linux/gstreamer-1.0/include/gst/gl/gstglconfig.h /usr/include/gstreamer-1.0/gst/
```

## 关于 mfplat 补丁

### !!! 此方法暂时无效 !!!

~此补丁用于修复 GStreamer 无法解码的问题。~

~需运行 `get_latest_mfplat_patch.sh` 脚本获取补丁文件。请确保：~
1. ~网络可连接 GitHub。~
2. ~已安装 `curl`。~
3. ~使用的是最新版 Wine 主线、tkg 或 tkg-staging 的源码。~

~**注意**：每次 Wine 版本更新后都需重新运行此脚本获取新补丁。若不备份补丁文件，旧补丁可能不兼容新版本源码。~

~经测试，该补丁在最新的 Kron4ek wine-tkg 和 mainline 主线版本上应用失败。~

## 杂项

### 关于 `wine-virtual-memory.patch` (mapping.c) 应用失败

此问题已通过迭代补丁 `wine-virtual-memory2.patch` 解决。

## Q/A 常见问题

**Q: 使用 `patch -p1` 命令应用补丁时显示失败 (failed) 怎么办？**  
**A:** 可尝试添加 `-R` 参数进行反向操作以检查冲突：`patch -p1 -R`。如果提示，输入 `y` 尝试应用反向补丁。这有助于诊断问题，但**并非**解决方案。

**Q: 有没有更保险的 `patch` 命令参数？**  
**A:** 有：
- 使用 `--dry-run` 参数进行试运行，不实际修改文件：`patch -p1 --dry-run < patchfile.patch`
- 使用 `-N` 参数跳过已应用的补丁：`patch -Np1 < patchfile.patch`

如有其他问题，请反馈至 Issues。针对补丁的迭代或修改，请提交 Pull Request。

## Proton Wine

### 关于 Proton 构建失败

构建 Proton 版本的 Wine 时可能会遇到以下问题，需进行修复：

1. **OpenCL 构建错误**:
   - **提交哈希**: `dd8d73ba895`
   - **描述**: `opencl: HACK: Build a stub dll if Unix headers are missing.`
   - **解决方法**: 使用命令 `git show dd8d73ba895 | git apply -R` 撤销此提交，或应用补丁文件 `fix-build_opencl.patch`。

2. **FFmpeg 构建错误**:
   - **提交哈希**: `063a29bc8ba`
   - **描述**: `winedmo: Handle PCM audio big-endian formats.`
   - **解决方法**: 使用命令 `git show 063a29bc8ba | git apply -R` 撤销此提交，或应用补丁文件 `fix-build_ffmpeg.patch`。

### 补丁应用失败 `path-patch-universal.patch` (unixlib.c)

此补丁对应 Valve 的 Wine 提交 [a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1)。

如果应用失败，请尝试使用 `unixlib.patch` 来修复。

## 获取

```bash
git clone https://github.com/Waim908/wine-termux.git
```

## 构建指南

1. **应用补丁**  
   进入你的 Wine 源码目录，运行以下命令来应用所需补丁（请替换 `/path/to/version/` 和 `XXX.patch` 为实际路径和补丁名）：
   ```bash
   cd /path/to/your/wine/source
   patch -p1 < /path/to/wine-termux/对应版本的文件夹/XXX.patch
   ```

2. **设置编译环境**  
   使用 `source` 或 `.` 命令执行提供的环境变量脚本：
   ```bash
   . /path-to/wine-termux/x64.sh
   # 或
   source /path-to/wine-termux/x64.sh
   ```

3. **配置编译选项**
   ```bash
   ./configure --enable-archs="i386,x86_64" ${arg[@]} --prefix=/your/installation/path/
   ```
   > **注意**: 如果配置过程中出现类似 `--without-piper` 参数不存在的警告，通常可以**忽略**，此选项不会影响非 Proton 版本 Wine 的构建。

4. **编译并安装**
   ```bash
   make -j$(nproc)
   make install
   ```

## 致谢

感谢以下项目和开发者：

- [airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)
- [Frogging-Family/wine-tkg-git](https://github.com/Frogging-Family/wine-tkg-git)
- [hostei33/wine-tkg](https://github.com/hostei33/wine-tkg)
- [Kron4ek/Wine-Builds](https://github.com/Kron4ek/Wine-Builds)