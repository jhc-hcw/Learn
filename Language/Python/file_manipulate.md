### 路径操作和平台相关

```Python
import os

myfile = ['aaaa.txt', 'bbb.txt', 'cccc.txdt']
for name in myfile:
    print(os.path.join('c\\dd\\bb', name))  #利用join函数拼接路径，与平台无关。
print(os.getcwd())  # 获取当前工作路径
os.chdir("D:\\")  #改变工作路径
print(os.getcwd())
os.chdir(os.path.join(os.getcwd(),"Test","Python"))
print(os.getcwd())
#os.makedirs(os.path.join(os.getcwd(),'aa','bb','vv','dd')) #递归建立文件夹
print(os.path.abspath('.'))  #根据相对路径返回绝对路径
print(os.path.isabs('.'))   #判断是否是绝对路径
print(os.path.isabs(os.path.abspath('.')))
print(os.path.relpath('D:\\Test','D:\\'))    #以后面参数为基准（当作绝对根路径），返回路径的相对地址
print(os.path.basename('D:\\Test\\a.txt'))   #返回路径末尾的最后一个斜杠后的名字（返回文件名）
print(os.path.dirname('D:\\Test\\a.txt'))    #返回最后斜杠之前文件路径（返回文件所在路径)
apath='D:\\Test\\a.txt'
print(apath.split(os.path.sep))  #os.path.sep获取当前系统文件路径分割符 ，在动用字符串方法发分割。
print(os.path.getsize(apath) ) #获得文件大小
print(os.path.getsize(os.path.dirname(apath)))   #获取路径大小不会递归4096
print(os.path.getsize('D:\\'))  #获取路径大小是错误的，8192
print(os.listdir(os.path.dirname(apath)))  #获取目录下文件列表
print(os.path.exists(apath))  #几个判断函数
print(os.path.isdir(apath))
print(os.path.isfile(apath))
```

### 目录修改文件修改

```python
import os
import shutil

apath='D:\\Test\\a.txt'
print(shutil.move(r'D:\Test\a.txt',r'D:\\b.txt'))      #移动或者重命名文件或目录
print(shutil.move(r'D:\Test\Python\aa',r'D:\Test\Python\aaa'))
print(shutil.move(r'D:\Test\Python\aaa',r'D:\Test\Python\aa'))
print(shutil.copy(r'D:\b.txt',apath))  #只能复制文件，如果右边是文件，左边也是文件，就复制过去，并替换文件名 返回复制后的路径
print(shutil.copytree(r'D:\Test\Python\aa',r'D:\Test\aa'))  #递归复制目录的时候，会将源目录名替换目的目录名，所以目录目录名不存在才能成功。
print(shutil.rmtree(r"D:\Test\aa"))  #递归删除目标目录
```

### 大杀器，便利操作目录

```python
import os


for folderName ,subfolders, filenames in os.walk(r'D:\Test\Python'):   #直接递归遍历完给定目录，将三个参数返回在循环里操作。迭代器类似于返回一个目录信息。
    print('current folder is' + folderName)
    for subfolder in subfolders:
        print('subfolder is'+ folderName+':'+subfolder)
    for filename in filenames:
        print('file inside'+folderName+': '+filename)
    print('---------------')

```

