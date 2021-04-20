section .text
	global _ft_strcpy

_ft_strcpy :
	xor rcx, rcx

put_str :
	mov dl, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], dl
	cmp BYTE [rsi + rcx], 0
	je end
	inc rcx
	jmp put_str

end :
	mov rax, rdi
	ret
