export script_dir="$(dirname $(readlink -f "$0"))"
proton_apply_patch() {
  if [[ -d $script_dir/$1/$2 ]]; then
    . $script_dir/$1/$2/___patch___.conf $3
    echo "${patchFileArry[@]}"
    [[ ! -z ${patchFileArry[@]} ]] || exit 1
    for i in "${patchFileArry[@]}"; do
      [[ -f $script_dir/$1/$2/$i ]] || exit 1
      echo "Apply $1/$2/$i"
      if ! patch -p1 <$script_dir/$1/$2/$i; then
        echo "Apply $i for $1/$2 failed"
        return 1
      fi
    done
  else
    echo "Not Version Patch files=>$1/$2"
  fi
}

wine_apply_patch() {
  if [[ -d $script_dir/$1 ]]; then
    . $script_dir/$1/___patch___.conf $2
    echo "${patchFileArry[@]}"
    [[ ! -z ${patchFileArry[@]} ]] || exit 1
    for i in "${patchFileArry[@]}"; do
      [[ -f $script_dir/$1/$i ]] || exit 1
      echo "Apply $1/$i"
      if ! patch -p1 <$script_dir/$1/$i; then
        echo "Apply $i for $1 failed"
        return 1
      fi
    done
  else
    echo "Not Patch files=>$1"
  fi
}

copy_patches() {
  if [[ -d $script_dir/$1 ]]; then
    . $script_dir/$1/___patch___.conf $2
    echo "${patchFileArry[@]}"
    [[ ! -z ${patchFileArry[@]} ]] || exit 1
    for i in "${patchFileArry[@]}"; do
      [[ -f $script_dir/$1/$i ]] || exit 1
      echo "Copy $1/$i to $3"
      cp $script_dir/$1/$i $3/
    done
  else
    echo "Not Patch files=>$1"
  fi
}

add_tkg_mfdxgi() {
  if [[ -z $ENABLE_PROTON_MF ]] || [[ $ENABLE_PROTON_MF == false ]] || [[ $ENABLE_PROTON_MF == 0 ]]; then

    ver=$2 # 10.14
    major_ver=$(echo "$ver" | cut -d. -f1)
    minor_ver=$(echo "$ver" | cut -d. -f2)

    echo "mfdxgi: Add env \'\$WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER\' only (no full proton mf patch)"

    if [ "$major_ver" -eq 9 ]; then
      cp "$script_dir/wine9_do_not_create_dxgi_device_manager.patch" $3/wine9_do_not_create_dxgi_device_manager.mylatepatch || exit 1
    elif [ "$major_ver" -ge 10 ] && [ "$minor_ver" -ge 4 ]; then
      cp "$script_dir/wine_do_not_create_dxgi_device_manager2.patch" $3/wine_do_not_create_dxgi_device_manager2.mylatepatch || exit 1
    else
      echo "error"
    fi
  fi
}

case $1 in
proton) proton_apply_patch proton $2 || exit 1 ;;
wine-tkg) wine_apply_patch wine-tkg-git-staging-ge $2 || exit 1
  add_tkg_mfdxgi ;;
wine-tlg-auto) copy_patches wine-tkg-git-staging-ge $2 $3 || exit 1
  add_tkg_mfdxgi ;;
esac
