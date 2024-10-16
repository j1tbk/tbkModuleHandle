.code
getPEB proc
	push rsi
	xor rsi, rsi
	
	mov rsi, GS : [60h]
	mov rax, rsi

	pop rsi
	ret
getPEB endp

getLDR proc
	push rsi
	xor rsi, rsi

	mov rsi, rcx
	mov rsi, [rsi + 18h]
	mov rax, rsi

	pop rsi
	ret
getLDR endp

getDTE proc
	push rsi
	xor rsi, rsi

	mov rsi, rcx
	mov rsi, [rsi + 20h]
	mov rax, rsi

	pop rsi
	ret
getDTE endp

getNextDte proc
	push rsi
	xor rsi,rsi

	mov rsi, rcx
	mov rsi, [rsi]
	mov rax, rsi 

	pop rsi
	ret
getNextDte endp

getDteName proc
	push rsi
	xor rsi, rsi

	mov rsi, rcx
	mov rsi, [rsi + 50h]
	mov rax, rsi

	pop rsi
	ret
getDteName endp

getDteBase proc
	push rsi
	xor rsi,rsi

	mov rsi, rcx
	mov rsi, [rsi + 20h]
	mov rax, rsi

	pop rsi
	ret
getDteBase endp
