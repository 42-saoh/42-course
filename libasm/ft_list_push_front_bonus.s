section .text
	global _ft_list_push_front
	extern _malloc

_ft_list_push_front :
	push rsp
	push rdi
	push rsi
	xor rax, rax
	mov rdi, 16
	call _malloc
	pop rsi
	pop rdi
	cmp rax, 0
	je end
	mov [rax], rsi
	mov rdx, [rdi]
	mov [rax + 8], rdx
	mov [rdi], rax

end :
	pop rsp
	ret
