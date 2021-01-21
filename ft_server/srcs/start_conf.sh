#!/bin/bash

service nginx start

mv /srcs/phpmyadmin /var/www/html/
mv /srcs/wordpress /var/www/html/
mv /srcs/nginx/mysite /etc/nginx/sites-available/
mv /srcs/nginx/ssl /etc/nginx/

unlink /etc/nginx/sites-enabled/default
ln -s /etc/nginx/sites-available/mysite /etc/nginx/sites-enabled/

chown -R www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/

printf "1\n1\n4\n" | dpkg -i /srcs/mysql/mysql-apt-config_0.8.16-1_all.deb
apt-get update

debconf-set-selections <<< 'mysql-community-server mysql-community-server/root-pass password '
debconf-set-selections <<< 'mysql-community-server mysql-community-server/re-root-pass password '
apt-get -y install mysql-server

service mysql start

echo "CREATE DATABASE wordpress; ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'tpgns120'; GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost'; FLUSH PRIVILEGES;" | mysql

service mysql restart
service nginx restart
service php7.3-fpm start
service php7.3-fpm restart

bash
