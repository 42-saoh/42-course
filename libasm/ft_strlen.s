section .text
	global _ft_strlen

_ft_strlen :
	xor rcx, rcx

roop :
	cmp BYTE [rdi + rcx], 0
	je end
	inc rcx
	jmp roop

end :
	mov rax, rcx
	ret
