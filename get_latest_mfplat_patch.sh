RAW_URL="https://raw.githubusercontent.com/Frogging-Family/wine-tkg-git/master/wine-tkg-git"
if ! curl --progress-bar -o "${PWD}/gstreamer-patch1.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch1.patch; then
    echo "补丁下载失败"
fi
echo "此版本是否使用了staging补丁？(Kron4ek版本已经应用，如果不是这个版本自行判断)"
read -n 1 -p "Y/n/任意字符退出" is_staging
case $is_staging in
    Y|y)
        if ! curl --progress-bar -o "${PWD}/gstreamer-patch2.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch2.patch; then
            echo "补丁下载失败"
        fi 
    ;;
    N|n)
        if ! curl --progress-bar -o "${PWD}/gstreamer-patch2.patch" $RAW_URL/wine-tkg-patches/proton/proton-mf-patch/gstreamer-patch2-non-staging.patch; then
            echo "补丁下载失败"
        fi 
    ;;
    *) exit ;;
esac