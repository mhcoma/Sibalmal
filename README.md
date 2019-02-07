# Ezlang
난해하지 않은 난해한 프로그래밍 언어

## 예제
### 수를 입력받아 입력받은 크기로 삼각형 별찍기
	x372**z55+a`:?:Bb:?x:@b1-:\z:@a1-:\
결과 :  
	*****  
	****  
	***  
	**  
	*  
	
	x372**z55+a1`:.:,<~?;:B;b:?x:@b1-:\z:@a:.1+:,<~\
결과 :  
	*  
	**  
	***  
	****  
	*****  
	
	x372**y48*z55+a`::?:.:,-Cc:?y:@c1-:\a;:B;b:?x:@b1-:\z:@a;1-:,\
결과 :  
	*****  
	 ****  
	  ***  
	   **  
	    *  
	
	x372**y48*z55+a1`:.:,<~?:.:,-Cc:?y:@c1-:\a;:B;b:?x:@b1-:\z:@a:.1+:,<~\
결과 :  
	    *  
	   **  
	  ***  
	 ****  
	*****  


## 명령어
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
		현재 저장공간에 0을 삽입하고,  
		현재 저장공간에서 값을 하나 뽑아 입력 종료문자로 설정한 뒤,  
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
		나눗셈을 제외하면, a와 b 중 하나라도 실수형이면 반환값은 실수형,  
		아니라면 정수형이다.
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
