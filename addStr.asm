includelib legacy_stdio_definitions.lib
.386
.model flat,stdcall
extern printf:near
extern scanf:near

;������ � ������� ����������� ���������� ����� �����
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

;����� ���� �����
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
addStr proc C, stroka1:DWORD, stroka2:DWORD, stroka3:DWORD         ;��������� ��������� 3 ������ � ���������� �� ��������� ���������

    mov ecx, 0
	len stroka1                                     ;���������� ����� ������ ������
    ;printLen                                       ;����� ����� (��� �������)
    mov edi,stroka1
    lea esi, result

addstr1:                                            ;������ ������ �� ����� � ����������� ������ �� ������ edi � esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;����������������� ��� ���������� �������
loop addstr1
    push esi
    len stroka2                                     ;���������� ����� ������ ������
   ; printLen                                       ;����� ����� (��� �������)
    mov edi,stroka2
    pop esi
addstr2:                                            ;������ ������ �� ����� � ����������� ������ �� ������ edi � esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;����������������� ��� ���������� �������
loop addstr2
    push esi
    len stroka3                                     ;���������� ����� ������� ������
   ; printLen                                       ;����� ����� (��� �������)
    mov edi,stroka3
    pop esi
addstr3:                                            ;������ ������ �� ����� � ����������� ������ �� ������ edi � esi
    mov al, byte ptr[edi]
    mov [esi],al
    inc edi
    inc esi                                         ;����������������� ��� ���������� �������
loop addstr3

    mov eax, offset result
	ret
addStr endp
end