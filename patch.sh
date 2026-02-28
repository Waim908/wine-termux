export script_dir="$(dirname $(readlink -f "$0"))"
proton_apply_patch() {
  if [[ -d $script_dir/$1/$2 ]]; then
    . $script_dir/$1/$2/___patch___.conf $3
    echo "${patchFileArry[@]}"
    [[ ! -z ${patchFileArry[@]} ]] || exit 1
    for i in "${patchFileArry[@]}"; do
      [[ -f $script_dir/$1/$2/$i ]] || exit 1
      echo "Apply $1/$2/$i"
      if ! patch -p1 < $script_dir/$1/$2/$i; then
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
      if ! patch -p1 < $script_dir/$1/$i; then
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

case $1 in
proton) proton_apply_patch proton $2 || exit 1 ;;
wine-tkg) wine_apply_patch wine-tkg-git-staging-ge $2 || exit 1 ;;
wine-tlg-auto) copy_patches wine-tkg-git-staging-ge $2 $3 || exit 1 ;;
;;
esac