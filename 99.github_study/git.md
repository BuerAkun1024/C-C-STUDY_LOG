### 关于github的一些操作 

> 参考：https://blog.csdn.net/hc_ttxs/article/details/79375788   密钥对生成

1. 申请github账号

2. 再github上创建 public 或者 private 仓库

3. 下载git版本控制软件，右键gitbash启动。

4. 将远程的github与本地的绑定

   ```shell
   # 本地生成密钥
   $ ssh-keygen -t rsa -C "1641070658@qq.com"  
   # 在user/your_user_name/.ssh/* 中找到已经生成的公钥，复制其内容并将其放到github指定位置
   # 验证
   $ ssh -T git@github.com
   Enter passphrase for key '/c/Users/Buer_Akun/.ssh/id_rsa': # 在这里输入密码 之前没输就不用管
   Hi BuerAkun1024! You've successfully authenticated, but GitHub does not provide shell access.
   # 设置用户名 全局 
   $ git config --global user.name "BuerAkun1024"
   # 设置邮箱 全局
   $ git config --global user.email "1641070658@qq.com"
   ```

5. github基本操作：

   ```shell
   $ git status # 查看修改过的文件
   $ git add . # 将所有修改加入到舞台区
   $ git commit -m "描述" # 将修改提交
   $ git push # 将修改推到远端仓库
   ```

6. 分支操作



7. 冲突操作