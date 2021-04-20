section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc

_ft_strdup :
	call _ft_strlen
	push rdi
	mov rdi, rax
	inc rdi
	call _malloc
	pop rdi
	xor rcx, rcx

put_data :
	mov dl, BYTE [rdi + rcx]
	mov BYTE [rax + rcx], dl
	cmp BYTE [rdi + rcx], 0
	je end
	inc rcx
	jmp put_data

end :
	ret
