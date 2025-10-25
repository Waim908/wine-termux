# Wine for Termux

通过补丁使 x86_64 Wine 在 Termux glibc 和 Box64 环境中可以正常运行，并修复一些问题。

---

# 本项目基于 [LGPL2.1](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html)协议开源

# Wine_Builds部分使用MIT协议

# 这里按照wine本身的开源协议LGPL2.1为主

## [wine-tkg-custom源码](https://github.com/Waim908/wine-tkg-custom)

### Kron4ek版本补丁停止更新

# 变量说明

启用ESYNC ```WINEESYNC=1```

启用FSYNC ```WINEFSYNC=1```

 - wine**10.16-2** fsync 添加可配置的自旋计数——可能有助于性能，但也可能引入稳定性问题或挂起。尝试设置环境变量
   ```WINEFSYNC_SPINCOUNT=100``` 

## RELEASES
使用wine-tkg-git作为主要构建版本，从**wine10.14**开始，提供两种gstreamer解码来解决游戏解码问题

第一种直接应用此仓库do not create dxgi相关补丁

第二种就是tkg-git-staging-ge启用proton_mf_patch相关选项

part1＝> tag包含unityH264
part2＝> 版本号-tkg-git-staging-ge

新tkg版本使用proton的wine vulkan方案补丁

版本号-重置次数 

重置版标准重新制定

unityH264重置版本将不再包含winevulkan提速而是使用原版winevulkan（提高稳定性）

常规重置版本继续正常mf解码修复补丁以及winevulkan支持

## 关于补丁文件

### `wine_do_not_create_dxgi_manager.patch`
此补丁通过新增环境变量 `WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER` 来修复使用 GStreamer 的 Unity 游戏的 H.264 解码问题。

> **注意**：
> - 这**依旧不是一个完美的解决方案**。
> - 此变量**必须**设置为 `1`（即 `export WINE_DO_NOT_CREATE_DXGI_MANAGER=1`）。如果设置为 `0`，部分游戏可能出现无法运行等问题。

### `esync.patch` 与 `esync2.patch`
- `esync2.patch` 方案源自 [hostei33 的 wine-tkg glibc 分支仓库](https://github.com/hostei33/wine-tkg)。
- **注意**：`esync.patch` 和 `esync2.patch` **只能二选一**应用。

`ntsync-fix-32-bit-processes.patch` -- 来自Kron4ek，我也不清楚此补丁是否有用，看后续安卓版本内核是否支持ntsync（10.16+）

---

## 关于 `wine-tkg-git`

[查看详情](README_TkG.md)

---

## 关于gstreamer gl头文件缺失

archlinux

```bash
cp /lib/gstreamer-1.0/include/gst/gl/gstglconfig.h /usr/include/gstreamer-1.0/gst/
```

ubuntu/debian

```bash
/lib/对应架构-linux/gstreamer-1.0/include/gst/gl/gstglconfig.h /usr/include/gstreamer-1.0/gst/
```
## 关于 mfplat 补丁

### !!! 此方法暂时无效 !!!

~此补丁用于修复 Gstreamer 无法解码的问题。~

~你需要运行 `get_latest_mfplat_patch.sh` 脚本来获取补丁文件。请确保：~
1.  ~网络可以连接 GitHub。~
2.  ~已安装 `curl`。~
3.  ~你使用的是最新版 Wine 主线、tkg 或 tkg-staging 的源码。~
~**注意**：每次 Wine 版本更新后都需要重新运行此脚本获取新补丁。如果不备份补丁文件，旧补丁可能不兼容新版本的源码。~

~经测试，该补丁在最新的 kron4ek wine-tkg 和 mainline 主线版本上应用失败。~

---

## 杂项

### 关于 `wine-virtual-memory.patch` (mapping.c) 应用失败

此问题已通过迭代补丁 `wine-virtual-memory2.patch` 解决。

---

## Q/A 常见问题

**Q: 使用 `patch -p1` 命令应用补丁时显示失败 (failed) 怎么办？**
**A:** 可以尝试添加 `-R` 参数进行反向操作以检查冲突：`patch -p1 -R`。如果提示，输入 `y` 尝试应用反向补丁。这有助于诊断问题，但**并非**解决方案。

**Q: 有没有更保险的 `patch` 命令参数？**
**A:** 有的：
-   使用 `--dry-run` 参数进行试运行，不实际修改文件：`patch -p1 --dry-run < patchfile.patch`
-   使用 `-N` 参数跳过已应用的补丁：`patch -Np1 < patchfile.patch`

如果有其他问题，请反馈至 Issues。针对补丁的迭代或修改，请提交 Pull Request。

---

## Proton Wine

### 关于 Proton 构建失败

构建 Proton 版本的 Wine 时可能会遇到以下问题，需要进行修复：

1.  **OpenCL 构建错误**:
    -   **提交哈希**: `dd8d73ba895`
    -   **描述**: `opencl: HACK: Build a stub dll if Unix headers are missing.`
    -   **解决方法**: 使用命令 `git show dd8d73ba895 | git apply -R` 撤销此提交，或者应用补丁文件 `fix-build_opencl.patch`。

2.  **FFmpeg 构建错误**:
    -   **提交哈希**: `063a29bc8ba`
    -   **描述**: `winedmo: Handle PCM audio big-endian formats.`
    -   **解决方法**: 使用命令 `git show 063a29bc8ba | git apply -R` 撤销此提交，或者应用补丁文件 `fix-build_ffmpeg.patch`。

### 补丁应用失败 `path-patch-universal.patch` (unixlib.c)

此补丁对应 Valve 的 Wine 提交 [a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1)。

如果应用失败，请尝试使用 `unixlib.patch` 来修复。

---

## 获取

```bash
git clone https://github.com/Waim908/wine-termux.git
```

---

## 构建指南

1.  **应用补丁**:
    进入你的 Wine 源码目录，运行以下命令来应用所需补丁（请替换 `/path/to/version/` 和 `XXX.patch` 为实际路径和补丁名）：
    ```bash
    cd /path/to/your/wine/source
    patch -p1 < /path/to/wine-termux/对应版本的文件夹/XXX.patch
    ```

2.  **设置编译环境**:
    使用 `source` 或 `.` 命令执行提供的环境变量脚本：
    ```bash
    . /path-to/wine-termux/x64.sh
    # 或
    source /path-to/wine-termux/x64.sh
    ```

3.  **配置编译选项**:
    ```bash
    ./configure ${arg[@]} --prefix=/your/installation/path/
    ```
    > **注意**: 如果配置过程中出现类似 `--without-piper` 参数不存在的警告，通常可以**忽略**，此选项不会影响非 Proton 版本 Wine 的构建。

4.  **编译并安装**:
    ```bash
    make -j$(nproc) # 使用所有可用的 CPU 核心进行编译
    make install     # 安装到 --prefix 指定的目录
    ```

---

## 致谢

感谢以下项目和开发者：

 - [airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)

 - [Frogging-Family/wine-tkg-git](https://github.com/Frogging-Family/wine-tkg-git)

 - [hostei33/wine-tkg](https://github.com/hostei33/wine-tkg)

 - [Kron4ek/Wine-Builds](https://github.com/Kron4ek/Wine-Builds)