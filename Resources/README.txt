此文件夹内存放需要使用的资源文件，请按照以下结构存放，如有资源名字调整，请到编译脚本里修改相关脚本代码。

├── WeChat.app 	被调试的目标app
├── WeChat_arm64	目标64位二进制，强烈建议恢复符号
└── WeChat_armv7	目标32位二进制，强烈建议恢复符号
└── 其他文件
└── ......

以上文件或目录可以使用`软链接`形式（不能用替身！必须是软链），避免增加磁盘占用。

```
cd Resources
ln -fs xxxxxxx/Resources/WeChat.app ~/WeChat.app
ln -fs xxxxxxx/Resources/WeChat_arm64 ~/WeChat_arm64
```
