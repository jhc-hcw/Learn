# 2022.7.27

```text
sudo dpkg -i path_to_deb_file  /*安装deb包*/
```

- 给爷记住了。

  ```text
  git remote add origin git@github.com:user_name/repositories
  ```

- 将本地仓库与远程仓库关联

  ```test
  git push -u origin master
  ```
- 将本地的master分支推送到远程仓库

```test
git pull 
```
- 等同于git fetch先下载另一个仓库的分支在进行给git merge  

  include_drectories("path")
  添加所有目标头文件的搜索路径
  target_include_drectories(demo public/private/interface  "drectory")
  为目标添加头文件搜索路径
  g++ main.cpp src/swap.cpp  -Iinclude -0 main
  message(${`````})
打印一条信息
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set设置变量，这里设置了CMAKE系统变量，将输出放入目录的bin目录下
option(VERSION_ENABLE "output version" ON)
添加一个配置开关选项

configure_file("项目头文件名.h.in" "编译后形成的头文件名.h")
 --用@@ 和${} 包裹的变量会被替换
在文件中添加#cmakedefine VAR ...
VAR被定义就定义出来，没有就是注释。
if(ENABLE)
	set(VAR 'aaa')
endid()



# 2022 7.30

gdb      输入:r(run) 运行程序，输入:b(break)  [函数名|行号] 进行断点，输入:info  b  可查看断电情况

输入:n(next) 向下走一行     list列出代码    quit退出    p(print)打印变量    display[变量名] 始终显示某变量

shell +命令    直接运行bash命令      set  logging on 自动记录日志到文件中

watch  变量地址    持续观察变量变化情况     info watchpoint   查看监控情况



# 2022 7.31

sudo systemctl daemon-reload 刷新



git config --global user.name "jhc"

git config --global user.email "jhc"

ssh-keygen -t rsa -C "2654192132@qq.com"

ssh -T git@github.com

sudo apt install openssh-server

## 输入查找激活：services.http.response.headers.location: account.jetbrains.com/fls-auth

# 2022 8.1

vim command mode:

ctrl + f  向下翻一页 |   ctrl +d  向下翻半页

ctrl + b 向上一页     |   ctrl + u向上半页

单输入 0  光标跳到该行首，最前面。  $    跳到末尾

gg  跳到最开头    G 跳到最末尾

/world    查找world      接下来按n移动到下一个，N上一个       ?world往上找

x    删除后面一个字符    X删除前面一个字符等于backspace

dd  删除光标一整行（吐了，应该记得），   yy  复制一行,方到粘贴板     再按p|P 粘贴

p向下粘贴   P向上粘贴         u撤销一个动作    ctrl+r 将上一次操作取消（包括撤销操作） | . 重复上一条动作。

i   光标不动，从光表前插入       a  光标向后移动一下，光标所指字母后面插入    A 走到光标最后开始插入（应该好用的）

o 向下另起一行插入    O向上另起一行插入      r和R  替换，不同的是R会一直保持

--------------------------------------------------------------------------------------------------------------------------------------------

v:  选中光标走过的字符      V：选中光标走过的那一列        ctrl+v   :矩形选框     之后：y   选区复制（到剪切板）     d    选区删除      p   粘贴(将剪切板里内容粘贴）



 

