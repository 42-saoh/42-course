#!/bin/sh

mkdir -p /var/ftp/user
mkdir -p /etc/ssl/private
mkdir -p /etc/ssl/certs

openssl req -new -x509 -nodes -newkey rsa:2048 -keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt -days 365 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/CN=localhost"

adduser -D $FTP_USER -h /var/ftp/user
chown $FTP_USER:$FTP_USER /var/ftp/user
echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd

vsftpd /etc/vsftpd/vsftpd.conf
