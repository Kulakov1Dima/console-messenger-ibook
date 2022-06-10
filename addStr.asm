includelib legacy_stdio_definitions.lib
.386
.model flat,stdcall
extern printf:near
extern scanf:near

;макрос в котором реализовано вычисление длины строк
len macro str:REQ
    cld
    mov edi,str
    mov esi,edi
    mov ecx, 0ffffffffh;
    xor al, al
    repne scasb
    sub edi,esi
    dec edi
    mov ecx, edi
endm

;вывод длин строк
printLen macro
    push ecx
    push edi
    push offset formatOutput
    call printf
    add esp, 4
    pop ecx
endm

.data
formatOutput db "%d", 10, 0
result db "                                                                                                                        "
.code
public addStr
addStr proc C, stroka1:DWORD, stroka2:DWORD, stroka3:DWORD         ;процедура принимает 3 строки и возвращает их склеенный результат

    mov ecx, 0
	len stroka1                                     ;вычисление длины первой строки
    ;printLen                                       ;вывод длины (для отладки)
    mov edi,stroka1
    lea esi, result

addstr1:                                            ;запись данных из места в оперативной памяти по адресу edi в esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;инкриминтирование для следующего символа
loop addstr1
    push esi
    len stroka2                                     ;вычисление длины второй строки
   ; printLen                                       ;вывод длины (для отладки)
    mov edi,stroka2
    pop esi
addstr2:                                            ;запись данных из места в оперативной памяти по адресу edi в esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;инкриминтирование для следующего символа
loop addstr2
    push esi
    len stroka3                                     ;вычисление длины третьей строки
   ; printLen                                       ;вывод длины (для отладки)
    mov edi,stroka3
    pop esi
addstr3:                                            ;запись данных из места в оперативной памяти по адресу edi в esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;инкриминтирование для следующего символа
loop addstr3

    mov eax, offset result
	ret
addStr endp
end