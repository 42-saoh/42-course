#!/bin/sh

mydir -p /run/mysqld

mysql_install_db --user=root > /dev/null

echo "CREATE DATABASE IF NOT EXISTS wordpress;
        FLUSH PRIVILEGES;
        GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY 'pass' WITH GRANT OPTION;
        FLUSH PRIVILEGES;" > cmd.sql
mysqld -u root --bootstrap < cmd.sql
mysqld -u root

