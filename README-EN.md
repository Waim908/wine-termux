# Wine for Termux

Enables x86_64 Wine to run properly in a Termux glibc and Box64 environment through patches and fixes various issues.

##### Language: [中文](README.md) | [English](README-EN.md)

---
## RELEASES  
Using wine-tkg-git as the primary build version, starting from **wine10.14**, two gstreamer decoding options are provided to address game decoding issues:  

The first option directly applies the "do not create dxgi" related patches from this repository.  

The second option uses tkg-git-staging-ge with the "proton_mf_patch" related feature enabled.

part1 => Tag includes unityH264  
part2 => Version number-tkg-git-staging-ge

## About Patch Files

### `wine_do_not_create_dxgi_manager.patch`
This patch introduces the environment variable `WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER` to fix H.264 decoding issues in Unity games using GStreamer.

> **Important Notes**:
> - This is **still not a perfect solution**.
> - This variable **must** be set to `1` (i.e., `export WINE_DO_NOT_CREATE_DXGI_MANAGER=1`). If set to `0`, some games may fail to run or encounter other issues.

### `esync.patch` and `esync2.patch`
- The `esync2.patch` solution originates from [hostei33's wine-tkg glibc branch repository](https://github.com/hostei33/wine-tkg).
- **Note**: `esync.patch` and `esync2.patch` are **mutually exclusive**. Apply only one of them.

---

## About `wine-tkg-git`

[See Details](wine-tkg-git-staging/README.md)

---

## About mfplat Patch

### !!! This method is currently ineffective !!!

~This patch aimed to fix Gstreamer decoding issues.~

~You needed to run the `get_latest_mfplat_patch.sh` script to fetch the patch file. Ensure:~
1.  ~Your network can access GitHub.~
2.  ~`curl` is installed.~
3.  ~You are using the latest Wine mainline, tkg, or tkg-staging source code.~
~**Note**: This script needed to be run after every Wine version update. Without backing up patch files, old patches might become incompatible with new source versions.~

~Testing showed this patch failed to apply on the latest kron4ek wine-tkg and mainline versions.~

---

## Miscellaneous

### Regarding `wine-virtual-memory.patch` (mapping.c) Application Failure

This issue has been resolved by the iterative patch `wine-virtual-memory2.patch`.

---

## Q/A

**Q: The `patch -p1` command fails when applying a patch. What should I do?**
**A:** You can try adding the `-R` flag for a reverse dry-run to check for conflicts: `patch -p1 -R`. If prompted, answer 'y'. This helps diagnose the issue but is **not** the solution itself.

**Q: Are there safer parameters for the `patch` command?**
**A:** Yes:
-   Use `--dry-run` for a trial run without modifying files: `patch -p1 --dry-run < patchfile.patch`
-   Use `-N` to skip already applied patches: `patch -Np1 < patchfile.patch`

If you encounter other problems, please report them via Issues. For iterations or modifications to the patches, please submit a Pull Request.

---

## Proton Wine

### About Proton Build Failures

Building the Proton version of Wine might encounter the following issues, which require fixes:

1.  **OpenCL Build Error**:
    -   **Commit Hash**: `dd8d73ba895`
    -   **Description**: `opencl: HACK: Build a stub dll if Unix headers are missing.`
    -   **Solution**: Revert this commit using `git show dd8d73ba895 | git apply -R` or apply the `fix-build_opencl.patch` file.

2.  **FFmpeg Build Error**:
    -   **Commit Hash**: `063a29bc8ba`
    -   **Description**: `winedmo: Handle PCM audio big-endian formats.`
    -   **Solution**: Revert this commit using `git show 063a29bc8ba | git apply -R` or apply the `fix-build_ffmpeg.patch` file.

### Patch Application Failure for `path-patch-universal.patch` (unixlib.c)

This patch corresponds to Valve's Wine commit [a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1).

If application fails, try using the `unixlib.patch` to fix the issue.

---

## Download

```bash
git clone https://github.com/Waim908/wine-termux.git
```

---

## Build Instructions

1.  **Apply Patches**:
    Navigate to your Wine source directory and run the following command to apply the required patches (replace `/path/to/version/` and `XXX.patch` with the actual path and patch name):
    ```bash
    cd /path/to/your/wine/source
    patch -p1 < /path/to/wine-termux/version_folder/XXX.patch
    ```

2.  **Set Build Environment**:
    Use the `source` or `.` command to execute the provided environment script:
    ```bash
    . /path-to/wine-termux/x64.sh
    # or
    source /path-to/wine-termux/x64.sh
    ```

3.  **Configure Build Options**:
    ```bash
    ./configure ${arg[@]} --prefix=/your/installation/path/
    ```
    > **Note**: Warnings about non-existent options like `--without-piper` during configuration can usually be **ignored**, as this option does not affect the build of non-Proton Wine versions.

4.  **Compile and Install**:
    ```bash
    make -j$(nproc) # Compile using all available CPU cores
    make install     # Install to the directory specified by --prefix
    ```

---

## Thanks

Thanks to the following projects and developers:

-   [airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)
-   [Frogging-Family/wine-tkg-git](https://github.com/Frogging-Family/wine-tkg-git)
-   [hostei33/wine-tkg](https://github.com/hostei33/wine-tkg)