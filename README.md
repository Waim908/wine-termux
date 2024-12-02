# wine-termux

你可以通过切换分支查看对应版本的代码 实际上只是修改了临时目录路径为 /data/data/com.termux/usr/tmp 挂载z盘为 /data/data/com.termux/usr/glibc

You can switch branches to view the code for the corresponding version.
In fact, it simply modifies the temporary directory path to
/data/data/com.termux/usr/tmp
and mounts the Z drive to
/data/data/com.termux/usr/glibc.

Releases 文件不是传统的wow64构建，构建时选项--enable-archs=i386,x86_64，故bin目录没有wine64，直接运行wine即可

The Releases file is not a traditional wow64 build. The build options used are --enable-archs=i386,x86_64, so the bin directory does not contain wine64. You can run wine directly.