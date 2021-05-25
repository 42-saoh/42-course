FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add bash openssl vsftpd

ARG PASV=${pasv_address}

ENV FTP_USER=user \
	FTP_PASS=pass \
	PASV_ENABLE=YES \
	PASV_MIN_PORT=20000 \
	PASV_MAX_PORT=20003 \
	NODE_ADDRESS=${PASV}

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ftps.sh /usr/sbin/ftps.sh

RUN chmod +x /usr/sbin/ftps.sh

EXPOSE 20 21 20000-20004

ENTRYPOINT ["/usr/sbin/ftps.sh"]
