# Docker

## 도커란?

어쩌고 저쩌고 가상환경 ..

environmental disparity

## 컨테이너란?

집에 여러 컨테이너 거주 가능.. 수도랑 전기 공유

## 도커 이미지?

환경 세팅해서 고대로 냉동

## 도커 이미지 다운받고 실행하기

[https://hub.docker.com/](https://hub.docker.com/)


### 1. 컴퓨터 내 도커 이미지 보기

```c
docker images
```

### 2. 도커 이미지 다운받아 컨테이너로 만들어 바로 실행하기(pull & create & start & attach)

```c
docker run -it {이미지명}:{태그}
```


|옵션 | 설명|
---
|-it | 컨테이너로 들어갔을 때 bash로 CLI 입출력을 사용할 수 있도록 해 줍니다.|
|--name | 컨테이너 이름붙이기(수동)|
|-v | 컨테이너와 내 컴퓨터의 특정 폴더 공유(v for volume)|
|-d | 뒤에서 알아서 돌아가라(난 터미널 그대로 사용할거임)|


### 2-1. 도커 이미지 다운받기

```c
docker pull {이미지명}:{태그}
```

### 2-2. 이미지 해동해서 컨테이너 생성하기

```c
docker create {옵션} {이미지명}:{태그}
```

### 2-3. 컨테이너 시작하기(이미지에 CMD로 지정해놓은 작업 시키기)

```c
docker start {컨테이너 id 또는 이름}
```

### 2-4. 컨테이너로 들어가기(컨테이너 내 CLI 이용하기)

```c
docker attach {컨테이너 id 또는 이름}
```

## 컨테이너 보기

### 작업중인 컨테이너만 보기

```c
docker ps
```

### 전부 다 보기

```c
docker ps -a
```

### 컨테이너 삭제하기

```c
docker rm {name or id}
```

### 이미지 삭제하기

```c
docker rmi {name or id}
```

### 강제로 이미지&컨테이너 삭제하기

- 이미지 삭제 전 컨테이너를 먼저 삭제해야하나, -f 옵션 사용

```c
docker rmi -f {name or id}
```

## 도커파일

- 공식 이미지 수정해서 튜닝버전 만들기 위한 설계도

<p align = "center"><img src = "https://github.com/euiminnn/image-upload/blob/master/docker%20file.png" width = "600"></p>


### RUN & COPY

- 이미지 생성 과정에서 실행되는 명령어

### CMD & VOLUME

- 컨테이너 실행시 실행되는 명령어

### 도커파일로 이미지 만들기

```c
docker build -t {만들어질 이미지 이름} .

// 마지막 . 은 Dockerfile로의 상대주소
// file명이 Dockerfile이라면 따로 명시할 필요 없음
```


<p align = "center"><img src = "https://github.com/euiminnn/image-upload/blob/master/docker%20build.png" width = "600"></p>

→ 이런식으로 도커파일에 적힌 내용 실행함

### 컨테이너 생성과 실행

```c
docker run --name {만들어질 컨테이너 이름} -v $(pwd):/home/node/app -p 8080:8080 {실행할 이미지 이름}
```

-v $(pwd):/home/node/app : 내 컴퓨터의 현위치(pwd)에 있는 파일들을 컨테이너의 /home/node/app에 복사

(얄코 예시)

<p align = "center"><img src = "https://github.com/euiminnn/image-upload/blob/master/container%20execute.png" width = "600"></p>

