# network_memo.md
By: echung <echung@student.42seoul.kr>

` this memo is for the subject "NETWHAT" `

# 계산문제

subnet mask는 앞에서부터 1 개수

and 연산 후 앞(mask 씌워진)부분은 Network 영역,

뒷부분은 host 영역

host 범위에서

맨 앞 하나 더 앞은 Network 주소,

맨 뒤 하나 더 뒤는 Broadcast 주소

클래스 A라면 255.0.0.0, B라면 255.255.0.0


# DHCP & DNS

IP주소 동적 할당 (현재 사용 중이지 않거나 대여 기간이 끝난 IP주소는 또 다른 곳에 자동으로 할당)

## DHCP:

Dynamic Host Configuration Protocol

which is a mechanism that automates the IP configuration, including IP address, subnet mask, default gateway, and DNS information.

DHCP employs a connectionless service model, using UDP(User Datagram Protocol)

	SMTP - TCP

	FTP - TCP

	HTTP - TCP(HTTP can use UDP but only for recent ones. eg.HTTP3)

## DNS:

Domain Name System

영문으로 쓰여진 이름과 숫자로 된 IP주소 연결


# TCP vs. UDP

## TCP:

Transmission Control Protocol

신뢰성(3handshake)

connection oriented

sequencing 데이터 순서 부여, 흐름제어

## UDP:

User Datagram Protocol

속도

datagram oriented

basic error checking mechanism only(checksum이용)

broadcasting available


# Class
5 classes(A ~ E) available for IPv4

## A class

- IP address starts with 1 ~ 126
- Private IP 10.0.0.0 ~ 10.255.255.255

## B class

- IP address starts with 128 ~ 191
- Private IP 172.16.0.0 ~ 172.31.255.255

## C class

- IP address starts with 192 ~ 223
- Private IP 192.168.0.0 ~ 192.168.255.255


# localhost

127.0.0.1


# IPv4 vs. IPv6

## IPv4

32bits, 5클래스(A~E)

8비트 2진수의 10진수 표기법

e.g. http://naver.com → `125.209.222.141`

DNS 통해서 문자↔숫자

## IPv6

128bits

e.g. `2001:0db8:85a3:0000:0000:8a2e:0370:7334`

(googled "an example of IPv6 address")


# Ping

Ping operates by sending ICMP(Internet Control Message Protocol) echo request packets to the target host and waiting for an ICMP echo reply.
