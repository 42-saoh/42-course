section .text
	global _ft_list_size

_ft_list_size :
	xor rax, rax
	cmp rdi, 0
	je end
	inc rax
	cmp DWORD [rdi + 8], 0
	je end
	mov rdx, [rdi + 8]
	inc rax

roop :
	cmp DWORD [rdx + 8], 0
	je end
	mov rcx, [rdx + 8]
	inc rax
	cmp DWORD [rcx + 8], 0
	je end
	mov rdx, [rcx + 8]
	inc rax
	jmp roop

end :
	ret
