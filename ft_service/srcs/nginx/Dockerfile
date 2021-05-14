FROM alpine:3.12.0
MAINTAINER saoh

RUN apk update && apk --update --no-cache add nginx openssh-server openssl

COPY default.conf /etc/nginx/
COPY nginx.sh /etc/nginx/

RUN chmod +x /etc/nginx/nginx.sh

EXPOSE 80 443 22

ENTRYPOINT ["etc/nginx/nginx.sh"]
