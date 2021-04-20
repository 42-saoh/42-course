section .text
	global _ft_atoi_base

_ft_atoi_base :
	cmp rsi, 0
	je error_end
	cmp BYTE [rsi], 0
	je error_end
	cmp BYTE [rsi + 1], 0
	je error_end
	cmp rdi, 0
	je error_end
	xor rcx, rcx
	jmp check_base

up_rc :
	inc rcx

check_base :
	cmp BYTE [rsi + rcx], 0
	je set_str
	cmp BYTE [rsi + rcx], 43
	je error_end
	cmp BYTE [rsi + rcx], 45
	je error_end
	cmp BYTE [rsi + rcx], 32
	je error_end
	cmp BYTE [rsi + rcx], 9
	je error_end
	cmp BYTE [rsi + rcx], 10
	je error_end
	cmp BYTE [rsi + rcx], 11
	je error_end
	cmp BYTE [rsi + rcx], 12
	je error_end
	cmp BYTE [rsi + rcx], 13
	je error_end
	cmp BYTE [rsi + rcx], 14
	je error_end
	mov rdx, rcx
	inc rdx

roop_base :
	cmp BYTE [rsi + rdx], 0
	je up_rc
	mov al, BYTE [rsi + rdx]
	cmp BYTE [rsi + rcx], al
	je error_end
	inc rdx
	jmp roop_base

set_str :
	mov rbx, rcx
	xor rcx, rcx
	xor rax, rax
	mov rdx, 1
	jmp check_str
	
up_rcx :
	inc rcx

check_str :
	cmp BYTE [rdi + rcx], 32
	je up_rcx
	cmp BYTE [rdi + rcx], 9
	jc check_str2
	cmp BYTE [rdi + rcx], 14
	je check_str2
	jnc check_str2
	jmp up_rcx

minus :
	imul rdx, -1

plus :
	inc rcx

check_str2 :
	cmp BYTE [rdi + rcx], 43
	je plus
	cmp BYTE [rdi + rcx], 45
	je minus
	push rdx
	jmp get_num

get_result :
	imul rax, rbx
	add rax, r8
	inc rcx

get_num :
	cmp BYTE [rdi + rcx], 0
	je end
	mov r8, 0

get_num2 :
	cmp BYTE [rsi + r8], 0
	je end
	mov dl, BYTE [rsi + r8]
	cmp BYTE [rdi + rcx], dl
	je get_result
	inc r8
	jmp get_num2


error_end :
	mov rax, 0;
	ret

end :
	pop rdx
	imul rax, rdx
	ret
