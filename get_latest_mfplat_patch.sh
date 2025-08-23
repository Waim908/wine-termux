RAW_URL="https://raw.githubusercontent.com/Frogging-Family/wine-tkg-git/master/wine-tkg-git"
if ! curl --progress-bar -o "${PWD}/gstreamer-patch1.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch1.patch ; then
    echo "part 1 补丁下载失败"
fi
echo "此版本是否使用了staging补丁？(Kron4ek版本已经应用，如果不是这个版本自行判断)"
read -n 1 -p "Y/n/任意字符退出" is_staging
case $is_staging in
    Y|y)
        if ! curl --progress-bar -o "${PWD}/gstreamer-patch2.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch2.patch ; then
            echo "part 2 补丁下载失败"
        fi 
    ;;
    N|n)
        if ! curl --progress-bar -o "${PWD}/gstreamer-patch2.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch2-non-staging.patch ; then
            echo "part 2 no staging 补丁下载失败"
        fi 
    ;;
    *) exit ;;
esac
echo "HACK补丁可以与上面两个补丁一起应用，也可以选择不用"
if ! curl --progress-bar -o "${PWD}/proton_mf_hacks.patch" $RAW_URL/wine-tkg-patches/proton/proton_mf_hacks/proton_mf_hacks.patch ; then
    echo "HACK 补丁下载失败"
fi
echo "缺失文件夹补齐（from Proton）"
RAW_URL_PROTON="https://raw.githubusercontent.com/ValveSoftware/wine/refs/heads/proton_10.0/dlls/winegstreamer/media-converter"
if [[ -d "${PWD}"/media-converter ]]; then
    read -n 1 -p "${PWD}/media-converter文件夹已经存在，是否重新下载？" yesno_dl
    case $yesno_dl in
        Y|y) echo "下载" ;;
        N|n) echo "取消" 
        exit 0 ;;
        *) echo "取消"
        exit 0 ;;
    esac
fi
mkdir media-converter
Curl () {
    if ! curl --progress-bar -o "${PWD}/media-converter/$1" $RAW_URL_PROTON/$1; then
        echo "media-converter/$1 下载失败"
    fi
}
Curl audioconv.c
Curl audioconvbin.c
Curl fossilize.c
Curl lib.c
Curl media-converter.h
Curl murmur3.c
Curl protondemuxer.c
Curl videoconv.c
echo "复制文件夹"
echo "cp -r -p media-converter/ /path/to/your/src/dlls/winegstreamer/"