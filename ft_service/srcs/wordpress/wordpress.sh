#!/bin/sh

chmod -R 755 /var/www/*

mkdir -p /var/www/html
mkdir /etc/nginx/sites_available/
mkdir /etc/nginx/sites_enabled/

echo "<?php phpinfo(); ?>" >> /var/www/html/index.php

mysql -hmysql -Dwordpress -uuser -ppass < /run/nginx/wordpress.sql
