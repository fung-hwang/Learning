### 控制台查看sqlite数据库中的数据

1. adb shell（需配置环境）

2. ~~改权限 chmod 777 /data/data/<包名>~~

3. 进入文件夹 cd /data/data/<包名>/databases

4. （命令）sqlite3 dbname.db

5. 常用命令
  + .table 查看表
  + .schema （逆向）查看sql语句
  + SQL语句
