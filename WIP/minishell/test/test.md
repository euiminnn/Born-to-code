파이프 잘 되는지

리다이렉션 잘 되는지

https://unix.stackexchange.com/questions/176235/fork-and-how-signals-are-delivered-to-processes

명령어 하나 잘되는지

명령어 여러개 잘 되는지

병렬처리 잘 되는지
ls asdf | ls -> 해보면 가끔식 출력 막 꼬임
-> 오류 난경우는 잘 되는지

command not found
no file
syntax error

asdf -> command not found
./asdf -> No such file or directory
./include -> is a directory

https://www.gnu.org/software/bash/manual/html_node/Exit-Status.html

$? 는 가장 마지막 프로그램만 해당
https://unix.stackexchange.com/questions/14270/get-exit-status-of-process-thats-piped-to-another

명령어 하나에 대헤서
^C
^\

명령어 여러개에 대해서
^C
^\

그냥
^C
