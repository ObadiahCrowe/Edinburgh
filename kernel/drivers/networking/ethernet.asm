;Ethernet driver
;For intel based ethernet systems

initialise_net_driver:
  push rsi
  push rdx
  push rcx
  push rax

  ;Get Input and Ouput addresses of the ethernet port
  mov dl, 0x04
