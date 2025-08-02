# wine-termux

Fix wine patch

# fix proton 2025.8.2

## build falid
bad ffmpeg (old ffmpeg) and bad opencl (old opencl)

git show NUM | git apply -R

~dd8d73ba895~ opencl: HACK: Build a stub dll if Unix headers are missing.
~063a29bc8ba~ winedmo: Handle PCM audio big-endian formats.

## patch faild "path-patch-universal.patch" unixlib.c

https://github.com/ValveSoftware/wine/commit/a7bbfbd0b28b053da5b793cfd40ed1cce4eb99b1

## configure arg 

add `--without-piper` with "x64.sh"

apply proton/XXX.patch

`patch -p1 < /path/to/proton/XXX.patch`

`. /path-to/proton/x64.sh`
`./configure \${arg[@]}  --prefix=/xxx/`
`make -j$(nproc) && make install`

# Thanks
[airidosas252/Wine-Builds](https://github.com/airidosas252/Wine-Builds)