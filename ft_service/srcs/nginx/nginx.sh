#!/bin/sh

mkdir -p /etc/nginx/ssl
openssl req -new -x509 -nodes -newkey rsa:4096 -keyout localhost-nginx.key -out localhost-nginx.crt -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=saoh/CN=localhost"
mv localhost-nginx.key /etc/nginx/ssl/nginx.key
mv localhost-nginx.crt /etc/nginx/ssl/nginx.crt

ssh-keygen -A
adduser --disabled-password ${SSH_USERNAME}
echo "${SSH_USERNAME}:${SSH_PASSWORD}" | chpasswd

mkdir -p /run/nginx
echo "<h1> WELLCOM NGINX </h1>" >> /var/www/index.html

/usr/sbin/sshd
/usr/sbin/nginx -g "daemon off;"

/bin/sh
