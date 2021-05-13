FROM alpine:3.12.0
MAINTAINER saoh

COPY default.conf /etc/nginx/
COPY nginx.sh /etc/nginx/

RUN apk update && apk --update --no-cache add nginx openssh-server openssl
RUN chmod +x /etc/nginx/nginx.sh

EXPOSE 80 443 22

ENTRYPOINT ["etc/nginx/nginx.sh"]
