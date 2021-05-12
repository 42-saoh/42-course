#!/bin/sh

rm /etc/nginx/conf.d/default.conf
mv /etc/nginx/default.conf /etc/nginx/conf.d/

mkdir -p /etc/nginx/ssl
openssl req -new -x509 -nodes -newkey rsa:4096 -keyout localhost-nginx.key -out localhost-nginx.crt -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=saoh/CN=localhost"
mv localhost-nginx.key /etc/nginx/ssl/nginx.key
mv localhost-nginx.crt /etc/nginx/ssl/nginx.crt

mkdir -p run/nginx
ln -s /var/lib/nginx/html /var/www/

/usr/sbin/sshd
/usr/sbin/nginx -g "daemon off;"
