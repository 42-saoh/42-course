section .text
	global _ft_strcmp

_ft_strcmp :
	xor rcx, rcx

cmpstr :
	mov dh, BYTE [rdi + rcx]
	cmp BYTE [rsi + rcx], dh
	je same_str

end :
	mov dl, BYTE [rdi + rcx]
	sub dl, BYTE [rsi + rcx]
	movsx rax, dl
	ret

same_str :
	cmp dh, 0
	je end
	inc rcx
	jmp cmpstr
