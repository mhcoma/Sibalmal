# Sibalmal
난해하지 않은 난해한 프로그래밍 언어

Sibalmal은 괄호류를 제외한 아스키 코드 글자 하나가 명령어로 해석되는 인터프리터 방식의 프로그래밍 언어입니다.

https://blog.naver.com/bmh4080/221487749470
주소에서 받을 수 있는 파일은 Winodws용 인터프리터이며 여기 있는 소스와는 다르게 유니코드로 입출력이 이루어집니다.  
Sibalmal 코드의 확장자로는 .sibalmal이 권장됩니다.

## 예제
### Hello, world! 출력
	89*:@39*2++:@7+:::@@3+:@48*::34*+@@,::8+@@3+@:@8-@1+@
### 수를 입력받아 입력받은 크기로 삼각형 별찍기
저장공간 간의 이동은 불필요하지만 빠른 이해를 위해 추가했음.  

	x372**z55+a`:?:Bb:?x:@b1-:\z:@a1-:\
  
	*****  
	****  
	***  
	**  
	*  
	
	x372**z55+a1`:.:,<~?;:B;b:?x:@b1-:\z:@a:.1+:,<~\
  
	*  
	**  
	***  
	****  
	*****  
	
	x372**y48*z55+a`::?:.:,-Cc:?y:@c1-:\a;:B;b:?x:@b1-:\z:@a;1-:,\
  
	*****  
	 ****  
	  ***  
	   **  
	    *  
	
	x372**y48*z55+a1`:.:,<~?:.:,-Cc:?y:@c1-:\a;:B;b:?x:@b1-:\z:@a:.1+:,<~\
  
	    *  
	   **  
	  ***  
	 ****  
	*****  
### 99병의 맥주 출력
상당히 급조한 코드라 허점이 존재할 수 있음.

	q48*::R34*+:R25*S2+St55+:1+:,*:9+:8-:.-:,q:Tt.1+.:,:1+q:Tt.:,54+-::,6+.4-:85+-.:U,u:55+-;:7+:6-:3+:88+1+-q:Uu.:,88++:56+-q:Uu.:,78++:.:,3-::V87++v4+:67++:3-:2-q:Vv.:,:8+:2+:4+q:Vv.:,255+*+:4-.:,3-q:Vv.:,1-:55++:76+-q:Vv.:,:67++:3-:5+:1-q:Vv.:,:3+:66++q:Vv.:,55++:5+q:Vv.:,55++:55+4*-.:,Ww:67++:3-:,:2-q:Ww.:1-:Xx2-::56+-:56+2*+q:Xx.:,7-:3+:66++q:Xx.:,2+:1+:Yy3+::Z67+-:::ZZ:3-:Zq:Yy:Z.:,66+-:Z:9+:Zq:Yy:Z.:,1+:77+-:Z:7+:Z:8+::::ZZ5-:Z:67+-:Zuq:Uu.:,:55++:67+-a99*99++::?:#q:@a::1-:? y0,:?:,@:\ 0\a~? z0,:?:,@:\ 0\aq:@x0,:?:,@:\ r0,:?:,@:\ a:#q:@a::1-:? y0,:?:,@:\ 0\a~? z0,:?:,@:\ 0\s0,:?:,@:\ t0,:?:,@:\ q:@u0,:?:,@:\ r0,:?:,@:\ a1-:::? :#0\:~? w0,:?:,@:\ 0\q:@a:1-:? y0,:?:,@:\ 0\:~? z0,:?:,@:\ 0\q:@x0,:?:,@:\ s0,:?:,@:\ 55+@a\w48*-0,:?:,@:\ 48*+q:@y0,:?:,@:\ q:@x0,:?:,@:\ r0,:?:,@:\ w0,:?:,@:\ q:@y0,:?:,@:\ s0,:?:,@:\ v0,:?:,@:\ r0,:?:,@:\ a.#q:@y0,:?:,@:\ q:@x0,:?:,@:\ s0,:?:,@:\ 

## 자료형
자료형은 정수형과 실수형 두 가지가 있지만 실제 사용에서는 구분할 수 없으며 하나처럼 사용됩니다.  
정수형은 4바이트, 실수형은 배정밀도 8바이트로 표현됩니다.

문자 자료형은 따로 없으며 4바이트의 부호 없는 정수를 유니코드 문자 코드로 사용합니다.  
문자열 또한 따로 없지만, 입력 시엔 끝부분에 0이 붙으며 저장공간에 역순으로 삽입됩니다.  
여기서의 0은 문자열의 끝을 알리는 역할을 합니다.

논리 자료형은 따로 없으며, 반복문에서 0은 false로, 0이 아닌 모든 수는 true로 사용합니다.  
하지만 논리 연산을 통해 얻어지는 결과에서 true는 1을 내보냅니다.

## 저장공간
저장공간은 a부터 z까지의 알파벳 이름의 Deque 26개로 구성되어있습니다.  
저장공간으로의 입출력은 Stack처럼 머리부분에서만 이루어지나,  
이동 명령어들을 통해 맨 뒤의 원소를 가져올 수도 있습니다.

## 명령어
**개행하면 다른 함수로 인식합니다. 함수 기능을 후에 추가할 예정이니 코드에서 개행하지 마세요.**
* 선택
	- **a** ~ **z**  
		각 알파벳에 해당하는 저장공간을 선택한다.
* 이동 및 복사
	- **A** ~ **Z**  
		현재 저장공간에서 값을 하나 뽑아 각 알파벳에 해당하는 저장공간에 삽입한다.
	- **:**  
		현재 스택의 맨 앞에 있는 값을 중복 삽입한다.
	- **;**  
		현재 스택의 맨 앞에 있는 두 값을 교환한다.
	- **.**  
		현재 스택의 맨 뒤에 있는 값을 뽑아 맨 앞에 삽입시킨다.
	- **,**  
		현재 스택의 맨 앞에 있는 값을 뽑아 맨 뒤에 삽입시킨다.
	* 응용
		- **.;,**  
			현재 스택의 맨 앞과 맨 뒤에 있는 값을 교환한다.
		- **.:,**  
			현재 스택의 맨 뒤에 있는 값을 맨 앞에 중복 삽입한다.
* 입력
	- **0** ~ **9**  
		현재 저장공간에 각 숫자에 해당하는 정수를 삽입한다.
	- **`**  
		현재 저장공간에 숫자를 입력받아 삽입한다.  
		입력한 수에 '.'이 포함되어있을 경우 실수형으로 삽입되지만,  
		정수와 동일할 경우 정수형으로 삽입된다.
	- **'**  
		현재 저장공간에 문자를 입력받아 삽입한다.
	- **"**  
		현재 저장공간에서 값을 하나 뽑아 입력 종료문자로 설정한 뒤,  
		현재 저장공간에 0을 삽입하고,  
		입력 종료문자가 나올 때까지 문자열을 입력받아 거꾸로 저장공간에 삽입한다.  
		입력 종료문자가 0일 경우 아무 공백이 나올 때까지 입력받는다.
* 출력
	- **#**  
		현재 스택에서 값을 하나 뽑아 정수형으로 출력한다.
	- **^**  
		현재 스택에서 값을 하나 뽑아 실수형으로 출력한다.
	- **@**  
		현재 스택에서 값을 하나 뽑아 해당하는 문자로 출력한다.
	- **(spacebar)**  
		현재 스택에서 값을 하나 뽑아 버린다.
* 연산  
	명령어에 따라 현재 저장공간에서 값을 한 번, 혹은 두 번 뽑는다.  
	이 설명에서는 두 번 뽑을 경우 먼저 뽑은 값을 b, 나중에 뽑은 값을 a라 칭한다.
	* 산술 연산  
		나눗셈을 제외하면, a와 b 중 하나라도 실수형일 경우의 반환값은 실수형, 아니라면 정수형이다.
		- **\+**  
			a와 b를 더한 값을 삽입한다.
		- **\-**  
			a에서 b를 뺀 값을 삽입한다.
		- **\***  
			a에 b를 곱한 값을 삽입한다.
		- **/**  
			a를 b로 나눈 몫을 실수형으로 삽입한다.
		- **%**  
			a를 b로 나눈 나머지를 삽입한다.
	* 비교 연산
		- **\=**  
			a와 b가 같으면 1을, 아니면 0을 삽입한다.
		- **>**  
			a가 b보다 크면 1을, 아니면 0을 삽입한다.
		- **<**  
			a가 b보다 작으면 1을, 아니면 0을 삽입한다.
	* 논리 연산
		- **&**  
			a와 b가 둘 다 1이면 1을, 아니면 0을 삽입한다.
		- **|**  
			a와 b 중 하나라도 1이면 1을, 아니면 0을 삽입한다.
		- **~**  
			a가 1이면 0을, 아니면 1을 삽입한다.
	* 응용
		- **=~**  
			a와 b가 같지 않으면 1을, 아니면 0을 삽입한다.
		- **>~**  
			a가 b보다 크거나 같으면 1을, 아니면 0을 삽입한다.
		- **<~**  
			a가 b보다 작거나 같으면 1을, 아니면 0을 삽입한다.
		- **&~**  
			a와 b 중 하나라도 0이면 1을, 아니면 0을 삽인한다.
		- **|~**  
			a와 b가 둘 다 0이면 1을, 아니면 1을 삽입한다.
* 제어
	- **?**  
		현재 저장공간이 비어있지 않다면,  
		값을 하나 뽑아 그 값이 0이 아니면 같은 수준의 '\\'가 나올 때까지  
		명령을 수행한 뒤 다시 제자리로 점프한다.  
		저장공간이 비어있거나 뽑은 값이 0이면 같은 수준의 '\\'까지 점프한다.  
	- **\\**  
		반복문의 범위를 지정한다.
	- **!**  
		이중 '?\\'문 안에서, 한 단계 아래 수준의 '\\'까지 점프하여 반복문을 빠져나온다.
