export script_dir="$(dirname $(readlink -f "$0"))"
apply_patch() {
  if [[ -d $script_dir/$1/$2 ]]; then
    . $script_dir/$1/$2/___patch___.conf
    for i in "${patchFileArry[@]}"; do
      if ! patch -p1 < $script_dir/$1/$2/$i; then
        echo "Apply $i for $1/$2 failed"
        return 1
      fi
    done
  else
    echo "No Version Patch files=>$1/$2"
  fi
}

if [[ $1 == proton ]]; then
  apply_patch proton $2 || exit 1
fi