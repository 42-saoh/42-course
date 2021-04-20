section .text
	global _ft_list_remove_if
	extern _free

_ft_list_remove_if :
	push rbp
	push rbx
	push r12
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
	cmp rdx, 0
	je end
	cmp rcx, 0
	je end
	mov r12, [rdi]
	xor rbx, rbx
	jmp lst_cmp

lst_remove :
	mov r8, [rdi]
	mov rbp, [r8 + 8]
	push rsi
	push rdx
	push rcx
	push rdi
	mov r8, [rdi]
	mov rdi, [r8]
	call rcx
	pop rdi
	push rdi
	mov r8, [rdi]
	mov rdi, r8
	call _free
	pop rdi
	pop rcx
	pop rdx
	pop rsi
	mov [rdi], rbp
	cmp rbx, 0
	jne pre_lst_set
	mov r12, rbp
	jmp lst_cmp

pre_lst_set :
	mov [rbx + 8], rbp
	jmp lst_cmp

null_data :
	xor rdi, rsi
	mov rax, rdi
	jmp lst_cmp2

next_lst :
	mov rbx, [rdi]
	mov r8, [rbx + 8]
	mov [rdi], r8

lst_cmp :
	cmp QWORD [rdi], 0
	je end
	push rdi
	push rsi
	push rdx
	push rcx
	mov r8, [rdi]
	mov rdi, [r8]
	cmp rdi, 0
	je null_data
	call rdx

lst_cmp2 :
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	cmp rax, 0
	je lst_remove
	jmp next_lst

end :
	mov [rdi], r12
	pop r12
	pop rbx
	pop rbp
	ret
