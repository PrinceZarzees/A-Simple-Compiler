.model small
.stack 100h
.data
cr equ 0Dh
lf equ 0Ah
number db "00000$"
;int func(int n)
.code
func proc
push bp
mov bp,sp
mov bx,[bp+4]
mov [bp-2],bx
sub sp,2
sub sp,2
;int i;
mov bx,[bp-2]
push ax
mov ax,bx
mov bx,0
;n==0
cmp ax,bx
jne L1
mov bx,1
jmp end_L1
L1:
mov bx,0
end_L1:
pop ax
cmp bx,0
je L2
mov bx,0
;return 0;
add sp,2
add sp,2
pop bp
ret
;if(n==0)
L2:
mov bx,[bp-2]
;i=n
mov [bp-4],bx
mov bx,[bp-2]
push ax
mov ax,bx
mov bx,1
;n-1
sub ax,bx
mov bx,ax
pop ax
push bx
;func(n-1)
call func
pop cx
push ax
mov ax,bx
mov bx,[bp-4]
;func(n-1)+i
add bx,ax
pop ax
;return func(n-1)+i;
add sp,2
add sp,2
pop bp
ret
func endp
;int func2(int n)
func2 proc
push bp
mov bp,sp
mov bx,[bp+4]
mov [bp-2],bx
sub sp,2
sub sp,2
;int i;
mov bx,[bp-2]
push ax
mov ax,bx
mov bx,0
;n==0
cmp ax,bx
jne L3
mov bx,1
jmp end_L3
L3:
mov bx,0
end_L3:
pop ax
cmp bx,0
je L4
mov bx,0
;return 0;
add sp,2
add sp,2
pop bp
ret
;if(n==0)
L4:
mov bx,[bp-2]
;i=n
mov [bp-4],bx
mov bx,[bp-2]
push ax
mov ax,bx
mov bx,1
;n-1
sub ax,bx
mov bx,ax
pop ax
push bx
;func(n-1)
call func
pop cx
push ax
mov ax,bx
mov bx,[bp-4]
;func(n-1)+i
add bx,ax
pop ax
;return func(n-1)+i;
add sp,2
add sp,2
pop bp
ret
func2 endp
;int main()
main proc
mov ax,@data
mov ds,ax
mov bp,sp
sub sp,2
;int a;
mov bx,7
push bx
;func(7)
call func
pop cx
;a=func(7)
mov [bp-2],bx
;println(a);
mov ax,[bp-2]
call print_output
call new_line
mov bx,0
;return 0;
mov ah,4Ch
int 21h
main endp
new_line proc
    push ax
    push dx
    mov ah,2
    mov dl,cr
    int 21h
    mov ah,2
    mov dl,lf
    int 21h
    pop dx
    pop ax
    ret
    new_line endp
print_output proc  ;print what is in ax
    push ax
    push bx
    push cx
    push dx
    push si
    lea si,number
    mov bx,10
    add si,4
    cmp ax,0
    jnge negate
    print:
    xor dx,dx
    div bx
    mov [si],dl
    add [si],'0'
    dec si
    cmp ax,0
    jne print
    inc si
    lea dx,si
    mov ah,9
    int 21h
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret
    negate:
    push ax
    mov ah,2
    mov dl,'-'
    int 21h
    pop ax
    neg ax
    jmp print
    print_output endp
end main
