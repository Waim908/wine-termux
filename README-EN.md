##### Language: [中文](README.md) [English](README-EN.md)

# wine-termux

Patches to enable x86_64 Wine to run properly in the Termux glibc box64 environment, along with some issue fixes.

## About Some Patch Files

**`wine_do_not_create_dxgi_manager.patch`**: This patch fixes the H264 decoding issue in GStreamer Unity games by adding the variable `WINE_DO_NOT_CREATE_DXGI_MANAGER`. <u>Note: This is still not a definitive solution, and this variable must be set to 1. If set to 0, some games may fail to run or encounter issues.</u>

**`esync2.patch`**: The solution is based on instructions from <u>hostei33</u>. For details, refer to the repository [wine-tkg glibc branch](https://github.com/hostei33/wine-tkg).

<u>Only one of `esync.patch` or `esync2.patch` should be applied.</u>

## About mfplat Patch

Fixes GStreamer decoding issues.

Use `get_latest_mfplat_patch.sh` to obtain the patch file. Ensure you have an internet connection to GitHub and have `curl` installed. Also, make sure you are using the latest mainline, TKG, or TKG-staging source code. This script must be run every time the version is updated. If the patch file is not backed up, it may not be compatible with older source code versions.

## Miscellaneous

### About "wine-virtual-memory.patch" => mapping.c Patch Application Failure

The patch has been updated to `wine-virtual-memory2.patch`.

### Q/A

**Q:** What should I do if the `patch -p1` command fails after applying a patch?  
**A:** You can add the `-R` parameter: `patch -p1 -R`. If prompted, enter `y` to apply the patch.

**Q:** Are there safer parameters for the `patch` command?  
**A:** Yes. You can add `--dry-run` for a trial run, or replace `-p1` with `-Np1` to skip existing modifications.

If you encounter other issues, please report them via Issues. For patch updates or modifications, submit a pull request.

## Proton Wine

### About Proton Build Failures

Use `git show [corresponding commit hash] | git apply -R` or apply the patch files `fix-build_opencl.patch` and `fix-build_ffmpeg.patch`.

#### opencl
`dd8d73ba895`: opencl: HACK: Build a stub dll if Unix headers are missing.

#### ffmpeg
`063a29bc8ba`: winedmo: Handle PCM audio big-endian formats.

### Patch Application Failure for "path-patch-universal.patch" => unixlib.c

[a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1](https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1)

Fix using `unixlib.patch`.

## Download

```bash
git clone https://github.com/Waim908/wine-termux.git
```

## Build Parameters

Errors about non-existent parameters like `--without-piper` can be ignored. This option does not affect the build of non-Proton Wine versions.

Apply patches from the "corresponding version folder/XXX.patch".

Navigate to your source code directory:

```bash
patch -p1 < /path/to/version/XXX.patch
. /path-to/x64.sh  # or `source` this file
./configure ${arg[@]} --prefix=/xxx/
make -j$(nproc) && make install
```

# Thanks
[airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)  
[Frogging-Family/wine-tkg-git](https://github.com/Frogging-Family/wine-tkg-git)