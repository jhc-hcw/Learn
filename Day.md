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